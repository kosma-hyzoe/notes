# Theory part 1

## Git

There are system, local(repository) and global(user) configs. The system ones override
global, local overrides system.

## Git file statuses

* modified
* unmodified
* staged
* deleted


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


## Jenkins

discard builds **older than OR when there are more than**

### Build triggers

* manual
* after other build
* on a vcs push
* via api
* with cron expressions

### CRON

* m / min
* h / hour
* dom / day of month
* mon / month
* dow / day of week

* H - random over range (spread the load evenly)
* \* - all
* ? - any
* '-' - range
* , - multiple values
* / - increments(ie. `5/15 * * * *` - every )
* \# - "N-th"
* W - weekday
* L - kast


* The H symbol can be used with a range. For example, H H(0-7) * * * means some time between 12:00 AM (midnight) to 7:59
AM. You can also use step intervals with H, with or without ranges.

