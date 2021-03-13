## Cmake
- **What** Cmake(opensource) is NOT a build system but build-system generator. It generates `Makefiles` which can be used for compile the project.
- **Why?** Platform neutral code(same code can be compiled on both Windows & Unix)

## Steps of Compile/Run on Windows
- **1. Get, Configure cmake in Env Variable**
  - *1a.* Get cmake-3.20.0-rc4-windows-x86_64.zip from [Windows x64 ZIP](https://cmake.org/download/)
  - *1b.* Extract cmake in any Directory `C:\go-here\cmake`
  - *1c.* Set PATH enviornment variable to `C:\go-here\cmake\bin
- **2. Build project with cmake**
```c
Open command prompt
cmd> cd C:\go-here\Code\Sum_of_2_Numbers\
cmd> cmake -G "Visual Studio 16 2019" .      //This creates VS Project files to build
```
