**Chain of Responsibility**
- [How it works](#how)

## Chain of Responsibility
Request is processed by 1 or more objects in chain.
<a name=how></a>
### How it works
- Take a Abstract class(also called handler interface), override in concrete class
  - Each concrete class will hold pointer to Object of next class.
  - Responsibility/Work is passed by calling function from other object using pointer.

### Code
```cpp
#include <iostream>
using namespace std;

int limit_per_object = 50;

class Base {                    //ABSTRACT CLASS. Handler Interface
protected:
  Base *next;
public:
  Base(){next = NULL;}
  virtual void request(int value) = 0;    //Pure virtual Function. Cannot have body in Abstract class, must be overridden in derived class.
  void setNextHandler(Base *p){
    this->next = p;
  }
};

class derv : public Base{       //Concrete class
  int myId;
public:
  derv(int a): myId(a) {}

  void request(int value){
    if(value > limit_per_object) {
      cout<<"Object"<<this->myId<<" handling ["<<limit_per_object<<"] requests\n";

      if(this->next != NULL){
        this->next->request(value - limit_per_object);
      } else {
        cout << "I am the last handler Object"<<this->myId<<" handling ["<<limit_per_object << "] requests.\n" << endl;
        if(value - limit_per_object)
          cout<<"Sorry your ["<<(value - limit_per_object)<<"] requests are still pending\n";
      }
    }//if
  }
};

int main () {
  Base *obj1 = new derv(1);
  Base *obj2 = new derv(2);
  Base *obj3 = new derv(3);

  obj1->setNextHandler(obj2);
  obj2->setNextHandler(obj3);
  cout<<"\nResponsibility Chain Set\n\n";

  obj1->request(180);

  delete obj1;
  delete obj2;
  delete obj3;

  return 0;
}

/*
 Output:
# ./a.out 

Responsibility Chain Set

Object1 handling [50] requests
Object2 handling [50] requests
Object3 handling [50] requests
I am the last handler Object3 handling [50] requests.

Sorry your [30] requests are still pending

*/
```
