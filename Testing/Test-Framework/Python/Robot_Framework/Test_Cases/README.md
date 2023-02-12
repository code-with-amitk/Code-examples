- Test Cases
  - [1. Test case file](#t1)
  - [2. Test Suite Directory](#t2)
- Test Case File Formats
  - [1. Space Seperated Format](#ssf)
  - [2. Pipe Seperated Format](#psf)
  - [3. reStructuredText format](#ret)
- [Dividing data into multiple rows](#dd)
- [Arguments to functions](#varg)


<a name=tc></a>
### Test Cases
- Test cases are created in test case files.
- **Test Suite:** Group of test cases in a file are test suites.

<a name=t1></a>
#### 1. Test case file
Test case file contains test cases.

<a name=t2></a>
#### 2. Test Suite Directory
Directory contaning test case files. This will also have a initialization file.


### Test Case file formats
<a name=ssf></a>
#### 1. Space Seperated Format
- **Seperator** is Space. keywords and their arguments, are separated from each others with two or more spaces.
```robot
$ vim space_sepearted_format.robot
*** Settings ***
Documentation     Example using the space separated format.
Library           OperatingSystem

*** Variables ***
${MESSAGE}        Hello, world!

*** Test Cases ***
My Test
    [Documentation]    Example test.
    Log    ${MESSAGE}
    My Keyword    ${CURDIR}

Another Test
    Should Be Equal    ${MESSAGE}    Hello, world!

*** Keywords ***
My Keyword
    [Arguments]    ${path}
    Directory Should Exist    ${path}
    
C:\Users\amitk\source\repos\Python-Based-Test-Scripting\robot_framework>robot test-1.robot
==============================================================================
Test-1 :: Example using the space separated format.
==============================================================================
My Test :: Example test.                                              | PASS |
------------------------------------------------------------------------------
Another Test                                                          | PASS |
------------------------------------------------------------------------------
Test-1 :: Example using the space separated format.                   | PASS |
2 tests, 2 passed, 0 failed
==============================================================================
```

<a name=psf></a>
#### 2. Pipe Seperated Format
- **Separator** is the pipe character surrounded with spaces (|)
- **Problem with Space delimited format:** 
  - _1._ Visually separating keywords from arguments can be tricky, if there are lot of arguments.
- **Rules:**
  - _1._ Leading pipe character is mandatory
  - _2._ Pipe at the end of the line is optional
  - _3._ Must always be at least one space or tab on both sides of the pipe except at the beginning and at the end of the line 
  - _4. Aligning Pipes:_ Not required, but makes data visually more clear
```robot
| *** Settings ***   |
| Documentation      | Example using the pipe separated format.
| Library            | OperatingSystem

| *** Variables ***  |
| ${MESSAGE}         | Hello, world!

| *** Test Cases *** |                 |               |
| My Test            | [Documentation] | Example test. |
|                    | Log             | ${MESSAGE}    |
|                    | My Keyword      | ${CURDIR}     |
| Another Test       | Should Be Equal | ${MESSAGE}    | Hello, world!

| *** Keywords ***   |                        |         |
| My Keyword         | [Arguments]            | ${path} |
|                    | Directory Should Exist | ${path} |

>robot Pipe_separated_format.robot
==============================================================================
Pipe separated format :: Example using the pipe separated format.
==============================================================================
My Test :: Example test.                                              | PASS |
------------------------------------------------------------------------------
Another Test                                                          | PASS |
------------------------------------------------------------------------------
Pipe separated format :: Example using the pipe separated format.     | PASS |
2 tests, 2 passed, 0 failed
==============================================================================
```

<a name=ret></a>
#### 3. reStructuredText format
- This is  is a lightweight markup language designed to be both (a) processable by documentation-processing software such as Docutils, and (b) easily readable by human programmers who are reading and writing Python source code
-  File format for textual data used primarily in the Python
- Stored in `rst` or `rest` extension
```robot
reStructuredText example
------------------------

This text is outside code blocks and thus ignored.

.. code:: robotframework

   *** Settings ***
   Documentation    Example using the reStructuredText format.
   Library          OperatingSystem

   *** Variables ***
   ${MESSAGE}       Hello, world!

   *** Test Cases ***
   My Test
       [Documentation]    Example test.
       Log    ${MESSAGE}
       My Keyword    ${CURDIR}

   Another Test
       Should Be Equal    ${MESSAGE}    Hello, world!

Also this text is outside code blocks and ignored. Code blocks not
containing Robot Framework data are ignored as well.

.. code:: robotframework

   # Both space and pipe separated formats are supported.

   | *** Keywords ***  |                        |         |
   | My Keyword        | [Arguments]            | ${path} |
   |                   | Directory Should Exist | ${path} |

.. code:: python

   # This code block is ignored.
   def example():
       print('Hello, world!')

>robot restructuredFormat.rst
==============================================================================
restructuredFormat :: Example using the reStructuredText format.
==============================================================================
My Test :: Example test.                                              | PASS |
------------------------------------------------------------------------------
Another Test                                                          | PASS |
------------------------------------------------------------------------------
restructuredFormat :: Example using the reStructuredText format.      | PASS |
2 tests, 2 passed, 0 failed
==============================================================================
```

<a name=dd></a>
### Dividing data into multiple rows
- if data does not fit in 1 row, it can be placed into multiple lines using ellipsis (`...`).

<a name=varg></a>
### Variable number of arguments
- **Remove files:** This keyword takes variable number of arguments
- **Join:** keyword takes atleast 1 argument.
```robot
*** Test Cases ***
Example
    Remove Files    ${TEMPDIR}/f1.txt    ${TEMPDIR}/f2.txt    ${TEMPDIR}/f3.txt
    @{paths} =    Join Paths    ${TEMPDIR}    f1.txt    f2.txt    f3.txt    f4.txt
```
