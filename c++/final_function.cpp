/*
Final Function: Final function cannot be inherited

Java: final is placed before function name.
        final void f1(){
                cout<<"Test";
        }
 */
#include<iostream>
using namespace std;

class A{
public:
        virtual void f1() final{
//      virtual void f1() {                     <<This will work
                cout<<"f1 base"<<endl;
        }
};

class B: public A{
        void f1(){
                cout<<"f1 Derv";
        }
};
int main(){
        A *ptr = new B();
        ptr->f1();
        return 0;
}
/*
Output:
error: virtual function ‘virtual void B::f1()’ overriding final function
 */
