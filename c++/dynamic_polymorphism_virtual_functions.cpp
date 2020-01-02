/*
Dynamic/Runtime Polymorphism? Memory is allocated at run time.

Example of Dynamic polymorphism? Virtual Function

When to use VF? Same named functions in Base & derv class & both to be accessed using Base class Pointer only.

Virtual Function? Function prefixed with virtual keyword in base class.

How VF logic is implemented? Using vtable,Virtual Table,Dispatch table
*********************

**************************************
VIRTUAL TABLE/vtable/Dispatch table: Static array of function pointers.

- Present in RO-DS section.
- Each class will have its vtable. 3 classes 3 vtables
- vptr is 1st member of object, which points to base address of vtable
- [Note] virtual function should have a body, if its not pure virtual function.
- [Class C] if class does not override a VF, still its vtable is created which points to base class function address.

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

*/

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
/*
Output:
A vf1
B vf1
 */
