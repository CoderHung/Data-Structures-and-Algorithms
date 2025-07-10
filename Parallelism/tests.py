import unittest
import non_parallel
import threading_version
import multiprocessing_version
import asyncio
from async_version import run_async

class TestCPUBoundMethods(unittest.TestCase):

    def test_non_parallel(self):
        duration = non_parallel.run()
        print(f"Non-parallel: {round(duration, 2)}s")


    def test_threading(self):
        duration = threading_version.run()
        print(f"Threading: {round(duration, 2)}s")


    def test_async(self):
        duration = asyncio.run(run_async())
        print(f"Asyncio: {round(duration, 2)}s")


    def test_multiprocessing(self):
        duration = multiprocessing_version.run()
        print(f"Multiprocessing: {round(duration, 2)}s")


if __name__ == '__main__':
    unittest.main()
