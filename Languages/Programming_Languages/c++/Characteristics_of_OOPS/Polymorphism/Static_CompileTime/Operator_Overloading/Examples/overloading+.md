## Overloading + Operator
- `A& operator+(const A& obj)` ie `Operator+()` cannot return reference.
  - Because we are creating a local object(A t) in function and that needed to be copied in `A obj3`.
  - If i return reference `A& operator+(const A& obj)`, local object will get destroyed as function call end and coredump.

### Code
```c++
class A{
  int a;
  string s;
  public:
    A(int b, string s1):a(b),s(s1){}    //Constructor Initialization list: For initializing member variables of class.
    A(){}
    A operator+ (const A& obj){        //A& operator+(const A& obj) will not work, see above
      A t;
      t.a = this->a + obj.a;
      t.s = this->s + obj.s;
      return t;
    }
    void disp(){
      std::cout<<a;
      std::cout<<s;
    }
};

int main(){
  A obj1 (1,"test");
  A obj2 (2,"now");
  A obj3 = obj1 + obj2;   //obj2.operator+(obj1)
  obj3.disp();
}
```
