# Git Cheat Sheet

[GitHub Git cheatsheet](https://training.github.com/downloads/ru/github-git-cheat-sheet/)

## Remote
[git-remote](https://git-scm.com/docs/git-remote)

Show remote URLs:
```
git remote -v
```

## List files
[git-ls-files](https://git-scm.com/docs/git-ls-files)

List files EOL:
```
git ls-files --eol
```

Find CRLF files in repo:
```
git ls-files --eol | grep "i/crlf"
```

## Configuration
Show configuration:
```
git config --list --show-origin
```
```
git config --list --show-scope
```

Set username and email:
```
git config --global user.name "YOUR_USERNAME"
```
```
git config --global user.email "YOUR_EMAIL"
```

Disable fast-forward merge:
```
git config --global merge.ff false
```
```
git config --global pull.ff true
```
