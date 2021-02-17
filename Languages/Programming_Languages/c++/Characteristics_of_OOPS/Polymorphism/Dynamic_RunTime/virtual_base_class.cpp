/*
        virtual_base_class.cpp
        
 *Virtual Base class: Used for preventing multiple “instances” of a given class appearing in an inheritance hierarchy when using multiple inheritances.

See Below code:
 - data members/function of class A are inherited twice to class D.
 - When any data / function member of class A is accessed by an object of class D, ambiguity arises as to which data/function member would be called? One inherited through B or the other inherited through C. This confuses compiler and it displays error.

[Note] virtual can be written before or after the public. Now only one copy of data/function member will be copied to class C and class B and class A becomes the virtual base class. 

 */

#include <iostream>
using namespace std;

class A {
public:
    void fun(){
        cout << "A class\n";
    }
};

class B : virtual public A {};  //if virtual not used will give (error: request for member ‘fun’ is ambiguous)

class C : public virtual A {};

class D : public B, public C {};

int main(){
    D obj;
    obj.fun();
}

/*
 * Output:
 * A class
 */
