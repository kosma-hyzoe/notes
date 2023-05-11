# Advanced C notes

## Todo

* variadic funcs
* elaborate on storage classes
* bitwise oprations cheatsheet?
* preprocessor details
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

### Designated initializers

`int a[6] = {[4] = 29, [2] = 15};` or `int a[3] = {[4]29, [2]15}`
`int a[] = {[0 ... 9] = 1, [10 ... 99]= 2}`

## Type Qualifiers

* declaring constants with `static const` saves the hassle of differentiation
  between declaration and definition, but copies the data across all the files
* volatile - "suppress optimization, this will be changed 'unexpectedly'". For:
  * memory-mapped peripheral registers
  * global variables modified by an interrupt service routine
  * global vars accessed by multiple task within a multi-threaded app
* const and volatile is NOT mutually exclusive!
* restrict - "this pointer is the only reference to that value thru its scope"
  * `int * restrict intPtr;`

## Bit Manipulation

### Bitmasks

* bitmask - data used for bitwise operations

```c
#define MASK 2 // binary 0b10
int flags = 303;
// check and use only the bit at 2nd position, rest is 'masked'
flags = flags & MASK;
// turn on the bit at position 2, leave the rest unchanged
flags = flags | MASK;
if ((flags & MASK) == MASK) printf("foobar\n"); // check if mask bit is on
```

* XOR to turn off if on and vice versa

## Advanced function concepts

* variadic fuctions - variable n of arguments
* at least one mandatory arg

```c
#include <stdarg.h>

int sum(int count, ...) {
    int result = 0;
    va_list args;
    // va_list copy;
    // va_copy(args, copy);
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int arg = va_arg(args, int);
        result += arg;
    }
    va_end(args);
    return result;
}

int main() {
    printf("%d\n", sum(3, 1, 2, 3)); // output: 6
    printf("%d\n", sum(5, 1, 2, 3, 4, 5)); // output: 15
    return 0;
}
```

* inline functions should be but in a header in multi file programs
  (it's usually a bad idea to put such logic in a header, this is an exception)
* `_Noreturn` hints the user and the compiler(may boost efficiency) that the
  function doesn't return the control

## Unions

* all members share the same memory. the memory is allocated for the biggest
  member.

```c
struct myStruct {
  int someInt;
  union {
    float someFloat;
    char someChar;
  };
};

// accessing unions in structs
struct myStruct myVar;
myVar.someInt = 10;
myVar.someFloat = 3.14;

// declaring a struct with a table/array of unions
struct myTable {
  union {
    int myInt;
    float myFloat;
  } entries[10];
};

// designated initializers
union myUnion u = {.f = 3.14};
```

## Preprocessor

* deletes comments, includes stuff, expands macros
* `#ifdef`/`#ifndef` are short for `#if defined(foo)`/`#if !defined(foo)`

```c
// gcc -D MY_MACRO=1 myprogram.c -o myprogram
int main(){ }
    #ifdef MY_MACRO
        printf("MY_MACRO is defined.\n");
        #if MY_MACRO == 1 && FOO == "BAR"
            printf("It's equal to 1.\n");
        #endif
    #endif
#if MY_MACRO == 1
  printf
```
