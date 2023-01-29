**pytest**
- [Why pytest is better?](#w)
  - [pytest as Automation testing tool](#at)
- Running tests in pytest
  - [1. Running 1 test in vscode](#otest)
  - [2. Running multiple test in vscode](#mtest)
  - [3. Catching exception in function](#catch)
  - [4. Group multiple tests in 1 class](#mc)
    - Advantages of Running testcases in class
      - [1. Joint parametrization of multiple test methods belonging to same class](#adv2)
      - [2. Reuse of test data and test logic via subclass inheritance](#adv2)
- [Fixtures](#fix)
  - [Example-1: Fruit Basket](#ex1)
  - [Example2: Testing HashMap using Fixtures](#ex2)
  - [Advatages/Disadvatanges of Fixtures](#advd)
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
<a name=at></a>
#### pytest as Automation testing tool
- **Automation Testing?**
  - Automation testing requires minimal tester intervention, because Automation testing uses software tools to execute test cases.
  - It is faster & more accurate than manual testing as human errors are zeroed.
- **Pytest with Selenium**
  - open-source tool for automating web browsers

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

<a name=catch></a>
### [3. Catching exception in function](https://testautomationu.applitools.com/pytest-tutorial/chapter3.html)
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

<a name=mc></a>
### 4. Group multiple tests in 1 class
```py
"""
1. Test class is a class which contains multiple test cases
    which can be executed simultanously
2. Class name should always begin with Test (not test)
"""
class TestClass:       #Class name should begin with Test (not test)
#class ABC:            #This will not execute

    def test_1(self):   #Testcase names should start with test
    #def atest(self):   #Will not execute
    #def Test_1(self):   #Will not execute
        x = "this"          #create a object
        assert "h" in x     #Testcase Passed as h is present in x

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
.F.                                                                  [100%]   << All Test cases executed
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

#### Advantages of Running testcases in class
<a name=adv1></a>
##### 1. Joint parametrization of multiple test methods belonging to same class
  - With pytest parametrization decorator, @pytest.mark.parametrize, can be used to make inputs available to multiple methods within a class. 
```py
"""
decorator, @pytest.mark.parametrize: 
    is used to make inputs available to multiple methods within a class

inputs parameter1 and parameter1 are available to each of the methods TestClass
    test_1() and 
    test_2()
"""
import pytest
@pytest.mark.parametrize(
    ("parameter1", "parameter2"),
    [
        ("a", "b"),     #parameter1
        ("c", "d"),     #parameter2
    ],
)
class TestClass:
    def test_1(self, parameter1: str, parameter2: str) -> None:     #Parameter names should be same as declared above
        print("\ntest_1", parameter1, parameter2)

    def test_2(self, parameter1: str, parameter2: str) -> None:
        print("\ntest_2", parameter1, parameter2)
        assert "a" in parameter1                        #Check a is present in parameter1
        assert "h" in parameter2                        #Check h is present in parameter1


> pytest.exe .\JointParametrizationOfMultipleTestMethodsOfSameClass.py
====================================================== test session starts =======================================================
platform win32 -- Python 3.10.8, pytest-7.1.3, pluggy-1.0.0
rootdir: C:\Users\amitk\source\repos\Python-Based-Test-Scripting\pytest\Group_Multiple_tests_in_1_class
plugins: html-3.2.0, metadata-2.0.4
collected 4 items

JointParametrizationOfMultipleTestMethodsOfSameClass.py ..FF                                                                [100%]

============================================================ FAILURES ============================================================ 
_____________________________________________________ TestClass.test_2[a-b] ______________________________________________________ 

self = <JointParametrizationOfMultipleTestMethodsOfSameClass.TestClass object at 0x0000020EDB7D27A0>, parameter1 = 'a'
parameter2 = 'b'

    def test_2(self, parameter1: str, parameter2: str) -> None:
        print("\ntest_2", parameter1, parameter2)
        assert "a" in parameter1                        #Check a is present in parameter1
>       assert "h" in parameter2                        #Check h is present in parameter1
E       AssertionError: assert 'h' in 'b'

JointParametrizationOfMultipleTestMethodsOfSameClass.py:25: AssertionError
------------------------------------------------------ Captured stdout call ------------------------------------------------------

test_2 a b
_____________________________________________________ TestClass.test_2[c-d] ______________________________________________________ 

self = <JointParametrizationOfMultipleTestMethodsOfSameClass.TestClass object at 0x0000020EDB7D2830>, parameter1 = 'c'
parameter2 = 'd'

    def test_2(self, parameter1: str, parameter2: str) -> None:
        print("\ntest_2", parameter1, parameter2)
>       assert "a" in parameter1                        #Check a is present in parameter1
E       AssertionError: assert 'a' in 'c'

JointParametrizationOfMultipleTestMethodsOfSameClass.py:24: AssertionError
------------------------------------------------------ Captured stdout call ------------------------------------------------------ 

test_2 c d
==================================================== short test summary info ===================================================== 
FAILED JointParametrizationOfMultipleTestMethodsOfSameClass.py::TestClass::test_2[a-b] - AssertionError: assert 'h' in 'b'
FAILED JointParametrizationOfMultipleTestMethodsOfSameClass.py::TestClass::test_2[c-d] - AssertionError: assert 'a' in 'c'
================================================== 2 failed, 2 passed in 0.46s =================================================== 
```
<a name=adv2></a>
##### 2. Reuse of test data and test logic via subclass inheritance
```py
# in file `test_example.py`
class TestClass:
    a: int = 3
    b: int = 4
    def test_a_positive(self) -> None:
        assert self.a >= 0

class TestSubclass(TestClass):      #Subclass of TestClass
    c: int = 8

    def test_a_even(self) -> None:  #Checking Method from base class
        assert self.a % 2 == 0

    def test_b(self) -> None:       #Checking Method from base class
        assert self.b == 4
        
> pytest.exe '.\Adv2-Reuse of test data and test logic via subclass inheritance.py'
====================================================== test session starts =======================================================
platform win32 -- Python 3.10.8, pytest-7.1.3, pluggy-1.0.0
rootdir: C:\Users\amitk\source\repos\Python-Based-Test-Scripting\pytest\Group_Multiple_tests_in_1_class
plugins: html-3.2.0, metadata-2.0.4
collected 4 items

Adv2-Reuse of test data and test logic via subclass inheritance.py ..F.       [100%]  << All test cases executed

============================================================ FAILURES ============================================================ 
____________________________________________________ TestSubclass.test_a_even ____________________________________________________ 

self = <Adv2-Reuse of test data and test logic via subclass inheritance.TestSubclass object at 0x000001DC2FF53190>

    def test_a_even(self) -> None:  #Checking Method from base class
>       assert self.a % 2 == 0
E       assert (3 % 2) == 0
E        +  where 3 = <Adv2-Reuse of test data and test logic via subclass inheritance.TestSubclass object at 0x000001DC2FF53190>.a
Adv2-Reuse of test data and test logic via subclass inheritance.py:12: AssertionError
==================================================== short test summary info ===================================================== 
FAILED Adv2-Reuse of test data and test logic via subclass inheritance.py::TestSubclass::test_a_even - assert (3 % 2) == 0
================================================== 1 failed, 3 passed in 4.27s =================================================== 
```

<a name=fix></a>
### Fixtures
- **What?**
  - A fixture in Python is a fixed state of data that is used as a baseline for running tests.
  - It provides a known set of inputs and expected outputs, allowing developers to test the behavior of their code under controlled conditions. 
<a name=ex1></a>
- **Example-1: Fruit Basket**
```py
# cat fixtures.py

import pytest

"""
1. Created 3 fixtures (ie 3 fruit objects)
  [apple]
  [guvava]
  [banana, apple]
"""
@pytest.fixture             #Any function decorated with this decorator is fixture. This is fixture
def apple_fruit():
    return Fruit("apple")
    
@pytest.fixture             #This is fixture
def guvava_fruit():
    return Fruit("guvava")
    
@pytest.fixture             #This is fixture
def fruit_basket(apple_fruit):
    return [Fruit("banana"), apple_fruit]
    
#apple_fruit = [apple]  #guvava_fruit = [guvava]    #fruit_basket = [banana, apple]

class Fruit:
    def __init__(self, name):
        self.name = name
    def __eq__(self, other):
        return self.name == other.name
    
"""
2. Function to test [apple] is present in [fruit_basket] or not
"""
def test_apple_in_basket(apple_fruit, fruit_basket):      #Pass
    assert apple_fruit in fruit_basket

"""
3. Function to test [guvava] is present in [fruit_basket] or not
"""
def test_guvava_in_basket(guvava_fruit, fruit_basket):    #Fail
    assert guvava_fruit in fruit_basket

# pytest .\fixtures.py
fixtures.py:24: AssertionError
==================================================== short test summary info ==================================================== 
FAILED fixtures.py::test_guvava_in_basket - assert <fixtures.Fruit object at 0x000002973F21F1F0> in [<fixtures.Fruit object at ...================================================== 1 failed, 1 passed in 0.48s ===============================================
```
<a name=ex2></a>
- **Example2: Testing HashMap using Fixtures**
```py
import pytest

"""
1. Create a fixture which declares a HashMap (ie Key,value) pairs
"""
@pytest.fixture
def dict():
    data = {'key1': 'value1', 'key2': 'value2', 'key3': 'value3'}
    return data

"""
2. Function to check if Hashmap has value1 for key1
"""
def test_fixture1(dict):
    assert dict['key1'] == 'value1'

def test_fixture2(dict):
    assert dict['key2'] == 'value1'
```

<a name=advf></a>
#### Advatages/Disadvatanges of Fixtures
- **Advantages**
  - _1._  fixture can be reused in multiple tests, hence reduce code duplication and promote consistency.
- **Disadvantages**
  - _1._ They require small differences in the data that might litter the test objects. 
  - _2._ Because of the additional indirection layer, it might even be worse.
  - _3._ Finding the ideal level of fixture use requires some practise and consideration, as with most abstractions.

<a name=plug></a>
### [Using plugins with pytest](https://testautomationu.applitools.com/pytest-tutorial/chapter10.html)
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
