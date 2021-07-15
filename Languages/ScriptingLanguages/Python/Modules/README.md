- [What is Module](#what)
- [Creating & using Module](#create)
- [Modules as scripts](#asscript)
- [Examples](#ex)
  - [1. Calender module](#calender)
  - [2. OS module](#os)
  - [3. re Module](#re)
  - [4. datetime module](#datetime)
  - [5. testmod](#testmod)


<a name=what></a>
## Module
-  This is a File containing python functions, class, variables etc. Examples
  - *sys* Access system variables, functions maintained by interpreter.
```py
import sys
print(sys.path)     #['/root/amit-code/python', '/usr/lib64/python36.zip', '/usr/lib64/python3.6', 
'/usr/lib64/python3.6/lib-dynload', '/root/.local/lib/python3.6/site-packages', '/usr/local/lib64/python3.6/site-packages', 
'/usr/local/lib/python3.6/site-packages', '/usr/local/lib/python3.6/site-packages/memory_profiler-0.57.0-py3.6.egg', 
'/usr/lib64/python3.6/site-packages', '/usr/lib/python3.6/site-packages']
```
  - *builtin* Built-in identifiers of Python
```py
import builtins
print(dir(builtins)) #['ArithmeticError', 'AssertionError', 'AttributeError', 'BaseException', 'BlockingIOError', 
'BrokenPipeError', 'BufferError', 'BytesWarning', 'ChildProcessError', 'ConnectionAbortedError', 'ConnectionError', 
'ConnectionRefusedError', 'ConnectionResetError', 'DeprecationWarning', 'EOFError', 'Ellipsis', 'EnvironmentError', 
'Exception', 'False', ...]
```

<a name=create></a>
## Creating & Using Modules
- _1. Define a module_
- _2. Import the module:_ means including the module to use its functionality. There are 2 methods of importing a module.
  - _2A._ Import complete Module
  - _2B._ Import 1 function from Module
```py
# vim Multiply_Sum.py                 #1. Defined module(Multiply_Sum)
def Multiply(a,b):
  print('Multiplies:', a*b)
def Sum(a,b):
  print('Sum:', a+b)  
  
########## 2. Import module  ####
# vim test.py                               # 2A. Import complete module
import Multiply_Sum as MS
#OR from Multiply_Sum import *
MS.Multiply(1,2)                    #2
MS.SUM(4,5)                         #9
print(MS.__name__)                   #Print the module name: Multiply_Sum

# vim test2.py                              # 2B. Import 1 function from module
from Multiply_Sum import Multiply
Multiply(2,3)                         #6
```

<a name=asscript></a>
## Modules as scripts
- Means passing command line arguments to module. This code needed to be added at end of module:
```python
    # vim mult_sum.py
        def mult1(a,b):
            print('Mult:',a*b)
        def sum1(a,b):
            print('Sum:',a+b)    
        if __name__ == "__main__":
            import sys
            mult1(int(sys.argv[1]),int(sys.argv[2]))

    # python3.6 mult_sum.py 2 3         #6
```

<a name=ex></a>
## Examples

<a name=calender></a>
### 1. Calender module
- Output calendars and provides additional useful functions related to the calendar.
- _1._ Print calendar for any year and month
```py
import calendar
y = int(input("year:"))
m = int(input("month:"))
print(calendar.month(y,m))

$ python3 test.py
year:2017
month:2
   February 2017
Mo Tu We Th Fr Sa Su
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28
```

<a name=os></a>
### 2. OS module
- Miscellaneous operating system interfaces
- **Functions available**
  - rename()

<a name=re></a>
### 3. re Module
- Used for string manipulations. Eg: Checking whether email address is of correct format or not.
- **Regular Expressions**

|Regular Expression|Meaning|
|---|---|
|\S |Match any non-whitespace character|
|+ |Repeats a character one or more times|


<a name=datetime></a>
### 4. datetime module
- Contains classes for manipulating dates and times.
- _1. Print number of days between two dates_
```py
from datetime import date
fdate = date(2014, 7, 2)
ldate = date(2014, 7, 11)
diff = ldate - fdate
print(diff.days)
```

<a name=testmod></a>
### 5. testmod
```py
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
```
