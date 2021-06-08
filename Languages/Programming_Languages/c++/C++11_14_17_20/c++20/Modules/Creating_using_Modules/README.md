## Creating and using modules
- [C++20 compiler wandbox](https://wandbox.org/)
```c++
1. Creating Module: Create a module with export statement.
```c++
# vim hello.cpp     
export module module1;                                //module name
import <iostream>;         
 
export void hello() {                       
  std::cout << "Hello world!\n";
}

2. Using module: Use module in other file

# vim main.cpp 
import module1;          //import declaration
int main() {
  hello();
}
```
