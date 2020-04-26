/*      decltype.cpp

https://en.cppreference.com/w/cpp/language/decltype
WHAT? Inspects the type of an entity/expression.

SYNTAX:
        decltype ( expression )         //Since C++11
        decltype ( type )               //Since C++11

WHY USE DECLTYPE?
- when declaring types that are difficult or impossible to declare using standard notation,
like lambda-related types or types that depend on template parameters.

EXAMPLES:
A. Declaring variable using decltype
B. LAMBDA FUNCTION:
    - return type of function is int
    - decltype(f) is int
C. TEMPLATES:
    - return type depends on template parameters
    - return type can be deduced since C++14
*/

#include<iostream>
#include<string>
using namespace std;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u)
{
    return t+u;
}

int main(){

        /***A. VARIABLE****/
        int a;
        decltype(a) b = 10;
        cout<<b<<endl;          //10


        /***B. LAMBDA***/
        auto f = [](int a, int b)->int {return a*b;};
        decltype(f) c = f;
        cout<<c<<endl;          //1


        /***C. TEMPLATE***/
        decltype(add(1.2,1.3)) d = 3.4;         //float d = 3.4
        string s1 = "never", s2 = "give";
        decltype(add(s1,s2)) s = "Think";       //string s = "Think"
        cout<<d<<endl;          //3.4
        cout<<s<<endl;          //Think
}
