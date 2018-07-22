/* L-Value(C++98)?
 * 	Values those are suitable for Left Hand side of assignment Operator. Types:
 *	a. Modiyable L-values	b. Non-Modifyable L-values
 *
 * L-Value Reference(C++11)?
 * 	These are called reference variables in C++98
 *
 * R-Value(C++98)?
 *	Eveything that is not L value. Eg:
 *		a. Literals(eg: 5), Temporary variables(x+1)
 *
 * R-Value Reference(C++11)?
 * 	Represented by &&
 * 	Points to R-values
 *
 * Usage of R-value, R-value Reference?
 * 	a. Overloading Functions based on parameter types
 */

#include<iostream>
void fun(int &var) {
	std::cout<<"L value Reference"<<std::endl;
}
void fun(int &&var){
	std::cout<<"R value Reference"<<std::endl;
}
//void fun(int var){}		
//This will confuse compiler because 'var' can take L-value, R-value also. So it will give an error

int main() {
	//Examples
	int a = 5;	//a is L-value, 5 is R-value
	int &b = a;	//b is L-value Reference
	int &&c = 5;	//c is R-value Reference

	fun (10);	//R value reference
	fun (a);	//L value reference
	return 0;
}
/*Output:
 * R value Reference
 * L value Reference
 */
