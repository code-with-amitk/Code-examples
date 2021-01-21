## 6 default/implicit/trivial functions provided by g++ compiler
1. Default ctr
2. Copy ctr
3. Copy assignment operator
4. Move ctr (Since C++11)
5. Move assignment operator (Since C++11)
6. Destructor

### Default Ctr
- Same named function of class
- When Compiler **provides default ctr**?
  1. No user created Constructor is declared in class
- When complier **does not provide default ctr**?
  1. If user has  defined ANY constructor(either default of copy ctr)
  2. There is a Member in class that is not default-constructible. Eg: Pointer, Reference    
  3. [In C++11] Deleting Default Constructor using A() = delete;
- Forcing compiler to create default ctr
  - class_name () = default

### Syntax
```c++
  class_name ( ) ;
  class_name :: class_name ( ) body
  class_name() = delete ;         (since C++11)
  class_name() = default ;                (since C++11)
  class_name :: class_name ( ) = default ;        (since C++11)
```

### Compiler provided default ctr
```c++
#include<iostream>
#include<iomanip>
using namespace std;

class A{
        int a=1;
public:
        void disp(){
                cout<<a<<"\n";
        }
};
int main(){
        A obj1; 
        obj1.disp();    //1

        A obj2; 
        obj2.disp();    //1
}
```

### Forcing compiler to generate default ctr
```c++
class A{
        int a=1;
public:
        A() = default;
        void disp(){
                cout<<a<<"\n";
        }
};
int main(){
        A obj1;
        obj1.disp();    //1

        A obj2;
        obj2.disp();    //1
}
```

### User defined default ctr
```c++
class A{
        int a;
public:
        A(int b):a(b){}
        void disp(){
                cout<<a<<"\n";
        }
};
int main(){
        A obj1(2);
        obj1.disp();    //1

        A obj2(3);      //Two objects are created
        obj2.disp();    //1
}
```
