#include<iostream>
using namespace std;
class Base{
public:
	Base(){
	cout<<"Base Ctr"<<endl;
	}
};
class derv:public Base{
public:
	derv(){
	cout<<"Derv Ctr"<<endl;
	}
};

int main(){
	derv d;
	return 0;
}

/*
 * Output
 * 	Base Ctr
 *	Derv Ctr
 */
