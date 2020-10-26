# Module
- **What** 
  - Same as python module. File containing functions, class, variables etc. A module is a set of source code files that are compiled independently of the translation units that import them. Modules can be used side-by-side of header files, see difference below.
- **Why** Modules help divide large amounts of code into logical parts.

## Creating & Using Modules
### A. In Python
```
//////Creating Module///////
# vim mult_sum.py           #Module named mult_sum is defined.    //file1
def fmult(a,b):
  print('Mult:',a*b)
def fsum(a,b):
  print('Sum:',a+b)    

///////Using Module///////
# vim main.py                                                    //file2
import mult_sum as a
a.fmult(1,2)                        #2
a.fsum(4,5)                         #9
```

### B. In C++
- **Creating Module**
```c++
# vim hello.cpp                                                 //file1
export module hello;       //module declaration
import <iostream>;         //import declaration
 
export void hello() {      //export declaration
  std::cout << "Hello world!\n";
}
```
- **Using module**
```c++
# vim main.cpp                                                  //file2
import helloworld;          //import declaration
int main() {
  hello();
}
```

## MODULES vs HEADER FILES
| | Modules | Headers |
| --- | --- | --- |
| include | import modules in any order without concern for macro redefinitions | provide header guards so that its not included again |
