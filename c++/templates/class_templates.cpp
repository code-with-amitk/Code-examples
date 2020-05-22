/*  class_template.cpp

TEMPLATE CLASS? Generic class which having(Generic member variables, Generic member functions)
 */
#include<iostream>
using namespace std;

/**************************************
Rule-A: template statement need to be written again when template class function is defined outside template class.
Rule-B: Compiler cannot deduce template parameter type(s) for class template. We need to tell compiler the data 
types we would be using.
Rule-C: If arguments are of other type and template argument of other type. Compiler will ignore Argument type.
****************************************/

template <class T>            //OR <typename T>
class A {
        A a, b;               //Generic Member variables
    public:
        A (T x, T y):a(x),b(y){}
        A add ();
};

template <class T>                    //A
T A <T>::add(){ return a+b; }

int main(){
        test <int> obj(5,6);            //B
        cout<<obj.add()<<endl;          //Output: 11

        test <float> obj1(5.6,6.7);
        cout<<obj1.add()<<endl;         //Output: 12.3

        test <int> obj2(5.6,6.7);       //C
        cout<<obj2.multiply()<<endl;    //Output: 30
}
*/

/**********************************************************
Rule-D: Seperate class is created for different parameter types
Test<int>::Test()     //class-1
Test<double>::Test()  //class-2
***********************************************************/
template <class T>
class Test
{
    T val;
public:
    static int count;
    Test()  {   count++;   }
};
 
template<class T>
int Test<T>::count = 0;
 
int main()
{
    Test<int> a;
    Test<int> b;
    Test<double> c;
    cout << Test<int>::count   << endl;       //2
    cout << Test<double>::count << endl;      //1
    return 0;
}
*************************************************/
