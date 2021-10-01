**Destructor**
- [When dtr is called by compiler](#w)
- [When dtr is not provided by compiler](#w1)
- **Destructor calling Hierarchy**
  - [Example1: Inheritance case](#ex1)
  - [Example2: Non Inheritance case](#ex2)

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
<a name=ex1></a>
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
<a name=ex2></a>
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
