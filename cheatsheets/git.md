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

List branches:
```
git branch [options]
```
Options:
* `-v`: verbose
* `--merged [commit]`: merged into the commit (commit defaults to HEAD)
* `--no-merged [commit]`: not merged into the commit (commit defaults to HEAD)

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

Show log:
```
git log [options]
```
Options:
* Format:
  * `--oneline`: compact
  * `--format=medium`: medium
* `--all`: show all branches
* `--graph`: draw a text-based graphical representation of the commit history
* `--stat`: show diffstat
* `--patch`, `-p`: show patch
* `--merges`: show only merge commits
* `--first-parent`: follow only the first parent

Show unique (not merged to master) commits in current branch:
```
git log master..HEAD
```

## Maintenance
[git-clean](https://git-scm.com/docs/git-clean)

Clean the working tree (recursively, starting from the current directory):
```
git clean -f [items_to_remove] [--interactive] [--dry-run]
```
Items to remove:
* Not set: untracked files
* `-d`: + untracked dirs
* `-x`: + ignored files
* `-X`: ignored files only

[git-gc](https://git-scm.com/docs/git-gc)

Cleanup unnecessary files and optimize the local repository:
```
git gc
```

## Merge
[git-merge](https://git-scm.com/docs/git-merge)

Fast-forward options:
* `--no-ff`
* `--ff` (fast-forward when possible)
* `--ff-only`

Undo merge:
```
git reset --hard ORIG_HEAD
```

Check fast-forward possibility:
```
git merge --ff-only <branch> && git reset --hard ORIG_HEAD
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

⚠️❓ Set fast-forward policy:
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

Set log format:
```
git config --global format.pretty oneline
```
```
git config --global log.abbrevCommit true
```
