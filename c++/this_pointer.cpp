/*
Every Function call passes the address of Object which calls it.
Which Actual Implementation stores in this pointer.
 */
#include<iostream>
using namespace std;

class A{
    int a;
    public:
        void fun(int x){        //Implemented as void fun(const test *this, int x)
            a=x;                //this->a=x
        }
        void disp(){
                cout<<"a="<<a<<endl;
        }
};

int main(){
    A t1, t2, t3;
    t1.fun(10);                 //Implemented as: t1.fun(&t1, 10);
    t2.fun(20);                 //t2.fun(&t1,20);
    t3.fun(30);                 //t3.fun(&t3,30);

    t1.disp();                  //t1.disp(&t1)
    t2.disp();                  //t2.disp(&t2)
    t3.disp();                  //t3.disp(&t3)
}

/*
Output:
# ./a.out 
a=10
a=20
a=30
*/
