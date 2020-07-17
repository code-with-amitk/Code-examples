## RVO(Return value optimization)
- Compiler is allowed to avoid creating temporary objects for return values, even if they have side effects.

#### Simple Example-1(RVO)
###### Without RVO
```
int fun(int a)
{
  return a;
}
int b() 
{
  int a[fun(10)];
}
```
> See how_many_temporary_copies.md on call by value page.

- In b(), Before call to fun(), 10 is copied in register rdi.
- Inside fun(), rdi is copied to stack of fun()
- a=10 is copied to register(rax) to be returned to b().

- if we note here,
  - copying value to fun()'s stack(temporary copy) is an unecessary step.

#### With RVO
- Instead of writing a to stack of fun() we place a directly onto stack of b()
- Code for doing such optimization is written in complier itself.

#### Example-2(RVO)
> -fno-elide-constructors this switch disables RVO.
[Article](https://shaharmike.com/cpp/rvo/)
```
# vim test.cpp
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
```

- RVO Disabled by user. 
```
# g++ -fno-elide-constructors test.cpp
# ./a.out
c'tor
move c'tor
d'tor
move c'tor
d'tor
d'tor
```

- RVO not disabled by user, complier doing RVO.
```
# g++ test.cpp
c'tor
d'tor
```

## NRVO(Named Return Value Optimization)
- Object with a name is returned but is not copied or used.
```
int fun(int a)
{ 
  int c = a;
  return c;
}
int b() 
{
  int a[fun(10)];
}
```

## Copy Elison
- The objects are constructed directly into the storage where they would otherwise be copied/moved to.
