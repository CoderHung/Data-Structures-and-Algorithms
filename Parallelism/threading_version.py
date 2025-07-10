import time
import threading
from cpu_task import compute

def run():
    start = time.time()
    threads = []
    for _ in range(5):
        t = threading.Thread(target=compute, args=(10**6,))
        threads.append(t)
        t.start()
    for t in threads:
        t.join()
    return time.time() - start
