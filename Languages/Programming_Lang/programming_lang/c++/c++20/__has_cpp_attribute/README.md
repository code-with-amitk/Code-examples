## `__has_cpp_attribute( attribute-token ) C++20`
  - C++ defines set of preprocessor macro called [attributes](https://github.com/amitkumar50/Code-examples/blob/master/programming_lang/c%2B%2B/c%2B%2B11/attributes/README.md) on C++11 page.
  - `__has_cpp_attribute( attribute-token )` Checks for the presence of an attribute named by attribute-token.
  
  ```c++
#include<iostream>
using namespace std;

//depreacted introduced in (C++14)
#  if __has_cpp_attribute(unlikely)
  # define TEST 10
#else
  # define TEST 2
#endif

int main(){
  cout<<TEST;
}
  ```
