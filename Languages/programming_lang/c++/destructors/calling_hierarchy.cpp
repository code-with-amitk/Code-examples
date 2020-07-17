/*Why Dtr calling hierarchy is opposite of Ctr?
 *
 */
#include<iostream>
class Base{
public:
	Base(){
		std::cout<<"Base Ctr"<<std::endl;
	}
	~Base(){
		std::cout<<"Base Dtr"<<std::endl;
	}
};
class derv:public Base{
public:
	derv(){
		std::cout<<"derv Ctr"<<std::endl;
	}
	~derv(){
		std::cout<<"derv Dtr"<<std::endl;
	}
};
int main(){
	derv d;
	return 0;
}

/*
 * Output:
 * 	Base Ctr
 * 	Derv Ctr
 *
 * 	Derv Dtr
 * 	Base Dtr
 */
