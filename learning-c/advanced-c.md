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
