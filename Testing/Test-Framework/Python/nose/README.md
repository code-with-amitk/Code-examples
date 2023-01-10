**nose**
- Comparison
  - [nose vs unittest](#c1)
  - [nose2 vs nose vs unittest2](#c2)
- Examples
  - [Ex-1. nose2 provides more tools wrt unittest (Eg: startswith())](#e1)

## nose
- This is extension of pytest (unitest). Hence it provides more tools wrt unittest.

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
```
