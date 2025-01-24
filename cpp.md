## Pliki

## Generowanie liczb losowych

```cpp
#include <cstdlib>
// (...)
srand(time(0));
rand() / double(RAND_MAX); // <0,1>, double
a + (b - a)  * rand() / (double)RAND_MAX; // <a, b>, double
rand() % 100  // <0,99>, int
a + rand() % (b + 1 - a); // <a, b>, int
cout << (char) 'a' + rand()%('z' + 1 - 'a'); // print chars
```
* `<cmath>`
  * `pow(x, 2)`
  * `sqrt`
  * `abs`
* `<iomanip>`
    * `seprecision(1) // 1.1`
    * `setw(5)`
    * `cout << fixed // print 0 as 0.0`


## Pliki

```
ifstream if;
ofstream of;
fstream f("foobar", ios::app); // can append, create file
if (!f.is_open()) return 1;
while(!f.eof());
f.get(c); f.put(c);
getline(f, str);
```

## Operatory

* `|` - or
* `^` - xor
* `~` - negacja
* `,` - :P
* `size_of`

## Rzutowanie

* `static_cast` - rzutowanie typu sprawdzane na etapie kompilacji, stosunkowo
  bezpieczne.
* `dynamic_cast` - rzutowanie sprawdzane w trakcie wykonania programu. Bardzo
  użyteczne przy programowaniu obiektowym.
* `const_cast` - rzutowanie, którego celem jest zmiana zmiennej, której nie
  powinno się zmieniać, na zmienną, którą można zmieniać swobodnie. Jak się
  domyślacie - jest to dość niebezpieczne.
* `reinterpret_cast` - rzutowanie z całkowitą zmianą znaczenia. Jego
  wykorzystanie powoduje konieczność dokonania ponownego rzutowania w celu
  powrotu do pierwotnej wartości. Wykorzystywane praktycznie jedynie przy
  wykonywaniu niskopoziomowych operacji na sprzęcie - bardzo niebezpieczne.

## Tablice

```
int foo[1][2] const int w=3, k=4;
int A[w][k]={2,3,8,6,4,2,9,0,7,1,12,5};
int B[w][k] {2,3,8,6,  4,2,9,0,  7,1,12,5};  // C++11
int D[w][k] {2,3,8,6,
             4,2,9,0,
             7,1,12,5}; // C++11
```

## Misc

* `<cmath>`
  * `pow(x, 2)`
  * `sqrt`
  * `abs`
* `<iomanip>`
  * `seprecision(1) // 1.1`
  * `setw(5)`
  * `cout << fixed // print 0 as 0.0`

* `system("PAUSE"); // "Press any key to continue..."`
* `cin.ignore() // ignore char`
* `cin.ignore() // ignore one char`
* `cin.ignore(n, del) // up to n chars or until encounters delimeter`
* operandy - argumenty
* `cin >> x >> y >> z;` - wczytaj wartości danych o nazwach x, y, z
* `std::cout << "The value of x is: " << x << std::endl;`
