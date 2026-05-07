# Commits Cheat Sheet

## Commit format
```
<type>(<optional scope>)[!]: <Subject> [...]
<BLANK LINE>
<optional body>
<BLANK LINE>
<optional footer>
```

### Type

#### Main types:

| Type | Change description |
| --- | --- |
| fix | Bug fix |
| feat | New or changed feature in API/UI |

#### Additional types:

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

### Footer

The `footer` should contain issue references and informations about **Breaking changes**

* The footer is an **optional** part, except if the commit introduce breaking changes
* Optionally reference issue identifiers (Closes #123, Fixes JIRA-456)
* **Breaking changes** must start with the word `BREAKING CHANGE:`
  * For a single line description just add a space after `BREAKING CHANGE:`
  * For a multi line description add two new lines after `BREAKING CHANGE:`

## Versioning

* **Breaking changes** incremented the **major** version
* **API relevant changes** (feat, fix) incremented the **minor** version
* **Else** increment the **patch** version
