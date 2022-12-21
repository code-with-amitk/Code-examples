## Virtual Destructor?
- Same concept of virtual-function. 
- Base-class-pointer pointing to derived class object, derv class destructor will not be called if base class destructor is not virtual.

### Derv class destructor not called
```c++
class Base{
public:
  ~Base(){ cout<<"~base\n";  }      //Base class dtr not virtual
};
class derv:public Base{
public:
  ~derv(){ cout<<"~derv\n"; }
};
int main(){
  Base *p = new derv();
  delete p;
}
# ./a.out
~base
```

### When base destructor is virtual, derv class destructor called
```c++
class Base{
public:
  virtual ~Base(){ cout<<"~base\n";  }
};

class derv:public Base{
public:
  ~derv(){ cout<<"~derv\n"; }
};

int main(){
  Base *p = new derv();
  delete p;
}
# ./a.out
~derv
~base
```
