# main.py
from PQ import PriorityQueue

pq = PriorityQueue()
for val in [15, 10, 30, 5, 20]:
    pq.push(val)

print("PQ:", pq)
print("Top:", pq.top())     # 30
print("Pop:", pq.pop())     # 30
print("PQ after pop:", pq)
##PQ: [30, 20, 15, 5, 10]
##Top: 30
##Pop: 30
##PQ after pop: [20, 10, 15, 5]
