# Git Cheat Sheet

## Other cheatsheets 📌
* [GitHub Git cheatsheet](https://education.github.com/git-cheat-sheet-education.pdf)

## Reference 📌
* [Reference topics](https://git-scm.com/docs)
* [Git config](https://git-scm.com/docs/git-config)
* [Revisions](https://git-scm.com/docs/gitrevisions)
* [Reset, restore and revert](https://git-scm.com/docs/git#_reset_restore_and_revert)

## Branches
List branches ([git-branch](https://git-scm.com/docs/git-branch)):
```
git branch [options]
```

`git branch` options:
* `-v`: verbose
* `--merged [commit]`: merged into the commit (commit defaults to HEAD)
* `--no-merged [commit]`: not merged into the commit (commit defaults to HEAD)

## Fetching
Fetch and remove any remote-tracking references that no longer exist on the remote ([git-fetch](https://git-scm.com/docs/git-fetch)):
```
git fetch --prune [remote]
```

## List files
List files EOL ([git-ls-files](https://git-scm.com/docs/git-ls-files)):
```
git ls-files --eol
```

Find CRLF files in repo ([git-ls-files](https://git-scm.com/docs/git-ls-files)):
```
git ls-files --eol | grep "i/crlf"
```

## Log
Show log ([git-log](https://git-scm.com/docs/git-log)):
```
git log [options]
```

`git log` options:
* Format:
  * `--oneline`
  * `--format=medium`
  * `--format=raw`
* Diff:
  * `-p`: show diffs
  * `--dd`: show diffs, produce diff with respect to first parent (shortcut for `--diff-merges=first-parent -p`)
* `--all`: show all branches
* `--graph`: draw a text-based graphical representation of the commit history
* `--stat`: show diffstat
* `--merges`: show only merge commits
* `--first-parent`: follow only the first parent

Show unique (not merged to master) commits in current branch ([git-log](https://git-scm.com/docs/git-log)):
```
git log master..HEAD
```

## Maintenance
Clean the working tree (recursively, starting from the current directory) ([git-clean](https://git-scm.com/docs/git-clean)):
```
git clean -f [items_to_remove] [--interactive] [--dry-run]
```

`git clean` `items_to_remove` options:
* not set: untracked files
* `-d`: + untracked dirs
* `-x`: + ignored files
* `-X`: ignored files only

Cleanup unnecessary files and optimize the local repository ([git-gc](https://git-scm.com/docs/git-gc)):
```
git gc
```

## Merging
Fast-forward options:
* `--no-ff`
* `--ff` (fast-forward when possible)
* `--ff-only`

Undo merge ([git-reset](https://git-scm.com/docs/git-reset)):
```
git reset --hard ORIG_HEAD
```

Check fast-forward merge possibility ([git-merge](https://git-scm.com/docs/git-merge), [git-reset](https://git-scm.com/docs/git-reset)):
```
git merge --ff-only <branch> && git reset --hard ORIG_HEAD
```

Show merge commit parents ([git-show](https://git-scm.com/docs/git-show)):
```
git show --format=raw <commit>
```

Show merge commit diff ([git-show](https://git-scm.com/docs/git-show), [git-diff](https://git-scm.com/docs/git-diff)):
```
git show -m <commit>
```
```
git diff <commit>^n <commit>
```

## Pushing
Push branch to specified remote and set upstream tracking (allows to pull/push without any argument) ([git-push](https://git-scm.com/docs/git-push)):
```
git push -u <remote> <branch>
```

## Remote
Show remote URLs ([git-remote](https://git-scm.com/docs/git-remote)):
```
git remote -v
```

Show information about the remote ([git-remote](https://git-scm.com/docs/git-remote)):
```
git remote show <remote>
```

Remove any remote-tracking references that no longer exist on the remote ([git-remote](https://git-scm.com/docs/git-remote)):
```
git remote prune <remote>
```

## Working trees
🚧 [git-worktree](https://git-scm.com/docs/git-worktree)

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
