# Delta configuration

* [Download](https://github.com/dandavison/delta/releases) and install
* Select `system` or `global` scope and git config location dir:
```
git config --list --show-scope --show-origin
```
* Save `delta.gitconfig` file to the selected dir
* Execute with the selected scope:
```
git config set --<system|global> --append include.path delta.gitconfig
```
