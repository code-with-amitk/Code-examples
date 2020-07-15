# Static Object/Library
## Extensions
- `*.a`(linux)
- `*.lib`(windows)

## Disadvantages  
- Increased Size of Binary
  - If Static Library contains 1000 functions, this all source code will become part of application code. if library contains 1000 functions, size of application code becomes huge.
- If changes in static library, application code has to be complied everytime
  - 3rd Party static library developer done some changes in libtotal.a & publishes on internet, to take those changes we have to download & compile with our exe again.

## Creating/Linking Shared library
1. Create static object `libtotal.a`
- /bin Contains executables for basic operations. Commands: mkdir, cp, chmod, uname etc
- /usr/bin Installed softwares by user
```
# /bin/cat total.c                  
    int total(int a, int b){
        return (a+b);
    }
# /usr/bin/g++ -c total.c                             //Step-1: Create Object file
# /bin/ls
  total.c total.o
# nm total.o                                          //Step-2: list symbols from object files 
  0000000000000000 T _Z5totalii
# /usr/bin/ar rs libtotal.a total.o                   //Step-3: Create Archive  [OR ar -cvq]
  creating libtotal.a
# /bin/ls
  libtotal.a  total.c  total.o
```

| ar Option | Meaning |
| --- | --- |
| r | Insert the files member... into archive (with replacement) |
| s | Add an index to the archive, or update it if it already exists. |

2. Link static library to code `libtotal.a`
```
# /bin/cat main.c
  # include<iostream>
  using namespace std;
  int total(int, int);
  int main(){
        cout<<total(2,3);
  }
# /usr/bin/g++ main.cpp
/tmp/ccqttCD4.o: In function `main':
main.cpp:(.text+0xf): undefined reference to `total(int, int)'      <<Linker Error. Compiler only check declaration(which it finds). Linker cannot find definition
collect2: error: ld returned 1 exit status
# /usr/bin/g++ main.cpp libtotal.a -o TEST              //Step-4: Create EXE
# ./TEST
5
```
