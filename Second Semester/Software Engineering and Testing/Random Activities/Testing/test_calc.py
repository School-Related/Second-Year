# testing file, this fill will do all the testing for us. 
# inbuilt module. The fact that it is inbuilt, tells us how important it is.
# you gotta import the file or module that you are testing. 
# doc links for unittest module
# https://docs.python.org/3/library/unittest.html#unittest.TestCase.assertEqual
import unittest
import calc

class TestCalc(unittest.TestCase):
    '''
    all the functions that you will write in this class will be run by unittest to test your code.
    '''
    
    # this functions would be 1 test. 
    def test_add(self):
        # this is the test for the add function
        self.assertEqual(calc.add(10, 5), 15) # positive ones
        self.assertEqual(calc.add(-1, 1), 0) # negative and positive
        self.assertEqual(calc.add(-1, -1), -2) # negative ones
        
    def test_subtract(self):
        # this is the test for the subtract function
        self.assertEqual(calc.subtract(10, 5), 5)
        self.assertEqual(calc.subtract(-1, 1), -2)
        self.assertEqual(calc.subtract(-1, -1), 0)  

    def test_multiply(self):
        # this is the test for the multiply function
        self.assertEqual(calc.multiply(10, 5), 50)
        self.assertEqual(calc.multiply(-1, 1), -1)
        self.assertEqual(calc.multiply(-1, -1), 1)
        
    def test_divide(self):
        # this is the test for the divide function
        self.assertEqual(calc.divide(10, 5), 2)
        self.assertEqual(calc.divide(-1, 1), -1)
        self.assertEqual(calc.divide(-1, -1), 1)
        self.assertEqual(calc.divide(5, 2), 2.5)
        
        # we can also use the assertRaises function
        # self.assertRaises(ValueError, calc.divide, 10, 0)
        # this is the same as the following:
        with self.assertRaises(ZeroDivisionError):
            calc.divide(10, 0)
    
    def test_factorial(self):
        # this is the test for the factorial function
        self.assertEqual(calc.factorial(0), 1)
        self.assertEqual(calc.factorial(1), 1)
        self.assertEqual(calc.factorial(2), 2)
        self.assertEqual(calc.factorial(3), 6)
        self.assertEqual(calc.factorial(4), 24)
        self.assertEqual(calc.factorial(5), 120)
    
    
if __name__ == '__main__':
    unittest.main()
    
# Output
# .....
# ----------------------------------------------------------------------
# Ran 5 tests in 0.000s

# OK