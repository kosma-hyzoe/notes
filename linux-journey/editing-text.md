# Editing text

## Standard in, out and error

* 0, 1, 2 - stdin, stdout, sdterr

```bash
ls /error/evoking/path 2> hello.txt # redirect stderr
# redirect stderr and stdout
ls /err > hello.txt 2>&1
ls /err &> hello.txt
# just get rid of stderr
ls /err &> /dev/null
```

## Misc stdin/stdout processing

* head/tail
  * -n 11 - number of lines
  * -f - see what's added to a file (i.e. a log file) continously
* cut
  * -c - by character
  * -f - by column/field
  * -d - change delimeter
* paste -s - merges lines
* tr - translate one set of chars to another one, i.e. `tr a-z A-Z`

* env - show env variables
* expand/unexpand - change tabs to space and vice versa
* join - join files specifying fields/columns
* split - split file into multiple files(default: after exceeds 1000 chars)
