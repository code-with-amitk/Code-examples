- [Dynamic/Runtime Polymorphism](#dp)
  - [vtable](#vt)
- [Pure Virtual Function](#pv)

<a name=dp></a>
### Dynamic/Runtime Polymorphism
- Means Same named functions in Base & derv class & both to be accessed using Base class Pointer only. Achieved using Virtual Functions
- Virtual Function? Function prefixed with virtual keyword in base class.

<a name=vt></a>
#### How VF logic is implemented?
- Using vtable,Virtual Table,Dispatch table. VIRTUAL TABLE/vtable/Dispatch table is Static array of function pointers. Present in RO-DS section.
- Each class will have its own vtable. 3 classes 3 vtables. vptr is 1st member of object, which points to base address of vtable
- virtual function should have a body, if its not pure virtual function.

<img src=vtable.png width=600/>

```c
vptr: Which points to vtable of object.
vtable: Points to actual implementation of functions on Code Segment.

Class A's vtable: Points to its own implementation of vf1, vf2.
Class B's vtable: Points to 
                        - Own implementation of vf1
                        - Class A's implementation of vf2
Class C's vtable: Points to
                        - Class A's implementation of vf1
                        - Class A's implementation of vf2

[Stack]|<--     Heap       ->| <- Data Segment   ->| <-    CS   ->
       |                     |    <-        RO   ->|
       |                     |                     |
       |  |vptr_A=0x1|x|     |    |0x4|            |    0x4 A::vf1(){...}
       |  object of A        |    0x1 vtable of A  |
       |                     |                     |
       |  |vptr_B=0x2|x|y|   |    |0x5|            |    0x5 B::vf1(){...}
       |  object of B        |    0x2 vtable of B  |
       |                     |                     |    Non-Virtual-Functions
       |  |vptr_C=0x3|x|z|   |    |0x4|            |    0x100 A::f1(){..}
       |  object of C        |    0x3 vtable of C  |    0x200 B::f1(){..}
       |                     |                     |    0x300 B::f2(){..}
**************************************                      

*******How function call happens in vtable*********
a. call (*(p->vptr)[n])(p)
b. p points to base address of objectB
c. *(p->vptr_B)=0x2. Goes to vtable of B
d. (*(p->vptr)[n])(p) resolves to actual function implementation
***************************************************

#include<iostream>
using namespace std;

class A{
public:
        virtual void vf1(){cout<<"A vf1";}      //virtual function should have body if its not pure
        void f1();
private:
        int x;
};

class B: public A{
public:
        virtual void vf1(){cout<<"B vf1";}
        void f1();
        void f2();
private:
        int y;
};

class C: public A{
private:
        int z;
};

int main(){
        A *ptr = new C();
        ptr->vf1();             //O/P: A vf1.   C's Vtable points to A

        ptr = new B();          //O/P: B vf1.   B's vtable points to B
        ptr->vf1();
}
$ ./a.out
A vf1
B vf1
 ```
 
<a name=pv></a>
### Pure Virtual Function
- When we can't (or don't want to) implement a method for the base class. We want classes to inherit it and implement the PVF. Always needs to be overridden in derv class
- Abstract_class can have other non-virtual functions defined in it.
```cpp
class A{                                        //ABSTRACT CLASS
public:
        virtual void fun1()=0;
        void fun2(){
                cout<<"class A fun2()\n";
        }
};

class B: public A{
public:
        void fun1(){
                cout<<"class B fun1()//PVF\n";
        }
};

int main(){
        A *obj = new B();
        obj->fun1();
        obj->fun2();
}

# ./a.out 
class B fun1()//PVF
class A fun2()
```
