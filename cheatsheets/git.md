# Git Cheat Sheet

[Reference](https://git-scm.com/docs) \
[GitHub Git cheatsheet](https://education.github.com/git-cheat-sheet-education.pdf)

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

## Maintenance
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
```
--ff (fast-forward when possible)
--no-ff
--ff-only
```

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

Enable automatic fetch --prune:
```
git config --global fetch.prune true
```
```
git config --global fetch.pruneTags true
```
