## Exception
- **What?**
  - Problem/error that arises when program is Running. Eg: Divide by Zero. 
  - Normally what will happen in this case is Segmentation Fault and abort.
  - But we can place the same code inside try, catch and do something so that program does no coredumps.
- **Example** 
  - **a. Generating coredump(without try catch)**
```c++
int main(){
  int a = 4, b, c=0;
  b = 4/c;                        //Coredumps here
  cout << b;
}
```
  - **b. Catching error(with try catch)**
```c++
int main(){
  int a = 4, b, c=0;
  try{
    if(c==0)
      throw 99;
    b = 4/c;
    cout << b;
  } catch (...){
    cout<<"Divide by 0 happened\n";
  }
}
# ./a.out                       //No coredump happenened
Divide by 0 happened
```

## Exception Handling?
- In case of problem instead of simply dying(coredumping), transfer control from one part of a program to another. This is build on 3 keywords:
  - *1. try block*: Block of code which throws exception. This is followed by one or more catch blocks
  - *2. throw keyword:* Instead of dying throw the exception
  - *3. catch:* This catches the thrown exception. This is piece of code that executes on thrown Exception.
- Code placed inside try/catch block is called protected code.
- You can list multiple catch block after try. Because Code can generate different kind of Exceptions in different conditions.
```c++
try {
   // protected code
} catch( ExceptionName e1 ) {
   // catch block
} catch( ExceptionName e2 ) {
   // catch block
} catch( ExceptionName eN ) {
   // catch block
}
```
