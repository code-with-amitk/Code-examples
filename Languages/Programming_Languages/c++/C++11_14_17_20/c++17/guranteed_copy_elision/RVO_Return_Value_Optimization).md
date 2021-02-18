## RVO(Return value optimization)
- Compiler is allowed to avoid creating temporary objects for return values, even if they have side effects.
- **SIDE EFFECT?**
  - function or expression is said to have a side effect if it modifies some variable(s) outside its local  scope.

### 1. With and Without RVO
- **1. Without RVO**
```c++
int fun(int a){
  return a;
}
int b(){
  int a[fun(10)];
}
```
- *[How many temporary copies?](/assembly/Stack_frame_example.md)*
  - In b(), Before call to fun(), 10 is copied in register rdi. Inside fun(), rdi is copied to stack of fun()
  - a=10 is copied to register(rax) to be returned to b().
  - if we note here, copying value to fun()'s stack(temporary copy) is an unecessary step.

- **2. With RVO**
  - Instead of writing a to stack of fun() we place a directly onto stack of b(). Code for doing such optimization is written in complier itself.

### [2. Disabling RVO with `-fno-elide-constructors` switch](https://shaharmike.com/cpp/rvo/)
```c++
#include<iostream>
using namespace std;

struct A{   // Note: All methods have side effects
        A() { cout << "c'tor" << endl; }
        ~A() { cout << "d'tor" << endl; }
        A(const A&) { cout << "copy c'tor" << endl; }
        A(A&&) { cout << "move c'tor" << endl; }
};

A ExampleRVO() {
          return A();
}

int main() {
          A s = ExampleRVO();
}

# g++ -fno-elide-constructors test.cpp
# ./a.out
c'tor
move c'tor
d'tor
move c'tor
d'tor
d'tor

# g++ test.cpp            //RVO not disabled by user, complier doing RVO.
c'tor
d'tor
```
