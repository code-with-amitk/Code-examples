# MODULES
- **What** 
  - Same as python module. File containing functions, class, variables etc.
  - A module is a set of source code files that are compiled independently of the translation units that import them.
  - Isn't it same as header files of namespaces?
  https://docs.microsoft.com/en-us/cpp/cpp/modules-cpp?view=vs-2019
- **Why** Modules help divide large amounts of code into logical parts.

## Creating & Using Modules
### A. In Python
- **Creating**
```
# vim mult_sum.py           #Module named mult_sum is defined.    //file1
def fmult(a,b):
  print('Mult:',a*b)
def fsum(a,b):
  print('Sum:',a+b)    
```
- **Using Module**
```
# vim main.py                                                    //file2
import mult_sum as a
a.fmult(1,2)                        #2
a.fsum(4,5)                         #9
```

### B. In C++
- **Creating module**
```
# vim hello.cpp                                                 //file1
export module hello;       // module declaration
import <iostream>;         // import declaration
 
export void hello() {      // export declaration
    std::cout << "Hello world!\n";
}
```
- **Using module**
```
# vim main.cpp                                                  //file2
import helloworld;  // import declaration
int main() {
    hello();
}
```

## MODULES vs HEADER FILES
