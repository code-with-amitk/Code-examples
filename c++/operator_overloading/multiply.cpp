/* Meaning:
 * 	- Overloading Operator * to multiply 2 objects
 * Format:
 * 	return_type operator_keyword Operator_to_overload (arguments)
 */
#include<iostream>
class test {
	int a;
public:
	test (int b):a(b) {}		
	const test operator * (test p) {
		return (this->a)*(p.a);
	}
	void disp() {
		std::cout<<"value="<<this->a<<std::endl;
	}
};
int main() {
	test obj10(10);		//obj10.a=10
	test obj20(20);		//obj20.a=20
	test obj = obj10*obj20;
	obj.disp();		
}
/*
 * Output:200
 */
