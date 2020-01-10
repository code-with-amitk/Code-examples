/*
        virtual_destructor.cpp
 
Virtual Destructor: 
 Freeing Memory allocated in derived class using Base class pointer, BASE CLASS Destructor needed to be declared virtual.

- if base class destructor is not virtual:
        Derv class constructor will not be called.
Ouput:
Deleted k
~B
~A

- if virtual is not prefixed before base class constructor.
Output:
~A

*/
#include<iostream>
using namespace std;

class A{
public:
        virtual ~A(){
                cout<<"~A"<<endl;
        }
};
class B: public A{
public:
        ~B(){
                char *k = new char;
                delete k;
                cout<<"Deleted k\n";
                cout<<"~B"<<endl;
        }
};

int main(){
        A *ptr = new B();
        delete ptr;
        return 0;
}
