- [explicit keyword](#explicit)
  - [implicit conversion](#impl)
- [final keyword](#final)
- [static](#what)
  - [1. static variable](#variable)
  - [2. static member function](#func)
  - [3. static class](#sclass)
- [this](#this)

<a name=what></a>
## static
- it has different meaning in different contexts.

<a name=variable></a>
### 1. static variable in class
- static variables are shared among all Objects of class. Only 1 copy of variables is created.
- Since we cannot have multiple copies of static variable hence cannot be initialized inside constructor.
- _Initialization:_ at compile-time.
- _Calling:_ Without creation of class object, ie shared among objects. All objects wil
- Java does not support Static Local variables
```c++
class A{
public:
  static int var;    	//Declared in Public Scope
  A(){}
	void disp(){
		cout<<var;
	}
};

int A::var=10;  //Rule: Initialize static variable. THIS IS REQUIRED, else Compiler will give undefined reference Error for var

int main(){
	A obj1;
	obj1.disp();    //10

	A obj2;
	obj2.disp();    //10
} 
```

<a name=func></a>
### 2. Static member function of class
- Can be called without class object.
- SMF can access: Static Data Members, Static Member Function, non-static functions from outside class.
- Do not have access to this pointer or super.
```c++
class A{
public:
  static void fun(){
    cout<<"fun";
  }
};
int main(){
  A::fun();         //fun
}
```

<a name=sclass></a>
### 3. static class
- Only present in Java. Way of grouping classes in Java. Only Inner(Nested classes) can be created static. But its not necessary that all nested classes needs to be static. 
```java
public class test{
    public static class InnerStatic{
        public InnerStatic(){    System.out.println("InnerTest");    }
    };
    public test(){    System.out.println("test");    }    
};
```

<a name=final></a>
## final

|Final|Java|C++|
|---|---|---|
|Class variable|<ul><li>Should be initialized at time of declaration</li></ul><ul><li>Value cannot be changed</li></ul>|same as const|
|Class Method|<ul><li>if final function is defined in base class, it cannot be overridden in derv class(Compilation error)</li></ul><ul><li>Final methods gets inherited</li></ul>|final|
|final class|Cannnot be extended/inherited||

<a name=explicit></a>
## explicit keyword

<a name=impl></a>
#### What is Implicit conversion?
- Compiler converts data-type to class object which is wrong.
- Example-1: fun() takes object as argument but we passed int and compiler did conversion internally. This is done using default constructor(1).
```c++
class A {
  int a;
public:
    A(int b) : a(b) {}             //1
    int get( ) {
      return a;
    }
};

void fun (A obj) {
  int x = obj.get ();
  cout << x;
}

int main() {
  fun (3);
}
# g++ test.cpp;./a.out
3
```
- **Explicit** 
  - explicit can only come in front of constructor.
  - Prefixing the explicit keyword before constructor prevents the compiler for using that constructor for implicit conversions. Above code will give error, we need.
```c++
class A {
  ...
  public:
     explicit A(int b) : a(b) {}             //CONSTRUCTOR PREFIXED with EXPLICIT stops implicit conversion
  ...
};
int main() {
  fun (A(3));
}
```

<a name=this></a>
## this pointer
- Every Function call passes the address of Object which calls it. Which Actual Implementation stores in this pointer.
 ```c++
class A{
  int a;
public:
  void fun(int x){        //Implemented as void fun(const test *this, int x)
    a = x;                //this->a=x
   }
};

int main(){
    A obj
    obj.fun(10);                //obj.fun(&obj, 10);
}
```
