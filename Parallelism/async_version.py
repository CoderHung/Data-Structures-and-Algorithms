import asyncio
import time
from cpu_task import compute

async def async_compute(n):
    return compute(n)

async def run_async():
    start = time.time()
    tasks = [async_compute(10**6) for _ in range(5)]
    await asyncio.gather(*tasks)
    return time.time() - start
