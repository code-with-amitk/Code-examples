/*      function-temp-specialization.cpp

Template Specialization? Seperate function/class template is defined for a particular data type.

TYPES?
1. FUNCTION TS
2. CLASS TS
*/

#include<iostream>
using namespace std;

template <class T>
void fun (T &a, T &b)
{
        cout<<"Template fun";
}

template <>
void fun (int &a, int &b)           //OR void fun <int> (int &a, int &b) 
{
    cout << "Specialized Template";
}


int main ()
{
        int a = 10, b = 20;
        fun (a, b);       //OR fun <int> (a, b);
}

/*
Output:
Specialized Template
*/
