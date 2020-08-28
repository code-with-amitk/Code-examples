/*
 * Format :
 * 	return_type operator_keyword operator_to_overload (arguments)
 */
#include<iostream>
#include<cstring>
# define arr 10

class A{
        int *p;
public:
        A(int a):p(new int()){*p = a;}

        A operator = (const A &k){
                int *t = new int;
                t = k.p;                //Deep copy
                return *this;
        }
};

int main(){
        A obj1(1);
        A obj2 = obj1;
}

