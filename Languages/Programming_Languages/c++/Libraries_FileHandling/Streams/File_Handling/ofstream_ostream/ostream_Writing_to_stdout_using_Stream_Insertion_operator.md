## ostream Writing to stdout using stream insertion (<<) opeartor
```c++
#include<iostream>
using namespace std;

#if defined(UNICODE_WINDOWS)
  #define _kcout            std::wcout
  #define _kostream         std::wostream
#else
  //for linux and other OSes
  #define _kcout            std::cout
  #define _kostream         std::ostream
#endif

struct A{
  int a;
  friend _kostream& operator<<(_kostream&, const A&);
};

_tostream& operator<<(_kostream& out, const A& obj){
  out << "Hello\n"
      << obj.a;
  return out;
}

A obj;
int main(){
  obj.a = 5;
  _tcout << obj;
}
```
