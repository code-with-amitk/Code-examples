- [Function Pointer](#fp)
  - [Pointer to function returning void, accepting void](#v)
  - [Pointer to class method](#cm)

<a name=fp></a>
## Function Pointer
<a name=v></a>
#### 1. Pointer to function returning void, accepting void
```c
void fun(){
  cout << "fun";
}
void (*ptr)() = fun;
ptr();                    
```
<a name=cm></a>
#### Pointer to class method
```cpp
class A{
public:
  typedef int (A::*ptr)();      //1. Declare function pointer to class A method returning int, accepting nothing
  int fun() {
    cout << "fun";
  }
};
int main() {
  A* obj = new A();            //2. Create object
  A::ptr p = &A::test();       //3. Create Function pointer p pointing to test
  (obj->*p)();                 //4. Invoke function using function pointer
}
```
