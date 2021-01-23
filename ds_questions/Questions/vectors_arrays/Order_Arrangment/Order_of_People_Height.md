## [Problem Interviewbit](https://www.interviewbit.com/problems/order-of-people-heights/)
- Problem is tought to understand so understand patently.
- We know height of Person and **number of people** whose height is greater than the person, standing in front of him in Queue.
- **Task:** Return how the queue will look like.
- Example
```c++
Input : Heights, infronts array
  Person      a  b    c  d    e  f    g   h
  Heights = {86, 92, 49, 21, 62, 27, 90, 59};
  Infronts = {2,  0,  0,  2,  0,  2,  1,  3};
  
  Person  Height  Number-People-taller-than-him-standing-before-him-in-queue
    a       86        2
    b       92        0
    c       49        0
    d       21        2
    e       62        0
    f       27        2
    g       90        1
    h       59        3

Output:
  49 62 21 27 92 90 59 86
  Person    Number-People-taller-than-him-in-queue
    c(49)     0 //index 0
    e(62)     0 //index 1. There is no person in queue taller than 62 before him
    d(21)     2 //index 2. There are 2 persons in queue taller than him before in queue(49, 62).
```

## Logic
1. Make pair (person's height, number-of-people-taller-than-him-in-queue)
```c++
                 key,val
vector<pair> v = 86, 2 |92, 0 |49, 0 |21, 2 |62, 0 |27, 2 |90, 1 |59, 3 |
```
2. Sort wrt key ie height
```c++
                 key,val
vector<pair> v = 92, 0 |90, 1 |86, 2 |62, 0 |59, 3 |49, 0 |27, 2 |21, 2 |
```
3. Create the output vector<int> res(representing the queue) by placing key at index=val
```c++
                      vector<int> res
res[0]=92             |92|
res[1]=90             |92|90|
res[2]=86             |92|90|86|
res[0]=62             |62|92|90|86|
res[3]=59             |62|92|90|59|86|
res[0]=49             |49|62|92|90|59|86|
res[2]=27             |49|62|27|92|90|59|86|
res[2]=21             |49|62|21|27|92|90|59|86| <<< Queue which we want
```

## Complexity
- **Time:** 2O(n) + O(nlogn)
```c++
  1. O(n): Creating pair
  2. O(nlogn): Sort
  3. O(n): Creating output vector
```
- **Space:** 3n
```c++
  vector<pair>: 2n
  vector<int> res: n
```

## Code
```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comparator(pair<int,int> p1, pair<int,int> p2){
    if(p1.first == p2.first)
      return p1.second < p2.second;

    return p1.first > p2.first;
}

vector<int> order(vector<int> &heights, vector<int> &infronts) {
  int n = heights.size();
  vector<int> res;

  vector<pair<int,int>> v(n);

  for(int i=0;i<n;i++)
    v[i] = {heights[i], infronts[i]};
    
  for(auto i:v)
    cout<<i.first<<", "<<i.second<<" |";
  cout<<"\n";

  sort(v.begin(), v.end(), comparator);

  for(auto i:v)
    cout<<i.first<<", "<<i.second<<" |";
  cout<<"\n";

  for(int i=0;i<n;i++)
    res.insert(res.begin()+v[i].second, v[i].first);

  return res;
}
int main(){
  vector<int> a = {86, 92, 49, 21, 62, 27, 90, 59};
  vector<int> b = {2, 0, 0, 2, 0, 2, 1, 3};
  vector<int> c = order(a,b);
  for(auto i:c)
    cout<<i<<" ";
}
#./a.out
86, 2 |92, 0 |49, 0 |21, 2 |62, 0 |27, 2 |90, 1 |59, 3 |
92, 0 |90, 1 |86, 2 |62, 0 |59, 3 |49, 0 |27, 2 |21, 2 |
49 62 21 27 92 90 59 86
```
