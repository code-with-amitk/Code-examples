/*      rvalue-reference.cpp

RULES:
 A. overloading the function based on parameter type.

 B. Pass-by-value parameter cannot be used with L,Rvalue references.
     - One interesting thing here is if we declare int f(int i) with below functions. It will not compile. 
     Since compiler will not know which function to call in case of fun(a) or fun(6).

 C. r-value reference is collected in l-value reference.
*/

#include<iostream>
using namespace std;
void f(int &a){                         //A
        cout<<"a="<<a<<endl;
}

void f(int &&rval){                     //A
        cout<<"rval="<<rval<<endl;
}

/*///////// B /////////////
 error: call of overloaded ‘f(int)’ is ambiguous
void f(int b){
        cout<<"b="<<b;
}
*/
int main(){
        int b = 5;              //b:l value, 5:r value
        int &lr = b;            //lr: l value reference

        f(b);                   //calls f(&a). b is lvalue              
        f(lr);                  //calls f(&a). lr is lvalue ref
        /* O/P:
         * a = 5
         * a = 5
         */

        int &&rr = 10;          //rr: r value reference
        f(10);                  //calls f(&&a). 10 is rvalue
        /* O/P:
         * rval = 10
        */

        //C
        f(rr);                  //calls f(&a). Because rval reference cannot be collected in rvalue reference
        /* O/P:
         * a = 10;
         */
}
