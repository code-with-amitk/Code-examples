/*
Class template: Generic class which having(Generic member variables, Generic member functions)
- Gen is Template variable

RULES:
  A. template statement need to be written again when template class function is defined outside template class.
  B. Compiler cannot deduce template parameter type(s) for class template. We need to tell compiler the data 
types we would be using.
  C. If arguments are of other type and template argument of other type. Compiler will ignore Argument type.
 */
#include<iostream>
using namespace std;

template <class Gen>            //OR <typename T>
class test {
        Gen a, b;               //Generic Member variables
    public:
        test (Gen x, Gen y){    //Generic function
                a = x;
                b = y;
        }
        Gen add (){
                return a+b;
        }
        Gen multiply ();
};

template <class Gen>                    //A
Gen test <Gen>::multiply(){
        return a*b;
}

int main(){
        test <int> obj(5,6);            //B
        cout<<obj.add()<<endl;          //Output: 11

        test <float> obj1(5.6,6.7);
        cout<<obj1.add()<<endl;         //Output: 12.3

        test <int> obj2(5.6,6.7);       //Rule-3
        cout<<obj2.multiply()<<endl;    //Output: 30
}
