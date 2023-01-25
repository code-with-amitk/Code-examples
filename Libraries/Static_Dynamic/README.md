- [Static vs Dynamic Library](#vs)
- **Static Object**
  - [a. Linux](#lis)
  - [b. Windows](#wins)
- **Dynamic Object**
  - [a. Linux](#lid)
  - [b. Windows](#wind)


<a name=vs></a>
## Static vs Shared
```c
            |       Static                                                     |   Dynamic
------------|------------------------------------------------------------------|------------
Extension   | Linux  (*.a)                                                     | (*.so)
            | Windows (*.lib)                                                  | (*.dll)

Disadv      | 1. Increased Size of Binary:                                     |
            |    If Static Library contains 1000 functions, all                |
                 source code will become part of application code. 
                 Size of application code becomes large.
            | 2. If changes in static lib, application has to be complied again
                 3rd Party static library developer done some changes in 
                 libtotal.a & publishes on internet, to take those changes we 
                 have to download & compile with our exe again.
Advantages  |                                                                  | 1. Size of Binary not increased
                                                                                    A dynamic library does not become part of
                                                                                    application code. These are stored at some
                                                                                    memory (/usr/lib64/libutil.so) Only address
                                                                                    of function is placed inside with the exe.
                                                                               | 2. If changes happens in Dynamic Library
                                                                                    provided by 3rd party, application need not
                                                                                    to be complied.
```

### 1. Static Lib
<a name=lis></a>
#### a. Linux
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
#### b. Windows          //WORKING
- _1._ Create `*.lib` file
  - Visual Studio 2019 > File > New > Project > Search (Static Library) > Name (StaticLib1). VS will create following folders
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
  - Linker > General > Additional library Dependencies (Provide complete path of StaticLib1.lib)  //Link the Library
  - Linker > Input > Additional Dependencies > StaticLib1.lib                //Add Library Name
```

### 2. Dynamic Lib
<a name=lid></a>
#### a. Linux
- _1._ Create shared object `*.so`
  - Object files for shared libraries need to be compiled as **position independent code (-fPIC)** because they are mapped to any position in the address space. See `-fPIC` option on Compile/gcc-options.md
```c
# cat total.cpp
  int sum(int a, intb){ 
    return a+b; 
  }
# g++ -c -fPIC total.cpp                           //Step-1: Create *.o (Object Files) with -fPIC flag enabled
# ls
  total.o total.cpp
# g++ -shared ./total.o -o libtotal.so             //Step-2: Create *.so(Shared object) with -shared flag
# ls
  libtotal.so   total.o   total.cpp
```
- _2._ Check what function are present in `*.so`
```c
# nm -D libtotal.so                                //List symbols
```
- _3._ Link the shared object `*.so` with application
```c
# vim main.c                                              //Step-3: Create driver file
  int sum(int, int);
  int main(){ 
    int c = sum(3,2); 
  }
# g++ main.cpp -L/home/amit/amit-code -ltotal -o TEST      //Step-4: -L<path-to-shared-lib-dir>  -l<named of shared library without .so>
# ls
  TEST  libtotal.so  main.cpp  total.cpp
# ln -s /home/amit/amit-code/libtotal.so /usr/lib
``` 
- _4._ Listing all `*.so` linked to exe
```c
# ldd TEST
  linux-vdso.so.1 (0x00007ffff2074000)
  libtotal.so => not found
  libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fcee89d0000)
  /lib64/ld-linux-x86-64.so.2 (0x00007fcee9000000)
```

<a name=wins></a>
#### b. Windows
