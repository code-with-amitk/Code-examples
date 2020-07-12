# UNDEFINED REFERENCE
## LINKER ERRORS
- Those errors which occurs at linking stage.
- This means Compiler compiles the program successfully, which linker(Finding actual definition in CS) finds error.
- Undefined reference is **Linker Error**.

### A. MEANING OF UR
- *Compiler* can find reference of object (class, function, variable, etc.).    //Compilation Ok
- *Linker* cannot find the definition of a linked object.

### B. REASONS/CAUSES OF UR
#### B1. No Definition Provided For Object
- The programmer has forgotten to define the object.
```c++
int fun();
int main()
{
    fun();
}
$ g++ test.cpp
/usr/bin/ld: /tmp/ccJoOloD.o: in function `main':
undefined-reference.cpp:(.text+0x9): undefined reference to `ffun()'
collect2: error: ld returned 1 exit status

//How to resolve? Provide definition of fun()
```

#### B2. Wrong/Mismatched Definition
- Definition of function is different from what's declared.
- In Example below, declaration of function does not contain parameter, while definition does.
```c++
int fun();
int main()
{
    fun();
}
int fun(int n){
    cout<<"hello, world!!";
}
/usr/bin/ld: /tmp/cc3VJO9c.o: in function `main':
undefined-reference1.cpp:(.text+0x9): undefined reference to `fun()'
collect2: error: ld returned 1 exit status
```

#### B3. Object files not linked properly
- We have more than 1 source file and those are compiled independently. 
- At time linking, object files are not linked properly.
- Example: function `fun()` is declared in main.cpp & defined in `test.cpp`. 
  - When main.c is compiled seperately. We get -> undefined Reference
  - When both files are compiled together. No Error.
```c++
/////////////test.cpp////////////////
void fun(int a){
  cout<<a;
}

////////////main.cpp////////////////
int fun(int);
int main(){
  cout<<fun(1);
}
$ g++ main.c                                      <<<<<<<<<<<<<<<<Error when main.cpp is compiled seperately ie definition is not found
/usr/bin/ld: /tmp/ccugsclC.o: in function `main':
main.c:(.text+0xe): undefined reference to `fun(int)'
collect2: error: ld returned 1 exit status

$ g++ test.c main.c                               <<<<<<<<<<<<< No Error
$
```
