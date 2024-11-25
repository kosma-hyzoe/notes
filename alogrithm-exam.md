# Algorithm exam

## Graphs

* vertice, edge
* e <= v^2
  * m <= n * (n - 1)
  * m <= n * (n - 1) / 2 (skierowany)
* directed, undirected
* representation:
  * matrix (r,c) - labyrinth-style
  * adjacency matrix


## Arrays, heaps and misc

```python
import array, queue, heapq, copy, random


ar = array.array('b')
# sort in place
ar.sort()
# return sorted object
sorted_ar = sorted(ar)

q = queue.Queue()
dq = queue.deque([1, 2, 3], maxlen=3)

l = [1, 2, 3]
heapq.heapify(l)

_dq_dc = copy.deepcopy(dq)
```
