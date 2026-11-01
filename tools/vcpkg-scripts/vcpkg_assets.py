from __future__ import annotations

import hashlib
import json
import os
import re
import shutil
import sys
from collections.abc import Iterable
from dataclasses import dataclass
from datetime import datetime, timedelta
from pathlib import Path
from typing import Any, NoReturn, Callable

from vcpkg_setup import BASE_DIR, ASSET_CACHE_DIR, MANIFEST_DIR
from vcpkg_setup import ensure_dir
from vcpkg_setup import print_operation_begin, print_operation_end
from vcpkg_setup import run_shell_command, ShellCommandOutput

SHORT_HASH_LEN = 15
MANIFEST_HASH_ALG = 'sha1'


class AssetsInfo:
    HashType = str
    UrlType = str
    AssetDict = dict[HashType, UrlType]

    def __init__(self) -> None:
        self.manifest_hash = ''
        self.assets: AssetsInfo.AssetDict = {}

    @staticmethod
    def load_from_file(file: Path, *, missing_ok: bool = False) -> AssetsInfo:
        assets_info = AssetsInfo()
        assets_info.__dict__ |= AssetsInfo._load_data_from_file(file, missing_ok=missing_ok)
        return assets_info

    @staticmethod
    def load_from_files(files: list[Path], *, missing_ok: bool = False) -> AssetsInfo:
        assets_info = AssetsInfo()
        for file in files:
            loaded_data = AssetsInfo._load_data_from_file(file, missing_ok=missing_ok)
            assets_info.assets |= loaded_data['assets']
        return assets_info

    @staticmethod
    def _load_data_from_file(file: Path, *, missing_ok: bool = False) -> dict:
        if not file.is_file():
            if missing_ok:
                return {}
            else:
                raise FileNotFoundError(f'asset info file "{file}" not found')

        with file.open() as f:
            return json.load(f)

    def save(self, file: Path) -> None:
        with file.open(mode='w') as f:
            json.dump(self.__dict__, f, indent=2)

    def update_info(self, update: AssetsInfo.AssetDict) -> None:
        self.assets |= update


class AssetDownloader:
    _TEMP_DIR = BASE_DIR / '_temp'
    _OUTPUT_ASSET_BASE_PATTERN = r'\S+/([0-9a-f]+)\s.*?authoritative source ([^\s,]+)'
    _OUTPUT_ASSET_SUCCESS_PATTERN = f'using asset cache {_OUTPUT_ASSET_BASE_PATTERN}'
    _OUTPUT_ASSET_MISSING_PATTERN = f"won't retry download from {_OUTPUT_ASSET_BASE_PATTERN}"

    class AssetDownloadError(Exception):
        pass

    class MissingAssetError(Exception):
        def __init__(self, asset_hash: str, asset_url: str):
            self.asset_hash = asset_hash
            self.asset_url = asset_url

    def __init__(self, manifest_file: Path) -> None:
        self._manifest_file = manifest_file

        self.project_name = self._manifest_file.stem

        self._work_dir = self._TEMP_DIR / self.project_name
        self._downloads_dir = self._work_dir / 'downloads'
        self._binary_cache_dir = self._work_dir / 'binary_cache'
        self._assets_info_file = ASSET_CACHE_DIR / f'_{self.project_name}.json'
        self._log_file = self._work_dir / 'install.log'

        self._assets_info = AssetsInfo()

    def prepare(self) -> None:
        self._cleanup()
        self._ensure_dirs()
        self._copy_manifest_file()
        self._init_assets_info()

    def _cleanup(self) -> None:
        if self._work_dir.is_dir():
            shutil.rmtree(self._work_dir)
        self._assets_info_file.unlink(missing_ok=True)

    def _ensure_dirs(self) -> None:
        ensure_dir(ASSET_CACHE_DIR)
        ensure_dir(self._work_dir)
        ensure_dir(self._downloads_dir)
        ensure_dir(self._binary_cache_dir)

    def _copy_manifest_file(self) -> None:
        shutil.copy(self._manifest_file, self._work_dir / 'vcpkg.json')

    def _init_assets_info(self) -> None:
        self._assets_info.manifest_hash = calc_file_hash(
                self._manifest_file,
                algorithm=MANIFEST_HASH_ALG,
                )

    def download(self) -> timedelta:
        output_text, exit_code, elapsed_time = self._run_vcpkg_install()
        self._write_log(output_text)

        downloaded_assets_info = self._extract_downloaded_assets_info(output_text)
        self._assets_info.update_info(downloaded_assets_info)

        if exit_code:
            self._handle_download_error(output_text)

        self._assets_info.save(self._assets_info_file)
        return elapsed_time

    def _run_vcpkg_install(self) -> tuple[str, int, timedelta]:
        env = os.environ.copy()
        env['VCPKG_DOWNLOADS'] = str(self._downloads_dir)
        env['VCPKG_DEFAULT_BINARY_CACHE'] = str(self._binary_cache_dir)
        env['VCPKG_KEEP_ENV_VARS'] = 'PATH'

        start_time = datetime.now()
        process_res = run_shell_command(
                command='vcpkg install --clean-after-build',
                cwd=self._work_dir,
                env=env,
                check=False,
                output=ShellCommandOutput.CAPTURE_COMBINED,
                )
        elapsed_time = datetime.now() - start_time
        output_text = process_res.stdout

        return output_text, process_res.returncode, elapsed_time

    def _write_log(self, output_text: str) -> None:
        self._log_file.write_text(output_text, encoding='utf-8')

    def _extract_downloaded_assets_info(self, output_text: str) -> dict[str, str]:
        downloaded_info = {}

        matches = re.finditer(self._OUTPUT_ASSET_SUCCESS_PATTERN, output_text)
        for match in matches:
            sha512, url = match.groups()
            downloaded_info[sha512] = url

        return downloaded_info

    def _extract_missed_asset_info(self, output_text: str) -> tuple[str, str] | None:
        match = re.search(self._OUTPUT_ASSET_MISSING_PATTERN, output_text)
        if not match:
            return None
        sha512, url = match.groups()
        return sha512, url

    def _handle_download_error(self, output_text: str) -> NoReturn:
        messed_asset_info = self._extract_missed_asset_info(output_text)
        if messed_asset_info:
            sha512, url = messed_asset_info
            raise self.MissingAssetError(sha512, url)
        else:
            raise self.AssetDownloadError


def download_assets() -> None:
    manifests = select_manifests()
    for manifest in manifests:
        download_manifest_assets(manifest)
    print('Done')


def select_manifests() -> list[Path]:
    if not MANIFEST_DIR.is_dir():
        stop('Error: manifests dir not found')

    manifests = get_manifest_files()
    if not manifests:
        stop('Error: manifest files not found')

    options = [('ALL', manifests)] + [(m.stem, [m]) for m in manifests]
    return get_user_selection(options, start_index=0)


def get_manifest_files() -> list[Path]:
    files = MANIFEST_DIR.glob('*.json')
    files = [file for file in files if file.is_file()]
    return files


def download_manifest_assets(manifest: Path) -> None:
    downloader = AssetDownloader(manifest)
    downloader.prepare()

    while True:
        try:
            print_operation_begin(f'Downloading assets ({downloader.project_name})')
            elapsed_time = downloader.download()
            print_operation_end(f'ok ({elapsed_time})')
            return
        except AssetDownloader.AssetDownloadError:  # noqa: PERF203
            print_operation_end('error')
            stop('Finished with an ERROR (see log)')
        except AssetDownloader.MissingAssetError as ex:
            print_operation_end('error')
            print(f'Cannot download asset:\n  hash: {ex.asset_hash}\n  url: {ex.asset_url}')
            if not user_wants_to_repeat():
                stop('Download aborted')
            continue


def user_wants_to_repeat() -> bool:
    options = [
        ('repeat', True),
        ('abort', False),
        ]
    return get_user_selection(options)


@dataclass
class AssetsState:
    asset_files: list[Path]
    good_asset_files: list[Path]
    missing_asset_files: list[Path]
    extra_asset_files: list[Path]

    info_files: list[Path]
    good_info_files: list[Path]
    outdated_info_files: list[Path]
    missing_info_files: list[Path]
    extra_info_files: list[Path]

    other_files: list[Path]

    good_assets_info: AssetsInfo

    @staticmethod
    def gen_assets_state() -> AssetsState:
        if not ASSET_CACHE_DIR.is_dir():
            error_message = f'error (asset cache dir "{ASSET_CACHE_DIR.name}" not found)'
            sys.exit(error_message)

        if not MANIFEST_DIR.is_dir():
            error_message = f'error (manifest dir "{MANIFEST_DIR.name}" not found)'
            sys.exit(error_message)

        asset_files, info_files, other_files = AssetsState._get_asset_cache_dir_files()

        good_info_files, outdated_info_files, missing_info_files, extra_info_files = \
            AssetsState._categorize_info_files(info_files)

        good_assets_info = AssetsInfo.load_from_files(good_info_files)
        good_asset_files, missing_asset_files, extra_asset_files = \
            AssetsState._categorize_asset_files(asset_files, good_assets_info)

        return AssetsState(
                asset_files=asset_files,
                good_asset_files=good_asset_files,
                missing_asset_files=missing_asset_files,
                extra_asset_files=extra_asset_files,
                info_files=info_files,
                good_info_files=good_info_files,
                outdated_info_files=outdated_info_files,
                missing_info_files=missing_info_files,
                extra_info_files=extra_info_files,
                other_files=other_files,
                good_assets_info=good_assets_info,
                )

    @staticmethod
    def _get_asset_cache_dir_files() -> tuple[list[Path], list[Path], list[Path]]:
        files = ASSET_CACHE_DIR.glob('*')
        files = [file for file in files if file.is_file()]

        asset_files, files = partition_by_predicate(files, AssetsState._is_asset_file)
        info_files, files = partition_by_predicate(files, AssetsState._is_info_file)

        return asset_files, info_files, files

    @staticmethod
    def _is_asset_file(file: Path) -> bool:
        return bool(re.fullmatch(r'[0-9a-f]{128}', file.name))

    @staticmethod
    def _is_info_file(file: Path) -> bool:
        return bool(AssetsState._get_project_name_from_info_file(file))

    @staticmethod
    def _get_project_name_from_info_file(file: Path) -> str | None:
        match = re.fullmatch(r'_(.*)\.json', file.name)
        return match[1] if match else None

    @staticmethod
    def _categorize_info_files(
            info_files: list[Path],
            ) -> tuple[list[Path], list[Path], list[Path], list[Path]]:
        manifest_files = get_manifest_files()
        rest_info_files = info_files.copy()

        good_info_files = []
        outdated_info_files = []
        missing_info_files = []

        for manifest in manifest_files:
            project_name = manifest.stem
            info_file = ASSET_CACHE_DIR / f'_{project_name}.json'

            if not info_file.is_file():
                missing_info_files.append(info_file)
                continue

            actual_manifest_hash = calc_file_hash(manifest, MANIFEST_HASH_ALG)
            expected_manifest_hash = AssetsInfo.load_from_file(info_file).manifest_hash

            if actual_manifest_hash == expected_manifest_hash:
                good_info_files.append(info_file)
            else:
                outdated_info_files.append(info_file)

            rest_info_files.remove(info_file)

        return good_info_files, outdated_info_files, missing_info_files, rest_info_files

    @staticmethod
    def _categorize_asset_files(
            asset_files: list[Path],
            assets_info: AssetsInfo,
            ) -> tuple[list[Path], list[Path], list[Path]]:
        rest_asset_files = asset_files.copy()

        good_asset_files = []
        missing_asset_files = []

        for asset_hash in assets_info.assets:
            asset_file = ASSET_CACHE_DIR / asset_hash

            if not asset_file.is_file():
                missing_asset_files.append(asset_file)
                continue

            good_asset_files.append(asset_file)
            rest_asset_files.remove(asset_file)

        return good_asset_files, missing_asset_files, rest_asset_files

    def print_items(
            self,
            items: list[Path],
            desc: str,
            *,
            transform_asset_files: bool = True,
            transform_info_files: bool = True,
            ) -> None:
        if not items:
            return

        print(f'{desc} ({len(items)}):')

        for path in items:
            if AssetsState._is_asset_file(path) and transform_asset_files:
                short_hash = path.name[:SHORT_HASH_LEN] + '...'
                url = self.good_assets_info.assets.get(path.name, None)

                output = short_hash
                output += f' ({url})' if url else ''

            elif AssetsState._is_info_file(path) and transform_info_files:
                output = self._get_project_name_from_info_file(path)

            else:
                output = path.name

            print('  *', output)


def print_hr(
        category_name: str = '',
        header_len: int = 99,
        ) -> None:
    output = '---'
    output += f' {category_name} ' if category_name else ''
    output += '-' * (header_len - len(output))
    print(output)


def show_assets_state() -> None:
    state = AssetsState.gen_assets_state()

    if any((
            state.good_asset_files,
            state.good_info_files,
            )):
        print_hr('Good')
        state.print_items(state.good_asset_files, 'Assets')
        state.print_items(state.good_info_files, 'Projects')

    if any((
            state.missing_asset_files,
            state.missing_info_files,
            state.outdated_info_files,
            )):
        print_hr('To process')
        state.print_items(state.missing_asset_files, 'Missing assets')
        state.print_items(state.missing_info_files, 'New projects')
        state.print_items(state.outdated_info_files, 'Outdated projects')

    if any((
            state.extra_asset_files,
            state.extra_info_files,
            state.other_files,
            )):
        print_hr('To delete')
        state.print_items(state.extra_asset_files, 'Assets')
        state.print_items(state.extra_info_files, 'Info files', transform_info_files=False)
        state.print_items(state.other_files, 'Other files')

    print_hr()


def cleanup_assets() -> None:
    state = AssetsState.gen_assets_state()

    files_to_process = \
        state.missing_asset_files + state.missing_info_files + state.outdated_info_files

    files_to_delete = \
        state.extra_asset_files + state.extra_info_files + state.other_files

    if files_to_process:
        stop('Error: there are files to process')

    if not files_to_delete:
        stop('No files to delete')

    for file in files_to_delete:
        file.unlink()
    state.print_items(files_to_delete, 'Deleted files', transform_info_files=False)


def calc_file_hash(file: Path, algorithm: str = 'sha1') -> str:
    h = hashlib.new(algorithm)

    with file.open(mode='rb') as f:
        while True:
            chunk = f.read(h.block_size)
            if not chunk:
                break
            h.update(chunk)

    return h.hexdigest()


def partition_by_predicate(
        iterable: Iterable[Any],
        predicate: Callable[[Any], bool],
        ) -> tuple[list[Any], list[Any]]:
    true_items = []
    false_items = []
    for item in iterable:
        if predicate(item):
            true_items.append(item)
        else:
            false_items.append(item)
    return true_items, false_items


def get_user_selection(
        options: list[tuple[str, Any]],
        start_index: int = 1,
        ) -> Any:  # noqa ANN401
    for index, option in enumerate(options, start_index):
        option_desc, _ = option
        print(f'{index}. {option_desc}')

    while True:
        user_input = input('Select option: ')
        try:
            option_index = int(user_input) - start_index
            if option_index < 0:
                raise IndexError
            _, result = options[option_index]
            return result
        except (ValueError, IndexError):
            continue


def stop(error_message: str) -> NoReturn:
    sys.exit(error_message)


def main() -> None:
    operations = [
        ('download', download_assets),
        ('state', show_assets_state),
        ('cleanup', cleanup_assets),
        ]
    operation = get_user_selection(operations)
    operation()


if __name__ == '__main__':
    main()
