## Decltype auto
- Similar to auto, it deduces return types while keeping their references, and cv-qualifiers(const, volatile), while auto will not.
- **const int**
```c++
  const int x = 0;
  auto x1 = x;            //Problem: x1 is int, should be 'const int'
  decltype(auto) x2 = x;  //Solved: x2 is const int
```
- **int&**
```c++
  int y = 0;
  int& y1 = y;
  auto y2 = y1;           //Problem: y2 is int
  decltype(auto) y3 = y1; //Solved:  y3 is int&
```
- **int&&**
```c++
  int&& z = 0;
  auto z1 = move(z);              //Problem: z1 is int
  decltype(auto) z2 = move(z);    //Solved: z2 is int&&
```
- **function return type**
```c++
auto fun(const int& i) {
        return i;                       //Problem:Return type is `int`
}

decltype(auto) fun(const int &i){
        return i;                       //Solved: Return type is `const int&`
}
```
