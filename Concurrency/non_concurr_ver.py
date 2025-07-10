import time
from task import fake_download

def run():
    start = time.time()
    for i in range(5):
        fake_download(i)
    return time.time() - start  # ← This line must return the duration

