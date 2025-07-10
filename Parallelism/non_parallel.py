import time
from cpu_task import compute

def run():
    start = time.time()
    for _ in range(5):
        compute(10**6)
    return time.time() - start
