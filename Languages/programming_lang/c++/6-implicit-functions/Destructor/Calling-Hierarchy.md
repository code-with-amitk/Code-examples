### Destructor calling hierarchy
- Opposite of constructor
- **Example code**
```c++
#include<iostream>
class Base{
public:
	Base(){		std::cout<<"Base Ctr\n";	}
	~Base(){  std::cout<<"~Base\n";  }
};
class derv:public Base{
public:
	derv(){		std::cout<<"derv Ctr\n";	}
	~derv(){	std::cout<<"~derv;\n";	}
};
int main(){
	derv d;
}
# ./a.out
   	Base Ctr
  	Derv Ctr
 
  	~Derv
  	~Base
```
