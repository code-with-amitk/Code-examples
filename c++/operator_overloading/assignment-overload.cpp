/*
 * Format :
 * 	return_type operator_keyword operator_to_overload (arguments)
 */
#include<iostream>
#include<cstring>
# define arr 10
class test {
	int *ptr, a;
public:
	test ():a(0) {}
	test (int b): a(b), ptr(new int [arr]) {}
	const test operator = (test p) {	//Deep copy assignment Operator Overload
		this->a = p.a;
		this->ptr = new int [arr];
		memcpy (this->ptr,p.ptr,arr);	//void *memcpy(void *dest, const void *src, size_t n)
		return *this;
	}
	void disp() {
		std::cout<<"a="<<this->a<<std::endl;
	}
};
int main() {
	test obj10(10);		//obj10.a=10 obj10.ptr points to arrary of 10 ints
	test obj;
	obj = obj10;	//obj.operator=(obj10)  Copy Assignment called
	obj.disp();
}
