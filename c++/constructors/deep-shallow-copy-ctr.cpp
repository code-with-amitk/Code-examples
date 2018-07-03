/* Shallow Copy(Compiler Provided Copy Ctr):
 * 	- This does member-wise copy. If object has ptr variable, then memory pointed by pointer variable is not duplicated.
 * Deep Copy Ctr:
 *	- Does duplicate memory pointed by pointer variable.
 *
 * Note:
 * 	1. If user creates Copy constructor, Compiler does not provides it own.
 */

#include<iostream>
class test{
	int *ptr;
public:
	test () {
		ptr = new int;
		*ptr = 4;
	}
/*	test (const test &obj) {	//obj=obj1. shallow copy
		this->ptr = obj.ptr;
	}*/
	test (const test &obj) {	//Deep Copy
		this->ptr = new int;
		*(this->ptr) = *obj.ptr;
	}
	void disp(int a){
		std::cout<<"Object"<<a<<"\t"<<"ptr="<<*(this->ptr)<<std::endl;
	}
};
int main(){
	test obj1;		//obj1.ptr=4
	test obj2(obj1);	//obj2 = test(obj1)
	obj1.disp(1);
	obj2.disp(2);
	return 0;
}

/*Output:
 * Object1 ptr=4
 * Object2 ptr=4
 */
