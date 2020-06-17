## `[[nodiscard]](C++17)  [[nodiscard("reason")]](C++20)`
  - Compiler will issue a warning if return value is discarded from `nodiscard` function.
  - **Where nodicard can be used?**
    1. Function declaration
      - 
    2. Enumeration declaration
      - 
    3. class declaration
      - 
```c++
//////////////////////////FUNCTION DECLARATION///////////////////
[[nodiscard]] int f(){
  return 1;
}
int main(){
  f();
}
$ g++ nodiscard.cpp
test.cpp: In function ‘int main()’:
test.cpp:9:3: warning: ignoring return value of ‘int f()’, declared with attribute nodiscard [-Wunused-result]
    9 |  f();
      |  ~^~
```
