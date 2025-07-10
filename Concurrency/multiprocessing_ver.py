import time
from multiprocessing import Process
from task import fake_download

def run():
    start = time.time()
    processes = []
    for i in range(5):
        p = Process(target=fake_download, args=(i,))
        processes.append(p)
        p.start()
    for p in processes:
        p.join()
    return time.time() - start  # ← Return duration

