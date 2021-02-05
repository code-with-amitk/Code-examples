### Things to note:
- *A.* Template class is declared with `template <>`
- *B.* The type to be used as a template argument must be specified directly following the name of the class

```c++
template < typename T >
class A {
public:
  void fun () {
    cout<<"Generic class"; 
  }
};

template <>                               //A
class A < char > {                        //B   class A<char>
public:
  void fun (){ 
    cout<<"Specialized class"; 
  }
};

int main() {
  A  <char> o1;
  o1.fun();                  //Output: Specialized class

  A <int> o2;
  o2.fun();                  //Output: Generic class

  A <float> o3;
  o3.fun();                  //Output: Generic class
}
```
