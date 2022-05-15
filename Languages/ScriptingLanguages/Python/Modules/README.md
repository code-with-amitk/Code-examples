**Module**
- [Creating & using Module](#create)
- [Modules as scripts](#asscript)
- [Examples](#ex)
  - [1. Calender module](#calender)
  - [2. OS module](#os)
  - [3. re Module](#re)
  - [4. datetime module](#datetime)
  - [5. testmod](#testmod)
- Packages
  - [Creating Package](#cp)


## Module
- Module is a File in python with .py extension containing python functions, class, variables etc.
- They can be imported and initialized once using the import statement. If partial functionality is needed, `from foo import bar`.

**builtin** Built-in identifiers of Python
```py
import builtins
print(dir(builtins)) #['ArithmeticError', 'AssertionError', 'AttributeError', 'BaseException', 'BlockingIOError', 
'BrokenPipeError', 'BufferError', 'BytesWarning', 'ChildProcessError', 'ConnectionAbortedError', 'ConnectionError', 
'ConnectionRefusedError', 'ConnectionResetError', 'DeprecationWarning', 'EOFError', 'Ellipsis', 'EnvironmentError', 
'Exception', 'False', ...]
```

<a name=c></a>
### Create & use Modules
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

## Package
- This is Collection of modules grouped together
- `__INIT__.PY`: if this file is present in directory python treats that directory as package.

<a name=cp></a>
### Creating Packages
```py
sound_package
    |
    |__init__.py
    |format
        |__init__.py
        |wavread.py
        |wavwrite.py
    |effects
        |__init__.py
        |echo.py
            def fun(a):
            print(a)
    |filters
        |__init__.py
        |karaoke.py

 # mkdir sound_package
 # touch sound_package/__init__.py
 
 # mkdir -p sound_package/format
 # touch sound_package/format/__init__.py
 # touch sound_package/format/wavread.py
 # touch sound_package/format/wavwrite.py

 # mkdir -p sound_package/effects
 # touch sound_package/effects/__init__.py
 # touch sound_package/effects/echo.py

 # mkdir -p sound_package/filters
 # touch sound_package/filters/__init__.py
 # touch sound_package/filters/karaoke.py
 
 # vim sound_package_user.py


from sound_package.effects.echo import fun
fun('Sit with ease, Preserve energy')   #Sit with ease, Preserve energy
```
