## Constructor calling Hierarchy
- **What** Whenever derived class constructor(default or parameterized) is called, Base class default constructor is ***ALWAYS*** called.
- **Why Base class Constructor called by Derived class ctr**
  - Constructors have job to initialize member variables. A Derived class constructor has access only to its own class members, but a Derived class object also have inherited property of Base class, and only base class constructor can properly initialize base class members. Hence all the constructors are called, else object wouldn't be constructed properly.

## Rules of Calling Base class Constructor
### 1. Base class ctr called 1st
```c++
class A{
public:
  A() { cout<<"base ctr"<<endl;  }
  ~A() { cout<<"~base"<<endl;  }
};

class B: public A {
public:
  B() { cout<<"Derv ctr"<<endl;  }
  ~B() { cout<<"~derv"<<endl;  }
};

int main(){
    B obj;
}
/*
Output:
base ctr
Derv ctr
~derv
~base
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
  ~B() { cout<<"~derv"<<endl;  }
};

int main(){
    B obj;
}
# ./a.out
Error cannot find A::A()
```

### 3. Inheritance Ctr calling Hierarchy
- class B constructor > class C constructor > class A constructor.
```c++
class A : public B, public C ;
```

### 4. Contructor of Abstract class
  - A class containing pure virtual function is only a template, Since we will not be creating object of that class, it good to provide empty contructor.
```c++
class A{                                  //Abstract class.
public:
  virtual void fun()=0;                   //Pure Virtual function
  A(){};
  virtual ~A(){};
};
class B: public A {
public:
  void fun(){}                          //Derived class must override PVF else declare it as PV.
  B() { cout<<"Derv ctr"<<endl;  }
  ~B() { cout<<"Derv dtr"<<endl;  }
};
int main(){
    B obj;
}
# ./a.out
Derv ctr
Derv dtr
```
