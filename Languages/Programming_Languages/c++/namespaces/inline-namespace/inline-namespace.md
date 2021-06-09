## inline namespace
- **What**
  - Members of an inline namespace are treated as if they are members of the enclosing namespace.
  - inline may appear in front of every namespace name except the first.
- **Example**
  - _1._ var is treated as member of namespace A. 
```c++
namespace A{
  inline namespace B{           //if we remove inline from front, cout will throw error
    int var = 10;
  }
}

int main(){
  cout<<A::var;     //10
}
```
