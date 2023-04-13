## grep

## Basic piping

```
cat file.txt | grep word # find lines with "word"
grep word file.txt # same, but grep can do it alone
grep word file.txt > log.log # write to file 
grep word file.txt >> log.log # append to file
cat file.txt | grep word | less
> /dev/null # emulate forwarding to a null output
```

# Basics

* __ctrl + z__ - move running program in the background/suspend
* __ctrl + d__ - close terminal
* __ctrl+l / clear__ - clears the terminal
* !-2 - second last command
* !n - run the last command starting with 'n'

## Basic utils

* __whatis__ - simple info about the program
* __file__ - check file type
* __apropos__ - find apps related to a topic
* __pushd / popd__ - pop in and out of a directory
* __cat file file1__ - join files, *concatenate*

## Users

* __sudo -s__ - enter super user mode. quit with __exit__
* __su - joe__ - become super user as joe
* __su -__ - become root and head into root's home
* __users__ - display active users
* __id__ - display user info

