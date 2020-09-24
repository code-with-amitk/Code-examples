## constexpr
- **1. const vs constexpr**

||Variable|Function|Object|
|---|---|---|---|
|const|Whose value remains same through out the program|Always returns a constant value|once initialized, the value of that object won't change|
|constexpr|<ul><li>Variable whose value is derived at compile-time & is initialized.</li></ul><ul><li>Should be compile time constant</li></ul><ul><li>Should be initialized at declaration</li></ul>|||
 
 - **2. constexpr Variable**
```c++
#include<iostream>
using namespace std;
int main(){

 ///////////PROBLMATIC CODE////////////
 int a;
 cin>>a;
 const int b = a;   //Problem: How b is const if its value can be changed at runtime?
 
 /////////SOLUTION: constexpr//////////
 //constexpr int c = a;  //error: uninitialized const ‘c’ [-fpermissive
 //constexpr int c;      // error: uninitialized const ‘c’ [-fpermissive]
 constexpr int c = 1;
}
```

- **3. constexpr function**
  - It return value should be computable at compile time only.
  - RULES:
    - constexpr function or constructor is implicitly inline.
    - constexpr function accepts and returns only literal-types.
    - constexpr functions cannot be virtual
    - A constructor can't be defined as constexpr when the enclosing class has any virtual base classes.
    - The body can be defined as = default or = delete.
    - The body can contain no goto statements or try blocks.
    - constexpr function return value can be collected in const variable.
```c++
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

## Constexpr vs Macro

||macro|constexpr|
|---|---|---|
|Type|int|unsigned|
|When to use|Use constexpr whenever you may|macros only if no other solution is possible|
