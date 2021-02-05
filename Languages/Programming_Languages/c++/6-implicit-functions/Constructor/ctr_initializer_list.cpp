#include<iostream>
class test{
	int a;
	char b;
	float *c;
public:
	test (int x, int y): a(x), b(y), c(new float[10]) {
		std::cout<<"a="<<a<<"\tb="<<b<<"\t"<<std::endl;
	}
};
int main() {
	test obj(1,'g');
	return 0;
}
/*
 * Output
 * 1 g
 */
