## Lambda capture initializers
- Allows lambda captures initialized with arbitrary expressions.
```c++
  auto f = [x = test(2)] { return x; };           //20  
```
