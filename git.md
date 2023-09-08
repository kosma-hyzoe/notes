# Git

## Questions

* `--depth=1`?
* keep git from overridding ln?
* remove from repo without removing local files
* ogólne zasady

## Misc

* `git diff` , `--cached`
* `git restore` - restore all local changes, with flags like diff
* `git log -grep`, `-author`
* git merge z gałęzi docelowej!
* git merge ---continue ~= git commit
* fast-forward merge - point dest branch to a newer branch

## Git file statuses

* modified
* unmodified
* staged
* deleted

* working (modified, untracked), stage, 

### resets

* --soft - uncommit
* --mixed - uncommit + unstage
* --hard - uncommit + unstage + delete

### pull vs fetch

* pull = fetch + merge

* `git config --list` - (local first, then global, then system)

```
git config user.name # shows the value of the "user" setting
git config --list
git log -n 5
```

* git diff master...feature
* git diff master
* git branch - display branches
* git checkout -b - switch to a new branch


* git remote add origin *link to repo*
* git remote -v - show connected remote repositories
* git push -u origin master - set upstream for the future and push
^
* git commit -m message -m description

* git reset --hard *commit id*
* git reset --hard origin/master


