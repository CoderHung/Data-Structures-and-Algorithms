import asyncio
import time

async def async_fake_download(file_id):
    await asyncio.sleep(1)
    return f"Data from file {file_id}"

async def run_async():
    start = time.time()
    tasks = [async_fake_download(i) for i in range(5)]
    await asyncio.gather(*tasks)
    return time.time() - start  # ← Return duration

