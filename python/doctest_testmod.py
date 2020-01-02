"""
https://www.geeksforgeeks.org/testing-in-python-using-doctest-module/

What? This searches for pieces of text that look like interactive Python sessions, and then executes
those sessions to verify that they work exactly as shown.
Using docstring for testing: docstrings """ can be used for function description and also testing purposes.
The Doctest Module finds patterns in the docstring that looks like interactive shell commands.

Syntax: testmod(function_name_to_execute, verbosity)
returns: failed, total testcases count    
"""

from doctest import testmod

# define a function to test 
def factorial(n):
        ''' 
        This function calculates recursively and 
        returns the factorial of a positive number. 
        Define input and expected output: 
        >>> factorial(2) 
        2
        >>> factorial(5) 
        120
        '''
        if n <= 1:
                return 1
        return n * factorial(n - 1)

# call the testmod function 
if __name__ == '__main__':
    failed, total = testmod(name ='factorial', verbose = True)
    print('failed='+str(failed))
    print('total='+str(total))

"""
Output:

Trying:
    factorial(2) 
Expecting:
    2
ok
Trying:
    factorial(5) 
Expecting:
    120
ok
1 items had no tests:
    factorial
1 items passed all tests:
   2 tests in factorial.factorial
2 tests in 2 items.
2 passed and 0 failed.
Test passed.
failed=0
total=2
"""
