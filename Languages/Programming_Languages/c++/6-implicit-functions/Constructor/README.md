**Constructor**
- **Rules:**
  - **1. Ctr calling Hierarchy**
    - [a. ctr(1st base then derv)](#r1)
  - **2. dtr calling Hierarchy**
    - [a. dtr(1st derv then base)](#r2)
  - [3. Base class constructor should be defined](#b2)
- [Ctr Initializer list](#il)
- **[Conversion Ctr](/Languages/Programming_Languages/c++/Keywords)**

## Constructor
Same named function of class called when object of class is created. Used to provide values to data members. 
```c
  Return type:               None 
  Accessing address of ctr: cannot
  Inheriting ctr:           Cannot
  PRIVATE SCOPED CTR*:      Can ctr be inside private section(Yes. Single DP)
```

## Rules
- Whenever derived class constructor(default or parameterized) is called, Base class default constructor is **ALWAYS** called.

### 1. Ctr calling Hierarchy
<a name=r1></a>
#### a. Base class ctr is called 1st then derv ctr
Constructors have job to initialize member variables. A Derived class constructor has access only to its own class members, but a Derived class object also have inherited properties of Base class, and only base class constructor can properly initialize base class members. Hence all the constructors are called, else object wouldn't be constructed properly.
```cpp
class A{
public:
  A() { cout<<"base ctr";  }
  ~A() { cout<<"base dtr";  }
};

class B: public A {
public:
  B() { cout<<"Derv ctr";  }
  ~B() { cout<<"Derv dtr";  }
};
int main(){
    B obj;
}
$ a.out
base ctr
Derv ctr
Derv dtr
Base dtr
```

### 2. Dtr calling Hierarchy
<a name=r2></a>
#### [a. Derv class dtr is called 1st then base ctr](#r1)
Why? Because objects are allocated on stack and top of stack is removed 1st.
```c
 | base-obj | derv-obj |
 stack----------->
```

<a name=b2></a>
#### 2. Base class constructor should be defined
```c++
class A{
public:
  A();
  ~A();
};
class B: public A {
public:
  B() { cout<<"B ctr";  }
  ~B() { cout<<"~B";  }
};
int main(){
    B obj;
}
# ./a.out
Error cannot find A::A()
```

<a name=il></a>
### Ctr Initializer list
In the initializer list, the order of execution takes place according to the order of declaration of member variables. 
```cpp
class test{
  int a; //Declared 1st
  int b; //Declared 2nd
public:
	test (int x): b(x), a(b * 2) {
		cout << b << a;       //b=10, a=garbage
	}
};
int main() {
	test obj(10);
	return 0;
}
```
