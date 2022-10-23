**pytest**
- [Why pytest is better?](#w)
- Running tests in pytest
  - [1. Running 1 test in vscode](#otest)
  - [2. Running multiple test in vscode](#mtest)

## pytest
<a name=w></a>
### [Why pytest is better?](https://realpython.com/pytest-python-testing/)
- _1._ Less Boilerplate
- _2._ Nicer Output
- _3._ Less to Learn
- _4._ Easier to Manage State and Dependencies
- _5._ Easy to Filter Tests
- _6._ Allows Test Parametrization
- _7._ Has a Plugin-Based Architecture 

### Run test with pytest in vscode
<a name=otest></a>
#### 1. Running 1 test
- _1._ Install python on windows https://www.python.org/downloads/ (Set PATH variable)
- _2._ Install pytest on windows
```c
cmd> pip install -U pytest
```
- _3._ Run test using pytest in vscode. Open file in vscode
```py
def func(x):
    return x + 1

def test_answer():
    assert func(3) == 5
```
- _4._ from Terminal. 
```py
PS C:\Users\amitk\source\repos\python> pytest.exe .\func.py
=========================================== test session starts ===========================================
platform win32 -- Python 3.10.8, pytest-7.1.3, pluggy-1.0.0
rootdir: C:\Users\amitk\source\repos\python
collected 1 item

func.py F                                                                        [100%] <<<<< All tests ran

================================================ FAILURES ================================================= 
_______________________________________________ test_answer _______________________________________________

    def test_answer():
>       assert func(3) == 5
E       assert 4 == 5
E        +  where 4 = func(3)

func.py:6: AssertionError
========================================= short test summary info ========================================= 
FAILED func.py::test_answer - assert 4 == 5
============================================ 1 failed in 0.48s ============================================
```
<a name=mtest></a>
#### 2. Run multiple tests
```py
# vim func.py
def func(x):
    return x + 1
def func1(x):
    return x + 1
def test_answer():
    assert func(4) == 5
    assert func1(3) == 4

// From vscode terminal
PS C:\Users\amitk\source\repos\python> pytest.exe .\func.py
====================================================== test session starts ======================================================
platform win32 -- Python 3.10.8, pytest-7.1.3, pluggy-1.0.0
rootdir: C:\Users\amitk\source\repos\python
collected 1 item

func.py .                                                                                                   [100%]  <<< completed
======================================================= 1 passed in 0.21s ======================================================= 
PS C:\Users\amitk\source\repos\python>
```
