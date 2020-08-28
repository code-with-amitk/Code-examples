
```c++
template <class T>            //OR <typename T>
class A {
  A a, b;                    //Generic Member variables
public:
  A (T x, T y):a(x),b(y){}
  A add ();
};

//Template statement need to be written again when template class function is defined outside template class.
template <class T>
T A <T>::add(){ 
  return a+b; 
}

int main() {
  A<int> obj(5,6);
  cout<<obj.add()<<endl;          //11

  A <float> obj1(5.6,6.7);
  cout<<obj1.add()<<endl;         //Output: 12.3

  A <int> obj2(5.6,6.7);       //C
  cout<<obj2.multiply()<<endl;    //Output: 30
}
```
