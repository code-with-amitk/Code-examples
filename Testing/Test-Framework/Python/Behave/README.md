**Behave**
- [How Behave works](#h)
- Examples
  - [1. Testing product-j](#e1)

### Behave / BDD(Behaviour-driven Development)
#### BDD?
- [Agile software development technique](System-Design/Concepts/Scrum/README.md#ag) that encourages collaboration between developers, QA and non-technical or business participants in a software project
- BDD focuses on obtaining a clear understanding of desired software behavior through discussion with stakeholders.
- It extends TDD by writing test cases in a natural language that non-programmers can read. 
- [BDD Practices](https://cucumber.io/docs/gherkin/)
  - Gherkin is a plain-text language with a simple structure

<a name=h></a>
### How Behave works?
- We need to have below directory structure, where:
  - _1. feature file:_ contains Plain text(english) sentences filled by Non-Technical people(PLM or Project Manager).
    -  This file contains keywords (Feature, Scenario, Given, When, Then)
```c
Scenario: some scenario
    Given some condition          
    When some action is taken     //testcase
    Then some result is expected. //output
```
  -  _2. steps directory:_ Contains actual test cases to be executed
    -  _2a. python file:_ Python file inside steps directory contains actual **tests which corresponds to keywords present in feature file**.
```c
Test
  |- mytest.feature
    |- steps
      |- mytest.py
```

### Examples
<a name=e1></a>
#### Example-1 (Testing Product)
```py
product-j
  |- product.feature
    |- steps
      |- product.py

$ product.feature
#Let's consider we have a product which comprises of 2 modules.
#  module1: Reads text from file and converts to json passes to module2.
#  module2: Gets json, saves in DB. sends output when reader queries
#
#  test.txt
#   a a1
#   b b1
#            <========== Product-J ============> 
#     -----> Module1
#           Read test.txt
#           convert to test.json
#               -------test.json-------> Module2
#                                       Save in DB
#                                                           Reader
#                                           <--info about a---
#                                           --------a1------->

Feature: Tests for Product-j
  Scenario: TEST-MODULE-1
     Given we have test.txt file present
      When We read test.txt
      Then reading test.txt success
```
- **steps\product.py**
```py
steps/product.py
from behave import *

@given('we have test.txt file present')
def step_impl(context):
    pass

@when('We read test.txt')
def step_impl(context):
    assert True is not False

@then('reading test.txt success')
def step_impl(context):
    assert context.failed is False
```
- **Testing**
```py
> behave
Feature: Tests for Product-j # product.feature:18

  Scenario: TEST-MODULE-1               # product.feature:20 
    Given we have test.txt file present # steps/product.py:3 
    When We read test.txt               # steps/product.py:7 
    Then reading test.txt success       # steps/product.py:11

1 feature passed, 0 failed, 0 skipped
1 scenario passed, 0 failed, 0 skipped
3 steps passed, 0 failed, 0 skipped, 0 undefined
Took 0m0.004s
```
