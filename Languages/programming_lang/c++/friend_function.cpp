/*
Friend Function?
- Function name prefixed with keyword 'friend'.
- [Usage] 
        - This is common function declared in multiple classes.
        - Inside this function private data of classes can be accessed/modified using class object.
- Note: friend is not member of class, so:
        - friend function cannot access pvt members, this pointer directly.

Declared: inside class scope
Definition: inside or outside class.
 */
#include<iostream>
using namespace std;

class B;    //Forward declaration

class A{
    int a;
    public:
        A(){
                a =0;
        }
        friend void fun(A, B, int, int);
};

class B{
    int b;
    public:
        B(){
                b=0;
        }
        friend void fun(A, B, int, int);
};

void fun(A objA, B objB, int x, int y){
        objA.a = x;
        objB.b = y;
        cout<<"Inside friend function"<<endl;
        cout<<"a="<<objA.a<<" b="<<objB.b<<endl;
}

int main(){
        A objA;
        B objB;
        fun(objA, objB, 10, 20);
        return 0;
}
/*
Output:
# ./a.out
Inside friend function
a=10 b=20
 */
