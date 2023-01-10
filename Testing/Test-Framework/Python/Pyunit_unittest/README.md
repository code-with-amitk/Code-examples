**Pyunit or unittest**
- Examples
  - [Testing class](#e1)

### Pyunit or unittest
- _Why?_ used to test a unit of source code
#### Features
- _1._ PyUnit is very simple yet very flexible in test case execution
- _2._ Test report formats generated: XML, unittest xml reports
- _3._ Supports fixtures, test cases, test suites and test runners for automation of testing

### Examples
<a name=e1></a>
#### Testing class
```c
1. Create the class which need to be tested
2. Create seperate module(which import above class)  & calls its functions for testing.
```
- _1._ This is the class we want to test.
```py
# car.py  //Class to store the name and return
class car:
    name = ""

    def set(self, name) -> bool():
        self.name = name
        return True

    def get(self):
        return self.name
            
if __name__ == '__main__':
    c = car()
    if c.set('BMW') == True:
        print('car BMW has been added')
    else:
        print('car add failed')
    print('car is ', c.get())

> python.exe .\car.py
car BMW has been added
car is  "BMW"
```
- _2._ Write the unittest module(which will test car class).
```py
# car_testing.py
import unittest

# 1. import the class which we want to test
import car as c

"""
2. 
Write a class which will test car class.
This class should inherit unittest.TestCase
"""
class car_testing(unittest.TestCase):
    car = c.car()       # 3. Create object of car class
    """
        Note unittest module executes the test functions in the order of their name
        since we want our set() test to execute first, we have named our test case
        functions as test_0_set() and test_1_get()
    """
    def test_0_set(self): # 4. Any method which starts with ``test_`` will considered as a test case.
        print ("\nStart set() test..")
        self.car.set('Audi')
        print("Finish set() test\n")

    def test__1_get(self):
        print("\nStart get() test..")
        # 5. if 2 parameters does not match test case will fail
        var = self.car.get()
        print (var)
        self.assertEqual(var, 'Audi')
        print("Finish get() test\n")

if __name__ == '__main__':
    unittest.main()
    
> python.exe .\car_testing.py

Start set() test..
Finish set() test

.
Start get() test..
Audi
Finish get() test

.
----------------------------------------------------------------------
Ran 2 tests in 0.009s
OK
```
