# WS Academy

## Misc

* 32-bit architecture on the exam

## Number representation, bitwise

* `int4b x = 7;` `x+1 == -8;` - 'zakres liczb ujemnych to zakres dotatnich + 1'
* `x >> 3` - powielamy bit znaku w signed, w unsigned wstawiamy 0
* Java: `>>>`
* `x << 1` - mnożenie przez 2
* `x >> k` - dzielenie przez 2 do k
* `-25 >> 1 == -13`?


```c
#define ABS(x) ()

int x = 30506;
while (abs(x) >= 0)
    --x;

x = 1234;
printf("%d\n", x & MASK);

```
