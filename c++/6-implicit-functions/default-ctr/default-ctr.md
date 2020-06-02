## SIX DEFAULT/TRIVIAL/IMPLICIT FUNCTIONS PROVIDED BY G++ COMPILER:        
1. DEFAULT CONSTRUCTOR
2. COPY CONSTRUCTOR
3. COPY ASSIGNMENT OPERATOR
4. MOVE CONSTRUCTOR: (Since C++11)
5. MOVE ASSIGNMENT OPERATOR (Since C++11)
6. DESTRUCTOR

### DEFAULT CONSTRUCTOR
- Same named function of class
- When Compiler provides default ctr?
  1. No user created Constructor is declared in class
- When complier does not provide default ctr?
  1. If user has  defined ANY constructor(either default of copy ctr)
  2. There is a Member in class that is not default-constructible. Eg: Pointer, Reference    
  3. [In C++11] Deleting Default Constructor using A() = delete;
- Forcing compiler to create default ctr
  - class_name () = default

### SYNTAX
```c++
  class_name ( ) ;
  class_name :: class_name ( ) body
  class_name() = delete ;         (since C++11)
  class_name() = default ;                (since C++11)
  class_name :: class_name ( ) = default ;        (since C++11)
```

### COMPILER PROVIDED DEFAULT CTR
```
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

### FORCING COMPILER TO GENERATE DEFAULT CTR
```
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

### USER DEFINED DEFAULT CTR
```
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
