- Test Cases
  - [1. Test case file](#t1)
  - [2. Test Suite Directory](#t2)
- Test Case File Formats
  - [1. Space Seperated Format](#ssf)
  - [2. Pipe Seperated Format](#psf)


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
$ vim test_1.robot
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
