**selection statements with initializers**

### Selection statements with initializers
- We can have variable initializers before the condition in:
  - if or if…else statement 
  - switch statement.
```cpp
 #include <iostream>
 using namespace std;
 
 int main() {
  if (int value{7}; value == 7) 
    cout << "value is " << value << "\n";
  else
    cout << "value is not 7; it is " << value << "\n";
}
```
