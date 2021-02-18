## Designated Initializer
  - Doing designated initialization of struct, union etc
  
### E
  - Designator order must match declaration order, If order is correct any element can be skipped from between
```c++
int main(){
  struct A {
    int x;
    int y;
    int z;
  };
  A b{.x = 1, .z = 2};                    // ok, b.y initialized to 0
  cout<<b.z;                              //2
  
  //A a{.y = 2, .x = 1};                  //error; designator order does not match declaration order
}  
```

### RULE-2 (DI for unions)
  - Only 1 initializer is valid for unions.
```c++
  union u {
    int a;
    const char* b;
   };
  u f = { .b = "asdf" };                // OK, active member of the union is b
  u g = { .a = 1, .b = "asdf" };        // Error, only one initializer may be provided
```
  
