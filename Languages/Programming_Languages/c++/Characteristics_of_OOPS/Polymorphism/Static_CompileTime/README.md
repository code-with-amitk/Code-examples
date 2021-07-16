- [Types of Static Polymorhism](#types)
  - [1. Operator Overloading / Adhoc Polymorhism](#oo)
  - [2. Templates](#temp)

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
