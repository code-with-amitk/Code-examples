## Using both `[=]` and `[&]`
- **1. Capture by reference all except 1**
  - Except "j" everything else is captured as reference(ie can be changed). Just "j" cannot be changed
```c++
  auto p7  =  [ &, j ]  (int a, int b)  ->  int {
    i=7;
    return a + b + i; 
  };
```  

- **2. Capture by Value all except 1**
- Except "i" nothing can be changed.
```c++
  auto p8  =  [ =, &i ]  (int a, int b)  ->  int {  i=95;  return a + b + i; };
```
