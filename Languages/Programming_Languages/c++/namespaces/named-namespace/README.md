## Named namespace
- namespace having name.
- **Syntax**
```c++
namespace ns_name { declarations }
```  
- **Example** 
```c++
int a = 10;                       //Global variable
namespace A{
  int a;                          //Namespace variable
}

int main(){
  A::a = 30;                      //Initializing namespace variable
  cout<<A::a<<endl;               //30
  {
    extern int a;                   //Global variable
    cout<<"Global a: "<<a<<endl;    //10
  }
  return 0;
}
```
