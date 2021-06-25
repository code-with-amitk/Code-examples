## 1. Create static object/Library `libtotal.a`
- /bin Contains executables for basic operations. Commands: mkdir, cp, chmod, uname etc
- /usr/bin Installed softwares by user
```c
# /bin/cat total.c                  
    int total(int a, int b){
        return (a+b);
    }
# g++ -c total.c                             //Step-1: Create Object file
# ls
  total.c total.o
# nm total.o                                //Step-2: list symbols from object files 
  0000000000000000 T _Z5totalii
# /usr/bin/ar rs libtotal.a total.o         //Step-3: Create Archive  [OR ar -cvq]
  creating libtotal.a
# /bin/ls
  libtotal.a  total.c  total.o
  
ar Options:
  r: Insert the files member... into archive (with replacement)
  s: Add an index to the archive, or update it if it already exists.
```

### 2. Link static library to code `libtotal.a`
```c
# cat main.c
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

# g++ main.cpp libtotal.a -o TEST                       //Step-4: Create EXE
# ./TEST
5
```
