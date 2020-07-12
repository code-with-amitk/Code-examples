### Contents
  - A. Linker Errors
    - undefined reference
  
## A. LINKER ERRORS
- Those errors which occurs at linking stage.
- This means Compiler compiles the program successfully, which linker(Finding actual definition in CS) finds error.

### A1. UNDEFINED REFERENCE
- **Meaning** 
  - *Compiler* can find reference of object (class, function, variable, etc.).    //Compilation Ok
  - *Linker* cannot find the definition of a linked object.
- **Reasons for udefined reference**
  1. *No Definition Provided For Object* The programmer has forgotten to define the object.
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
  2. *Wrong Definition* 
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
  3. 
