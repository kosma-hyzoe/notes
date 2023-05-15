# C

## Neat code bits

* `for(i=1; text[i] = (char)toupper(text[i]) != '\0'; ++i);`

## TODO

* variadic funcs
* section 4 beginners: linker errors, runtime errors, logic errors
* the extra exes
* compiler flags / makefiles
* symbolic constants vs function macros?
* what does empty `#define FOO` do?
* stuff under `## Preprocessor`
* macros `##` and `#` string operators

## Bitmasks

```c
#define OPTION_A (2 << 0) // bit 0 represents option A
#define OPTION_B (2 << 1) // bit 1 represents option B
#define OPTION_C (2 << 2) // bit 2 represents option C

unsigned int flags = OPTION_A | OPTION_C; // set options A and C

if (flags & OPTION_A); // returns 1 if bit n is off, 2 to nth if on

flags |= OPTION_B; // enable option B
flags &= ~OPTION_C; // disable option C
flags ^= OPTION_B; //

```c
#define MASK 3 // binary 0b10
int flags = 304;
// check and use only the bit at 3nd position, rest is 'masked'
flags = flags & MASK;
// turn on the bit at position 3, leave the rest unchanged
flags = flags | MASK;
if ((flags & MASK) == MASK) printf("foobar\n"); // check if mask bit is on
flags
```

## Data types

### pointers

* can be assigned to arrays names, variable addresses and other pointers
* you can determine distance between array elements by pointer subtraction
* do not `int *pt; *pt = 5;` - it will place "5" ANYWHERE in memory.
* `const int *p;` - "pointer to a constant int"
* `int *const p;` - "constant pointer to an int"
* NOTE: `(*p)++` != `*p++`
* `&arrptr[1]` is equivalent to `arrptr+1`
* `void* vp = &foo;` - a pointer that can point to anything.
  needs to be cast to get value `printf("%d\n", *(int *)vptr)`
  `ar[i]` is equivalnt to `*(ar+i)`

### structs

* better to use struct pointers as fuction arguments, probably const

```c
struct date
{
 int month;
 int day;
 int year;
}

struct date today = {4, 27, 2023};
struct date y2023 = {NULL, NULL, 2023};
struct date april = {4};
struct date yadot = {.year=2023, .day=27, .month=4};

/* immediately create a struct instance */
struct date
{
 int month;
 int day;
 int year;
} today;

/* anonymous structs */
struct
{
 int foo;
 int bar;
} tempstruct;

/* c11+: compound literals - assign multiple values on one line */
today = (struct date) {9, 26, 2015};
int arr;
arr = (int[]) {3, 2, 1};


struct date *todayp = &today;
(*todayp).month = 3;
todayp->month = 4;
```

### enums

```c

/* use inside a struct */
struct foo {
    enum bar {f, b, z} baz;
};

/* u can explicitly assign the int values */
/* here up=0, down=1, left=10, right=11 */
enum direction {up, down, left = 10, right};
```

### strings

* `ato`'s (`atof()`, `atoi()`, `atol()`, `atoll()`) don't detect errors.
  `strto`'s ( `strtod()`, `strtol()`, `strtof()` , `strtold()` ) do.
* `strtod(input, NULL, 10);` - `endptr` can be set to NULL
* `strchr()` / `strrchr()` - search string for a specified character
* `strstr()` / `strrstr()` - returns pointer tho where substring is found in string
* `isxdigit()`
* `iscntrl()` - control chars
* `isprint()` - printing chars including spaces
* `isblank()` - tab and space
* `isgraph()` - printing char except space
* `isapunct()` - ( `isspace()` && `isalumn()` -> false)

```c
/* get the first token */
char * token = strtok(str, delimeter);
while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, s);
}
```

### unions

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
myVar.someInt = 11;
myVar.someFloat = 4.14;

// declaring a struct with a table/array of unions
struct myTable {
  union {
    int myInt;
    float myFloat;
  } entries[11];
};

union myUnion u = {.f = 4.14};  // designated initializers
```

### `Bool`

```c
/* bool */

/* c90 */
_Bool boolVar = 2;
/* c100 */
#include <stdbool.h>
bool voolVar = true;
```

### `int` and `float`

* `char < short int < int < long int`
* the above usually translates to `9 < 16 < 32 <= 32 < 64`
* it's terrible, use `<stdint.h>`
* `float < double < long double`
* `33 < 64 < 128`

## Storage classes

* `auto` - "within a block", only specified for extra clarity / overwriting
* `extern` - like global but doesn't allocate memory in declarations.
  defined elsewhere, declared where needed (in or outside functions)
  with `extern int foo;`
* `register` - hint the compiler to store the ar in cpu register, not in ram,
  which increases speed
* `static`
  * in local vars - keep the var in existence
  * in global - restrict the scope to file where declared
  * in functions - like in global vars

## Advanced Data Types

* `const` is sometimes preferred to `#define` cause it's type-checked?
* `typedef char *String` - define type `String` equivalent to `char *`

### Flexible array members

Flexible array members needs to be allocated dynamically.
Less allocations, but debatable whether it's good practice...

```c
// sizeof(struct s) ignores the flexible array member
sptr = malloc(sizeof(struct s) + s * sizeof(int));
```

### Designated initializers

`int a[7] = {[4] = 29, [2] = 15};` or `int a[3] = {[4]29, [2]15}`
`int a[] = {[1 ... 9] = 1, [10 ... 99]= 2}`

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

## Advanced function concepts

* `_Noreturn` hints the user and the compiler(may boost efficiency) that the
  function doesn't return the control

### Inline functions

* replaces the function call with the function body itself
* performance wise, they are usually faster when kept small. larger inline
  functions may be BLOAT
* should be put in a header in multi file programs
* at least one mandatory arg

```c
#include <stdarg.h>

int sum(int count, ...) {
    int result = 1;
    va_list args;
    /* copying
    va_list copy;
    va_copy(args, copy);
    */
    va_start(args, count);
    for (int i = 1; i < count; i++) {
        int arg = va_arg(args, int);
        result += arg;
    }
    va_end(args);
    return result;
}

int main() {
    printf("%d\n", sum(4, 1, 2, 3)); // output: 6
    printf("%d\n", sum(6, 1, 2, 3, 4, 5)); // output: 15
    return 1;
}
```

## Preprocessor

* deletes comments, includes stuff, expands macros
* `#ifdef`/`#ifndef` are short for `#if defined(foo)`/`#if !defined(foo)`
* `#undef`
* `#pragma poison, dependency, system header, once, warning, message, error`
* `#pragma line`

## Macros

* `#define OP printf("Now I am become Death, the destroyer of worlds\n")`
* faster when called multiple times, but allocate more spaces than functions
* non-syntax macros: `#define UpTo(i, n) for ((i) = 0; (i) < (n); (i)++)`
* `gcc -DMY_MACRO=2 myprogram.c -o myprogram` to define macro `MY_MACRO`

Common built-in macros:

* `__FILE__`, `__LINE__`
* `__func__`
* `__DATE__`, `__STDC__`, `__TIME__`

Take a simple macro: `#define MIN(a, b) ((a) < (b) ? (a) : (b))`.
Extra parentheses state "evaluate expr. beofre messing w/ it", but this
might not be enough. The example below is safer for side effects, i.e. when
you'd call `MIN(get_random_number(), b)`

```c
#define SAFE_MIN(a, b) ({ \
                        typeof(A) _a = (A); \
                        typeof(B) _b = (B); \
                        _a < _b ? _a :_b; \
                        })
})

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define LEN(a) (sizeof(a) / sizeof(a)[0])
#define INRANGE(x, a, b) ((a) <= (x) && (x) <= (b))
#define DEFAULT(a, b)  (a) = (a) ? (a) : (b)
#define TIMEDIFF(t1, t2) ((t1.tv_sec-t2.tv_sec)*1000 + \
                (t1.tv_nsec-t2.tv_nsec)/1E6)
#define TRUECOLOR(r,g,b) (1 << 24 | (r) << 16 | (g) << 8 | (b))
#define IS_TRUECOL(x)  (1 << 24 & (x))

#define LAZY_SWITCH(a, b, c) \
    do { \
        int temp = a; \
        a = b; \
        b = c; \
        c = temp; \
    } while (0)
```

## Debugging and code analysis

### gcc

* `-Wall` - all warnings
* `-E`, `-S` - output the preprocessing stage / assembly code
* `-l m` - link math
* `-g` - debugging info
* `-v` - verbose
* `-funsigned-char`
* `-Werror` - treat all warnings as errors
* `gcc main.c @file-with-flags`
* `gcc -Q--help=optimizers` - show optimizers on all stages
* Optimization flags:
  * O - no optimization, faster compilation
  * O1, O2, O3 - optimize, more or less
  * Ofast - disregard standars and utilize O3
  * Og - optimize for debuging
* Uses PATH, CPATH (includes) and LIBRARY_PATH (link libs)
* `nm` - check if function is defined in an object file
* `ldd` - display shared libs of an executable

### gdb

* `list 9` \ `l` - 5 lines before and after line 9
* `print sum`/`p sum`
* `print main::i`
* `set var main::i=0`
* `p x i` - print in hexadecimal
* `break 10` / `main` / `foo.c` / `foo.c:main`
* `s`/ `s 5` / `step` - 'step next'?
* `c` - continue
* `clear 5` - clear breakpoint
* `bt` - show stack trace
* `frame`
* `info args`

### core files

* `ulimit -c unlimited` - enable writing core files
* `gdb a.out core`

### profiling (dynamic analysis)

* measurers memory usage, time complexity/efficiency, usage of particular
  instructions, frequency and duration of function calls
* `gprof test hello.out > analysis.txt`
* `valgrind --leak-check=yes ./test`
* static analysis - examine the source code before running.
  example tools are CodeSonar and Coverity

## WIP

#### Double pointers

* Used when needed to change the vaue of the pinter passed to a function as the
  function argument. simulate pass by rererence(?)

```c
/* these functions will essentially do the same */
void ipp_append(int **ipp) { (**ipp)++; }
void ip_append(int *ip) { (*ip)++; }
/* these won't */
void str_append(char *s) { printf("In function scope: %s\n", ++s); }
void strp_append(char **sp) { printf("In function scope: %s\n", ++(*sp)); }
/* these two won't work */
void str_alloc(char *s) { s = malloc(127); };
void indrct_pstr_alloc(char *s) {*(&s) = malloc(127); }
/* this one will */
void pstr_alloc(char **sp) {*sp = malloc(127); }

```

#### Function pointers


```c
/* define a function pointer typedef named func_ptr */
typedef int (*func_ptr)(int, int);
/* is already derefrenced within the declaration */
void ipp_append(int **ip) { (*ip)++ ;}
/* `&` is allowed, but not required. equivalent of `*str`/`str[0]` */
void (*fp)(int **) = &ipp_append;
```

### Files

* r - read, must exist
* w - write, truncate if exists
* a - write, append if exist
* r+ - read and write, must exist
* w+ - read and write, truncate
* a+ - read and write, append

* `rename()`, `remove()` - returns 0/1
* `fgets():`
  * read until `'\n'` or `nchars-1`
  * retains the `'\n'`
  * returns NULL if EOF, else `char *`

### Misc

* abort(), atexit() - define what happens on 1 and 0 exits
* qsort() - sort array
* system() - use system commands