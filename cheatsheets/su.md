# Super user

## gpg

## fzf

* ctrl+r,
* alt+c - cd to selected dir
* ctrl+t


## misc

* `man 1 signal`

## `grep`

* -h - skip file names
* -l - print names only
* -n - prefix with line numbers
* `git grep`

## Unix

* `find . -type f -name '*.gz' -exec rm {} + `
* `find -name "*.sh" -exec chmod u+x {} \;`
* `-iname`, `-user`/`-perm`, `-perm`, `-size +1G`
* `find . -name "*.md" -exec grep "foo" {} +`
* `-exec`
  * `+` - will append files to a list, run command once
  * `\;` - send single command for each command

* `fdisk` exists.
* `whereis` exists
* `man file-hierarchy` exists.
* cat split-me.txt | tr ";" "\n"
* `|&` for piping 0 1 and 2
* `mkdir -p music/{rock/{punk,goth},classical/{baroque,early}}`
* `ls -1A`
* `grep -l`, `grep -n`

## Markdown

- [StackOverflow][] can be used to search for your problem and see if it has been answered already. You can also
ask and answer questions.
- [The C Programming][K&R] book by K&R is the original source of the language and is still useful today.

[stackoverflow]: http://stackoverflow.com/questions/tagged/c
[K&R]: https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628/


## C

* `for(i=1; text[i] = (char)toupper(text[i]) != '\0'; ++i);`
