## UNNAMED/ANONYMOUS NAMESPACE
	- **What** Namespace without name.
	- **Why**
		- Makes variables, functions, classes local to translation unit(.cpp file and all its includes) scope.
		- This means that if another symbol(function,class,variable) with the same name is defined in some other file it will not generate error.
		- This can thought similar to C's `global static`.
	- **Syntax**
		- inline(optional) namespace attr(optional) { namespace-body }
			
### EXAMPLES
#### 1. unnamed namespace inside named namespace
```
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
