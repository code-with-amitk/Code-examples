#include<iostream>
class test {
	size_t len;
	int *ptr;
public:
	test ():len(0), ptr(NULL) {}
	test(size_t a) : len(a), ptr(new int[len]) {}	//Default Ctr

	~test() {delete [] ptr;}	//Default Dtr

	//& is Reference variable, C++11 calls it as L-value reference
	test (const test &obj) : len(obj.len), ptr(new int[len]) {		//Copy Ctr
		//copy(InputIterator first, InputIterator last, OutputIterator result)
		std::copy (obj.ptr, obj.ptr+len, ptr);		//Can use memcpy as well
	}

	//Takes L value, returns L value
	test &operator = (const test &obj){	//Overloaded Assignment Operator
		this->len = obj.len;
		ptr = new int[len];
		std::copy (obj.ptr, obj.ptr+obj.len, this->ptr);
		return *this;
	}

	//Move Ctr. Takes R-value reference. Its Ctr no return type
	test (test &&obj):len(0),ptr(NULL) {
		ptr = obj.ptr;	obj.ptr = NULL;
		len = obj.len;	obj.len = 0;
	}

	//Move Assignment Operator
	test &operator = (test &&obj) {
		this->len = obj.len;
		this->ptr = obj.ptr;
		obj.len = 0;	delete [] ptr;	obj.ptr = nullptr;
		return *this;
	}

	void disp (){
		std::cout<<"len value="<<this->len<<std::endl;
	}
};
int main() {
	test obj1 (100);		//obj1.a=100, obj1.data points to 100 ints

	//Copy Ctr Call
	test obj2 (obj1);	//Called as obj2.test(obj1)

	//Assignment Operator call
	test obj3;
	obj3 = obj2;		//Called as obj3.operator=(obj2)

	//Move Ctr call
	test obj4 (200);
	test obj5 (std::move(obj4));	//Move obj4 to obj5
	obj5.disp ();
	obj4.disp ();

	//Move Assignment Operator
	test obj6 (600);
	test obj7 = std::move(obj6);		// obj7.operator=(obj6)
	obj7.disp();
	obj6.disp();
}

/* Output
 * 200	//obj5
 * 0	//obj4
 *
 * 600	//obj7
 * 0	//obj6
 */
