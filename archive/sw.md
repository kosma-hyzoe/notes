# SW Academy

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
int main() {
    int x = 30506;
    while (abs(x) >= 0)
        --x;

    x = 1234;
    printf("%d\n", x & MASK);

    unsigned int i = 2;
    printf("%d\n", (i << 32));
    printf("%d\n", (i << 31));
    printf("%d\n", (i << 30));
    printf("%d\n", (i << 29));
}
```

## Advanced Basics

* `arrayList` / `vector`, O(1)
  * przy 100 elementach, bufor będzie mieć rozmiar ok. 200 elementów
  * `add(1, x)` w javie działa liniowo!
* `deque` / `arrayDeque` - kolejka dwustronna, rozszerzenie vectora.
  * zmienia się wskaźnik do początku arraya, "zmiana indeksów" odbywa się
    w czasie zamortyzowanym stałym (o ile bufor ma miejsce)
* `sorting` / `comparators`
* `bucket` - dobrze ustawić size na sqrt(n), wtedy tyle też będzie wynosić count
  kubełków

## Grafy

* zbiór wierchołow i krawędzi
* ścieżka - ciąg wierchołków?
* cykl - zaczynają się i kończą w jednym wierzchołku
* graf spójny - każdą parę łączy ścieżka
* drzewo - graf bez cykli, n wierchołków, n-1 krawędzi
* V - vertex, zbiór wierzchołków
* ukorzenianie drzew
* n * (n - 1) / 2 dla nieskierowanych, n * (n -1) dla skierowanych
  * LUB n * n dla skierowanych (np. pass w grze, ścieżka widokowa)
* macierz sąsiedztwa, listy sąsiedztwa/następników (może przechowywać więcej
  danych)
* wydajność listy sąsiedzstwa zależy od gęstości grafu
  w macierzy możemy zastąpić `int[][]` mapą lub słownikiem
* reprezentacja niejawna - np. przy ruchach na szachownicy
