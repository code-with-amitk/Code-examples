## What
- Places declaration of namespace within the block.

### Syntax
```  
using namespace ns_name
```  

### Example
```  
namespace A{
  int a = 10;
}
namespace B{
  int a = 20;
  namespace C{
    using namespace A;// all names from A injected into global namespace
  }
}
int main(){
  cout<<B::C::a<<endl;       //10
}
```

## Example: USING DECLARAION
### SYNAX
```
using typename(optional) nested-name-specifier unqualified-id ;
```
### Code
```c++
void fun(){
  cout<<"Global fun"<<endl;
}
namespace A{
  int a = 10;
  void fun(){
  cout<<"A::fun()"<<endl;
}
namespace B{
  using A::a;     //A::a is now visible as ::B::a
  using ::fun;
}
int main(){
  cout<<B::a;     //10
  B::fun();       //Global fun
}
```
