## Deep and shallow
- **Shallow Copy ctr**
  - This is Compiler Provided Copy Ctr.
 - This does member-wise copy. If object has ptr variable, then memory pointed by pointer variable is not duplicated.
- **Deep Copy Ctr**
  - User has to write deep copy.
  - Does duplicate memory pointed by pointer variable.
 
Note: If user creates Copy constructor, Compiler does not provides it own.

### Code 
```c++
#include<iostream>
using namespace std;

class A{
        int *a;
public:
        A (){
                a = new int;
                *a = 4;
        }

/*      A (const A &obj) {      //obj=obj1. shallow copy
                this->ptr = obj.ptr;
        }*/

        A (const A &obj){       //DEEP COPY CONSTRUCTOR
                this->a = new int;
                *(this->a) = *obj.a;
        }

        void disp(){
                cout<<"a="<<*(this->a)<<endl;
        }
};
int main(){
        A obj1;
        A obj2(obj1);   //obj2 = A(obj1)
        obj1.disp();
        obj2.disp();
        return 0;
}

/*Output:
 * a=4                  //obj1
 * a=4                  //obj2
 */
```
