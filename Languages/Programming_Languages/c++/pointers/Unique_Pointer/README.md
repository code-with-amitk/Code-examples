## Uniqe Pointer
- **What?** Introduced in C++11, Container class of raw pointer implemented as smart pointer.
- **CHARACTERISTICS/OPERATIONS OF UP?**
  - copy is not allowed(copy ctr, assignment operator are deleted)
  - std::move(transferring ownership) is allowed. Original pointer cannnot be accessed
  - ptr.reset(): Deletes the memory
- **Why to use make_unique?** 
  - *a.* Avoid use of new operator
  -  *b.* Provides exception safety, as new and delete internally handled by compiler. 
- **make_unique<T>()[C++14]**
  - Function defined in <memory> header for creating a unique pointer. Memory is allocated to 0.
### Code
```c++
#include<iostream>
#include <memory>
using namespace std;

int main(){
        /*Creating UP, Allocate *int, provide value=5*/ 
        unique_ptr<int> p(new int(5));
        cout<<*p;                               //5

        /*C1. copy of UP is not allowed*/
        //unique_ptr<int> p1 = p;               //error: use of deleted function

        /*C2. Moving ownership*/
        unique_ptr<int> p2 = std::move(p);
        cout<<*p2;                              //5
        //cout<<*p;                             //Segmentation Fault

        /*C3. reset() function*/
        p2.reset();

        /*B. Creating unique_ptr using make_unique()*/
        unique_ptr<int> p1 = make_unique<int>();
        cout<<*p1<<endl;                       //0
}
```
