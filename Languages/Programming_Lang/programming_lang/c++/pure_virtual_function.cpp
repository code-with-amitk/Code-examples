/*
Pure Virtual Function: When we can't (or don't want to) implement a method for the base class. 
We want classes to inherit it and implement the PVF. Always needs to be overridden in derv class

See Abstract_class can have other non-virtual functions defined in it.

Check virtual_function.cpp for how vtables work.
 */
#include<iostream>
using namespace std;

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
/*
# ./a.out 
class B fun1()//PVF
class A fun2()
 */
