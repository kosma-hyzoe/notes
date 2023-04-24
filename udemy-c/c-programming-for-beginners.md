# C Programming For Beginners

## Misc

* \r -
* \a - alert

## Datatypes

  ### Bool

```c
/* bool */

/* c89 */
_Bool boolVar = 1;
/* c99 */
#include <stdbool.h>
bool voolVar = true;
```

### short, long unsigned

* char < short int < int < long int
* float < double < long double

```c
/* long constants? */
long double US_deficit_2017 = 1.325e+7L;
long double bazBar;
/* non-negative only. "extended accuracy"? */
unsigned int barbaz;
/* just for extra clarity */
signed int baz;
```

### enums

```c
/* these store ints under the hood */
enum primaryColor {red, yellow, blue};

/* u can explicitly assign the int values */
/* here up=0, down=1, left=10, right=11 */
enum direction {up, down, left = 10, right};


/* declare two primaryColor vars */
enum primaryColor blueColor, redColor;
redColor = red;
blueColor = blue;
```

## Bitwise

* & - bitwise AND, copies the bit if both operands have it
* | - bitwise OR
* ^ - XOR
* ~ - flip bits
* `>>/<<`  - move bits

## 
