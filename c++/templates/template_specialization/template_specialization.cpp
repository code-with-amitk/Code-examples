/*      template_specialization.cpp

Template Specialization? Seperate class template is defined for a particular data type.

TYPES?
1. FUNCTION T
2. CLASS TS

2. Special Template/Implementation for char.
        - char is specialization Parameter. This tells about the type for which
template class is specialized
*/

#include<iostream>
using namespace std;

/*****************FUNCTION TEMPLATE SPECIALIZATION***************
template <class T>
void fun (T &a, T &b)
{
        cout<<"Template fun";
}

template <>
//void fun <int> (int &a, int &b)       OR
void fun (int &a, int &b)
{
    cout << "Specialized Template";
}

int main ()
{
        int a = 10, b = 20;
//      fun <int> (a, b);       OR
        fun (a, b);                     //Specialized Template
}
/***************************************************************/


/*****************CLASS TEMPLATE SPECIALIZATION***************/
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
/***************************************************************/
