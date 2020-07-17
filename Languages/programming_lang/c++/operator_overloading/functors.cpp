/*      functors.cpp

WHAT? 
- A object of class that can used on left side of Function call operator (). Ex: object()
- Overloading () operator inside class, now Object of this class can behave as Function.
- Remember functors are objects only, Hence can store state.

DOES COMPILER PROVIDES FUNCTOR? No, we need to define explicitly.

WHY?
1. FUNCTOR vs NORMAL-FUNCTION?
                NORMAL-FUNCTION                 FUNCTOR
store state?    No                              Yes
                Need to use global,static       a. non-static pvt member(ie object specific)
                                                b. static(across all objects)

 */
#include<iostream>
using namespace std;

class A {
        int state_variable;             //STATE VARIABLE
public:
        A(int c):state_variable(c) {};

        int operator ()(int b){
                return b*state_variable;
        }
};
int main(){
        A obj(10);
        cout<<obj(3)<<endl;     //30
        cout<<obj(5)<<endl;     //50
}
