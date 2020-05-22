/*      template_parameter_pack.cpp

**********A. TEMPLATE PARAMETER PACK(TPP) <...>*********
- Template parameter that accepts 0 or more template arguments.
*/

#include<iostream>
using namespace std;

//RULE-A1. Ellipsis can be expanded into 0 or more comma-separated instantiations of parameters.
template<class ...T>
void f1(T ... val) {
        (cout << ... << val);   //a 2cd
}
int main(){
         f1('a');
         f1(' ',2,"cd");
}

//RULE-A2. Template parameter is not a mandatory argument.
//See Here, Template argument is not present.
template <int i>
void fun()
{
   cout << i;   //10
}

int main()
{
   fun<10>();
}
