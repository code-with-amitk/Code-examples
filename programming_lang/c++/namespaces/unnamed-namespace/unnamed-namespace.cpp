/*	unnamed-namespace.cpp

WHAT? Namespace not having any name
*/

#include<iostream>
using namespace std;

/***********UNNAMED NAMESPACE************
SYNTAX:
  inline(optional) namespace attr(optional) { namespace-body }

HOW IT WORKS? Treated as global in enclosing namespace
*/

namespace 
{
        int a;          //::(unique)::a
}
void fun()
{
        a++;            //::(unique)::a++
}

namespace A
{
        namespace
	{
                int a=50;//A::(unique)::a
        }
        void fun() 
	{
                a++;    // A::unique::a++
        }
}

int main(){
        fun();
        cout<<a<<endl;     //1

        A::fun();
        cout<<A::a<<endl;       //51
}
