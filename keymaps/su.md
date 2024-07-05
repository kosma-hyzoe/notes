# Super user

New shortcuts and features to memorize and learn regularly. If it's here it
hasn't become "obvious", an instinct, yet.

## gpg

## fzf

* ctrl+r, alt+c, ctrl+t

## Lua

* `"~=" == "!="`

```lua
local nums = { 1, 2, 3 }
table.insert(nums, 4)
for i = 1, #nums do --[['#' - number of colors ]] end

local dict = {
  ["key1"] = 1,
  ["key2"] = 2
}
print(dict["key1"])
for k,d in pairs(dict) do end
dict["key1"] = nil
dict["key2"] = 3

math.abs(-1)
math.ceil(1.2) -- 2
math.floor(1.2) -- 1

require("mymodlue")
```

## misc

* `man 1 signal`

## `grep`

* -h - skip file names
* -l - print names only
* -n - prefix with line numbers
* `git grep`

## Unix

* `fdisk` exists.
* `man file-hierarchy` exists.
* cat split-me.txt | tr ";" "\n"
* `|&` for piping 0 1 and 2
* `mkdir -p music/{rock/{punk,goth},classical/{baroque,early}}`
* `find . -type f -name '*.gz' -exec rm {} + `
* `chmod` files recursively: `find -name "*.sh" -exec chmod u+x {} \;`
* `ls -1A`
* `grep -l`, `grep -n`
* `find . -name "*.md" -exec grep "foo" {} +`

## Markdown

- [StackOverflow][] can be used to search for your problem and see if it has been answered already. You can also
ask and answer questions.
- [The C Programming][K&R] book by K&R is the original source of the language and is still useful today.

[stackoverflow]: http://stackoverflow.com/questions/tagged/c
[K&R]: https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628/


## C

* `for(i=1; text[i] = (char)toupper(text[i]) != '\0'; ++i);`
