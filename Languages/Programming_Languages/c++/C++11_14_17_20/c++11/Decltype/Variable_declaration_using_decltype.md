## Declaring a variable using decltype

### 1. char,int variable
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

### 2. Lambda variable
- return type of function is int, decltype(f) is int
```c++
#include<iostream>
int main(){
  auto f = [](int a, int b)->int {return a*b;};
  decltype(f) c = f;
  std::cout<<typeid(c).name()<<"\n";          //Z4mainEUliiE_
  std::cout<<c<<"\n";                         //1
}
```

### 3. Template Variable
- return type depends on template parameters, return type can be deduced since C++14
```c++
#include<iostream>
using namespace std;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u){{
    return t+u;
}

int main(){
  decltype(add(1.2,1.3)) d = 3.4;         //float d = 3.4
  string s1 = "never", s2 = "give";
  decltype(add(s1,s2)) s = "Think";       //string s = "Think"
  cout<<d<<endl;          //3.4
  cout<<s<<endl;          //Think
}
```
