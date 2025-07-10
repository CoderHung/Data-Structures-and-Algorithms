import time
import threading
from task import fake_download

def run():
    start = time.time()
    threads = []
    for i in range(5):
        t = threading.Thread(target=fake_download, args=(i,))
        threads.append(t)
        t.start()
    for t in threads:
        t.join()
    return time.time() - start  # ← Return duration

