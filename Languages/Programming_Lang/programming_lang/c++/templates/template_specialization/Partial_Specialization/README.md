## Partial Specialization
- **What** Some template parameters are defined, while others are kept generic only. Class may have multiple definitions are in case of specilization.
- **Example**
```c++
template <typename T> class A<T,int>{ .. }                  //1
 
template <typename T1, typename T2> class A<T1*,T2*> {..}   //2

template <typename T1, typename T2> class MyClass {..}      //3

template <typename T> class A<T,T> { .. }                   //4

A<int,float> mif;     //uses 3 A<T1,T2>
A<float,float> mff;   //ses 4 A<T,T>
A<float,int> mfi;     //uses 1 A<T,int>
A<int*,float*> mp;    //uses 2 A<T1*,T2*> 
```
