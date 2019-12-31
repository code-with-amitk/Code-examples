/*
Class template: Generic class which having(Generic member variables, Generic member functions)
- Gen is Genlate variable

Rules:
1. Whenever we define function of template class outside class we need to write template statement again
2. Compiler cannot deduce template parameter type(s) for class template. We need to tell compiler the data types we would be using.
3. If arguments are of other type and template argument of other type. Compiler will ignore Argument type.
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

template <class Gen>                    //Rule-1
Gen test <Gen>::multiply(){
        return a*b;
}

int main(){
        test <int> obj(5,6);            //Rule-2
        cout<<obj.add()<<endl;          //Output: 11

        test <float> obj1(5.6,6.7);
        cout<<obj1.add()<<endl;         //Output: 12.3

        test <int> obj2(5.6,6.7);       //Rule-3
        cout<<obj2.multiply()<<endl;    //Output: 30
}
