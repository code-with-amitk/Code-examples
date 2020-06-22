## SOURCE/HEADER FILE INCLUSION
  - This is inclusion of other source file into current source file at the line immediately after the directive.
  
### TYPES OF FILE INCLUSIONS
  1. **`#include <filename>`**
     - Searches for filename at standard paths defined by implementation(ie standard include directories)
     - standard include directories usually can be controlled by the user through compiler options
  2. **`#include "filename"`**
     - search for the files that are not controlled by the implementation
     - 1st search present working directory, only if the file is not found, search the standard include directories as with (1)
  3. **`__has_include ( "filename" ) OR __has_include ( <filename> )`	C++17**
     - **What** Checks whether file(header or source) exists before including it.
       - if (filename exists)
         - return 1
       - else
         - return 0
     - **Example**: if `test.h` exists include it & set HAVE_TEST=1. if `test.h` does not exists use `default.h`.
```c++
#if __has_include("test.h")
#  include "test.h"
#  define HAVE_TEST 1
#elif __has_include("default.h")
#  include "default.h"
#  define DEFAULT 1
#else
#  define HAVE_TEST 0
#endif

#include <iostream>

int main()
{
    if (HAVE_TEST)
        std::cout << "TEST is present.\n";
#if HAVE_TEST == 1
  int a = 3;
#else
  int a = 4;
#endif
    cout << "a = " << a << '\n';
}

//Ouput:
a=4                     //When test.h is not present
Test is present a=3     //When test.h is present
```
     
### PROBLEM OF DUPLICATE INCLUSION     
  -  To avoid repeated inclusion of the same file we use `header guards` or `#pragma once`
     1. Header Guards
```
#ifndef FOO_H_INCLUDED /* any name uniquely mapped to file name */
#define FOO_H_INCLUDED
// contents of the file are here
#endif
```

  
