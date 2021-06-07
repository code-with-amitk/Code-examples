## Creating and using modules
- **Creating Module**
  - _1._ Create a module with export statement.
```c++
# vim hello.cpp                                                 //file1
export module hello;                                //1
import <iostream>;         //import declaration
 
export void hello() {                           //export declaration
  std::cout << "Hello world!\n";
}
```
- **Using module**
```c++
# vim main.cpp                                                  //file2
import helloworld;          //import declaration
int main() {
  hello();
}
```
