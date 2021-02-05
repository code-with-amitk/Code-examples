## Insert
- **1. void push_back (const value_type& val);**
```c++
#include <deque>

int main () {
  std::deque<int> d;
  int myint;
  d.push_back (myint);
}  
```

## Delete
### From Back
- **1. void pop_back();**
```c++
  std::deque<int> d;
  d.push_back (10);
  d.push_back (20);
  d.push_back (30);
  d.pop_back();
```
