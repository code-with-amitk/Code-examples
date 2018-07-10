#include<iostream>

template <class T>
class addMult {
	T a, b;
public:
	addMult () {}
	addMult (T x, T y) : a(x), b(y) {}
	T add () { 
		return a+b; 
	}
	T multiply();
};

template <class T>
T addMult <T>::multiply () { 
	return a*b;
}

int main (){
	addMult <int> obj1 (10,2);
	std::cout<<"obj1.add()="<<obj1.add()<<std::endl;

	addMult <float> obj2(4.5,2.2);
	std::cout<<"obj2.multiply()="<<obj2.multiply()<<std::endl;
	
	return 0;
}
/*
 * Output:
 * obj1.add()=12
 * obj2.multiply()=9.9
 */
