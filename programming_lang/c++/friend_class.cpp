/*
Friend class: class is declared friend of other can access private/protected members of class.

- Class A is friend of B. Butt B is not friend of A that means:
        B cannot access member variables of class A
*/

#include<iostream>
using namespace std;

class B{
        friend class A;         //A can access B's members not viceversa
        int b;
public:
        B(int x){
                b = x;
        }
};

class A{
        int a;
public:
        A(){
                a=0;
        }
        void fun(B obj){
                a = obj.b;      //This will throw (error: ‘int B::b’ is private within this context) if friend is removed from B.
        }
        void disp(){
                cout<<"a="<<a<<endl;
        }
};


int main(){
        B objB(10);

        A objA;
        objA.fun(objB);

        objA.disp();
        return 0;
}
/*
Output:
a=10
*/
