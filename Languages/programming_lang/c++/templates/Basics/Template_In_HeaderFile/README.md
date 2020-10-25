## Problem
- Template function declaration is present in Header File, Definition inside source. But **Linker Error** on compilation.
  - **Linker Error: undefined reference to `void fun<int>()'**
```c++
//test.hpp
#pragma once
template <typename T>
void fun ();

//test.cpp
#include <iostream>
#include "test.hpp"
template <typename T>
void fun () {
 std::cout <<"In fun" << std::endl;
}

//main.cpp
#include "test.hpp"
int main() {
 fun<int>();
}

# g++ main.cpp test.cpp -I.
Linker Error: undefined reference to `void fun<int>()'
```
- **Why Linker Error?**
  - The definition of the function template fun() has not been instantiated.
- **Function template instantiation?**
  - *What?* Determining template arguments at compile time so that compiler can generate actual function(which is going to be used).
  - *Why?* 
    - A function template is not a Type or Function. No code is generated from a source file that contains only template definitions.
    - In order for any code to be generated, the template arguments must be determined so that the compiler can generate an actual function.
  - *How?* Compiler must know which definition should be instantiated.
  
## Solutions
### 1. Include test.cpp in main.cpp
### 2. Inclusion Model (recommended)
- **What?** Include definition of function template inside header file.
```c++
//test.hpp
#pragma once
#include <iostream>
#include "test.hpp"
template <typename T>
void fun ();

template <typename T>
void fun () {
 std::cout <<"In fun" << std::endl;
}

//main.cpp
#include "test.hpp"
int main() {
 fun<int>();
}
# g++ main.cpp -I.

```
- **Problems with inclusion model**
  - *1.* With header file system header files also gets included in main.cpp, which increases size and increses compilation time.
  
