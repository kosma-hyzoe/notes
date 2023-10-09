# Linux: Bash and shell scripts

* `unset`
*`.bash_profile` - read when bash is invoked as login shell
* `compgen -t` - show bash keywords
* `enable` - get builtins
* `export FOO=bar` - set as environment var (`env`).
	* `export -n FOO` - remove env var
	* `export -f FUN` - mark function for export

```bash
a=1
(
  a=2
)
echo $ a # prints 1

a=1
{
  a=2
}
echo $a # prints 2
```

## echo

* `-n` - no newline
* `-e` /`-E` - enable/disable escape chars


