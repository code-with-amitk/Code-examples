## SOURCE FILE INCLUSION
  - This is inclusion of other source file into current source file at the line immediately after the directive.
  
### TYPES OF FILE INCLUSIONS
  1. **#include <filename>**
     - Searches for filename at standard paths defined by implementation(ie standard include directories)
     - standard include directories usually can be controlled by the user through compiler options
  2. **#include "filename"**
     - search for the files that are not controlled by the implementation
     - 1st search present working directory, only if the file is not found, search the standard include directories as with (1)
  3. **__has_include ( " filename " ) OR __has_include ( < filename > )	C++17**
     - Checks whether file(header or source) exists before including it.
