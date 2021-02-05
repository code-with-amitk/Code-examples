## BoostAny
- **C++ is strongly typed**
  - C++ is strongly typed language that means each variable have a specific type that defines what kind of information it can store.
  - Unlike Javascript, which can store kind of information in a variable. Eg: in JS single variable can contain a string, then a number, and afterwards a boolean value also.
- **What is boostAny**
  - Provides the `class boost::any` which, like JavaScript variables, can store arbitrary types of information.
  - Variables of type boost::any must be copy-constructible. So, you cannot store a C array, since C arrays aren’t copy-constructible.
  
### Examples
- *1.* Storing int,double,bool in same variable.
```c++
#include <boost/any.hpp>
int main() {
  boost::any a = 1;       //Storing int in a
  a = 3.14;               //Storing float in a
  a = true;               //Storing bool in a
  a = std::string{"Test"} //Storing string in a
}
```

- *2.* Accessing element is done using `boost::any_cast`
  - By passing the appropriate type as a template parameter to boost::any_cast, the value of the variable is converted. 
  - If an invalid type is specified, an exception of type boost::bad_any_cast will be thrown.
```c++
#include <boost/any.hpp>
#include <iostream>
int main() {
  boost::any a = 1;
  std::cout << boost::any_cast<int>(a) << '\n';
  a = 3.14;
  std::cout << boost::any_cast<double>(a) << '\n';
  a = true;
  std::cout << std::boolalpha << boost::any_cast<bool>(a) << '\n';
  
  try
  {
    boost::any a = 1;
    std::cout << boost::any_cast<float>(a) << '\n';
  }
  catch (boost::bad_any_cast &e)
  {
    std::cerr << e.what() << '\n';                  //boost::bad_any_cast: failed conversion using boost::any_cast
  }  
}
```
