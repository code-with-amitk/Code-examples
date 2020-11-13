## Cmake
- **What** Cmake is NOT a build system but build-system generator. It generates `Makefiles` which can be used for compile the project.
- **Features** cross-platform, open-source, compiler-independent method.

### Example-1 (Sum)
- **Steps**
  - **1. Create CMakeList.txt**
    - *1a.* Set CMAKE version number
    - *1b.* Set project-name and project version number(project-name=SUM)
    - *1c.* Set executable name and cpp files.  (EXECUTABLE CPP-FILES)
    - *1d.* Header file
    - *1e.* Set search path for include files.
  - **2. Create header file**
  - **3. Create source code file**
  - **4. Create Build directory and go in**
  - **5. Run cmake from inside of build directory**
  - **6. Make the code using Makefile**
  - **7. Run executable**
```c++
# pwd
/home/amit
# mkdir SimpleProg
# pwd
/home/amit/SimpleProg

# vim CMakeLists.txt                        //STEP-1
cmake_minimum_required(VERSION 3.0)         #1a

project(SUM VERSION 1.0)                    #1b

add_executable(SUM test.cpp)                #1c

configure_file(test.h test.h)               #1d

target_include_directories(SUM PUBLIC   #(ProjectName PUBLIC)     #1e
                           "${PROJECT_BINARY_DIR}"
                           )

# vim test.h                              //STEP-2
int sum(int a,int b){
  return a+b;
}

#include "test.h"                         //STEP-3
#include<iostream>
int main(){
  std::cout<<"sum "<<sum(1,2);
  return 1;
}

# pwd
/home/amit/SimpleProg
# mkdir build; cd build                  //STEP-4
# pwd
/home/amit/SimpleProg/build

# cmake ../                             //STEP-5
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/amit/amit-code/c++/Build-System/cmake/SimpleProg/build

# make                                    //STEP-6
Scanning dependencies of target SUM
[ 50%] Building CXX object CMakeFiles/SUM.dir/test.cpp.o
[100%] Linking CXX executable SUM
[100%] Built target SUM

# ./SUM                                   //STEP-7
sum 3
```
