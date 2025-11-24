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


## Pliki / strumienie

```
ifstream if;
ofstream of;
fstream f("foobar", ios::app); // can append, create file
if (!f.is_open()) return 1;
while(!f.eof());
f.get(c); f.put(c);
getline(f, str);
* `cin.ignore(n, del) // up to n chars or until encounters delimeter`
* `cin >> x >> y >> z;` - wczytaj wartości danych o nazwach x, y, z
* `std::cout << "The value of x is: " << x << std::endl;`
* `cin.ignore() // ignore one char`
```


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

* `<iomanip>`
  * `seprecision(1) // 1.1`
  * `setw(5)`
  * `cout << fixed // print 0 as 0.0`

* `system("PAUSE"); // "Press any key to continue..."`
* Namescape

## Klasy

* `virtual void func(int, int) = 0;` - pure virtual, must be defined
* explicit overriding not enforced, recommended
* `enum class Kind { circle, triangle, smiley }` / `switch (k) case Kind::circle`
* `if (Smiley* p = dynamic_cast<Smiley*>(ps))` - ptr or nullptr
* `Obj myO;` - stack alloc, auto handled in scope
* `Obj myO = new Obj();` - heap allock, dynamic lifetime and larger size but
  must be explicitly remove

## Wskaźniki i refy

* `unique_ptr<Shape>` ~= ` Shape *`, deletes objects when out of scope

```cpp
Class VectorContainer : public Vector { // public -> is subclass of
};
  Vector v;
public:
  double &operator[](int) {return v[i]; } // describes acces thru []
  double &operator+(Vector v1, Vector v2) { /*... */ } // describes acces thru []
};
```

## copy/move

There are five situations in which an object is copied or moved:

*  As the source of an assignment
*  As an object initializer
*  As a function argument
*  As a function return value
*  As an exception

In all cases, the copy or move constructor will be applied (unless it can be
optimized away). In addition to the initialization of named objects and objects on the free
store, constructors are used to initialize temporary objects and to implement
explicit type conversion.

```cpp
class Vector {
     Vector(const Vector& a);               // copy constructor
     Vector& operator=(const Vector& a);    // copy assignment
     Vector(Vector&& a);                    // move constructor
     Vector& operator=(Vector&& a);         // move assignment
     Y(const Y&) = default;
     Y(const Y&&) = default;

Vector::Vector(const Vector& a)     // copy constructor
    :elem{new double[a.sz]},        // allocate space for elements
    sz{a.sz}
{
    for (int i=0; i!=sz; ++i)      // copy elements
          elem[i] = a.elem[i];
}

Vector::Vector(Vector&& a)
    :elem{a.elem},          // "grab the elements" from a // TODO what??
    sz{a.sz}
{
    a.elem = nullptr;       // now a has no elements
    a.sz = 0;
}
```

