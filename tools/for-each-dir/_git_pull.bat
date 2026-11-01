@echo off

python "%~dp0\for_each_dir.py" "git fetch --all" "git merge --ff-only"
if errorlevel 1 pause
