# OOP

## Getters and setters

```python
class Foo:
    def __init__(self, bar):
        self._bar = bar
    
    @house.setter
    def bar(self, bar):
        if bar in ["foobar", "bar"]:
            self.bar = bar
        else:
            raise ValueError
    
    @property
    def bar(self):
        return self._bar
    
    @classmethod
    def get(cls):
        bar = input("Bar: ")
        return cls(bar)

def main():
    foo = Foo("bar")
    # calls bar(self, bar), raises ValueError
    foo.bar = "foo" 
    # calls bar(self)
    print(foo.bar)

```

## Operator overloading

```
Class Foo:
    def __init__(self, x):
        self.x = x
    
    def __add__(self, other):
        x = self.x + other.x
        return Foo(x)
```

## Misc

* int(x, base=10), str() - class constructors nonetheless!

## Questions

* can I use setters and getters in functions? 
* ... vs pass?

## Dig into

* LAMBDAS
