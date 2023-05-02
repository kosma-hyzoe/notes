# Advanced C notes

## Todo

* elaborate on storage classes

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
