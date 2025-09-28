# Git Cheat Sheet

## Other cheatsheets 📌
* [GitHub Git cheatsheet](https://education.github.com/git-cheat-sheet-education.pdf)

## Reference 📌
* [Reference](https://git-scm.com/docs)
* [Revisions](https://git-scm.com/docs/gitrevisions)
* [Reset, restore and revert](https://git-scm.com/docs/git#_reset_restore_and_revert)
* [Status short output format](https://git-scm.com/docs/git-status#_short_format)

## Repository configuration 📌
* [gitattributes](https://git-scm.com/docs/gitattributes)
* [gitignore](https://git-scm.com/docs/gitignore)

## Branches
#### List branches ([git-branch](https://git-scm.com/docs/git-branch))
```
git branch [options]
```

options:
* `-v`: verbose
* `-vv`: verbose (prints linked worktree (if any) and upstream status)
* `-a`: list both remote branches and local branches
* `-r`: list only remote branches
* `--merged [commit]`: merged into the commit (commit defaults to HEAD)
* `--no-merged [commit]`: not merged into the commit (commit defaults to HEAD)

#### Create a local branch that tracks a remote branch
```
git switch <remote-branch-name>
```
```
git switch -c <local-branch-name> <remote>/<remote-branch-name>
```
```
git branch --track <local-branch-name> <remote>/<remote-branch-name>
```

#### Push branch to specified remote and set upstream tracking ([git-push](https://git-scm.com/docs/git-push))
```
git push -u <remote> <branch>
```

#### Delete remote branch
Delete remote branch ([git-push](https://git-scm.com/docs/git-push)):
```
git push -d <remote> <branch>
```

Delete corresponding local branch ([git-branch](https://git-scm.com/docs/git-branch)):
```
git branch -d <branch>
```

Fetch on other machines to propagate changes ([git-fetch](https://git-scm.com/docs/git-fetch)):
```
git fetch --all --prune
```

## Commits
#### Show commit info ([git-show](https://git-scm.com/docs/git-show))
```
git show [options] <commit>
```

options:
* `--format=<format>`: output format (`short`, `medium`, `full`, `fuller`, `raw`)
* Show diffstat:
  * `--stat`
  * `--name-only`
  * `--name-status`
  * `--dirstat-by-file`
* Show diff:
  * `-p`: show diff for regular commits
    * `-m`: + show diff for merge commits
  * `--dd`: show diff to first-parent for both merge and regular commits

## Diff
#### Check for conflict markers or whitespace errors ([git-diff](https://git-scm.com/docs/git-diff))
```
git diff --check [--staged]
```

## Fetching
#### Download objects and refs from another repository ([git-fetch](https://git-scm.com/docs/git-fetch))
```
git fetch [options] [remote]
```

options:
* `--all`: fetch all remotes
* `--prune`: before fetching, remove any remote-tracking references that no longer exist on the remote

## List files
#### List files EOL and text/binary autodetection status ([git-ls-files](https://git-scm.com/docs/git-ls-files))
```
git ls-files --eol [options]
```

options:
* default: index files
* `--other --exclude-standard`: untracked files only
* `--other --exclude-standard --ignored`: ignored files only

#### Find CRLF files in repository ([git-ls-files](https://git-scm.com/docs/git-ls-files))
```
git ls-files --eol | grep "i/crlf"
```

## Log
#### Show log ([git-log](https://git-scm.com/docs/git-log))
```
git log [options]
```

options:
* Commit info:
  * `--format=<format>`: output format (`short`, `medium`, `full`, `fuller`, `raw`)
  * Show diffstat:
    * `--stat`
    * `--name-only`
    * `--name-status`
    * `--dirstat-by-file`
  * Show diff:
    * `-p`: show diff for regular commits
      * `-m`: + show diff for merge commits
    * `--dd`: show diff to first-parent for both merge and regular commits
* `--all`: show all refs
* `--branches[=<pattern>]`: show all local branches
* `--merges`: show only merge commits
* `--no-merges`: do not print commits with more than one parent
* `--first-parent`: follow only the first parent
* `--graph`: draw a text-based graphical representation of the commit history
* `--boundary`: output excluded boundary commits
* `--topo-order`: topological order

## Maintenance
#### Clean the working tree (recursively, starting from the current directory) ([git-clean](https://git-scm.com/docs/git-clean))
```
git clean -f [items-to-remove] [--interactive] [--dry-run]
```

`items-to-remove`:
* default: untracked files
* `-d`: + untracked dirs
* `-x`: + ignored files
* `-X`: ignored files only

#### Cleanup unnecessary files and optimize the local repository ([git-gc](https://git-scm.com/docs/git-gc))
```
git gc
```

## Merging
[How to resolve conflicts](https://git-scm.com/docs/git-merge#_how_to_resolve_conflicts)

Fast-forward options:
* `--no-ff`
* `--ff` (fast-forward when possible)
* `--ff-only`

#### Undo merge commit ([git-reset](https://git-scm.com/docs/git-reset))
```
git reset --hard ORIG_HEAD
```

### Merging / Before merge state

#### Check fast-forward merge possibility ([git-merge](https://git-scm.com/docs/git-merge), [git-reset](https://git-scm.com/docs/git-reset))
```
git merge --ff-only <branch> && git reset --hard ORIG_HEAD
```

#### Preview merge ([git-merge](https://git-scm.com/docs/git-merge)):
```
git merge --no-commit --no-ff <branch>
```
then:
```
git merge --abort
```

#### View diff between `branch1` and its common ancestor with branch `branch2` ([git-diff](https://git-scm.com/docs/git-diff), [git-difftool](https://git-scm.com/docs/git-difftool))
```
git diff[tool] <branch2>...<branch1> [pathspec]
```

#### Show unique (not merged) commits in branch
Option 1 ([git-log](https://git-scm.com/docs/git-log)):
```
git log [--boundary --graph] [--left-only|--right-only] [--no-merges] [--stat|--name-status|-p] <branch-left>...<branch-right>
```

Option 2 ([git-log](https://git-scm.com/docs/git-log)):
```
git log [--no-merges] <branch1> ^<branch2>
```
```
git log [--no-merges] <branch2>..<branch1>
```

Option 3 ([git-cherry](https://git-scm.com/docs/git-cherry)):
```
git cherry -v [upstream [head]]
```

### Merging / Exploring existing merge commits

#### Show merge commit parents ([git-show](https://git-scm.com/docs/git-show))
```
git show --format=raw <commit>
```

#### Show merge commit changes
Show diff with all parents ([git-show](https://git-scm.com/docs/git-show)):
```
git show -p -m <commit>
```

Show diff with first parent ([git-show](https://git-scm.com/docs/git-show)):
```
git show --dd <commit>
```

Show diff with selected parent ([git-diff](https://git-scm.com/docs/git-diff), [git-difftool](https://git-scm.com/docs/git-difftool)):
```
git diff[tool] <commit>^n <commit>
```

Show conflict resolving changes ([git-show](https://git-scm.com/docs/git-show)):
```
git show --cc <merge-commit>
```
```
git show --remerge-diff <merge-commit>
```

#### View merge conflict resolving changes
Create merge tree ([git-merge-tree](https://git-scm.com/docs/git-merge-tree)):
```
git merge-tree <merge-commit>^1 <merge-commit>^2
```

then check merge result status:
```
case $? in 0) echo "OK";; 1) echo "CONFLICTS";; *) echo "ERROR";; esac
```

then show merge result changes (including conflicts) ([git-diff](https://git-scm.com/docs/git-diff), [git-difftool](https://git-scm.com/docs/git-difftool)):
```
git diff[tool] <merge-commit>^ <new-merge-tree>
```

then show conflict resolving changes ([git-diff](https://git-scm.com/docs/git-diff), [git-difftool](https://git-scm.com/docs/git-difftool)):
```
git diff[tool] <new-merge-tree> <merge-commit>
```

### Merging / Resolving conflicts

#### View changes during conflicts resolution ([git-diff](https://git-scm.com/docs/git-diff), [git-difftool](https://git-scm.com/docs/git-difftool))
Show conflicts ("dense-combined" diff, `--cc`):
```
git diff
```

Show "combined" diff:
```
git diff -c
```

Show staged changes:
```
git diff[tool] --staged
```

Show full diff:
```
git diff[tool] HEAD
```

Show conflict resolving changes:
```
git diff[tool] AUTO_MERGE
```

#### View commits touching conflicted paths ([git-log](https://git-scm.com/docs/git-log))
```
git log --merge [--boundary --graph] [--left-only|--right-only] [--stat|--name-status|-p] [pathspec]
```

#### View information about unmerged files ([git-ls-files](https://git-scm.com/docs/git-ls-files))
```
git ls-files [-u|--unmerged]
```

#### Overwrite the contents of the conflicted files ([git-checkout](https://git-scm.com/docs/git-checkout))
```
git checkout <options> <pathspec>
```

options:
* `--ours`: use "ours" file version
* `--theirs`: use "theirs" file version
* `--merge`: discard changes and re-create the original conflicted merge result (worktree and index)

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

## Restore
#### Restore files ([git-restore](https://git-scm.com/docs/git-restore))
```
git restore [options] <pathspec>
```

options:
* `-W`, `--worktree`: restore worktree from index (default)
* `-S`, `--staged`: restore index from HEAD

## Working trees
🚧 [git-worktree](https://git-scm.com/docs/git-worktree)

## Configuration 📌
[git-config](https://git-scm.com/docs/git-config)

#### Show configuration
```
git config --list --show-origin
```
```
git config --list --show-scope
```

#### Set options
```
# Username and email
git config <scope> user.name "<username>"
git config <scope> user.email "<email>"

# EOL conversion
git config <scope> core.eol native
git config <scope> core.autocrlf true

# Fast-forward and rebase policy
git config <scope> merge.ff false
git config <scope> pull.ff only
git config <scope> pull.rebase false

# Enable automatic fetch --prune
git config <scope> fetch.prune true
git config <scope> fetch.pruneTags true

# Log format
git config <scope> format.pretty oneline
git config <scope> log.abbrevCommit true

# Status format
git config <scope> status.short true
git config <scope> status.branch true

# Set Winmerge as diff tool
git config <scope> diff.guitool winmerge
git config <scope> difftool.prompt false
git config <scope> difftool.guiDefault true
git config <scope> difftool.winmerge.cmd "'C:\\path\\to\\WinMergeU.exe' -u -fl -wr -e \"\$LOCAL\" \"\$REMOTE\""

# Set TortoiseMerge as merge tool
git config <scope> merge.guitool tortoisemerge
git config <scope> mergetool.prompt false
git config <scope> mergetool.guiDefault true
git config <scope> mergetool.keepBackup false

# Proxy
git config <scope> http.proxy <proxy>
git config <scope> http.schannelcheckrevoke false

# Aliases
git config <scope> alias.st "status"
git config <scope> alias.br "branch -vv"
git config <scope> alias.ls "ls-files --eol"
git config <scope> alias.lsu "ls-files --eol --other --exclude-standard"
git config <scope> alias.lsi "ls-files --other --exclude-standard --ignored"
```

`<scope>` options:
* `--system`
* `--global`
* `--local`

`core.autocrlf` options:
* `input`: Git will convert CRLF to LF during commit (Linux, Windows)
* `true`: Git will convert CRLF to LF during commit and LF to CRLF during checkout (Windows)

Fast-forward policy options (for `merge.ff`, `pull.ff`):
* `false` (`--no-ff`)
* `true` (`--ff`, fast-forward when possible)
* `only` (`--ff-only`)
