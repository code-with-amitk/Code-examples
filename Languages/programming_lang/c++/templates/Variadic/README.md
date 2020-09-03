### Variadic Templates
- **What**
  - Function taking arbitary/variable number of arguments same as `va_` family functions in C.
  - But good thing is unlike C, all arguments and function definition is resolved at compile time.
- **Types of VT**
  - *1.* Variadic Function template
  - *2.* Variadic class template


- **2. Variadic class template**
- class template taking variable no of arguments. template parameter pack must be the final parameter in the template parameter list else its compile time error.
```
template<typename ... T>
struct A {};
int main(){
  fun();       // OK: args contains no arguments
  fun(1);      // OK: args contains one argument: int
  fun(2, 1.0); // OK: args contains two arguments: int and double

  A<> t0;
  A<int> t1;        // Types contains one argument: int
  A<int, float> t2; // Types contains two arguments: int and float       
}
```
