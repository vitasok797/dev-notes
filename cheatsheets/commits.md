# Commits Cheat Sheet

## Commit format

```
<type>(<optional scope>)[!]: <Description> [...]
<BLANK LINE>
<optional body>
<BLANK LINE>
<optional footer>
```

### Type

#### Main types
| Type | Change description |
| --- | --- |
| fix | Bug fix |
| feat | New or changed feature in API/UI |

#### Additional types
| Type | Change description |
| --- | --- |
| perf | Performance improvement |
| refactor | Code restructuring without behavior change |
| style | Formatting |
| test | Tests added/corrected |
| docs | Documentation only |
| build | Build tools, dependencies, versions |
| ops | DevOps, CI/CD, infrastructure, backups |
| chore | Anything else (initial commit, modifying .gitignore, ...) |

### Breaking change

A commit that has a footer `BREAKING CHANGE:`, or appends a `!` after the type/scope, introduces a breaking change.
A breaking change can be part of commits of any type

### Footer

The `footer` should contain issue references and informations about breaking changes

* The footer is an optional part, except if the commit introduce breaking changes
* Optionally reference issue identifiers (Closes #123, Fixes JIRA-456)
* Breaking changes must start with the word `BREAKING CHANGE:`
  * For a single line description just add a space after `BREAKING CHANGE:`
  * For a multi line description add two new lines after `BREAKING CHANGE:`

## Reverting

One recommendation is to use the revert type, and a footer that references the commit SHAs that are being reverted:
```
revert: description

Commits: 676104e, a215868
```

## Versioning

* **fix** or "**additional**" types: correlates with **PATCH** in Semantic Versioning
* **feat** type: correlates with **MINOR** in Semantic Versioning
* **Breaking changes**: correlates with **MAJOR** in Semantic Versioning

## Links

* [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)
* [Conventional Commits Cheatsheet](https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13)
* [(Habr) Как генерировать осмысленные коммиты. Применяем стандарт Conventional Commits](https://habr.com/ru/companies/yandex/articles/431432/)
* [(Reddit) Conventional Commits: A Standardized Approach to Commit Messages](https://www.reddit.com/r/git/comments/1jgi54x/conventional_commits_a_standardized_approach_to/)
* [Conventional Commits Guide: Rules, Tools and CI/CD Enforcement](https://www.deployhq.com/blog/conventional-commits-a-standardized-approach-to-commit-messages)
