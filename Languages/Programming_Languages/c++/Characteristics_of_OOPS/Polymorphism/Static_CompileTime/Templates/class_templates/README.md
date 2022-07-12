**Class Template**
- **Rules**
  - [1. Template statement need to be written again when class function is defined outside class](#r1)
  - [2. Template can have 0 templated argument](#r2)
  - [3. On compile time, compiler creates seperate class for different parameter types](#r3)

## Class Template
Generic class which having(Generic member variables, Generic member functions)

### Rules
<a name=r1></a>
#### A. Template statement need to be written again when template class function is defined outside template class
- _B._ Compiler cannot deduce template parameter type(s) for class template. We need to tell compiler the data types we would be using.
- _C._ If arguments are of other type and template-type of other type. Compiler will ignore Argument type
```c++
template <class T>            //OR <typename T>
class A {
  A a, b;                    //Generic Member variables
public:
  A (T x, T y) : a(x), b(y) {}
  A add ();
};

template <class T>                    //A
T A <T>::add(){ 
  return a+b; 
}

int main() {
  A <int> obj(5,6);                  //B
  cout<<obj.add()<<endl;          //11

  A <float> obj1(5.6,6.7);
  cout<<obj1.add()<<endl;         

  A <int> obj2(5.6,6.7);           //C
  cout<<obj2.multiply()<<endl;    //Output: 30
}
```

<a name=r2></a>
#### 2. Template can have 0 templated argument
- _a._ Only 1 copy of static variable is kept per class
```c++
template < int n >                                //0 templated arguments
struct st {
  static const int val = 2 * st<n-1>::val;
};

template <> 
struct st < 0 > {                                  //0 templated arguments
  static const int val = 1 ;
};

int main() {
    cout << s<10>::val << endl;                //Output=1024
    return 0;
}
```

<a name=r3></a>
#### 3. On compile time, compiler creates seperate class for different parameter types.
```cpp
Test<int>::Test()     //class-1
Test<double>::Test()  //class-2
*/
template <class T>
class Test
{
  T val;
public:
  static int count;
  Test()  {   count++;   }
};
 
template<class T>
int Test<T>::count = 0;
 
int main() {
  Test<int> a;
  Test<int> b;
  Test<double> c;
  cout << Test<int>::count   << endl;       //2
  cout << Test<double>::count << endl;      //1
  return 0;
}
```
