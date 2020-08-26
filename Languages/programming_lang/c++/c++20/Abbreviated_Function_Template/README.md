## AFT
- **What**
  - When only `auto` or `concept auto` appears inside function parameter list then complier internally converts them to function template.
  - Function parameter becomes template parameter
  
### Examples  
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
- **3. Variadic concept**
```c++
void f3(C2 auto...);                        //C is a concept

//Above declaration is same as
template<C2... Ts>
void f3(Ts...)
```
- **4. Two concepts**
```c++
void f4(const C3 auto*, C4 auto&); 

//Above declaration is same as
template<C3 T, C4 U> 
void f4(const T*, U&);
```
- **5. Template and concept**
```c++
template <class T, C U>
void g(T x, U y, C auto z);

//Above declaration is same as
template<class T, C U, C W> 
void g(T x, U y, W z);
```
