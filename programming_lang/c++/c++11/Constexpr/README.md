## CONSTEXPR

### **CONST?** 
- ***CONST VARIABLE*** Whose value remains same through out the program.
- ***CONST FUNCTION*** Which always returns a constant value
 
### **CONSTEXPR?**
#### ***CONSTEXPR VARIABLE***
- Variable whose value is derived at compile-time & is initialized. 
  a. Should be compile time constant. 
  b. Should be initialized at declaration.

```
#include<iostream>
using namespace std;
int main(){

         ///////////PROBLMATIC CODE////////////
        int a;
        cin>>a;
        const int b = a;   //Problem: How b is const if its value can be changed at runtime?
        //////////////////////////////////////
 
        /////////SOLUTION: constexpr//////////
        //constexpr int c = a;  //error: uninitialized const ‘c’ [-fpermissive
        //constexpr int c;      // error: uninitialized const ‘c’ [-fpermissive]
        constexpr int c = 1;
}
```

#### ***CONSTEXPR FUNCTION***
- It return value should be computable at compile time only.
- RULES:
  a. constexpr function or constructor is implicitly inline.
  b. constexpr function accepts and returns only literal-types.
  c. constexpr functions cannot be virtual
  d. A constructor can't be defined as constexpr when the enclosing class has any virtual base classes.
  e. The body can be defined as = default or = delete.
  f. The body can contain no goto statements or try blocks.
  g. constexpr function return value can be collected in const variable.
```
/////////PBOBLEM: Function is not const because return depends on runtime////////////
const float fun()
{
        int b;
        cin>>b;                 //error: uninitialized variable ‘b’ in ‘constexpr’ function
        return b;              //NO ERROR
};

/////////////SOLUTION////////////////////////
constexpr float fun()
{
        //int b;               //error: uninitialized variable ‘b’ in ‘constexpr’ function
        int b = 10;
        return b;  
};

int main(){
         const float d = fun(2);
}
```
