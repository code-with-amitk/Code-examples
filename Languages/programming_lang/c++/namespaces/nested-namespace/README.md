## Nested Namespace (C++17)
- Namespace inside a namespace.
 
```
 namespace A::B::C { ... } 

is equivalent to 

 namespace A { 
   namespace B { 
     namespace C {
     } 
   } 
 }
```             
namespace A{
 int a = 10;
}
namespace A::B::C{
 int a = 20;
}

int main(){
 cout<<"A::B::C::a="<<A::B::C::a<<"\n";          //20
 cout<<"A::a="<<A::a<<"\n";                      //10
}
```
