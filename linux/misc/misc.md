## grep

Basic piping:
```
cat file.txt | grep word # find lines with "word"
grep word file.txt # same, but grep can do it alone
grep word file.txt > log.log # write to file 
grep word file.txt >> log.log # append to file
cat file.txt | grep word | less
> /dev/null # emulate forwarding to a null output
```

