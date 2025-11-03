**cmake**
- Install
- [cmake commands](#cmds)
- Examples
  - [1. Simple 1 file](#simp)
  - [2. Example having folder hierarchies](#folder)

## Cmake
- Cmake(opensource BSD License) is NOT a build system but build-system generator. It generates `Makefiles` which can be used for compile the project.
- It generates Platform neutral code(same code can be compiled on both Windows & Unix)

## Install
```c
Windows > kitware provides msi package
```

<a name=cmds></a>
## [cmake commands](https://code-with-amitk.github.io/Build_Systems/index.html)
- Create Executable: cmake_minimum_required, project, add_executable, target_sources
- Build Library: add_library, target_sources

## Examples
<a name=simp></a>
### 1. Simple 1 file
- _A. Generate Makefile on Linux and build_
```c
# vim CMakeLists.txt
cmake_minimum_required(VERSION 3.0)   #Set CMAKE version number
project(SUM VERSION 1.0)              #Set project-name
add_executable(SUM test.cpp)          #Create excutable file named SUM from test.cpp
configure_file(test.h test.h)         #Header File
target_include_directories(SUM PUBLIC   #Set search path for include files.
  "${PROJECT_BINARY_DIR}"
)

$ vim test.cpp
#include "test.h"
#include<iostream>
int main(){
  std::cout<<"sum "<<sum(1,2);
  return 1;
}

$ cat test.h
int sum(int a,int b){
	int VAR = 0;
#if defined(WIN32)
	VAR=4;
#else
	VAR=400;
#endif
  return a+b + VAR;
}
```
- _B. Build and run using Makefile_
```c
$ pwd
Sum_of_2_Numbers
$ mkdir Build
$ cd Build 
$ cmake ../
$ make
```
- _C. Generate `*.sln` files for Visual Studio 2019_
  - Install cmake-3.20.0-rc4-windows-x86_64.zip from [Windows x64 ZIP](https://cmake.org/download/)
  - Extract cmake in any Directory `C:\go-here\cmake`
  - Set PATH enviornment variable to `C:\go-here\cmake\bin`
```c
Open command prompt
cmd> cd C:\go-here\Code\Sum_of_2_Numbers\
cmd> cmake -G "Visual Studio 16 2019" .      //This creates VS Project files to build
```

<a name=folder></a>
### [2. Folder hierarchies](/Languages/Programming_Languages/c++/Design_Pattens/Behavioral/Mediator/Online_Auction/)
```c
 - driver
    |- main.cpp
 - seller
    |- src
          |- test1.cpp
    |- inc
          |- test1.h
 - mediator
    |- src
          |- test1.cpp
    |- inc
          |- test1.h	  
 - bidder
    |- src
          |- test1.cpp
    |- inc
          |- test1.h	
```
