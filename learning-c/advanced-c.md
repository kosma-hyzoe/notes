# Advanced C notes

## Todo

* elaborate on storage classes
* section 3 beginners: linker errors, runtime errors, logic errors

## Storage classes

* auto - "within a block", only specified for extra clarity /overwriting
* extern - like global but doesn't allocate memory in declarations, only  in
  definition
* register - hint the compiler to store the ar in cpu register, not in ram,
  which increases speed
* static
  * in local vars - keep the var in existence
  * in global - restrict the scope to file where declared
  * in functions - like in global vars

Extern:

```c
// source1.c
#include <stdio.h>

// option one: declared 'globally'
extern int count; 

void increment(void) {
   // option two: in a function body. exclusive with option 1?
   extern int count; 
   count++;
}

int main() {
   increment();
   printf("The value of count is: %d", count);
   return 0;
}

// source2.c
#include <stdio.h>

int count = 0; // external variable definition
```

## Advanced Data Types

* const is sometimes preferred to define cause it's type-checked?
* `typedef char *String` - define type `String` equivalent to `char *`
* typedefs are 'bad' for structs, good for casting
* variable length arrays are not based according to Torvalds

Flexible array members needs to be allocated dynamically.
Less allocations, but debatable whether it's good practice...

```c
// sizeof(struct s) ignores the flexible array member
sptr = malloc(sizeof(struct s) + s * sizeof(int));
```

```c
`#ifdef __STC_NO_VLA__` 
  printf("VLA not supported\n");
#endifdef
```

## 