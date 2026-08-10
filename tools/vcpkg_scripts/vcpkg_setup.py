from __future__ import annotations

import locale
import subprocess
import sys
import winreg as reg
from collections.abc import Mapping
from enum import Enum, auto
from pathlib import Path

BASE_DIR = Path().resolve()
VCPKG_ROOT_DIR = BASE_DIR / 'vcpkg_root'
ASSET_CACHE_DIR = BASE_DIR / 'asset_cache'
BINARY_CACHE_DIR = BASE_DIR / 'binary_cache'
MANIFEST_DIR = BASE_DIR / 'manifests'


class ShellCommandOutput(Enum):
    DEFAULT = auto()
    SUPPRESS = auto()
    CAPTURE = auto()
    CAPTURE_COMBINED = auto()


class EnvironmentType(Enum):
    ONLINE = auto()
    OFFLINE = auto()


def add_user_env_var(name: str, value: str) -> None:
    with reg.OpenKey(reg.HKEY_CURRENT_USER, 'Environment', access=reg.KEY_SET_VALUE) as key:
        reg.SetValueEx(key, name, 0, reg.REG_SZ, value)


def add_user_env_path_item(value: Path | str) -> None:
    value = Path(value)
    with reg.OpenKey(reg.HKEY_CURRENT_USER, 'Environment', access=reg.KEY_ALL_ACCESS) as key:
        cur_path_value, _ = reg.QueryValueEx(key, 'Path')
        path_items = cur_path_value.split(';')
        path_items = [Path(item) for item in path_items]

        if value in path_items:
            return

        new_path_value = f'{value};{cur_path_value}'
        reg.SetValueEx(key, 'Path', 0, reg.REG_SZ, new_path_value)


def run_shell_command(
        command: str,
        *,
        cwd: Path | None = None,
        env: Mapping | None = None,
        check: bool = True,
        output: ShellCommandOutput = ShellCommandOutput.SUPPRESS,
        ) -> subprocess.CompletedProcess:
    output_options: dict[str, int | None] = {}
    if output == ShellCommandOutput.DEFAULT:
        output_options['stdout'] = None
        output_options['stderr'] = None
    elif output == ShellCommandOutput.SUPPRESS:
        output_options['stdout'] = subprocess.DEVNULL
        output_options['stderr'] = subprocess.DEVNULL
    elif output == ShellCommandOutput.CAPTURE:
        output_options['stdout'] = subprocess.PIPE
        output_options['stderr'] = subprocess.PIPE
    elif output == ShellCommandOutput.CAPTURE_COMBINED:
        output_options['stdout'] = subprocess.PIPE
        output_options['stderr'] = subprocess.STDOUT
    else:
        raise ValueError(f'Unknown "output" argument value ({output})')

    console_encoding = 'oem' if sys.platform == 'win32' else locale.getpreferredencoding()

    return subprocess.run(
            command,
            cwd=cwd,
            env=env,
            shell=True,
            check=check,
            encoding=console_encoding,
            **output_options,
            )


def ensure_dir(path: Path) -> None:
    path.mkdir(parents=True, exist_ok=True)


def print_operation_begin(message: str) -> None:
    print(f'{message}... ', end='', flush=True)


def print_operation_end(message: str) -> None:
    print(message)


def create_vcpkg_root() -> None:
    print_operation_begin('Creating vcpkg_root')

    if VCPKG_ROOT_DIR.is_dir():
        print('skipped')
        return

    run_shell_command(f'git clone https://github.com/microsoft/vcpkg.git "{VCPKG_ROOT_DIR}"')
    run_shell_command('bootstrap-vcpkg.bat', cwd=VCPKG_ROOT_DIR)

    print_operation_end('ok')


def create_workspace_dirs() -> None:
    print_operation_begin('Creating workspace dirs')

    ensure_dir(ASSET_CACHE_DIR)
    ensure_dir(BINARY_CACHE_DIR)
    ensure_dir(MANIFEST_DIR)

    print_operation_end('ok')


def setup_vcpkg_environment(env_type: EnvironmentType) -> None:
    print_operation_begin('Setting environment variables')

    add_user_env_path_item(VCPKG_ROOT_DIR)

    add_user_env_var('VCPKG_ROOT', str(VCPKG_ROOT_DIR))
    add_user_env_var('VCPKG_DEFAULT_BINARY_CACHE', str(BINARY_CACHE_DIR))
    add_user_env_var('VCPKG_DISABLE_METRICS', '1')

    asset_cache_configuration = f'clear;x-azurl,{ASSET_CACHE_DIR.as_uri()},,'
    if env_type == EnvironmentType.ONLINE:
        asset_cache_configuration += 'readwrite'
    elif env_type == EnvironmentType.OFFLINE:
        asset_cache_configuration += 'read;x-block-origin'
    add_user_env_var('X_VCPKG_ASSET_SOURCES', asset_cache_configuration)

    # flush user environment settings
    run_shell_command('setx VCPKG_DISABLE_METRICS 1')

    print_operation_end('ok')


def main() -> None:
    create_vcpkg_root()
    create_workspace_dirs()
    setup_vcpkg_environment(EnvironmentType.ONLINE)
    print('Done')


if __name__ == '__main__':
    main()
