- Types of Static Polymorhism
  - [1. Operator Overloading / Adhoc Polymorhism](#oo)
    - [Operators which can be overloaded](#can)
    - [Operators which cannot be overloaded](#cannot)
    - Examples
      - [1.1 Overload `*`](#overloadstar)
      - [1.2 Overload =](#overloadass)
      - [1.3 Overload +](#overloadplus)
      - [1.4 Overload <<](#overloadstream)
      - [1.5 Overload ++prefix](#overloadprefix)
      - [1.6 Overload operator() / Functor](Operator_Overloading/Functor)
  - [2. Templates/ Generic Programming](#temp)
    - [Template Types](#tempt)

<a name=oo></a>
## 1. Operator Overloading/Adhoc Polymorphism
- Different behavior of operators in different context.    x=6, y=4; x+y=10 , x="hey", y="man"; x+y="hey man";
- *Can we define our own Operators?* NO, Language have not defined.                
- *Syntax of overloading an Operator*
```c++
  return_type Keyword-operator Operator-to-overload (arguments) {..}

  const A       operator          *                 (A obj1)    {..}
  std::ostream& operator          <<                (std::ostream& out, const *ptr)  
```

<a name=can></a>
#### Operators which can be overloaded
```c
=   +      -      `*`        /           +=         -=       `*=`         /=      ==      !=        >>        <<
```

<a name=cannot></a>
#### Operators which cannot be overloaded
```c++
.(member access)     
`*(pointer to member)`       
?:(Ternary)     
sizeof                  : sizeof is compile time operator. ie compiler places value in place of sizeof() at compile time. 
::(scope resolution)    
typeid
```

<a name=can></a>
### Examples
<a name=overloadstar></a>
#### 1.1 Overloading `*`
- Overloading Operator `*` to multiply 2 objects. Format
 ```c++
/////Format/////
//return_type operator_keyword  Operator_to_overload (arguments)
//const A          operator              *           (class object)

#include<iostream>
class A {
  int a;
public:
  A (int b):a(b) {}
  const A operator * (A obj) {
    cout<<"this->a="<<this->a<<endl;				//10	Even you can write a not this->a
    cout<<"obj.a="<<obj.a<<endl;					//20		
    return (this->a)*(obj.a);
  }
  void disp() {
    std::cout<<"value="<<this->a<<std::endl;
  }
};
int main() {
  A obj10(10);		//obj10.a=10
  A obj20(20);		//obj20.a=20
  A obj = obj10*obj20;		//Equivalent to 	obj10.operator*(obj20); 
  obj.disp();				//200
}
```

<a name=overloadass></a>
#### 1.2 Overloading =
- *Copy constructor* is called when a new object is created from an existing object, as a copy of the existing object.
- *Assignment operator* is called when an already initialized object is assigned a new value from another existing object.
- **Code**
```c++
constexpr int arr = 10;

class A{
  int *p;
public:
  A(){}
  A(int a):p(new int()){
    *p = a;
  }  
  A& operator = (const A &k) {
    int *t = new int;
    t = k.p;                //Deep copy
    return *this;
  }
};

int main(){
  A obj1(1);
  //A obj2 = obj1;      //This will call COPY CTR, since new object is getting created from existing object.
  
  A obj2;
  obj2 = obj1;          //obj2.operator=(obj1)  //This calls assignment operator
}
```

<a name=overloadplus></a>
#### 1.3 Overloading +
- `A& operator+(const A& obj)` ie `Operator+()` cannot return reference.
  - Because we are creating a local object(A t) in function and that needed to be copied in `A obj3`.
  - If i return reference `A& operator+(const A& obj)`, local object will get destroyed as function call end and coredump.
- Code
```c++
class A{
  int a;
  string s;
  public:
    A(int b, string s1):a(b),s(s1){}    //Constructor Initialization list: For initializing member variables of class.
    A(){}
    A operator+ (const A& obj){        //A& operator+(const A& obj) will not work, see above
      A t;
      t.a = this->a + obj.a;
      t.s = this->s + obj.s;
      return t;
    }
    void disp(){
      std::cout<<a;
      std::cout<<s;
    }
};

int main(){
  A obj1 (1,"test");
  A obj2 (2,"now");
  A obj3 = obj1 + obj2;   //obj2.operator+(obj1)
  obj3.disp();
}
```

<a name=overloadstream></a>
#### 1.4 Overloading <<
- *What is Output Stream?* Stream used to provide output to Printer, Monitor etc. **cout** is object of output stream class.
- *Usecase* Dumping Object in Cutomized manner by passing to `<<`. Eg: `cout<<obj`.
- *Why overloaded operator is friend?* operator overloading function a friend of the class because it would be called without creating an object.
- _Code:_ Printing Month Date Year in Customized manner
```c++
#include <iostream>
using namespace std;

class Date{
  int month, date, year;
public:
  Date(int m, int d, int y):month(m),date(d),year(yr) {}
  friend ostream& operator<<(ostream& os, const Date& dt);
};

//Equivalent
//return-type function(var = cout, o = obj)
ostream& operator<<(ostream& var, const Date& o) { 
  var << o.date << '/' << o.month << '/' << o.year;         //Each call to << passes data to 'cout' which dumps on stdout
  return var;
}

int main(){
  Date obj(31, 7, 2012);                        //Creates object obj (date=31, month=7, year=2013)

  //Equivalent    
  //  object.function(hidden-self-address, Object-on-which-operation-to-applied)
  //  cout.(operator<<)(this, obj)
  cout << obj;                                //Output:   31/7/2012
}

$ a.out
31/7/2012
```

<a name=overloadprefix></a>
#### 1.5 Overloading ++prefix
```cpp
class A{
  int a;
public:
  A(int x):a(x){}
  const A& operator ++() {
    ++this->a;
  }
};
int main(){
  A obj(1);
  ++obj;
}
```

<a name=temp></a>
## 2. Template/Generic Programming
- Writing a code that is independent of particular type.
- Template is compiler abstraction. Compiler creates the overloaded functions(specialization) for each type at compile time. Eg seperate for long int, short int, int, double, string.
- Specialization 
  - Benefits: Makes code type-safe.
  - Drawbacks: increases sizeof object file(But not much because compiler achieves using optimizations & inlining).
    
<a name=tempt></a>
### Template Types?
```c
      Type          |
  ------------------|---
   1. Function      | Generic function that can be called/worked without particular type
   2. Class         | - Class having Generic Member variables,  Generic Member functions
                    | - Compiler cannot deduce template parameter type(s) for class template.
                    |   We need to tell compiler the data types we would be using
   3. Template      | Giving special implementation for specific data type of class and Generic for all others.
     Specialization | Types: Explicit/Full Specialization, Partial Specialization
```

- **Example: Function Template** Template parameter type not specified.
```c++
template < typename T >
T maxof(T a, T b) {
  return (a>b)?a:b;
}

int main() {
	cout << maxof ( 4, 5 ) <<endl;  				<<<<<<<<<< Template parameter type not specified.
}
```
- **Example: Class template** Template parameter type specified.
```c++
template < typename T >
class A {
  A a, b;                    //Generic Member variables
public:
  A (T x, T y) : a(x), b(y) {}
  A add () { return a + b; }
};

int main() {
  A <int> obj(5,6);              <<<<<<<<<<<<<< Template parameter type specified.
  cout<<obj.add()<<endl;
}
```
