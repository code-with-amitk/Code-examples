**nose2**
- [Features](#f)
- Comparison
  - [nose vs unittest](#c1)
  - [nose2 vs nose vs unittest2](#c2)
- Examples
  - [Ex-1. nose2 provides more tools wrt unittest (Eg: startswith())](#e1)

## nose2
- nose2 is successor to nose and extension of pytest (unitest). Hence it provides more tools wrt unittest.
### [Advantages & Disadvatanges](https://blog.testproject.io/2020/10/27/top-python-testing-frameworks)
**Plugins**
- Nose2 provides a better plugin API and simplifies internal interfaces and processes. 
- There are many plugins that built-in the Nose2 module, and these plugins are loaded by default.

<a name=f></a>
### Features
- **1. Test Discovery:** 
  - All testcase files must begin with `test_`
  - The plugin looks for modules (or test files) in packages and directories whose names start with test
- **2. Parameterized Tests:**
  - Unlike Nose that required installing a separate package for test parameterization, Nose2 supports inherently.
- **3. Fixtures in Nose2**
  - Nose2 has support for fixtures at class, module, and test (or method) levels, similar to pytest.

### Comparison
<a name=c1></a>
#### [nose vs unitest](https://knapsackpro.com/testing_frameworks/difference_between/nose/vs/unittest)

<a name=c2></a>
#### nose2 vs nose vs unittest2
||nose|nose2|unittest2|
|---|---|---|---|
|Test Discovery and Loading|loads test modules lazily|nose2 loads all tests first, then begins test execution||
|Fixtures||same as unittest2(supports class, module level fixtures)||
|Parameterized and Generator Tests||supports more parameterized and generator tests||
|Configuration|wants plugins to make all of their configuration parameters available as command-line options|all configuration to be done via configuration files||
|Plugin Loading|uses setuptools entry points to find and load plugins.|nose2 requires that all plugins be listed in config files||
|Plugin API||Supports new plugin API based on the work done by Michael Foord in unittest2’s plugins branch.||
|Internals|nose wraps or replaces everything in unittest|nose2 does subclass TestProgram, and install its own loader, runner, and result classes||
|License|LGPL|BSD||

### Installation
```py
$ pip install nose2
  Downloading nose2-0.12.0-py2.py3-none-any.whl (152 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 152.8/152.8 kB 3.0 MB/s eta 0:00:00
Installing collected packages: nose2
Successfully installed nose2-0.12.0
```
### Examples
<a name=e1></a>
#### Ex-1. nose2 provides more tools wrt unittest (Eg: startswith())
**uniitest style**
```py
# in test_simple.py
import unittest

class TestStrings(unittest.TestCase):
    def test_upper(self):
        self.assertEqual("spam".upper(), "SPAM")
```
**nose2 style: import params**
- nose2 will look for tests in Python files whose names start with `test` and runs every test function it discovers.
```py
# test.py
from nose2.tools import params                        # nose2 supported feature

@params("Mr. Hello", "Miss New", "Mr. World")
def test_is_knight(value):
    assert value.startswith('Mr')

> nose2 -v --pretty-assert
'Miss New'
----------------------------------------------------------------------
Traceback (most recent call last):
  File "C:\Users\amitk\source\repos\Python-Based-Test-Scripting\nose2\example1\test.py", line 5, in test_is_knight
    assert value.startswith('Mr')
AssertionError

----------------------------------------------------------------------
Ran 4 tests in 0.091s
FAILED (failures=1, errors=1)
```
