# Regex

```
matches = re.search(substring, string)
matches.groups() # returns groups if specified in "(), ()" format
print(matches(1) + " " + matches(2))
```

```
username = re.sub(r'https://github.com/', "", url)

```

```
# assign and "ask if" at the same time
if matches := re.search(...):
    ...
```

* \d - decimal digit
* \D - not a decimal digit
* \w - alphanumeric + _
* \W - not a word character
* \s - whitespace
* \S - not whitespace
* . - any char EXCEPT NEWLINE

* ^ - matches the start
* $ - mathes the end
* [] - set of chars
* [^] - complementing the set / EXCEPT CHARS
* (com|edu) OR

* * - 0 or more
* + - 1 or more
* ? - 0 or 1
* {m} - m repetitions
* {m, n} - m-n repetitions

* re.IGNORECASE
* re.MULTILINE
* re.DOTALL

* (...) - a group
* (?:...) - non-capturing version
