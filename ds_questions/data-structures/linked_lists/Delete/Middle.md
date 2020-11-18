## Problem
- Delete middle of LL.
- if LL is empty, return empty. 
- if LL size=1, delete that node.
- if LL size=2, delete head node.
- if LL size=3, delete 2nd.
- if LL size=4, delete 3rd(ie 2nd middle).

### 1. C++ (forward_list<>). Complexity: O(n + n/2)
- forward_list is singly LL.
```c++
#include<iostream>
#include <forward_list>
using namespace std;

forward_list<int> Delete(forward_list<int>& fl){
  int size=0;
  for(auto i:fl)    //Find size. forward_list<> does not provide size() method
    size +=1;

  if(!size)   //empty list
    return fl;

  if(size==1 or size==2){
    fl.pop_front();
    return fl;
  }

  forward_list<int>::iterator itr = fl.begin();
  advance(itr,size/2-1);
  fl.erase_after(itr);
  return fl;
  
}
int main(){
  //forward_list<int> sll = { 1, 2, 3, 4, 5 };  //1,2,4,5
  //forward_list<int> sll = { 1, 2, 3 };        //1,3
  forward_list<int> sll = { 1, 2, 3, 4 };       //1,2,4
  //forward_list<int> sll = {  };               //{}

  forward_list<int> fl = Delete(sll);
  for(auto i:fl)
    cout<<i<<" ";
}
```
