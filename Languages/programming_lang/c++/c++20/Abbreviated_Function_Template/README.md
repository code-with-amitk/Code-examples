## AFT
- **What**
  - When only `auto` or `concept auto` appears inside function parameter list then complier internally converts them to function template.
  - **1. auto in parameter list**
```c++
void f1(auto);    

//Above declaration is same as 
template<class T> 
void f(T)
```
  - **2. concept auto in parameter list**
```c++
void f2(C1 auto);                           //C is a concept

//Above declaration is same as 
template<C1 T> 
void f2(T)
```
  - **3. Parametrized concept**
```c++
void f3(C2 auto...);                        //C is a concept

//Above declaration is same as
template<C2... Ts>
void f3(Ts...)
```
