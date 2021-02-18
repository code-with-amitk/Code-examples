## THIS INSIDE CAPTURE LIST 
### LAMBDA CAPTURE FOR `*THIS` (C++17)
- This is CALL-VALUE-COPY of the current object. call-by-value means you cannot change any of object's values.
```c++
class A{
  int  a = 3;       
public:
  void f(){
    int l;
    auto ptr = [l, *this]{
      //a = 3;                              //Compilation error: Changing value of RO Object is not allowed
      int k = a + l;    //This is OK
    };
  }
};
```

### Other `this` examples
#### Using `this` with Reference inside capture list
```c++
  int i = 2;
  auto p6 = [ &, this ] (int a)  ->  int { return a + i; };     //OK, equivalent to [&]
  cout << p6(4);    //6

   [&, this, i]{};                                              // OK, equivalent to [&, i]
```

#### Using `this` with Value inside capture list
```c++
  [=, *this]{};   // since c++17: OK: captures the enclosing function by copy
                  // until C++17: Error: invalid syntax
                    
  [=, this] {};   // since C++20: OK, same as [=]
                  // until C++20: Error: this when = is the default
```

#### Repeated `this` inside capture list
```c++
  [this, *this] {};   // Error: "this" repeated (C++17)
```

## BY-COPY, BY-REFERENCE CAPTURE of Parameter Pack (C++20)
```c++
auto f = []<typename ...Ts>(Ts&& ...ts) {
   return foo(std::forward<Ts>(ts)...);
};
```
