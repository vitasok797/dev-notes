# Git-bash configuration

* Apply `console_colors.reg` file
* Save `git-prompt.sh` file to `<git_install_dir>\etc\profile.d` directory
* Add to `<git_install_dir>\etc\profile.d\aliases.sh` file:
```
alias sl='echo; git st; echo; git log'
alias s='clear; sl ${FROM}~..HEAD'
alias dt='(git dt &> /dev/null &)'
alias dt-s='(git dt-s &> /dev/null &)'
alias t-log='(TortoiseGitProc.exe /command:log &> /dev/null &)'
alias t-reflog='(TortoiseGitProc.exe /command:reflog &> /dev/null &)'
alias t-cm='(TortoiseGitProc.exe /command:diff &> /dev/null &)'
alias t-cl='(TortoiseGitProc.exe /command:cleanup &> /dev/null &)'
alias expl='explorer .'
```
* Add to `<git_install_dir>\etc\profile.d\env.sh` file:
```
export FROM=origin/main
```
