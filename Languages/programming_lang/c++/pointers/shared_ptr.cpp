/*      shared_ptr.cpp
  
WHAT? Container of raw pointer with following characteristics:
 a. Maintains reference count ownership of its contained pointer. 
 b. Once count reaches 0, allocated memory is deleted.
*/
#include<iostream>
#include<memory>
using namespace std;

int main(){
        shared_ptr<int> p0(new int(5));         //p0 is pointer to integer having value=5

        shared_ptr<int> p1 = p0;                //Both now own the memory.

        cout<<*p0;                              //5
        cout<<*p1;                              //5

        p0.reset();                             //Deleting p0

        cout<<*p1;                              //5     But p1 still points to memory

        p1.reset();                             //Deleting p1

//      cout<<*p0;                              //Segmentation Fault
}
