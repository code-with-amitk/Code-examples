/*      sizeof_vector.cpp
  
How Size is calculated?
        sizeof(type)*no-of-elements

How sizeof internally implemented?
#define my_sizeof(a) (char *)(&a+1)-(char*)(&a)

Vector keeps some space for book-keeping.
*/

#include<iostream>
#include<vector>
using namespace std;

template<typename T>
size_t vectorsize(typename std::vector<T>& v){
        return sizeof(T) * v.size();
}

int main(){
        vector<int> a1;
        vector<int> b1 = {1,2,3};
        vector<char> c1 = {'a','b','c'};
        vector<double> d1 = {1,2,3};

        cout<<vectorsize(a1)<<endl;     //0
        cout<<vectorsize(b1)<<endl;     //12
        cout<<vectorsize(c1)<<endl;     //3
        cout<<vectorsize(d1)<<endl;   //24
}
