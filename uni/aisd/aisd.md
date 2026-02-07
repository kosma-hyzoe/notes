# AiSD – skrót do zadań rysunkowych

## 4. BST – drzewa binarne wyszukiwań

- lewe < korzeń < prawe
- inorder: L K P → wynik posortowany
- preorder: K L P
- postorder: L P K
- Wstawianie: por., idź l/p, wstaw
- usuwanie:
  * liść → usuń
  * jedno dziecko → podłącz dziecko
  * dwoje dzieci → zamień z następnikiem (min z prawego)

## 5. Kopiec (max-heap)
* Własność: rodzic >= dzieci, Reprezentacja: tablica
Indeksy:
* lewe = 2i+1
* prawe = 2i+2
* rodzic = (i-1)/2
* Wstawianie: dodaj na koniec przesuwaj w górę
* Usuwanie max: zamień z ostatnim, heapify w dół

### HeapSort
- buduj kopiec
- zdejmuj max na koniec

Złożoność: O(n log n)

---

## 6. Stos i ONP

Stos: LIFO

Operacje:
- push
- pop
- top

Algorytm ONP:
- liczba → na stos
- operator → zdejmij 2, oblicz, wrzuć wynik


## Sorty

```python
# Selection sort — wybieramy najmniejszy i przesuwamy na początek
import heapq

def selection_sort(a):
    n = len(a)
    for i in range(n - 1):
        m = i
        for j in range(i + 1, n):
            if a[j] < a[m]:
                m = j
        a[i], a[m] = a[m], a[i]

# Bubble sort — największe „wypływają” na koniec
def bubble_sort(a):
    n = len(a)
    for i in range(n):
        for j in range(0, n - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]

# Insertion sort — wstawiamy element w posortowaną część po lewej
def insertion_sort(a):
    for i in range(1, len(a)):
        x = a[i]
        j = i - 1
        while j >= 0 and a[j] > x:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = x

# Quick sort — dzielimy względem pivota
def quick_sort(a):
    if len(a) <= 1:
        return a
    pivot = a[-1]
    left = [x for x in a[:-1] if x <= pivot]
    right = [x for x in a[:-1] if x > pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)

# Merge sort — dzielimy na pół i scalamy
def merge_sort(a):
    if len(a) <= 1:
        return a
    mid = len(a) // 2
    L = merge_sort(a[:mid])
    R = merge_sort(a[mid:])

    out = []
    i = j = 0
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            out.append(L[i])
            i += 1
        else:
            out.append(R[j])
            j += 1

    return out + L[i:] + R[j:]



## 7. Algorytm Kruskala (MST)

Cel: minimalne drzewo rozpinające

Kroki:
1. sortuj krawędzie rosnąco
2. bierz najtańszą
3. dodaj jeśli nie tworzy cyklu
4. użyj Union-Find

Schemat:
dodaj krawędź jeśli łączy różne składowe

Złożoność: O(E log E)

Kod:
    struct Edge {
        int u, v, w;
    };

---


# heap
#left: 2*1, right: 2*i + 1, parent: i//2
def max_heapify(a, heap_size, i):
    l = left(i)
    r = right(i)

    largest = i
    if l < heap_size and a[l] > a[i]:
        largest = l

    if r < heap_size and a[r] > a[largest]:
        largest = r

    if largest != i:
        # swap elements
        a[i], a[largest] = a[largest], a[i]
        max_heapify(a, heap_size, largest)

def build_max_heap(a):
    heap_size = len(a)

    for i in range(heap_size//2, 0, -1):
        max_heapify(a, heap_size, i)

def heap_sort(a):
    build_max_heap(a)
    for i in range(len(a)-1, 1, -1):
        a[i], a[1] = a[1], a[i]

        # after the swap the last element is now sorted, but need to re-heapify
        max_heapify(a, i, 1)
```

