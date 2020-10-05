## Overloading `=`
- **Format**
  - return_type operator_keyword operator_to_overload (arguments)

- **Code**
```c++
#include<iostream>
#include<cstring>
constexpr int arr= 10

class A{
  int *p;
public:
  A(){}
  A(int a):p(new int()){
    *p = a;
  }
  
  A operator = (const A &k) {
    int *t = new int;
    t = k.p;                //Deep copy
    return *this;
  }
};

int main(){
  A obj1(1);
  //A obj2 = obj1;            //REMEMBER: This will call Copy Constructor
  
  A obj2;
  obj2 = obj1;                //obj2.operator=(obj1)  //This calls assignment operator
}
```
