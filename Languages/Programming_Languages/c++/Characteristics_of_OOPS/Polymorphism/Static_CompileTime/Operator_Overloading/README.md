### Operator Overloading/Adhoc Polymorphism
- **What** Different behavior of operators in different context.    x=6, y=4; x+y=10 , x="hey", y="man"; x+y="hey man";
- **Commonly overloaded operators**    
```c++
=    +      -      `*`        /           +=         -=       `*=`         /=      ==      !=        >>        <<
```
- **Operators which cannot be overloaded**    
```c++
.(member access)     `*(pointer to member)`       ?:(Ternary)     sizeof     ::(scope resolution)    typeid
```
- *Why sizeof cannot be overloaded*   sizeof is compile time operator. ie compiler places value in place of sizeof() at compile time. 
- *Can we define our own Operators?* NO, Language have not defined.                
- *Syntax of overloading an Operator*
```c++
  return_type Keyword-operator Operator-to-overload (arguments) {..}
Examples:  
  const A       operator          *                 (A obj1)    {..}
  std::ostream& operator          <<                (std::ostream& out, const *ptr)  
```
