# test_mymath.py
import unittest
from mymath import add

def multiply(a, b):
    return a * b

def divide(a, b):
    if b == 0:
        raise ValueError("Division by zero")
    return a / b

class TestMath(unittest.TestCase):
    def setUp(self):
        return super().setUp()
    
    def test_multiply_positive(self):
        self.assertEqual(multiply(2, 3), 6)

    def test_multiply_zero(self):
        self.assertEqual(multiply(0, 5), 0)

    def test_multiply_negative(self):
        self.assertEqual(multiply(-2, 3), -6)

    def test_divide_by_zero(self):
        with self.assertRaises(ValueError):
            divide(10, 0)
            
if __name__ == '__main__':
    unittest.main()
