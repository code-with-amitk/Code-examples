# Dynamic OR Shared Objects
- Extensions
  - `*.so`(linux)
  - `*.dll`(windows)
## What
- A dynamic library does not become part of application code. These are stored at some memory (/usr/lib64/libutil.so) and from there compiler picks them.https://www.youtube.com/watch?v=KNr4tAPvbvQ
## Advantages of Dynamic Libraries
- size of Binary not increased:    Since only address of function is placed inside with the exe, final size of binary is not increased.
- If changes happens in Dynamic Library provided by 3rd party, application need not to be complied

## Creating Linking `*.so`
### 1. Create shared object
- Object files for shared libraries need to be compiled as position independent code (-fPIC) because they are mapped to any position in the address space.
  - See `-fPIC` option on Compile/gcc-options.md
- /bin Contains executables for basic operations. Commands: mkdir, cp, chmod, uname etc
- /usr/bin Installed softwares by user  
```
# /usr/bin/vim total.cpp
  int sum(int a, intb){ 
    return a+b; 
  }
# /usr/bin/g++ -c -fPIC total.cpp                           //Step-1: Create *.o (Object Files) with -fPIC flag enabled
# /bin/ls
  total.o total.cpp
# /usr/bin/g++ -shared ./total.o -o libtotal.so             //Step-2: Create *.so(Shared object) with -shared flag
# /bin/ls
  libtotal.so total.o total.cpp
# /usr/bin/nm -D libtotal.so                                //List symbols
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
000000000000057a T _Z3sumii
0000000000201020 B __bss_start
                 w __cxa_finalize
                 w __gmon_start__
0000000000201020 D _edata
0000000000201028 B _end
0000000000000590 T _fini
0000000000000468 T _init
```

### 2. Link the shared object
```
# /usr/bin/vim main.c                                          //Step-3: Create driver file
  int sum(int, int);
  int main(){ 
    int c = sum(3,2); 
  }
# /usr/bin/g++ main.cpp -L/home/amit/amit-code -ltotal -o TEST    //Step-4: -L<path-to-shared-lib-dir>  -l<named of shared library without .so>
# /bin/ls
  TEST  libtotal.so  main.cpp  total.cpp
# ldd TEST                                                      //Step-5: List all shared libraries linked to this exe
  linux-vdso.so.1 (0x00007ffff2074000)
  libtotal.so => not found
  libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fcee89d0000)
  /lib64/ld-linux-x86-64.so.2 (0x00007fcee9000000)
```
