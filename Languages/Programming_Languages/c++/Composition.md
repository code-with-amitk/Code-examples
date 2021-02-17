## Composition
- If container Object is deleted, contained object will also be deleted. Member variables of class are example of composition.

### Code
```c++
- In below example, A is created But destroyed with B

#include<iostream>
using namespace std;
class A{
public:
        A(){
                cout<<"A's Constructor\n";
        }
        ~A(){
                cout<<"A's Destructor\n";
        }
};

class B{
       A  a;    //Composition
public:
       B(){
               cout<<"B's constructor\n";
       }
       ~B(){
               cout<<"B's Destructor\n";
       }
};
int main(){
        B b(1);
}
/* Output:
# ./a.out 
A's Constructor
B's constructor
B's Destructor
A's 
*/
```
