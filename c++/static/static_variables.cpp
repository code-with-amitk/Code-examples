/*
Static keyword has different meanings when used with different types.

STATIC MEMBER VARIABLE OF CLASS:
- These member variables are shared among all Objects of class. Only 1 copy of variables is created.
- Java does not support Static Local variables

*/

#include<iostream>
using namespace std;

class A{
public:
        static int static_var;    	//Declared in Public Scope
        A(){}
	void disp(){
		cout<<"static_var= "<<static_var<<endl;
	}
};

int A::static_var=10;    	//Rule: Initialize static variable. THIS IS REQUIRED, else Compiler will give undefined reference Error for var

int main(){
	A obj1;
	obj1.disp();

	A obj2;
	obj2.disp();
} 
