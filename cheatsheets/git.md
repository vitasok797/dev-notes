# Git Cheat Sheet

## Other cheatsheets 📌
* [GitHub Git cheatsheet](https://education.github.com/git-cheat-sheet-education.pdf)

## Reference 📌
* [Reference topics](https://git-scm.com/docs)
* [Git config](https://git-scm.com/docs/git-config)
* [Revisions](https://git-scm.com/docs/gitrevisions)
* [Reset, restore and revert](https://git-scm.com/docs/git#_reset_restore_and_revert)

## Branches
#### List branches ([git-branch](https://git-scm.com/docs/git-branch))
```
git branch [options]
```

Options:
* `-v`: verbose
* `-vv`: verbose (prints linked worktree (if any) and upstream status)
* `-a`: list both remote branches and local branches
* `--merged [commit]`: merged into the commit (commit defaults to HEAD)
* `--no-merged [commit]`: not merged into the commit (commit defaults to HEAD)

## Commits
#### Show commit info ([git-show](https://git-scm.com/docs/git-show))
```
git show [options] <commit>
```

Options:
* `--format=<format>`: output format (`short`, `medium`, `full`, `raw`)
* `--stat`: show diffstat
* `-p`: show diff for regular commits
  * `-m`: + show diff for merge commits
* `--dd`: show diff to first-parent for both merge and regular commits

## Fetching
#### Download objects and refs from another repository ([git-fetch](https://git-scm.com/docs/git-fetch))
```
git fetch [options] [remote]
```

Options:
* `--prune`: before fetching, remove any remote-tracking references that no longer exist on the remote

## List files
#### List files EOL ([git-ls-files](https://git-scm.com/docs/git-ls-files))
```
git ls-files --eol
```

#### Find CRLF files in repo ([git-ls-files](https://git-scm.com/docs/git-ls-files))
```
git ls-files --eol | grep "i/crlf"
```

## Log
#### Show log ([git-log](https://git-scm.com/docs/git-log))
```
git log [options]
```

Options:
* Commit info:
  * `--format=<format>`: output format (`short`, `medium`, `full`, `raw`)
  * `--stat`: show diffstat
  * `-p`: show diff for regular commits
    * `-m`: + show diff for merge commits
  * `--dd`: show diff to first-parent for both merge and regular commits
* `--all`: show all branches
* `--merges`: show only merge commits
* `--first-parent`: follow only the first parent
* `--graph`: draw a text-based graphical representation of the commit history
* `--topo-order`: topological order

#### Show unique (not merged to master) commits in current branch ([git-log](https://git-scm.com/docs/git-log), [git-cherry](https://git-scm.com/docs/git-cherry))
```
git log HEAD ^master
```
```
git log master..HEAD
```
```
git cherry -v master
```

#### Show unique (not pulled) commits in remote branch (after fetch) ([git-log](https://git-scm.com/docs/git-log))
```
git log <branch>..<remote/branch>
```

## Maintenance
#### Clean the working tree (recursively, starting from the current directory) ([git-clean](https://git-scm.com/docs/git-clean))
```
git clean -f [items_to_remove] [--interactive] [--dry-run]
```

`items_to_remove`:
* not set: untracked files
* `-d`: + untracked dirs
* `-x`: + ignored files
* `-X`: ignored files only

#### Cleanup unnecessary files and optimize the local repository ([git-gc](https://git-scm.com/docs/git-gc))
```
git gc
```

## Merging
Fast-forward options:
* `--no-ff`
* `--ff` (fast-forward when possible)
* `--ff-only`

#### Preview merge ([git-merge](https://git-scm.com/docs/git-merge)):
```
git merge --no-commit --no-ff <branch>
```
then:
```
git merge --abort
```

#### Undo merge commit ([git-reset](https://git-scm.com/docs/git-reset))
```
git reset --hard ORIG_HEAD
```

#### Check fast-forward merge possibility ([git-merge](https://git-scm.com/docs/git-merge), [git-reset](https://git-scm.com/docs/git-reset))
```
git merge --ff-only <branch> && git reset --hard ORIG_HEAD
```

#### Show merge commit parents ([git-show](https://git-scm.com/docs/git-show))
```
git show --format=raw <commit>
```

#### Show merge commit diff ([git-show](https://git-scm.com/docs/git-show), [git-diff](https://git-scm.com/docs/git-diff))
Show diff with all parents:
```
git show -p -m <commit>
```

Show diff with first parent:
```
git show --dd <commit>
```

Show diff with selected parent:
```
git diff <commit>^n <commit>
```

## Pushing
#### Push branch to specified remote and set upstream tracking (allows to pull/push without any argument) ([git-push](https://git-scm.com/docs/git-push))
```
git push -u <remote> <branch>
```

## Remote
#### Show remotes ([git-remote](https://git-scm.com/docs/git-remote))
```
git remote
```

#### Show remote URLs ([git-remote](https://git-scm.com/docs/git-remote))
```
git remote -v
```

#### Show information about the remote ([git-remote](https://git-scm.com/docs/git-remote))
```
git remote show <remote>
```

#### Remove any remote-tracking references that no longer exist on the remote ([git-remote](https://git-scm.com/docs/git-remote))
```
git remote prune <remote>
```

## Working trees
🚧 [git-worktree](https://git-scm.com/docs/git-worktree)

## Configuration 📌
#### Show configuration
```
git config --list --show-origin
```
```
git config --list --show-scope
```

#### Set username and email
```
git config --global user.name "YOUR_USERNAME"
```
```
git config --global user.email "YOUR_EMAIL"
```

#### ⚠️❓ Set fast-forward policy
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

#### Enable automatic fetch --prune
```
git config --global fetch.prune true
```
```
git config --global fetch.pruneTags true
```

#### Set log format
```
git config --global format.pretty oneline
```
```
git config --global log.abbrevCommit true
```
