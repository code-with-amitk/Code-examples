## Creating and using modules
- [C++20 compiler wandbox](https://wandbox.org/)
- _1. Creating Module:_ Create a module with export statement.
```c++
# vim hello.cpp     
export module module1;                                //module name
import <iostream>;         
 
export void hello() {                       
  std::cout << "Hello world!\n";
}
```

- _2. Using module:_ Use module in other file
```c++
# vim main.cpp 
import module1;          //import declaration
int main() {
  hello();
}
```
