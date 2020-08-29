## Constructor calling Hierarchy
- **What(VERY IMP)** 
  - Whenever derived class constructor(default or parameterized) is called, Base class default constructor is ***ALWAYS*** called.
- **Why Base class Constructor called by Derived class ctr**
  - Constructors have job to initialize member variables. A Derived class constructor has access only to its own class members, but a Derived class object also have inherited property of Base class, and only base class constructor can properly initialize base class members. Hence all the constructors are called, else object wouldn't be constructed properly.

## Rules of Calling Base class Constructor
### 1. if Base class ctr is defined it's called
```c++
class A{
public:
  A() { cout<<"base ctr"<<endl;  }
  ~A() { cout<<"base dtr"<<endl;  }
};

class B: public A {
public:
  B() { cout<<"Derv ctr"<<endl;  }
  ~B() { cout<<"Derv dtr"<<endl;  }
};

int main(){
    B obj;
}
/*
Output:
base ctr
Derv ctr
Derv dtr
base dtr
 */
```

### 2. If base class constructor is declared not defined(Run time error)
```c++
class A{
public:
  A();
  ~A();
};

class B: public A {
public:
  B() { cout<<"Derv ctr"<<endl;  }
  ~B() { cout<<"Derv dtr"<<endl;  }
};

int main(){
    B obj;
}
# ./a.out
Error cannot find A::A()
```

### 3. Inheritance Ctr calling Hierarchy
- 1st class B constructor > Then class C constructor > Then class A constructor.
```c++
class A : public B, public C ;
```
