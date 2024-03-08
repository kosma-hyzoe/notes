# Bash

## Misc

* `cat <(echo foo)`
* `read -p "some prompt" bar`
* `rm -f $0 # autodelete the script`
* `my_array=("foo" "bar")`
* `alias` - list all aliases
* `cat << EOF` - create a temp file (HereDoc)
* `wc <<< "redirect a temp string"`

## Pipes and redirects

* redirections redirect file streams, pipes redirect output trees
*  `./install_package.sh > file.txt 2>&1` is an equivalent of
   `./install_package.sh > file.txt > file.txt`

## Operators

* `;` - chain commands together, one after another
* `&&` - like `;`, but executes only if the first one succeeds
* `||` - only if it fails
* `&` - start the first command, start the second without waiting for it to end

```bash
letters=("A""B""C""D""E")
b=${letters:0:2}
```

## Conditionals

### File ops

```bash
[[ -a ${file} ]] # exists (regardless of type - even dir and FIFO)
[[ -b ${file} ]] # exists and is a block special file(?)
[[ -c ${file} ]] # exists and is a char special file(?)
[[ -d ${file} ]] # exists and is dir
[[ -e ${file} ]] # exists (is regular file or symbolic link)
[[ -f ${file} ]] # exists and is regular file
[[ -h ${file} ]] # exists and is symbolic link
[[ -r ${file} ]] # exists and is readable
[[ -s ${file} ]] # exists and has size > 0
[[ -w ${file} ]] # exists and is writable
[[ -x ${file} ]] # exists and is executable
[[ -L ${file} ]] # exists and is symbolic link
```

### String expressions

```bash
[[-v ${varname} ]] # true if variable varname is set
[[ -z ${string} ]] # len is zero
[[-n ${string} ]] # len is non zero
[[ $string1 == $string2 ]]
[[ $string1 != $string2 ]]
[[ $string < $string1 ]] # sorts before string1 lexicographically
[[ -z $string1 ]] # is empty
[[ -n $string1 ]] # is not empty

```

### Arithmetic ops

```bash
[[ $arg1 $a -eq $b]] # equal
[[ $a -ne $b]] # not equal
[[ k -lt $b]] # less than
[[ $a -le $b]] # less or equal
[[$a -gt $b]] # greater
[[ $a -ge $b]] # greater or equal
```

### Exit status ops

```bash
[[ $? -eq 0 ]] # successful
[[ $? -gt 2 ]]
```

## Loops

`continue [n]` tells your bash script to stop the current iteration of the loop and
start the next iteration. The `[n]` argument is optional and can be greater than
or equal to 1. When `[n]` is given, the n-th enclosing loop is resumed. continue
1 is equivalent to continue.

### Switch case

```bash
case $some_variable in
pattern_1) # case patterns must end with ')'
  commands
  ;;                   # cases must end with ';;'
pattern_2 | pattern_3) # multiple patterns can be used, divided by '|'
  commands
  ;;
*) # default
  default_commands
  ;;
esac

```

### For

```bash
for var in ${list}
do
  your_commands
done

users="devdojo bobby tony"
for user in ${users}
do
  echo "${user}"
done

for num in {1..10}
do
  echo ${num}
done
```

### While

```bash
while [ your_condition ]
do
  your_commands
done

until [[ your_condition ]] # 'while not true'
do
  your_commands
done

counter=1
while [[ $counter -le 10 ]]
do
    echo $counter
    ((counter++))
done
```

## Color selection

```bash
green='\e[32m'
blue='\e[34m'
clear='\e[0m'

ColorGreen() {
  echo -ne $green$1$clear
}
ColorBlue() {
  echo -ne $blue$1$clear
}

echo -ne $(ColorBlue 'Some text here')
```

## Menus

```bash
read a
case $a in
1) memory_check ; menu ;;
2) cpu_check ; menu ;;
3) tcp_check ; menu ;;
4) kernel_check ; menu ;;
5) all_checks ; menu ;;
0) exit 0 ;;
*) echo -e $red"Wrong option."$clear;
WrongCommand;;
esac
```
