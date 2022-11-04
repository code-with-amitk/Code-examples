**pytest**
- [Why pytest is better?](#w)
- Running tests in pytest
  - [1. Running 1 test in vscode](#otest)
  - [2. Running multiple test in vscode](#mtest)
  - [3. Group multiple tests in 1 class](#mc)
- [Catching exception in function](#catch)
- [Fixtures](#fix)
- [Using plugins with pytest](#plug)

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

<a name=mc></a>
#### 3. Group multiple tests in 1 class
```py
//In vscode
# vim test_class.py
class TestClass:
    def test_1(self):
        x = "this"
        assert "h" in x     #Pass h is present in x

    def test_2(self):
        x = "this"
        assert "k" in x     #Fail k not present in x

    def test_3(self):
        class Person:
            name = "John"
            age = 36
            country = "Norway"
        x = "hello check"
        assert hasattr(Person, 'age')   #Pass Object(Person) has attribute age

//In vscode terminal
PS C:\Users\amitk\source\repos\python> pytest -q test_class.py
.F.                                                                                                                        [100%]
=========================================================== FAILURES ============================================================ 
_______________________________________________________ TestClass.test_2 ________________________________________________________ 

self = <test_class.TestClass object at 0x000001DC99A33580>

    def test_2(self):
        x = "this"
>       assert "k" in x     #Fail k not present in x
E       AssertionError: assert 'k' in 'this'

test_class.py:8: AssertionError
==================================================== short test summary info ==================================================== 
FAILED test_class.py::TestClass::test_2 - AssertionError: assert 'k' in 'this'
1 failed, 2 passed in 3.99s
PS C:\Users\amitk\source\repos\python>
```

<a name=catch></a>
### [Catching exception in function](https://testautomationu.applitools.com/pytest-tutorial/chapter3.html)
```py
# Function raising an exception
def fun():
    num = 1/0
fun()
$ pytest test.py

# Exception caught
import pytest
def fun():
    with pytest.raises(ZeroDivisionError) as e:
        num = 1/0
    assert 'Hit Zero Division Error, Dude' in str(e.value)
fun()
$ pytest test.py
```

<a name=fix></a>
### Fixtures
- In testing, a fixture provides a context for the tests. Context may be: environment or content.
- Any function is a fixture if we decorate it with @pytest.fixture.
```py
# cat fixtures.py
import pytest
class Fruit:
    def __init__(self, name):
        self.name = name
    def __eq__(self, other):
        return self.name == other.name

@pytest.fixture
def apple_fruit():
    return Fruit("apple")
@pytest.fixture
def guvava_fruit():
    return Fruit("guvava")
@pytest.fixture
def fruit_basket(apple_fruit):
    return [Fruit("banana"), apple_fruit]
    
#apple_fruit = [apple]  #guvava_fruit = [guvava]    #fruit_basket = [banana, apple]
def test_apple_in_basket(apple_fruit, fruit_basket):    #Pass
    assert apple_fruit in fruit_basket
def test_guvava_in_basket(guvava_fruit, fruit_basket):    #Fail
    assert guvava_fruit in fruit_basket

# pytest .\fixtures.py
fixtures.py:24: AssertionError
==================================================== short test summary info ==================================================== 
FAILED fixtures.py::test_guvava_in_basket - assert <fixtures.Fruit object at 0x000002973F21F1F0> in [<fixtures.Fruit object at ...================================================== 1 failed, 1 passed in 0.48s ===============================================
```

<a name=plug></a>
### Using plugins with pytest
- [What is Python Plugin?](/Languages/ScriptingLanguages/Python/Plugins/)
#### pytest-html plugin
- This plugin will generate html reports from pytest.
- **Install plugin**
```py
In vscode
> pip install pytest-html
```

- **Use Plugin**
```py
$ test.py
def fun():
    num = 1/0
fun()

$ pytest test.py --html=test.html   //This html report page gets generated
```
