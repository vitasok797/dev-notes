# Git Cheat Sheet

## Other cheatsheets 📌
* [GitHub Git cheatsheet](https://education.github.com/git-cheat-sheet-education.pdf)

## Reference 📌
* [Reference topics](https://git-scm.com/docs)
* [Git config](https://git-scm.com/docs/git-config)
* [Revisions](https://git-scm.com/docs/gitrevisions)
* [Reset, restore and revert](https://git-scm.com/docs/git#_reset_restore_and_revert)

## Branches
[git-branch](https://git-scm.com/docs/git-branch)

List branches (merged or not merged into the named commit):
```
git branch [--merged [commit]] [--no-merged [commit]]
```

## Fetch
[git-fetch](https://git-scm.com/docs/git-fetch)

Before fetching, remove any remote-tracking references that no longer exist on the remote:
```
git fetch --prune [remote]
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

## Log
[git-log](https://git-scm.com/docs/git-log)

Show compact log:
```
git log --oneline
```

Show compact log (print ref names of any commits that are shown):
```
git log --oneline --decorate
```

## Maintenance
[git-clean](https://git-scm.com/docs/git-clean)

Clean the working tree (recursively, starting from the current directory):
```
git clean -f [-d] [-x|-X] [-i] [-n]
```
Items to remove:
* No options: untracked files
* d: + untracked dirs
* x: + ignored files
* X: ignored files only

[git-gc](https://git-scm.com/docs/git-gc)

Cleanup unnecessary files and optimize the local repository:
```
git gc
```

[git-prune](https://git-scm.com/docs/git-prune)

Remove all unreachable objects (in most cases, users will not need to call git prune directly, but should instead call git gc):
```
git prune
```

## Merge
[git-merge](https://git-scm.com/docs/git-merge)

Fast-forward options:
* `--no-ff`
* `--ff` (fast-forward when possible)
* `--ff-only`

## Push
[git-push](https://git-scm.com/docs/git-push)

Push branch to specified remote and set upstream tracking (allows to pull/push without any argument):
```
git push -u <remote> <branch>
```

## Remote
[git-remote](https://git-scm.com/docs/git-remote)

Show remote URLs:
```
git remote -v
```

Show information about the remote:
```
git remote show <remote>
```

Remove any remote-tracking references that no longer exist on the remote:
```
git remote prune <remote>
```

## Working trees
[git-worktree](https://git-scm.com/docs/git-worktree)

🚧

## Configuration 📌
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

❓ Set fast-forward policy:
```
git config --global merge.ff false
```
```
git config --global pull.ff true
```

Fast-forward policy options:
* `false` (`--no-ff`)
* `true` (`--ff`, fast-forward when possible)
* `only` (`--ff-only`)

Enable automatic fetch --prune:
```
git config --global fetch.prune true
```
```
git config --global fetch.pruneTags true
```
