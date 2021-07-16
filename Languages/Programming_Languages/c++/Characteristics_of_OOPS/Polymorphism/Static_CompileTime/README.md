- [Types of Static Polymorhism](#types)
  - [1. Operator Overloading / Adhoc Polymorhism](#oo)
  - [2. Templates](#temp)
    - [Template Types](#tempt)

<a name=oo></a>
## 1. Operator Overloading/Adhoc Polymorphism
- Different behavior of operators in different context.    x=6, y=4; x+y=10 , x="hey", y="man"; x+y="hey man";
- **Commonly overloaded operators**    
```c
=   +      -      `*`        /           +=         -=       `*=`         /=      ==      !=        >>        <<
```
- **Operators which cannot be overloaded**
```c++
.(member access)     
`*(pointer to member)`       
?:(Ternary)     
sizeof                  : sizeof is compile time operator. ie compiler places value in place of sizeof() at compile time. 
::(scope resolution)    
typeid
```
- *Can we define our own Operators?* NO, Language have not defined.                
- *Syntax of overloading an Operator*
```c++
  return_type Keyword-operator Operator-to-overload (arguments) {..}
Examples:  
  const A       operator          *                 (A obj1)    {..}
  std::ostream& operator          <<                (std::ostream& out, const *ptr)  
```

<a name=temp></a>
## Template/Generic Programming
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
