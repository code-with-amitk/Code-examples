### constexpr function
- **What?** It return value should be computable at compile time only.
- **RULES?**
  - constexpr function or constructor is implicitly inline.
  - constexpr function accepts and returns only literal-types.
  - constexpr functions cannot be virtual
  - A constructor can't be defined as constexpr when the enclosing class has any virtual base classes.
  - The body can be defined as = default or = delete.
  - The body can contain no goto statements or try blocks.
  - constexpr function return value can be collected in const variable.
    
- **Example**    
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
