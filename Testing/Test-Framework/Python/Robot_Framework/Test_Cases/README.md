- Test Cases
  - [1. Test case file](#t1)
  - [2. Test Suite Directory](#t2)
- Test Case File Formats
  - [1. Space Seperated Format](#ssf)
  - [2. Pipe Seperated Format](#psf)
  - [3. reStructuredText format](#ret)
- [Dividing data into multiple rows](#dd)
- [Arguments to functions](#varg)
- [Named Arguments](#na)
- [Error messages](#em)
- [Tagging](#tag)
- [Test setup and teardown](#st)


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

<a name=na></a>
### Named Arguments
- named arguments are a way to pass arguments to keywords using the name of the argument rather than the position of the argument in the argument list. 
- Named arguments are also sometimes referred to as keyword arguments or named parameters.
- **Advantages:**
  - Named arguments are particularly useful when a keyword has a large number of arguments or when the order of the arguments is not clear. 
  - By using named arguments, you can make your code more readable and easier to understand.
- Example:  
```robot
*** Settings ***
Library    Telnet    prompt=$    default_log_level=DEBUG    //This uses named arguments syntax with library keywords

*** Test Cases ***
Example
    Open connection    10.0.0.42    port=5002    alias=example
    List files    options=-lh
    List files    path=/tmp    options=-l

*** Keywords ***
List files
    [Arguments]    ${path}=.    ${options}=
    Execute command    ls ${options} ${path}
    
# robot test.robot
TimeoutError: [WinError 10060] A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond
```

<a name=em></a>
### Error messages
- The error message assigned to a failed test case is got directly from the failed keyword. Often the error message is created by the keyword itself, but some keywords allow configuring them.
- By default error messages are normal text, but they can contain HTML formatting. This is enabled by starting the error message with marker string *HTML*. This marker will be removed from the final error message shown in reports and logs. Using HTML in a custom message is shown in the second example below
```robot
*** Test Cases ***
Normal Error
    Fail    This is a rather boring example...

HTML Error
    ${number} =    Get Number
    Should Be Equal    ${number}    42    *HTML* Number is not my <b>MAGIC</b> number.
    
# robot test.robot
==============================================================================
Error Message
==============================================================================
Normal Error                                                          | FAIL |
This is a rather boring example...
------------------------------------------------------------------------------
HTML Error                                                            | FAIL |
No keyword with name 'Get Number' found.
------------------------------------------------------------------------------
Error Message                                                         | FAIL |
2 tests, 0 passed, 2 failed
==============================================================================
```

### Variable Names
- We can define variable names using `$`
```
*** Variables ***
${TEST1}      ${1234}
${TEST2}      ${5678}

*** Test Cases ***
Value of TEST1 = ${TEST1}
Value of TEST2 = ${TEST2}
Value of TEST3 = ${TEST3}
    # ...
    
# robot test.robot
Value of TEST1 = 1234
Value of TEST2 = 5678 
Value of TEST3 = ${TEST3}  
```

<a name=tag></a>
### Tagging
- Tags are used for classifying test cases and also user keywords. 
- Tags are free text and Robot Framework itself has no special meaning for them except for the reserved tags.
- **Usage of Tags:**
  - They are shown in test reports, logs and, of course, in the test data, so they provide metadata to test cases.
  - Statistics about test cases (total, passed, failed and skipped) are automatically collected based on them.
  - They can be used to include and exclude as well as to skip test cases.
- **Ways to specify tags:**
  - Test Tags in the Setting section
  - `[Tags]` with each test case
  - `--settag` command line option
  - Set Tags, Remove Tags, Fail and Pass Execution keywords
```robot
*** Settings ***
Test Tags       requirement: 42    smoke

*** Variables ***
${HOST}         10.0.1.42

*** Test Cases ***
No own tags
    [Documentation]    This test has tags 'requirement: 42' and 'smoke'.
    No Operation

Own tags
    [Documentation]    This test has tags 'requirement: 42', 'smoke' and 'not ready'.
    [Tags]    not ready
    No Operation

Own tags with variable
    [Documentation]    This test has tags 'requirement: 42', 'smoke' and 'host: 10.0.1.42'.
    [Tags]    host: ${HOST}
    No Operation

Set Tags and Remove Tags keywords
    [Documentation]    This test has tags 'smoke', 'example' and 'another'.
    Set Tags    example    another
    Remove Tags    requirement: *
```

<a name=st></a>
### Test setup and teardown
- Robot Framework has similar test setup and teardown functionality as many other test automation frameworks. 
- **Test setup:** is something that is executed before a test case, 
- **Test teardown:** is executed after a test case. 
- In Robot Framework setups and teardowns are just normal keywords with possible arguments.
- **Keywords**
  - **1. teardown:** 
    - Always executed even when a test case fails.
    - In addition, all the keywords in the teardown are also executed even if one of them fails. 
```robot
*** Settings ***
Test Setup       Open Application    App A
Test Teardown    Close Application

*** Test Cases ***
Default values
    [Documentation]    Setup and teardown from setting section
    Do Something

Overridden setup
    [Documentation]    Own setup, teardown from setting section
    [Setup]    Open Application    App B
    Do Something

No teardown
    [Documentation]    Default setup, no teardown at all
    Do Something
    [Teardown]

No teardown 2
    [Documentation]    Setup and teardown can be disabled also with special value NONE
    Do Something
    [Teardown]    NONE

Using variables
    [Documentation]    Setup and teardown specified using variables
    [Setup]    ${SETUP}
    Do Something
    [Teardown]    ${TEARDOWN}
```
