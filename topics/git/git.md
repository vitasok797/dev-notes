# Git

⭐ [Cheat Sheet](git-cheat-sheet.md)

## Tutorials
* [Git book](https://git-scm.com/book/ru/v2)
* [LearnGitBranching](https://learngitbranching.js.org)
* [Atlassian tutorials](https://www.atlassian.com/git/tutorials)
* [Шпаргалка](https://training.github.com/downloads/ru/github-git-cheat-sheet/)

## Articles
* [(Habr) Ещё раз о «Mercurial против Git» (с картинками)](https://habr.com/ru/articles/123700/)
* [(Habr) Зачем пользователи GIT-а редактируют свои коммиты](https://habr.com/ru/articles/179045/)
* [(Habr) Subversion vs. Git: Развенчивание мифов о развенчивании мифов](https://habr.com/ru/articles/320704/)
* [(Habr) Git happens! 6 типичных ошибок Git и как их исправить](https://habr.com/ru/companies/flant/articles/419733/)
* [(Habr) Безболезненное разрешение Merge конфликтов в Git](https://habr.com/ru/articles/323234/)
* [(Habr) Git. Скачем между ветками как древесные лягушки](https://habr.com/ru/articles/826260/)
* [(Habr) Git снизу вверх](https://habr.com/ru/companies/intel/articles/344962/)

## Branching
* [(Habr) Удачная модель ветвления для Git](https://habr.com/ru/articles/106912/)
* [(Habr) Пожалуйста, перестаньте рекомендовать Git Flow](https://habr.com/ru/companies/flant/articles/491320/)
* [A succesful Git branching model considered harmful](https://barro.github.io/2016/02/a-succesful-git-branching-model-considered-harmful/)
* [Trunk-Based Development site](https://trunkbaseddevelopment.com/)
* [What is Trunk-Based Development?](https://paulhammant.com/2013/04/05/what-is-trunk-based-development/)
* [GitHub Flow](https://docs.github.com/en/get-started/using-github/github-flow)
* [GitHub Flow](https://githubflow.github.io/)
* [(Habr) GitLab Flow](https://habr.com/ru/companies/softmart/articles/316686/)
* [(Habr) Бранч-стратегии при разработке в Git](https://habr.com/ru/companies/itglobalcom/articles/535524/)
* [(Habr) Работа с Git без использования локальных веток](https://habr.com/ru/articles/269671/)
* [(Habr) Собираем свой flow для git с нуля](https://habr.com/ru/articles/493866/)
* [Git branching strategies](https://docs.aws.amazon.com/prescriptive-guidance/latest/choosing-git-branch-approach/git-branching-strategies.html)
* [Comparing Git workflows](https://www.atlassian.com/git/tutorials/comparing-workflows)

### Branching / Feature flags
* [Feature Toggles (aka Feature Flags)](https://www.martinfowler.com/articles/feature-toggles.html)
* [(Habr) Стратегия ветвления ThreeFlow](https://habr.com/ru/companies/infopulse/articles/345826/)
* [(Habr) Feature Flags и фабрика ПО](https://habr.com/ru/articles/543420/)
* [(Habr) Укрощение feature-флагов](https://habr.com/ru/companies/hh/articles/580736/)

## Merge
* [(StackOverflow) How do I safely merge a Git branch into master?](https://stackoverflow.com/questions/5601931/how-do-i-safely-merge-a-git-branch-into-master)

## Rebase
* [(Habr) Руководство по Git. Часть №2: золотое правило и другие основы rebase](https://habr.com/ru/companies/vk/articles/493818/)
* [(Habr) Чем опасен rebase, или как получилось, что 2*3=5](https://habr.com/ru/articles/179123/)
* [(Habr) Почему нужно перестать использовать Git rebase](https://habr.com/ru/companies/vk/articles/340558/)
* [(Habr) Золотое правило git rebase](https://habr.com/ru/companies/otus/articles/352640/)
* [(Habr) Введение в Git Merge и Git Rebase: зачем и когда их использовать](https://habr.com/ru/articles/432420/)
* [(Habr) Git Rebase: руководство по использованию](https://habr.com/ru/articles/161009/)
* [Правим историю Git с помощью интерактивного rebase](https://alexeykalina.github.io/technologies/git-rebase-interactive.html)

## Configuring Git
* Setting
  [username](https://docs.github.com/en/get-started/git-basics/setting-your-username-in-git)
  and
  [email](https://docs.github.com/en/account-and-profile/setting-up-and-managing-your-personal-account-on-github/managing-email-preferences/setting-your-commit-email-address)
* Line endings:
  * [Configuring Git to handle line endings](https://docs.github.com/en/get-started/git-basics/configuring-git-to-handle-line-endings)
  * [Git. Символы конца строки EOL](https://tokmakov.msk.ru/blog/item/710)
  * [Git attributes (checking_out_and_checking_in)](https://git-scm.com/docs/gitattributes#_checking_out_and_checking_in)
* [Ignoring files](https://docs.github.com/en/get-started/git-basics/ignoring-files)

<details>
<summary>💡 Show configuration</summary>

```
git config --list --show-origin
git config --list --show-scope
```
</details>

<details>
<summary>💡 Setting username and email</summary>

```
git config --global user.name "YOUR_USERNAME"
git config --global user.email "YOUR_EMAIL"
```
</details>

<details>
<summary>💡 Disabling fast-forward merge</summary>

```
git config --global merge.ff false
git config --global pull.ff true
```
</details>

## GUI Tools
* [Windows GUI Clients](https://git-scm.com/downloads/guis?os=windows)
* [(Habr) GUI для Git: подборка популярных решений](https://habr.com/ru/articles/741016/)
* [(Habr) Git — сравнение Visual Studio 2022 с MeGit/EGit и SourceTree](https://habr.com/ru/companies/ruvds/articles/683576/)
* [(Habr) Текущее состояние инструментов. Взгляд пользователя (2011)](https://habr.com/ru/articles/112648/)
* GUI Clients:
  * [Sourcetree](https://www.sourcetreeapp.com/)
  * [Git Extensions](https://gitextensions.github.io/)
  * [MeGit](https://github.com/eclipsesource/megit)
  * [TortoiseGit](https://tortoisegit.org/)

## Video
* [(Youtube) Git. Большой практический выпуск](https://www.youtube.com/watch?v=SEvR78OhGtw)
* [(Youtube) So You Think You Know Git](https://www.youtube.com/watch?v=aolI_Rz0ZqY)
* [(Youtube) Git PULL vs FETCH](https://www.youtube.com/watch?v=T13gDBXarj0)
* [(Youtube) Never* use git pull](https://www.youtube.com/watch?v=xN1-2p06Urc)

## Var
* [(StackOverflow) What's the difference between git clone --mirror and git clone --bare](https://stackoverflow.com/questions/3959924/whats-the-difference-between-git-clone-mirror-and-git-clone-bare)
* [(StackOverflow) How do I clone a subdirectory only of a Git repository?](https://stackoverflow.com/questions/600079/how-do-i-clone-a-subdirectory-only-of-a-git-repository)
