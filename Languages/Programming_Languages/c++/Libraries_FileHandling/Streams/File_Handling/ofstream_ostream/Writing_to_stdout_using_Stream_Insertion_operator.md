## Writing to stdout using stream insertion (<<) opeartor
```c++
#include<iostream>
using namespace std;

#if defined(UNICODE_WINDOWS)
  #define _tcout            std::wcout
  #define _tostream         std::wostream
#else
  //for linux and other OSes
  #define _tcout            std::cout
  #define _tostream         std::ostream
#endif

struct A{
  int a;
  friend _tostream& operator<<(_tostream&, const A&);
};

_tostream& operator<<(_tostream& out, const A& obj){
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
