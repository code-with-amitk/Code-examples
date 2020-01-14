/*
Template Specialization: Seperate class template is defined for a data type.

1. Generic Template/Implementation
2. Special Template/Implementation for char.
        - char is specialization Parameter. This tells about the type for which template class is specialized
 */
#include<iostream>
using namespace std;

template <class T>              //1
class test{
public:
        void fun(T a){
                cout<<"Generic a="<<a<<endl;
        }
};

template <>                    //2
class test<char>{
public:
        void fun(char a){
                cout<<"Special Implementation"<<endl;
        }
};

int main(){
        test <char> obj1;
        obj1.fun('G');                  //Output: Special Implementation

        test <int> obj2;
        obj2.fun(2);                    //Output: Generic a=2

        test <float> obj3;
        obj3.fun(5.5);                  //Output: Generic a=5.5
}
