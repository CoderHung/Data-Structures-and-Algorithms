import unittest
import non_concurr_ver
import threading_ver
import multiprocessing_ver
import asyncio
from async_ver import run_async

class TestConcurrencyMethods(unittest.TestCase):

    def test_non_concurrent(self):
        duration = non_concurr_ver.run()
        print(f"Non-concurrent: {round(duration, 2)}s")


    def test_asyncio(self):
        duration = asyncio.run(run_async())
        print(f"Asyncio: {round(duration, 2)}s")


    def test_threading(self):
        duration = threading_ver.run()
        print(f"Threading: {round(duration, 2)}s")


    def test_multiprocessing(self):
        duration = multiprocessing_ver.run()
        print(f"Multiprocessing: {round(duration, 2)}s")


if __name__ == '__main__':
    unittest.main()
