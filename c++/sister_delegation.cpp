/*
 Basic Rule of PVF(Pure virtual function):
 - As per rule all PVFs of abstract class should be overridden/defined inside derived class or derived class should re-declare all PVFs as PVFs.

 sister delegation? is exception to above rule.
 - if virtually derived classes in combination overrides/defines the PVFs of base class, then compiler does not give error.
 - And this can be powerful tool used at places called SISTER Delegation 
 */
#include<iostream>
using namespace std;

class A{
        public:
                virtual void f1()=0;
                virtual void f2()=0;
};

class B:virtual public A{
        public:
                void f1(){
                        cout<<"B"<<endl;
                }
};

class C:public virtual A{
        public:
                void f2(){
                        cout<<"C"<<endl;
                }
};

class D: public B, public C{};

int main(){
        D *obj = new D();
        obj->f1();
        obj->f2();
        return 0;
}
/*
 * Output:
 * B
 * C
 */
