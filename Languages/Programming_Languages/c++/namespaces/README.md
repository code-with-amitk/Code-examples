- [What is Namespace](#what)
- [Types of Namespaces](#types)
  - [1. Inline namespace](#inline)
  - [2. Named namespace](#named)
  - [3. Nested namespace(C++17)](#nested)
  - [4. Unnamed / Anonymous namespace](#unnamed)
  - [5. using-directive Namespace](#using)


<a name=what></a>
## Namespaces
- This is Logical grouping of: classes, objects, variables etc. Used to avoid name conflict. We may have 2 classes with same name in different namespaces. instance of namespace cannot be created. 
- Header file contains lots of namespaces.

<a name=inline></a>
### 1. Inline namespace
- Members of an inline namespace are treated as if they are members of the enclosing namespace.
- inline may appear in front of every namespace name except the first.
- **Example**
  - _1._ var is treated as member of namespace A. 
```c++
namespace A{
  inline namespace B{     //if we remove inline from front, cout will throw error
    int var = 10;
  }
}

int main(){
  cout<<A::var;           //10
}
```

<a name=named></a>
### 2. Named namespace
- namespace having name
```c++
namespace ns_name { declarations }
```  
- *Example*
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

<a name=nested></a>
### 3. Nested namespace (C++17)
- Namespace inside a namespace.
- namespace A::B::C { ... } is equivalent to 
```c
 namespace A { 
   namespace B { 
     namespace C {
     } 
   } 
 }
```     
- Example
```c++
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

<a name=unnamed></a>
### 4. Unnamed / Anonymous namespace
- Namespace without name.
- **Why**
	- Makes variables, functions, classes local to translation unit(.cpp file and all its includes) scope.
	- This means that if another symbol(function,class,variable) with the same name is defined in some other file it will not generate error.
	- This can thought similar to C's `global static`.
- **Syntax**
	- inline(optional) namespace attr(optional) { namespace-body }
- **Examples**
- _1. unnamed namespace inside named namespace_
```c++
#include<iostream>
using namespace std;

namespace boost{
  namespace detail{

    namespace{
      void fun(){ cout<<"fun()"; }
    }

    void go(){ fun(); }

  }
}
int main(){
  boost::detail::go();
}

# ./a.out
fun()
```

<a name=using></a>
### 5. using-directive Namespace
- Places declaration of namespace within the block.
```c  
Syntax: using namespace ns_name

Code:
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
- **Example: USING DECLARAION**
```c
Syntax: using typename(optional) nested-name-specifier unqualified-id ;

Code:
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
