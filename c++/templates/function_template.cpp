#include<iostream>

template <class T>	//T is template variable
//template <typename T>	//T is template variable. We can use typename also
T max (T a, T b) {
	return (a>b) ? a : b;
}

int main (){
	int x = 8, y = 9;
	int z = max (x, y);
	std::cout<<"z="<<z<<std::endl;

	float x1 = 8.1, y1 = 9.1;
	float z1 = max (x1, y1);
	std::cout<<"z1="<<z1<<std::endl;

	return 0;
}
/*Output
 * z=9
 * z1=9.1
 */
