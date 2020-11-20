## Problem
- Delete middle of LL.
- if LL is empty, return empty. 
- if LL size=1, delete that node.
- if LL size=2, delete head node.
- if LL size=3, delete 2nd.
- if LL size=4, delete 3rd(ie 2nd middle).
```c
LinkedList        Output
  {}                {}
  {1}               {}
  {1,2}             {1}
  {1,2,3}           {1,3}
  {1,2,3,4}         {1,2,4}
  {1,2,3,4,5}       {1,2,4,5}
```

## Things to Note
- `forward_list` container does not provide erase_current(). it provides erase_next()
- `forward_list` container does not provide size() function.

## Logic
- *1.* Take 3 pointers. slow, fast, beforeSlow. Advance slow by 1, fast by 2, beforeSlow by 1 but behind slow
- *2.* Even number of elements
```c
  1   --->     2  -->   3
  /\          /\        /\
beforeslow   slow      fast
- Delete next element of beforeSlow. Because in singly LL we cannot get prev element. Also forward_list does not provide erase_current() only erase_next()
```
- *3.* Odd number of elements
```c
  1   --->  2  --->   3     --->     4
 /\         /\        /\
beforeslow  slow      fast
- Delete next element of slow. forward_list does not provide erase_current() only erase_next().
```

## Code: C++ (forward_list<>). Complexity: O(n)
- forward_list is singly LL.
```c++
#include<iostream>
#include <forward_list>
using namespace std;

forward_list<int> Delete(forward_list<int>& fl){
  forward_list<int>::iterator itSlow = fl.begin();  //slow Iterator
  forward_list<int>::iterator itFast = fl.begin();  //Fast Iterator
  forward_list<int>::iterator itBeforeSlow = fl.begin();

  if(itSlow == fl.end())    //empty list
    return fl;

//next(iterator,pos):Returns iterator pointing to element if advanced by position=pos. But original iterator is not advanced as done using ++itr
//  pos:Number of element positions offset
  if((next(itSlow,1) == fl.end()) or    //1 node
     (next(itSlow,2) == fl.end())       //2 nodes
    ){
    fl.pop_front();
    return fl;
  }

  int count=0;
  bool even,odd;
  even=odd=false;

  //Take 3 pointers. slow, fast, beforeSlow(stays 1 position before slow)
  while((next(itFast,1) != fl.end()) and
        (next(itFast,2) != fl.end())){
    advance(itSlow,1);
    advance(itFast,2);
    if(count)
      advance(itBeforeSlow,1);
    ++count;
  }
  if(next(itFast,1) == fl.end())  odd=true;
  else  even=true;

  if(odd)
    fl.erase_after(itBeforeSlow);
  if(even)
    fl.erase_after(itSlow);
    
  return fl;
}

int main(){
  //forward_list<int> sll = { 1, 2, 3, 4, 5 };
  //forward_list<int> sll = {  };
  //forward_list<int> sll = { 1 };    //{}
  //forward_list<int> sll = { 1,2 };  //{2}
  //forward_list<int> sll = { 1,2,3 };  //{1,3}
  //forward_list<int> sll = { 1,2,3,4 };  //{1,2,4}
  forward_list<int> sll = { 1,2,3,4,5,6,7,8,9,10,11 };  //{1,2,4}
  forward_list<int> fl = Delete(sll);
  for(auto i:fl)
    cout<<i<<" ";
}
```
