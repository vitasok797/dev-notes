# Git Cheat Sheet

👉 [Configuration](git.md#configuration)

## External
* [Шпаргалка](https://training.github.com/downloads/ru/github-git-cheat-sheet/)

## Remote
[doc](https://git-scm.com/docs/git-remote)

Show remote URL:
```
git remote -v
```

## List files
[doc](https://git-scm.com/docs/git-ls-files)

List files EOL:
```
git ls-files --eol
```

Find CRLF files in repo:
```
git ls-files --eol | grep "i/crlf"
```
