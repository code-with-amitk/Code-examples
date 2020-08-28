## Operator Overloading/Operator Adhoc Polymorphism
- **What**
  - Different behavior of operators in different context.    x=6, y=4; x+y=10 , x="hey", y="man"; x+y="hey man";
- **Commonly overloaded operators**    
```c
=    +      -      `*`        /           +=         -=       `*=`         /=      ==      !=        >>        <<
```
- **Operators which cannot be overloaded**    
```c
.(member access)     `*(pointer to member)`       ?:(Ternary)     sizeof     ::(scope resolution)    typeid
```
- **Why sizeof cannot be overloaded**   sizeof is compile time operator. ie compiler places value in place of sizeof() at compile time. 
- **Can any person Define his own Operators** NO, Language have not defined.                
- **Syntax of overloading an Operator**
```c++
  return_type Keyword-operator Operator-to-overload (arguments) {..}
Examples:  
  const A       operator          *                 (A obj1)    {..}
  std::ostream& operator          <<                (std::ostream& out, const *ptr)  
``` 

## About Stack
- Stack grows in reverse direction.
```c
  |----stack grows-----|-------------><------heap grows------
 0x450                0x200
 rbp                  rsp       
```
- rdi, rsi, rdx, rcx, r8, r9: Stores 1st 6 arguments to function. If there are more than 6 parameters,  then the program’s stack is used to pass in additional parameters to the function.
- rax: stores return value of the function. Larger return types like structs are returned using the stack.
- rax, rcx, rdx, rdi, rsi, rsp, r8-r11: These are caller save registers. 
- rbx, rbp, r12-r15: These are callee save registers. These are saved across function calls.   	
- Caller is main(), callee fun()
