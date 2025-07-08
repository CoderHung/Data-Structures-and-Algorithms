# pq.py
from MaxHeap import MaxHeap

class PriorityQueue:
    def __init__(self):
        self.heap = MaxHeap()

    def push(self, val):
        self.heap.insert(val)

    def pop(self):
        return self.heap.pop()

    def top(self):
        return self.heap.peek()

    def is_empty(self):
        return len(self.heap.heap) == 0

    def __str__(self):
        return str(self.heap)
