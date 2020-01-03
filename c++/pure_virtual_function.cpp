/*
Pure Virtual Function: Always needs to be overridden in derv class

Check virtual_function.cpp for how vtables work
 */
#include<iostream>
using namespace std;

class A{
public:
        virtual void pvf1()=0;
};

class B: public A{
public:
        void pvf1(){
                cout<<"B pvf1\n";
        }
};

int main(){
        A *obj = new B();
        obj->pvf1();
}

/*
Output:
B pvf1
*/
