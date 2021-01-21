/*
        virtual_destructor.cpp
 
Virtual Destructor: 
Same concept of virtual-function. We have base-class-pointer pointing to derived class object. 
And we want to delete base-class-pointer then Destructor of derived class will not be called, if not virtual.

if base class destructor is not virtual: Derv class destructor will not be called.
-> See commented example below.
*/

/*
#include<iostream>
using namespace std;
class A{
        int *a;
public:
        A(){a = new int;}                               
        ~A(){cout<<"Destructor class A. (deleting a)"<<endl;}   <<<<< NOT VIRTUAL
};
class B: public A{
        int *b;
public:
        B(){b = new int;}
        ~B(){cout<<"Destructor class B. (deleting b)"<<endl;}
};
int main(){
        A *ptr = new B();
        delete ptr;
        return 0;
}

Output:
Destructor class A. (deleting a)
*/

#include<iostream>
using namespace std;
class A{
        int *a;
public:
        A(){a = new int;}
        virtual ~A(){cout<<"Destructor class A. (deleting a)"<<endl;}
};
class B: public A{
        int *b;
public:
        B(){b = new int;}
        ~B(){cout<<"Destructor class B. (deleting b)"<<endl;}
};
int main(){
        A *ptr = new B();
        delete ptr;
        return 0;
}
/*
Output:
Destructor class B. (deleting b)
Destructor class A. (deleting a)
*/
