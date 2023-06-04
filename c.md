# C

## Neat code bits

## TODO

* -L and -l compile flags
* section 4 beginners: linker errors, runtime errors, logic errors
* the extra exes @ 04/00
* makefiles
* symbolic constants vs function macros?
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
flags ^= OPTION_B; // turn off if on, on if off
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
* `ar[i]` is equivalnt to `*(ar+i)`

#### double pointers

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

#### function pointers

```c
/* define a function pointer typedef named func_ptr */
typedef int (*func_ptr)(int, int);
/* is already derefrenced within the declaration */
void ipp_append(int **ip) { (*ip)++ ;}
/* `&` is allowed, but not required. equivalent of `*str`/`str[0]` */
void (*fp)(int **) = &ipp_append;
```

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
#define BETWEEN(x, a, b) ((a) <= (x) && (x) <= (b))
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

## Library linking and loading

### Static linking

* Produces archives(.a, .lib). All library contents are copied to the ex.
  file. Faster, but heavier on disk space and memory use and slower to
  recompile. Created with `ar`, stored at `*/lib`.

### Dynamic Linking

* dynamic linking(shared object libraries, .so) - compiled separately. no need
  to recompile after software updates. linked with `ld`
* convention is to name files `lib_$(foo).so`
* `lld` - list all shared libraries of an executable

### Dynamic loading

* Load a lib at runtime. program behavior might change if lib not available.
* PAM (Pluggable Authentication Modules) - enables easy extension loading
* `<dlfcn.h>` - AP for opening lib, looking ub symbols, handling erros, closing
  lib. `dlopen(filename, flag)` where `flag` - `RTLD_LAZY` (resolve undefined
  symbols as parts of lib) or `RTLD_NOW` (resolve before dlopen() or fail).
* `dlerror()` - report dlopen(), dlsym(), dlclose() erros.

```c
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
/* NOT including math.h */

// gcc -o run main.c -ldl
int main()
{
    void *handle;
    double (*pow)(double, double) = NULL;


    handle = dlopen("/usr/lib/x86_64-linux-gnu/libm.so.6", RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }
    dlerror(); // clear the error code?

    pow = dlsym(handle, "pow");
    printf("%f\n", pow(3, 2));

    dlcose(handle);
}
```

## WIP

## Libs

### `assert.h`

* prints to stderr, invokes abort()
* `#define NDBUG //switch off runtime assertions`
* `static_assert(foo == 0, "foo is not true!)` - will check on compilation

### `stdlib.h`


```c
do {
    printf("new x? ");
    result = scanf("%d", &x);
    fflush(stdin);
} while (result == 0); /* junk inputs like 123abc will still work */
```

```c
do { /* better to use getline() or fgets() */
    printf("new x? ");
    result = scanf("%d%c", &x, &nextch);
    fflush(stdin);
} while (result == 0 || nextch != '\n');

```

```c
char name[20];
scanf("%19s", name); /* macro tricks to avoid hard-code uglyness? */
```

* `exit()` - flushes output streams, closes open strams, closes tmp files
  (`tmpfile()`).
* `atexit()` - call a function at exit. can register up to 32 functions.
* `abort()` - cause abnomral process termination ("fail hard, fail often"?)
  * raises SIGABRT
  * unsuccesful termination will be hinted
  * will dump core
  * atexit() are not called
  * does NOT flush streams since glibc 2.26
* `srand()` - called once before `rand()` calls. usually `srand(time(0))`
* memcpy() - no overlap, memmove() - allows overlap
* strdup() - `ptr2 = malloc(strlen(ptr1)+1); strcpy(ptr2,ptr1);` as opposed
  tostrcpy() - `while(*ptr2++ = *ptr1++);`

* time() - seconds from jan 1 1970
* ctmie() / asctime() - convert to readable date
* gmtime() - into UTC

* clock(), time(), ctime(), difftime(), asctime(), localtime(), gmtime()
* qsort()
* system()
* getenv()

### Abstract data types

* stack - push, pop, peek, size, isEmpty
* queue - fifo, enqueue, dequeue, peek, size
* binary tree - insert, delete, search, size
  * preorder, postorder, inorder
* Linked lists - pointer to a next node is called a link

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

### Interprocesses communication and signals

* process - a program in execution
* interprocess communication
  * pipes
  * signals (with a table of most common signals)
* example c code: ignoring a signal, sigaction(), `struct sigaction`
* use sprintf() and write() instead of printf() in forked processes
/,/
`ps`, `kill`
alarm() - raise SIGALARM after timeout
sigkill, sgabrt, sigstop - "unstopable"

```c
void signalHandler(int signum) {
    printf("Signal %d received.\n", signum);
    // Handle the signal here
}

int main() {
    sighandler_t previousHandler;

    // Associate SIGINT signal with signalHandler and store the previous handler
    previousHandler = signal(SIGINT, signalHandler);
    if (previousHandler == SIG_ERR) {
        printf("Error setting signal handler.\n");
        return 1;
    }

    // Rest of the program

    // Restore the previous signal handler if needed
    signal(SIGINT, previousHandler);

    return 0;
}
```

## Threads

### Misc threads notes

* creating a new thread is faster than creating a new process
* arg structs are commonly declared `typedef struct { int a; int b; } args_t;`
* remember to free result pointers
* if a threads opens a file with r privileges, other threads from this process
  have inherit the privs.

* `if(pthread_create(&pt,NULL,fun_t,NULL) != 0) perror("pthread_create");`

### Basics

`pthread`, short for POSIX threads, is an API for managing multiple threads in a
POSIX-compliant operating system. In Linux, it needs to be linked via the
`-lpthread` option.

Let's dive into some of the primary functions:

* `pthread_create()`: This function creates a new thread and returns its thread
id. The function takes four arguments: a pointer to a `pthread_t` variable
(which will be set to the ID of the created thread), a `pthread_attr_t` that
specifies attributes for the new thread (or `NULL` for default attributes), a
function to be executed by the new thread, and a void pointer for passing
arguments to the function. Here is an example:

  ```c
  pthread_t thread_id;
  int arg = 123;
  pthread_create(&thread_id, NULL, my_thread_func, &arg);
  ```

* `pthread_join()`: This function waits for a specific thread to finish. It
blocks the calling thread until the specified thread terminates. If the thread
has already terminated, the function returns immediately. It can also return the
exit status of the terminated thread if a non-null pointer is passed as the
second argument.

  ```c
  void *exit_status;
  pthread_join(thread_id, &exit_status);
  ```

* `pthread_exit()`: This function terminates the calling thread and returns a
value via `retval` that (if the thread is joinable) is available to another
thread in the same process that calls `pthread_join()`.

  ```c
  pthread_exit((void *) exit_status);
  ```

* `pthread_self()`: This function returns the ID of the calling thread. This can
be useful for debugging or for control structures that need to know the current
thread.

  ```c
  pthread_t this_thread_id = pthread_self();
  ```

* `pthread_detach()`: This function is used to ensure that system resources are
automatically released when the thread terminates, without needing another
thread to join with the terminated thread.

  ```c
  pthread_detach(thread_id);
  ```

* `pthread_attr_setstacksize()`: This function sets the stack size attribute of
the thread attributes object referred to by `attr` to `stacksize`.

  ```c
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setstacksize(&attr, PREFERRED_STACK_SIZE);
  pthread_create(&thread_id, &attr, my_thread_func, &arg);
  ```

* `pthread_equal()`: This function compares two thread identifiers. If the two
IDs are equal, the function returns a nonzero value; otherwise, it returns 0.

  ```c
  if (pthread_equal(thread_id1, thread_id2)) {
    // the two thread IDs are equal
  }
  ```

### Thread Synchronization

Multiple threads within a process share same files, **address space** and
global variables. Sync them, OR ELSE!

#### Mutex

Prevents **deadlocks, race conditions and shared address collisions**. When
a piece of code is executed by wrapping it with a lock/unlock of a mutex, only
one thread can execute that code at a time. In other words, it provides a
mechanism for multiple threads to mutually exclude each other.

Here are some of the primary functions:

* `pthread_mutex_init()`: This function initializes a mutex. The mutex should be
destroyed with `pthread_mutex_destroy()` when it is no longer needed.

  ```c
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);
  ```

* `pthread_mutex_lock()`: This function locks a mutex. If the mutex is already
locked, the calling thread will be blocked until the mutex is unlocked.

  ```c
  pthread_mutex_lock(&mutex);
  ```

* `pthread_mutex_unlock()`: This function unlocks a mutex.

  ```c
  pthread_mutex_unlock(&mutex);
  ```

* `pthread_mutex_destroy()`: This function destroys a mutex. The mutex should be
unlocked before being destroyed.

  ```c
  pthread_mutex_destroy(&mutex);
  ```

#### Condition Variable

Condition variables are another type of synchronization mechanism. They allow
threads to synchronize based upon the actual value of data. It is used in
conjunction with a mutex lock.

Here are some of the primary functions:

* `pthread_cond_init()`: This function initializes a condition variable.

* `pthread_cond_wait()`: This function blocks the calling thread until the given
condition variable is signaled or broadcasted. It must be called with the mutex
locked. It will automatically release the mutex while it waits. After signal is
received and thread is awakened, mutex is locked again and `pthread_cond_wait()`
exits.

* `pthread_cond_signal()`: This function unblocks at least one of the threads
that are blocked on the specified condition variable.

* `pthread_cond_broadcast()`: This function unblocks all threads currently
blocked on the specified condition variable.

* `pthread_cond_destroy()`: This function destroys a condition variable.

#### Semaphore

In some cases, we need to allow more than one thread to access the same resource
at once, but still limit the overall number. This is where the semaphore comes
in. Semaphores are an advanced form of mutex which allow multiple access.

Here are some of the primary functions:

* `sem_init()`: This function initializes a semaphore.

  ```c
  sem_t sem;
  sem_init(&sem, 0, initial_value);
  ```

* `sem_wait()`: This function locks a semaphore. If the semaphore value is
greater than zero, then the decrement operation is performed and the function
returns immediately. If the semaphore value is zero, then the call blocks until
it becomes possible to perform the decrement operation.

  ```c
  sem_wait(&sem);
  ```

* `sem_post()`: This function increases the value of a semaphore and wakes up a
blocked thread waiting on the semaphore, if any.

  ```c
  sem_post(&sem);
  ```

*

 `sem_destroy()`: This function destroys a semaphore.

  ```c
  sem_destroy(&sem);
  ```

#### Barrier

A barrier is a type of synchronization method in multithreading, where a thread
will stop at the barrier point and cannot proceed until all other threads reach
this barrier.

Here are some of the primary functions:

* `pthread_barrier_init()`: This function initializes a barrier with a count.

* `pthread_barrier_wait()`: This function blocks the calling thread until the
specified number of threads have called `pthread_barrier_wait()` specifying the
barrier.

* `pthread_barrier_destroy()`: This function destroys a barrier when it is no
longer needed.

These are some of the main methods used to synchronize threads. It's crucial to
carefully design and test any code involving thread synchronization, as improper
use can lead to difficult-to-detect errors, like deadlocks, where two or more
threads are waiting for each other to release a resource, causing all of them to
be stuck indefinitely.

## Temp

* servers and clients
