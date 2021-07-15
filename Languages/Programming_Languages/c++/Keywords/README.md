- [What is static](#what)
  - [1. Static member variable of class](#variable)
  - [2. static member function](#func)

<a name=what></a>
## Static
- it has different meaning in different contexts.

<a name=variable></a>
### 1. Static member variable of class
- These member variables are shared among all Objects of class. Only 1 copy of variables is created.
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
