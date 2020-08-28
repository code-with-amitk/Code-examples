## Overload `*`
- **What** Overloading Operator `*` to multiply 2 objects
 - **Format**
 ```c++
return_type operator_keyword Operator_to_overload (arguments)
const A operator * (class object)
 ```
 - **Code**
 ```c++
#include<iostream>
class A {
	int a;
public:
	A (int b):a(b) {}
	const A operator * (A obj) {
    cout<<"this->a="<<this->a<<endl;				//10
    cout<<"obj.a="<<obj.a<<endl;						//20
		
		return (this->a)*(obj.a);
	}
	void disp() {
		std::cout<<"value="<<this->a<<std::endl;
	}
};

int main() {
	A obj10(10);		//obj10.a=10
	A obj20(20);		//obj20.a=20
	A obj = obj10*obj20;		//Equivalent to 	obj10.operator*(obj20);
	obj.disp();				//200
}
```
