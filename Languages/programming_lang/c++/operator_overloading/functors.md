## Functor
### WHAT?
- A object of class that can used on left side of Function call operator (). Ex: object()
- Overloading () operator inside class, now Object of this class can behave as Function.
- Remember functors are objects only, Hence can store state.
- Compipler does not provide functors, we need to define explicitly.

### FUNCTOR vs NORMAL-FUNCTION?
| | NORMAL-FUNCTION | FUNCTOR |
| --- | --- | --- |  
| store state? | <ul><li>No</li></ul> <ul><li>Need to use global,static</li></lu> | <ul><li>Yes</li></ul> <ul><li>a. non-static pvt member(ie object specific)</li></ul> <ul><li>b. static(across all objects)</li></ul> |
                                                

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
