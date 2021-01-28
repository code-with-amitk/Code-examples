/*
        check_no_is_prime.cpp   
Logic:
 - take k = sqrt(n) of number.
 - Divide k by (2 to k), if divisor is found then no is not prime else yes

Why sqrt?
- smallest factor of number cannot be greater than sqrt(n). Example:
For 47, Perform sqrt(47), check numbers from 2 to 7. if any one divides no is not prime
 */
#include<iostream>
#include<cmath>
using namespace std;

int main(){
        int n=49, flag=0;
//      cout<<"sqrt(n)"<<sqrt(n)<<"\n";

        for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0){
//                      cout<<"n="<<n<<", i="<<i<<"\n";
                    flag = 1;
                    break;
                }
        }

        if(flag==1)
                cout<<"not prime";
        else
                cout<<"prime";
}
