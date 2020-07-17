/*      class-template-specialization.cpp

Template Specialization? Seperate class/function template is defined for a particular data type.

TYPES?
1. FUNCTION TS
2. CLASS TS
*/

#include<iostream>
using namespace std;

template <typename T>
class A{
public:
        void fun(){  cout<<"Generic class"; }
};

template <>
class A<char>{
public:
        void fun(){ cout<<"Specialized class"; }
};

int main(){
        A <char> o1;
        o1.fun();                  //Output: Specialized class

        A <int> o2;
        o2.fun();                  //Output: Generic class

        A <float> o3;
        o3.fun();                  //Output: Generic class
}
