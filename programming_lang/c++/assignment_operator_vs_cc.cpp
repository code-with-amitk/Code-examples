#include<iostream>
using namespace std;

class A{
public:
        A(){}
        A(const A &t) {
                cout<<"Copy constructor called"<<endl;
        }

//returntype operator (arguments)       
        void operator= (const A &t){
                cout<<"Overloaded Assignment operator called\n"<<endl;
        }

};
int main(){
        A t1, t2;     //2 Objects created. 

        t2 = t1;       //Already Existing t2 initialized to t1. Copy Assignment Called.

        A t3 = t1;     //Copy Constructor Call. New Object Created from t1;
        return 0;
}

/*
Output: 
./a.out
Overloaded Assignment operator called

Copy constructor called
*/
