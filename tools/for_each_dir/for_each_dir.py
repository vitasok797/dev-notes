import locale
import subprocess
import sys
from pathlib import Path


def process_dir(target_dir: Path, commands: list[str]) -> None:
    print(f'Processing dir "{target_dir.name}"... ', end='', flush=True)

    if not target_dir.is_dir():
        print('Error (target dir not found)')
        sys.exit(1)

    for command in commands:
        process_command(target_dir, command)

    print('OK')


def process_command(target_dir: Path, command: str) -> None:
    console_encoding = 'oem' if sys.platform == 'win32' else locale.getpreferredencoding()

    try:
        subprocess.run(
                command,
                cwd=target_dir,
                shell=True,
                check=True,
                capture_output=True,
                encoding=console_encoding,
                )
    except subprocess.CalledProcessError as ex:
        print(f'Error\n{ex.stderr}')
        sys.exit(1)


def main() -> None:
    commands = sys.argv[1:]
    if not commands:
        print('Error: no commands provided')
        sys.exit(1)

    work_dir = Path()
    dir_items = work_dir.glob('*')
    dirs = [item for item in dir_items if item.is_dir()]

    for target_dir in dirs:
        process_dir(target_dir, commands)

    print('Done')


if __name__ == '__main__':
    main()
