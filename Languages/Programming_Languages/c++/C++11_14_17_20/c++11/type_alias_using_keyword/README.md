## Type Alias / using keyword
- **Usecase-1?** We use type alias in place of typedef
```c++
    C++03: typedef long counter;           //Here syntax of typedefs gets ugly with complex typedefs
    C++11: using counter = long;           //type alias.
```    
- **Usecase-2:** 
  - Bring a specific member from the namespace into the current scope. or Bring all members from the namespace into the current scope. 
  - or Bring a base class method or variable into the current class’s scope.
```rust
  using boost::any;        //Bringing any from boost namespace to current scope.
  vector<any> a;            //Now we can use 'any', else we have to define as: vector<boost::any> a
```    
