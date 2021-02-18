## 3 Way Comparison Operator
  - (a <=> b) < 0 if lhs < rhs
  - (a <=> b) > 0 if lhs > rhs
  - (a <=> b) == 0 if lhs and rhs are equal/equivalent.
### Code  
```c++
    double foo = -0.0;
    double bar = 0.0;

    auto res = foo <=> bar;

    if (res < 0)
        std::cout << "-0 is less than 0";
    else if (res == 0)
        std::cout << "-0 and 0 are equal";
        
//Output: -0 and 0 are equal        
```
