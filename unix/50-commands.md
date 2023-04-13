# Top 50 Linux Commands

Source: ["The 50 Most Popular Linux & Terminal Commands"](https://www.youtube.com/watch?v=ZtqBQ68cfJc) @ FreeCodeCamp's YT channel

## Misc


## stdin/stdout processing

* wc - word count (-l for lines, -w for words, -c for bytes)
* nl - number lines
* sort (-n/numbers, -r/reverse, -u/unique)
* uniq - omit repeated, adjacent-only(by default) lines 
  * -u - duplicate only
  * -c - count ocurrences
* tee - read input, write output and files

### grep

* `grep [options] pattern [file]`, reads from stdin if no file is specified

* -i - ignore case
* -r - recursive
* -v - select non-matching lines
* -n - print line numbers
* -c - print only the count of matching lines

## expansions

* ? - exactly one letter
* \*.{txt,md,py}
* 
