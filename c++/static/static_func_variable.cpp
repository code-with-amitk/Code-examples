/*      static_func_variables.cpp

A. STATIC MEMBER VARIABLES:
    - Shared among all Objects of class. Only 1 copy of variables is created.
    - Should be initialized before using the variable.

B. MEMBER FUNCTION: Can be called without class object
*/

#include<iostream>
using namespace std;

class A{
        static int a;           //A
public:
        static void f(){
                a = 20;
                cout<<"Hello="<<a<<endl;
        }
};

int A::a=10;                    //A

int main(){
        //B
        A::f();         //O/P: Hello

        return 0;
}
