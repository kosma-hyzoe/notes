* `cin.get(foobar)` - z białymi znakami
* `cin.get()` - wait for input
* `cin.ignore()`
* operandy - argumenty

* `|` - or
* `^` - xor
* `~` - negacja
* `,` :P
*`size_of`


* `cin >> x >> y >> z;` - wczytaj wartości danych o nazwach x, y, z
* `std::cout << "The value of x is: " << x << std::endl;`


* `system()`
  * PAUSE - press any key to continue

Inne operatory rzutowania dostępne w C++ to:
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

# C++ Operator Precedence and Associativity

```
16 	(  ) nawiasy
15 	jednoargumentowy minus i plus, inkrementacja ++,
    dekrementacja  --, negacja !,  rzutowanie
13 	mnożenie, dzielenie, reszta z dzielenia (czyli modulo %)
12 	dodawanie i odejmowanie
10 	relacje nierównościowe (większy >,  większy równy  >=,
    mniejszy  <,   mniejszy równy  <=)
9 	relacje równościowe (równy ==, różny  !=)
5 	koniunkcja &&
4 	alternatywa ||
2 	przypisanie =
```

* `cstdlib`, `srand`, `rand`
* `a + (b - a) * rand() / (double) RAND_MAX`

```
int foo[1][2] const int w=3, k=4;
int A[w][k]={2,3,8,6,4,2,9,0,7,1,12,5};
int B[w][k] {2,3,8,6,  4,2,9,0,  7,1,12,5};  // C++11
int D[w][k] {2,3,8,6,
             4,2,9,0,
             7,1,12,5}; // C++11
```

* `#include <iomanip>`
* Domyślna precyzja w C++ wynosi 6, co oznacza że liczba 0.123456789 będzie
wyświetlona jako 0.123457.
* `setprecision`, `fixed`, `scientific`
* `setw(7)`
* `cout << "Precyzja : " << i << ", liczba : " << setprecision(i) << v << endl;`
