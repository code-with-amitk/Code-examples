### Contents
  - A. Linker Errors
    a. undefined reference
  
## A. LINKER ERRORS
- Those errors which occurs at linking stage.
- This means Compiler compiles the program successfully, which linker(Finding actual definition in CS) finds error.

### A1. UNDEFINED REFERENCE
- **Meaning** 
  - *Compiler* can find reference of object (class, function, variable, etc.).    //Compilation Ok
  - *Linker* cannot find the definition of a linked object.
- **Reasons for udefined reference**
  a. *No Definition Provided For Object* The programmer has forgotten to define the object.
```c++
#include <iostream>
int fun();
int main()
{
    fun();
}
$ g++ test.cpp
/usr/bin/ld: /tmp/ccJoOloD.o: in function `main':
undefined-reference.cpp:(.text+0x9): undefined reference to `ffun()'
collect2: error: ld returned 1 exit status

//How to resolve? Provide definition of fun()
```
