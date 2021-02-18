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
    

### RELAXING CONSTRAINTS ON CONSTEXPR FUNCTION(C++14)
- In C++11, constexpr function bodies could only contain a very limited set of syntaxes, including (but not limited to): typedefs, using, and a single return statement. 
- In C++14, the set of allowable syntaxes expands greatly to include the most common syntax such as if statements, multiple returns, loops, etc.                
  - RETURN TYPE: C++14: Requires constexpr variables to be of literal type(the standard doesn't define a named requirement with this name. This can be scalar,reference type,array of literal type).
