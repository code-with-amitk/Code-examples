**constexpr**
- [constexpr vs macro](#vs)
- [const vs constexpr](#vs1)
- [constexpr function](#fun)
  - [RELAXING CONSTRAINTS ON CONSTEXPR FUNCTION](#relax)

## constexpr
Compiler “tries its best” to evaluate constexpr expression at compile-time, but not guaranteed. consteval is proper guarantee.

<a name=vs></a>
- **Constexpr vs Macro**
```cpp
                   macro | constexpr
-------------------------|----------------------
Typ e       |     int    |  unsigned
When to use |if no other solution is possible| wherever you want |
```

<a name=vs1></a>
### const vs constexpr
- const: Whose value remains same through out the program
- constexpr: variable whose value is derived at compile-time & initialized
```cpp
int main(){
 ///////////PROBLMATIC CODE////////////
 int a;
 cin >> a;
 const int b = a;   //Problem: How b is const if its value can be changed at runtime?
 
 /////////SOLUTION: constexpr//////////
 //constexpr int c = a;  //error: uninitialized const ‘c’ [-fpermissive
 //constexpr int c;      // error: uninitialized const ‘c’ [-fpermissive]
 constexpr int c = 1;
}
```

<a name=fun></a>
### constexpr function
It return value should be computable at compile time only.
- **RULES?**
  - constexpr function or constructor is implicitly inline.
  - constexpr function accepts and returns only literal-types.
  - constexpr functions cannot be virtual
  - A constructor can't be defined as constexpr when the enclosing class has any virtual base classes.
  - The body can be defined as = default or = delete.
  - The body can contain no goto statements or try blocks.
  - constexpr function return value can be collected in const variable.
- **Problem:** 
```cpp
/////////////const function//////////////
const int fun(){        //Function is not const because return depends on runtime
  int b;
  cin>>b;
  return b;              //NO ERROR
}

/////////////constexpr function//////////
constexpr int fun(){
  //int b;               //error: uninitialized variable ‘b’ in ‘constexpr’ function
  int b = 10;
  return b;  
}

int main(){
  const float d = fun(2);
}
```

<a name=relax></a>
#### RELAXING CONSTRAINTS ON CONSTEXPR FUNCTION(C++14)
- In C++11, constexpr function bodies could only contain a very limited set of syntaxes, including (but not limited to): typedefs, using, and a single return statement. 
- In C++14, the set of allowable syntaxes expands greatly to include the most common syntax such as if statements, multiple returns, loops, etc.                
  - RETURN TYPE: C++14: Requires constexpr variables to be of literal type(the standard doesn't define a named requirement with this name. This can be scalar,reference type,array of literal type).
