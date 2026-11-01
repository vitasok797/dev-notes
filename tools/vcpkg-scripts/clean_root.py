from __future__ import annotations

import shutil
import sys

from vcpkg_setup import VCPKG_ROOT_DIR


def delete_dir(dir_name: str) -> None:
    print(f'Deleting "{dir_name}"... ', end='', flush=True)

    target_dir = VCPKG_ROOT_DIR / dir_name

    if not target_dir.is_dir():
        print('missing')
        return

    try:
        shutil.rmtree(target_dir)
    except OSError as ex:
        print(f'error ({ex})')
        sys.exit(1)

    print('OK')


def main() -> None:
    delete_dir('buildtrees')
    delete_dir('downloads')
    delete_dir('packages')
    print('Done')


if __name__ == '__main__':
    main()
