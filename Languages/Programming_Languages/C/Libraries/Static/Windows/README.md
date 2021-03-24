### 1. Create *.lib file (Static library)
- *1.* Visual Studio 2019 > File > New > Project > Select (Static Library) > Name (StaticLib1)
- *2.* VS will create following folders
```c
StaticLib1
  |- Header Files
  |- Resource Files
  |- Source Files
      |- StaticLib1.cpp
```
- *3.* Define your function inside StaticLib1.cpp
```c
# cat StaticLib1.cpp
int MySum(int a, int b){
  return a+b;
}
```
- *4.* Build solution, it will create StaticLib1.lib in project folder.

### 2. Checking Function names present in `*.lib`
- *1.* Open Visual Studio Command Prompt. Tools > Command Line > Developer Command Prompt
```c
> cd <directory-containing-lib-file>
> dumpbin /symbols /exports StaticLib1.lib
  File Type : LIBRARY
  
  COFF SYMBOL TABLE
  01A 00000 SECT4 notype () External  | ?MySum@@KKASNDK (int  __cdecl MySum(int, int))
```

### 3. Linking Static library with Application
- *1.* Open a new Console Application. Visual Studio 2019 > File > New > Project > C++ > Name(test)
- *2.* Include Header file
```html
  Project Properties > C/C++ > General > Additional Include Directories
```
- *3.* Link the Library
```html
 Project Properties > Linker > library Depdencies (Provide complete path of StaticLib1.lib)
```
