# Algorithms

* use recursion when a for loop is not enough
* The Introduction to Algorithms
* "For Programmers who don't know how to datasctructue..."
* binary search - [lo, hi)
* quick sort - [lo, hi]

* array buffers


## Sorting

```python
for i in range(i, n):
	for j in range(i, n-i):
		swap(j , j+1)
```

## Binary tree comp

```python
def comp(a, b):
    if not a and not b:
        return True
    if not a or not b:
        return False
    if a != b:
        return False
    reutrn comp(a.left, b.left) && comp(a.right, b.right)
```
