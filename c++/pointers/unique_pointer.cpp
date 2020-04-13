/*      unique_pointer.cpp
 *
WHAT? Container class of raw pointer implemented as smart pointer.

CHARACTERISTICS/OPERATIONS OF UP?
 A. copy is not allowed(copy ctr, assignment operator are deleted)
 B. std::move(transferring ownership) is allowed. Original pointer cannnot be accessed
 C. ptr.reset(): Deletes the memory
*/
#include<iostream>
#include <memory>
using namespace std;

int main(){
        unique_ptr<int> p(new int(5));  //Allocate *int, provide value=5
        cout<<*p;                               //5

        //A     
        //unique_ptr<int> p1 = p;               //error: use of deleted function

        //B
        unique_ptr<int> p2 = std::move(p);
        cout<<*p2;                              //5
        //cout<<*p;                             //Segmentation Fault

        //C
        p2.reset();
}
