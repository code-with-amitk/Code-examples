/*      template_parameter_pack_&_variadic_template.cpp

**********A. TEMPLATE PARAMETER PACK(TPP) <...>*********
 - This is a template parameter that accepts zero or more template arguments.

A1. SYNTAX OF TPP:
        a. type ... Args(optional)
        b. typename|class ... Args(optional)
        c. template < parameter-list > typename(C++17)|class ... Args(optional)
        d. Args ... args(optional)      
        e. pattern ...

A2. TPP Expansion:
        - A parameter-name followed by an ellipsis can be expanded into 0 or more comma-separated instantiations of parameters.


********B. VARIADIC TEMPLATE*********
https://eli.thegreenplace.net/2014/variadic-templates-in-c/
A template with at least one parameter pack or Template taking variable number of arguments.
TYPES OF VT:
 B1. VARIADIC FUNCTION TEMPLATE: Function template taking variable no of arguments. Parameter pack may appear at any place.

 B2. VARIADIC CLASS TEMPLATE: lass template taking variable no of arguments. template parameter pack must be the final parameter in the template parameter list else its compile time error.
*/

#include<iostream>
using namespace std;

//B1
template<typename ... T>
void fun(T ... args);

//B2
template<typename ... T>
struct A {};


//A2
template<class ...T>
void f1(T ... val) {
        (cout << ... << val);   //a 2cd
}


int main(){
        fun();       // OK: args contains no arguments
        fun(1);      // OK: args contains one argument: int
        fun(2, 1.0); // OK: args contains two arguments: int and double

         A<> t0;
         A<int> t1;        // Types contains one argument: int
         A<int, float> t2; // Types contains two arguments: int and float       

         f1('a');
         f1(' ',2,"cd");
}
