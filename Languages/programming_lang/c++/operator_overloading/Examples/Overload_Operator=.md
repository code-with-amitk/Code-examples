## Overloading `=`
- **Format**
  - return_type operator_keyword operator_to_overload (arguments)
- **Remember**
  - *Copy constructor* is called when a new object is created from an existing object, as a copy of the existing object.
  - *Assignment operator* is called when an already initialized object is assigned a new value from another existing object.

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
  //A obj2 = obj1;            //This will call COPY CTR, since new object is getting created from existing object.
  
  A obj2;
  obj2 = obj1;                //obj2.operator=(obj1)  //This calls assignment operator
}
```
