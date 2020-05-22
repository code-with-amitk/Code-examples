/*  variadic_template.cpp

*****************VARIADIC TEMPLATE*************************
https://eli.thegreenplace.net/2014/variadic-templates-in-c/
A template with at least one parameter pack or Template taking variable number of arguments.

TYPES OF VT:
 1. VARIADIC FUNCTION TEMPLATE
 2. VARIADIC CLASS TEMPLATE:
*/

#include<iostream>
using namespace std;

/*A1.VARIADIC FUNCTION TEMPLATE: Function template taking variable no of arguments. Parameter pack may appear at any place.
*/
template<typename ... T>
void fun(T ... args){
        (cout << ... << args);
}

/*A2. VARIADIC CLASS TEMPLATE: class template taking variable no of arguments. template parameter pack must be the final 
parameter in the template parameter list else its compile time error.
*/
template<typename ... T>
struct A {};

int main(){
        fun();       // OK: args contains no arguments
        fun(1);      // OK: args contains one argument: int
        fun(2, 1.0); // OK: args contains two arguments: int and double

         A<> t0;
         A<int> t1;        // Types contains one argument: int
         A<int, float> t2; // Types contains two arguments: int and float       

}
