- **Static Library**
  - **Create/Link Static Object**
    - [A. Linux `*.a`](#lis)
    - [B. Windows `*.lib`](#wins)
- [Dynamic](#dy)


## Static Library / Static Object

**Disadvantages**

*1. Increased Size of Binary*
  - If Static Library contains 1000 functions, this all source code will become part of application code. Size of application code becomes large.

*2. If changes in static library, application code has to be complied everytime*
  - 3rd Party static library developer done some changes in libtotal.a & publishes on internet, to take those changes we have to download & compile with our exe again.

### Create/Link Static Object
<a name=lis></a>
#### A. Linux
- _1._ Create static object/Library `libtotal.a`
  - /bin Contains executables for basic operations. Commands: mkdir, cp, chmod, uname etc
  - /usr/bin Installed softwares by user
```c
# cat total.c
  int total(int a, int b) {
    return a+b;
  }
# g++ -c total.c                             //Step-1: Create Object file
# ls
  total.c total.o
# nm total.o                                //Step-2: list symbols from object files 
  0000000000000000 T _Z5totalii
# ar rs libtotal.a total.o                  //Step-3: Create Archive  [OR ar -cvq]
  creating libtotal.a
# ls
  libtotal.a  total.c  total.o
r: Insert the files member... into archive (with replacement)
s: Add an index to the archive, or update it if it already exists.
```
- _2._ Link static library to code `libtotal.a`
```c
# cat main.c
  # include<iostream>
  int total(int, int);
  int main(){
        cout<<total(2,3);
  }
# g++ main.cpp
/tmp/ccqttCD4.o: In function `main':
main.cpp:(.text+0xf): undefined reference to `total(int, int)'      <<Linker Error. Compiler only check declaration(which it finds). Linker cannot find definition
collect2: error: ld returned 1 exit status

# g++ main.cpp libtotal.a -o TEST                       //Step-4: Create EXE
# ./TEST
5
```

<a name=wins></a>
#### A. Windows
- _1._ Create `*.lib` file
  - Visual Studio 2019 > File > New > Project > Select (Static Library) > Name (StaticLib1). VS will create following folders
```c
StaticLib1
  |- Header Files
  |- Resource Files
  |- Source Files
      |- StaticLib1.cpp
      
# cat StaticLib1.cpp          //Define your function inside StaticLib1.cpp
int MySum(int a, int b){
  return a+b;
}      

//Build solution, it will create StaticLib1.lib in project folder.
```
- _2._ Check Function names present in `*.lib`
  - Open Visual Studio Command Prompt. Tools > Command Line > Developer Command Prompt
```c
> cd <directory-containing-lib-file>
> dumpbin /symbols /exports StaticLib1.lib
  File Type : LIBRARY
```
- _3._ Link (`*.lib`)Static library with Application
  - Open a new Console Application. Visual Studio 2019 > File > New > Project > C++ > Name(test)
  - Choose Platform, Include Header Files, Link Static Library
```c
Project Properties 
  - Configuration: Active(Debug)    Platform: Win32
  - C/C++ > General > Additional Include Directories                         //Include Header file
  - Linker > library Dependencies (Provide complete path of StaticLib1.lib)  //Link the Library
  - Linker > Input > Additional Dependencies > StaticLib1.lib                //Add Library Name
```

