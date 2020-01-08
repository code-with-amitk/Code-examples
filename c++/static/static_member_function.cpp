/*
Static member functions:
 1. Can be called without class object
*/

#include<iostream>
using namespace std;

class A{
    public:         
        static void static_fun(int x){
                cout<<"x="<<x<<endl;
        }
};

int main(){
    A::static_fun(4);           //1. Calling static function without class object
    return 0;
}
