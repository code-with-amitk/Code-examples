## Named namespace
- namespace having name.

### SYNTAX
```
namespace ns_name { declarations }
```  

### Example  
```c++
int a = 10;                       //Global variable

namespace A{
  int a;                          //Namespace variable
}

int main(){
  int a = 20;                     //Local variable

  
  A::a = 30;                      //Initializing namespace variable
  cout<<"namespace's a "<<A::a<<endl;    //30

  {
    extern int a;                   //Global variable
    cout<<"Global a: "<<a<<endl;    //10
  }

  cout<<"Main's a: "<<a<<endl;      //20    //Local variable
  return 0;
}
```
