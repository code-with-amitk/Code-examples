**Constructor**
- **Rules:**
  - **1. Ctr,dtr calling Hierarchy**
    - [a. ctr(1st base then derv). destr(1st derv then base)](#b1)
  - [2. Base class constructor should be defined](#b2)
  - [3. Inheritance Ctr calling Hierarchy](#b3)
  - [4. Contructor of Abstract class](#b4)
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
### 1. Constructor,Destructor calling Hierarchy
- Whenever derived class constructor(default or parameterized) is called, Base class default constructor is **ALWAYS** called.
- **Why Base class Constructor called by Derived class ctr**
  - Constructors have job to initialize member variables. A Derived class constructor has access only to its own class members, but a Derived class object also have inherited properties of Base class, and only base class constructor can properly initialize base class members. Hence all the constructors are called, else object wouldn't be constructed properly.

<a name=b1></a>
#### a. Base class ctr is called 1st then derv class ctr
Dtr is called opposite of ctr calling hierarchy
```cpp
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
$ a.out
Output:
base ctr
Derv ctr
~derv
~base
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

<a name=b4></a>
#### 4. Contructor of Abstract class
A class containing pure virtual function is only a template, Since we will not be creating object of that class, it good to provide empty contructor.
```cpp
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

<a name=il></a>
### Ctr Initializer list
```cpp
class test{
	int a;
	char b;
	float *c;
public:
	test (int x, int y): a(x), b(y), c(new float[10]) {
		std::cout<<"a="<<a<<"\tb="<<b<<"\t"<<std::endl;
	}
};
int main() {
	test obj(1,'g');
	return 0;
}
$ ./a.out
 1 g
```
