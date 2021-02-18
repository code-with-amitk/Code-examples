## Declaring a variable using decltype
```c++
#include<iostream>
int main(){
  char c;
  decltype(c) c1 = 10;
  std::cout<<typeid(c1).name();      //c
  
  int a;
  decltype(a) b = 10;
  std::cout<<typeid(b).name();      //i
}
```
