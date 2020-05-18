/*      what_is_snifae.cpp

 - we know complier creates as many overloaded functions as many calls to templated function at compile time only.

WHAT? SNIFAE is problem of compiler's confusion of when finding same named templated & non-templated functions
where both are equal candidates for function substitution.

 */
#include<iostream>
using namespace std;

/*************SNIFAE*****************
 Problem? There are 2 same named functions 
        a. without template
        b. With template
 Which one will compiler use for linking function?

 How complier overcomes the problem?
  - Type deduction in this case fails, no error is emitted & Compiler deduce from type of passed argument. 
  The compiler simply ignores this candidate and looks at the others.
  - Since, integer literals are signed by default A will be picked.
  <<<BUT THIS IS WRONG
 */
void fun(int i) {               //A
        cout << "Non-Templated: " << i << "\n";
}

template <typename T>
void fun(const T& t) {          //B
        cout << "Templated: " << t << "\n";
}

int main(){
        fun(4); //Non-templated 4
}
/*********************************/
