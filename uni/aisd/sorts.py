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


# Heap sort — kopiec max


def heap_sort(a):
    h = [-x for x in a]   # heapq to min-heap → odwracamy znak
    heapq.heapify(h)
    return [-heapq.heappop(h) for _ in range(len(h))]
