## string_view
- **What** 
  - [Example] Consider a window in your house, looking at a car parked on the street. We can look through the window and see the car, but can’t touch or move the car. Your window just provides a view to the car, which is a completely separate object.
  - Unlike std::string, which keeps its own copy of the string, std::string_view provides a view of a string
- **Example**
```c++
#include <iostream>
#include <string_view>
 
int main() {
  string_view a{ "hello" };     //a = hello
  string_view b{ a };           //b = a     no other copy is created, points to a
  string_view c{ b };           //c = a
    
  //b[3] = 'p';                   //Compilation error, its RO
}
```
