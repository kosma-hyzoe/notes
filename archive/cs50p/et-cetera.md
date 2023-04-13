# Et Cetera

## Typing

`number: int = int(input("Number: "))`

## argparse

`parser = argparse.ArgumentParser(description="foobar")`

## Misc

* `yield` - generates values "one by one"
* `first, _ =input("What's your name? ").split(" ")`
* `**coins` - unpack dictionary(as arg1=value1, arg2=value2)
* `**kwargs` - "auto dictionary"

```
# [word.upper()  for word in words]
uppercased = map(str.upper, words)
```

```
def is_gryffindor(s):
    return s["house"] == "Gryffindor"

    gryffindors = filter(is_gryffindor, students)
```

```
for i, foobar in enumerate(["foo", "bar", "foofoo", "barbar"]):
    print(i + 1, foobar)
```


