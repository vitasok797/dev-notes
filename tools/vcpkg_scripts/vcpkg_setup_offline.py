from __future__ import annotations

import re
import sys

from vcpkg_setup import VCPKG_ROOT_DIR, setup_vcpkg_environment, EnvironmentType
from vcpkg_setup import create_workspace_dirs
from vcpkg_setup import print_operation_begin, print_operation_end


def check_vcpkg_root() -> None:
    print_operation_begin('Checking VCPKG root')
    if not VCPKG_ROOT_DIR.is_dir():
        sys.exit('error (VCPKG root dir not found)')
    print_operation_end('ok')


def show_vcpkg_tool_url() -> None:
    tool_info_file = VCPKG_ROOT_DIR / 'scripts' / 'vcpkg-tool-metadata.txt'
    tool_info = tool_info_file.read_text()
    version, = re.search(r'VCPKG_TOOL_RELEASE_TAG=(.*)', tool_info).groups()
    url = f'https://github.com/microsoft/vcpkg-tool/releases/download/{version}'
    print('VCPKG tool:')
    print(f'  * (Windows): {url}/vcpkg.exe')
    print(f'  * (Linux): {url}/vcpkg-glibc')


def main() -> None:
    check_vcpkg_root()
    create_workspace_dirs()
    setup_vcpkg_environment(EnvironmentType.OFFLINE)
    show_vcpkg_tool_url()
    print('Done')


if __name__ == '__main__':
    main()
