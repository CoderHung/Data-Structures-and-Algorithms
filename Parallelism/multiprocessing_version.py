import time
from multiprocessing import Process
from cpu_task import compute

def run():
    start = time.time()
    processes = []
    for _ in range(5):
        p = Process(target=compute, args=(10**6,))
        processes.append(p)
        p.start()
    for p in processes:
        p.join()
    return time.time() - start
