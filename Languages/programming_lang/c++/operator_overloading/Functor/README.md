# A. Functor
## What?
- A object of class which overloads `operator ()`. Ex: object()
- Remember functors are objects only, Hence can store state.
- Compiler does not provide functors, we need to define explicitly.

## A1. Types of functors in STL
| Type | Generator | Unary Functor | Binary Functor |
| --- | --- | --- | --- |
| What | Functor that can be called with no argument | Functor called with 1 argument | With 2 arguments |
| Examples | <ul><li>print_it</li></ul> | | |

### A2. FUNCTOR vs NORMAL-FUNCTION?
| | NORMAL-FUNCTION | FUNCTOR |
| --- | --- | --- |  
| store state? | <ul><li>No</li></ul> <ul><li>Need to use global,static</li></lu> | <ul><li>Yes</li></ul> <ul><li>a. non-static pvt member(ie object specific)</li></ul> <ul><li>b. static(across all objects)</li></ul> |
                                                
### A3. FUNCTOR Code
```
#include<iostream>
using namespace std;

class A {
  int sv;             //STATE VARIABLE
public:
  A(int x):sv(x) {};

  int operator () (int b)     //class A overloads operator (), Now object of this class will be functor
  {
    return b*sv;
  }
};
int main(){
  A obj(10);
  cout<<obj(3)<<endl;        //Using object as Function ie functor. //30
}
```
