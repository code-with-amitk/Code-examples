## Structured Bindings
- **What?** Initializes multiple variables from array, tuple or struct. Unbinds the struct/tuple elements to variables.
- *Comparison with references?**
  - Like a reference, a structured binding is an alias to an existing object.
  - Unlike a reference, the type of a structured binding does not have to be a reference type.
- **Types of SB?**
  - *1.* ARRAY MEMBER BINDING
  - *2.* TUPLE MEMBER BINDING
  - *3.* STRUCTURE/CLASS MEMBER BINDING

#include<iostream>
#include<tuple>
using namespace std;

int main(){

        /*1. ARRAY MEMBER BINDING: 
             - expression is of type array
             - Number of identifiers in identifier-list must be equal to the number of elements in the array.

          attr(optional) cv-auto ref-operator(optional) [ identifier-list ] = expression ;
                attr not present
                cv-auto = auto
                ref-operator not present
                [identifier-list] = [xval,yval]
                expression = array type
        */
        int a[2] = { 1,2 };
        auto [ xval, yval ] = a;
        cout<<xval<<" "<<yval<<endl;    //1 2


        /*2. TUPLE ELEMENTS BINDING: 
             - expression is of type tuple

             attr(optional) cv-auto ref-operator(optional) [ identifier-list ] { expression }
                attr not present
                cv-auto = auto
                ref-operator not present
                [identifier-list] = [t1,t2,t3]
                expression = tuple type
         */
        tuple<int,char,float> tp1 = make_tuple(1,'a',3.5);
        auto [t1,t2,t3] = tp1;
        cout<<t1<<" "<<t2<<" "<<t3<<endl;       //1 a 3.5


        /*3. CLASS/STRUCTURE ELEMENTS BINDING:
             - expression is of type structure

             attr(optional) cv-auto ref-operator(optional) [ identifier-list ] ( expression ) ;
                attr not present
                cv-auto = auto
                ref-operator not present
                [identifier-list] = [d1,d2]
                expression = structure type
         */
struct A{
        int x;
        double y;
        A(int a, int b):x(a),y(b){}
};

        const auto [d1, d2] = A(10,20);
        cout<<d1<<" ,"<<d2<<endl;               //10,20
}
