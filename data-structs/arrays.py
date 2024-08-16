import array
import queue
import copy
import heapq
import random
from collections import OrderedDict


class TreeNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.height = 1


class Treemap:
    class

    def __init__(self):
        this._od = OrderedDict([1])
        this.head


tm = OrderedDict()


ar = array.array('i')
for _ in range(0, 100):
    ar.append(random.randint(1, 100))
ar.sort()

q = queue.Queue()
dq = queue.deque([1, 2, 3], maxlen=3)

l = [1, 2, 3]
hq = heapq.heapify(list)

_dq_dc = copy.deepcopy(dq)
