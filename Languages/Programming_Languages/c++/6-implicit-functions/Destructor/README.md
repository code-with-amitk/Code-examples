**Destructor**
- [When dtr is called by compiler](#w)
- [When dtr is not provided by compiler](#w1)
- **Destructor calling Hierarchy Examples**
  - [Ex1: Inheritance case](#e1)
  - [Ex2: Non Inheritance case](#e2)
  - [Ex3: Calling base destructor when derv destructor has exception](#e3)

## Destructor
`~classname()` that is called when lifetime of an object ends. Dtr frees resources that object may have acquired during its lifetime.
```c
PARAMETERS: None
RETURN TYPE: None
Cannot overloaded? Bcoz they cannot be called using objects.
```

<a name=w></a>
### When dtr is called by compiler
Whenever an object's lifetime ends, which includes
- program termination with exit()
- thread exit.
- end of function scope 
- delete called for objects with dynamic storage duration
- stack unwinding, for objects with automatic storage duration 

<a name=w1></a>
### When dtr is not provided by compiler
1. If explicitly declared destructor present in class.   
2. {In C++11} Default destructor deleted. ~A() = delete; 

### Destructor calling hierarchy = Opposite of constructor
<a name=e1></a>
#### Inheritance case
```cpp
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
  	Derv Ct
  	~Derv
  	~Base
```

<a name=e2></a>
#### Non-Inheritance case
```cpp
class A {
public:
    A() { cout << "ctr called " << id << endl; }
    ~A() { cout << "dtr called " << id << endl;
    }
};
int main() {
    A a[2];
    return 0;
}
$ ./a.out
ctr called    //a[0]
ctr called    //a[1]
dtr called    //a[1]
dtr called    //a[0]
```

<a name=e3></a>
#### Calling base destructor when derv destructor has exception
_Question:_ if destructor throws exception at line 1, then How memory allocated in base ctr will be freed?
- [Constructor, Destructor calling Hierarchy](/Languages/Programming_Languages/c++/6-implicit-functions/Constructor/README.md)
```cpp
#include<iostream>
using namespace std;

class base {
    char *bp;
public:
    base() {
        bp = new char[5];
        cout << "base() \n";
    }
    ~base(){
        cout << "~base\n";
        delete bp;
    }
};
class derv : public base {
    char *dp;
public:
    derv() {
        dp = new char[5];
        cout << "derv() \n";
    }
    
    //In C++11, By default Destructor always terminates on exception
    //We can make it no except
    ~derv() noexcept(false){              
        cout << "~derv\n";                
        delete dp;
        throw bad_alloc();               //////////////1
    }
};
int main(){
  try {
    derv d;
  }
  catch (std::bad_alloc& e) {
    cout << e.what();
  }
}
$ ./a.out
base() 
derv()
~derv 
~base              <<< Base dtr is called, if we remove noexcept(false) from destructor ~base will not be called.
std::bad_alloc
```
