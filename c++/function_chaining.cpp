/*
Function Chaining: Calling more than 1 function in 1 statement using this pointer.

(*this): Returns address of current object
 */
#include<iostream>
using namespace std;

class A{
    int a;
    public:
        A& f1() {
            cout<<"Fun1 ";
            return *this;               //Returns address of object=obj
        }
        A& f2(){
            cout<<"Fun2 ";
            return *this;
        }
        A& f3(){
            cout<<"Fun3"<<endl;
            return *this;
        }
};

int main(){
        A obj;
        obj.f1().f2().f3();     //Equivalent to calling obj.f1();obj.f2();obj.f3()
        return 0;
}
/*
Output:
# ./a.out
Fun1 Fun2 Fun3
 */
