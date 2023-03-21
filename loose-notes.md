# Loose notes

## Python

* rounding with f"{n:.2f}"
* use pathlib
* io.StringIO() vs join?

```
# eh
def do_io_with_path(path: str):
	...
# better
def do_io_with_io(fp: typing.TextIO):
	fp.write("...")
```
