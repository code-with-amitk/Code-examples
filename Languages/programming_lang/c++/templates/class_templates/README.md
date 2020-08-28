## Class Template
- **What**
  - Generic class which having(Generic member variables, Generic member functions)
  
- **Rules**
  - Rule-1
    1. Template statement need to be written again when template class function is defined outside template class.
    2. Compiler cannot deduce template parameter type(s) for class template. We need to tell compiler the data types we would be using.
    3. If arguments are of other type and template-type of other type. Compiler will ignore Argument type
```c++
template <class T>            //OR <typename T>
class A {
  A a, b;                    //Generic Member variables
public:
  A (T x, T y):a(x),b(y){}
  A add ();
};

template <class T>                    //A
T A <T>::add(){ 
  return a+b; 
}

int main() {
  A<int> obj(5,6);                  //B
  cout<<obj.add()<<endl;          //11

  A <float> obj1(5.6,6.7);
  cout<<obj1.add()<<endl;         

  A <int> obj2(5.6,6.7);           //C
  cout<<obj2.multiply()<<endl;    //Output: 30
}
```
