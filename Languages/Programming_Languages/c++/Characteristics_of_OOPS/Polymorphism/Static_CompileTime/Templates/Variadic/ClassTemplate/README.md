**Variadic class template**
- Examples
  - [Basic Understanding](#bu)
  - [ReverseBinaryValue_hackerRank](#rbv)

### Variadic class template
- class template taking variable no of arguments. 
- template parameter pack must be the final parameter in the template parameter list else its compile time error.

### Examples
<a name=bu></a>
#### Basic Understanding
```cpp
template<typename ... T>
struct A {};

//T = int, vars = float,string
template < typename T, typename ... vars >//vars: represents variable no of arguments
struct A < T, vars ... >                  //T, vars need to be copied as it is
{
  T a;                //int a   //1st variable
  
  A < vars ... > v ;  //{float=.., string=...}

  A ( const T& x, const vars & ... y ) : a(x), v (y...) {}
};

int main() {
  A < int, float, string > obj ( 10, 2.1, "Hello" );

  cout << obj.a << endl;    //10
}  
```

<a name=rbv></a>
#### [Reverse Binary Value hackerRank](https://www.hackerrank.com/challenges/cpp-variadics/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign)
- Create a template function named reversed_binary_value. It must take an arbitrary number of bool values as template parameters. These booleans represent binary digits in reverse order. Your function must return an integer corresponding to the binary value of the digits represented by the booleans. For example: reversed_binary_value<0,0,1>() should return. Examples
```c++
Input:
2
65 1
10 0
Output:
0100000000000000000000000000000000000000000000000000000000000000
0000000000100000000000000000000000000000000000000000000000000000
```
#### Code
```c++
#include<iostream>
using namespace std;

template <bool... digits> struct B;

template <>                                //Template can have 0 templated argument, mostly used in base case
struct B <> {                              //class B Base case
    static constexpr int val = 0;
};

template < bool t, bool ... Ts >
struct B <t , Ts ... > {                    //class B templated case
    static constexpr int val = t + 2*B < Ts ... >::val;
};

template < bool ... Ts >
int reversed_binary_value() {
    return B < Ts... > :: val;
}

template <int n, bool ... Ts>
struct A {                              //class A templated case
  static void fun (int x, int y) {
    A<n-1, 0, Ts...>::fun(x, y);
    A<n-1, 1, Ts...>::fun(x, y);
  }
};

template <bool... Ts>
struct A< 0, Ts ... > {                 //class A base case
    static void fun (int x, int y)
    {
      int z = reversed_binary_value <Ts ... >();
      std::cout << (z+64*y==x);
    }
};

int main() {
    int t; std::cin >> t;
    for (int i=0; i!=t; ++i) {
    int x, y;
      cin >> x >> y;
      A<6>::fun(x, y);
      cout << "\n";
    }
}
```
**How code works?**
```c++
B<>
  val = 0;

B<t=0, Ts=0>
  val = 0 + 2*B<0>::val

reversed_binary_value()
  B<0,0>::val

 A<n=0,Ts=0,0>::fun(65,1)
    z = reversed_binary_value<0,0>

A<1,Ts=0>::fun(65,1)
  A<0,0,0>::fun(65,1)

A<n=2>::fun(65,1)
  A<1,0>::fun(65,1)
  
main() 
  A<2>::fun(65,1)
```
