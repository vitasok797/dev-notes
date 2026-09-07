# Git-bash configuration

* Apply `console_colors.reg` file
* Save `git-prompt.sh` file to `<git_install_dir>\etc\profile.d` directory
* Add to `<git_install_dir>\etc\profile.d\aliases.sh` file:
```
alias sl='echo; git st; echo; git lg'
alias s='clear; sl ${FROM}~..HEAD'
alias dt='(git dt &> /dev/null &)'
alias dt-s='(git dt-s &> /dev/null &)'
alias tlog='(TortoiseGitProc.exe /command:log /path:. &> /dev/null &)'
alias exp='explorer .'
```
* Add to `<git_install_dir>\etc\profile.d\env.sh` file:
```
export FROM=origin/main
```
