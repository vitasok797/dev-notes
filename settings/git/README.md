# Git configuration

* [git-config](https://git-scm.com/docs/git-config)

## Show configuration
```
git config --list --show-scope --show-origin
```

## Common options
```bash
# Username and email
git config --<system|global> user.name "<username>"
git config --<system|global> user.email <email>

# EOL conversion
git config --<system|global> core.eol native
git config --<system|global> core.autocrlf <input|true>

# Fast-forward and rebase policy
git config --<system|global> merge.ff false
git config --<system|global> pull.ff only
git config --<system|global> pull.rebase false

# Enable automatic fetch --prune
git config --<system|global> fetch.prune true
git config --<system|global> fetch.pruneTags true

# Log format
git config --<system|global> format.pretty "%C(yellow)%h%C(auto)%d %Cblue%as (%ar) %Cgreen%an %Creset%s"

# Status format
git config --<system|global> status.short true
git config --<system|global> status.branch true

# Set WinMerge as diff tool
git config --<system|global> diff.guitool winmerge
git config --<system|global> difftool.prompt false
git config --<system|global> difftool.guiDefault true
git config --<system|global> difftool.winmerge.cmd "'<C:\\path\\to\\WinMergeU.exe>' -u -fl -wr -e \"\$LOCAL\" \"\$REMOTE\""

# Set TortoiseMerge as merge tool
git config --<system|global> merge.guitool tortoisemerge
git config --<system|global> mergetool.prompt false
git config --<system|global> mergetool.guiDefault true
git config --<system|global> mergetool.keepBackup false

# Aliases
git config --<system|global> alias.aliases "config --get-regexp alias\."
git config --<system|global> alias.br "branch -vv"
git config --<system|global> alias.ch "diff --check"
git config --<system|global> alias.dt "difftool -d"
git config --<system|global> alias.dt-s "difftool -d --staged"
git config --<system|global> alias.lg "log --all --graph"
git config --<system|global> alias.lg-f "log --all --graph --first-parent"
git config --<system|global> alias.log-h "log --format=\"%C(yellow)%h%C(auto)%d %Cblue%as (%ar) %Cgreen%an %Creset%B\""
git config --<system|global> alias.ls-i "ls-files --eol"
git config --<system|global> alias.ls-ig "ls-files --other --exclude-standard --ignored"
git config --<system|global> alias.ls-un "ls-files --eol --other --exclude-standard"
git config --<system|global> alias.show-h "show --format=fuller --no-patch"
git config --<system|global> alias.st "!git status && ig=$(git ls-ig | wc -l) && [ $ig -gt 0 ] && echo Ignored: $ig"
```

`core.autocrlf` options:
* `input`: Git will convert CRLF to LF during commit (Linux, Windows)
* `true`: Git will convert CRLF to LF during commit and LF to CRLF during checkout (Windows)

`merge.ff`/`pull.ff` fast-forward policy options:
* `false` (`--no-ff`)
* `true` (`--ff`, fast-forward when possible)
* `only` (`--ff-only`)

## Connection options
```bash
git config --<system|global> http.proxy <proxy>
git config --<system|global> http.schannelcheckrevoke false
git config --<system|global> http.sslBackend openssl
```

## Set WinMerge as TortoiseGit/SVN diff tool
```
"C:\path\to\WinMergeU.exe" /u /fl /wr /e /dl %bname /dr %yname %base %mine
```
