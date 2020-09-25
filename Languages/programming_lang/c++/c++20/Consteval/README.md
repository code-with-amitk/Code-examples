## consteval
### 1. constexpr
- **[What is constexpr](https://github.com/amitkumar50/Code-examples/blob/master/programming_lang/c++/c++11/Constexpr/README.md)**
- **Problem with constexpr** (It's not Guranteed compile-time-constant)
  - See the below code.
  - A runtime variable `c` is passed to constexpr function, then how constexpr function can be compile-time gurantee?
```
constexpr int fun(int a){
  return 2*a;
}
int main(){
  constexpr int b = fun(5); 
  cout<<b;    //10
  
  int c;  cin>>c;
  int d = fun(c); cout<<d;        //c=7 d=14
}
```
- **Conclusion on constexpr**
  - Compiler “tries its best” to evaluate constexpr compile-time, but not guranteed.
  - ie constexpr is only a marker used to express that the function can be used in a constant expression if needed.

- **Use cases of constexpr**
  - constexpr function might or might not be candidate for constant expression, ie it can be evaluated at compile or run time.
  - This can be useful in some contexts : for example, we want to be able to use STL algorithms at compile-time & runtime both.

### 2. consteval
- **What** Always evaluated at compile time. It provides a gurantee(unlike constexpr) that expression would be evaluated at compile time only.
- **Example(to understand)**
```
#include<iostream>
using namespace std;

constexpr int fun1(int a){
  return 2*a;
}

consteval int fun2(int a){
  return 2*a;
}


int main(){
  int b = 4;
  cout<<fun1(b);
  //cout<<fun2(b);                  //error: the value of 'b' is not usable in a constant expression
  cout<<fun2(5);                    //Ok
  //Even making b as [const int b=4;] will also work
}
```
- **Why restricting to Compile-time**
  1. C++ committee has has decided to make c++ more compile-time oriented programming language ie adding more support for compile time.
  2. consteval is used heavily in `metaclassses` & `reflections`.
