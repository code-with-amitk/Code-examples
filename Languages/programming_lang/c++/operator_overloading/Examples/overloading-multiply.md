## Overload `*`
- **What** Overloading Operator `*` to multiply 2 objects
 - **Format**
 ```c++
  	return_type operator_keyword Operator_to_overload (arguments)
		const A 				operator 					* 							(class object)
 ```
 - **Code**
 ```c++
#include<iostream>
class A {
	int a;
public:
	A (int b):a(b) {}
	const A operator * (A obj) {
		return (this->a)*(obj.a);
	}
	void disp() {
		std::cout<<"value="<<this->a<<std::endl;
	}
};

int main() {
	A obj10(10);		//obj10.a=10
	A obj20(20);		//obj20.a=20
	A obj = obj10*obj20;
	obj.disp();		
}
/*
 * Output:200
*/
```
