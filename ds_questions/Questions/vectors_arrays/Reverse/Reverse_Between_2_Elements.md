### Problem
- You receive a vector/ array and 2 numbers, eg 2 and 5. Between those 2 positions in the vector (2 and 5) you have to reverse the order of the elements.

## Code
```c++
#include<iostream>
#include<vector>
#include<algorithm>
using vec = std::vector<int>;
using itr = std::vector<int>::iterator;

int main(){
  vec v = {1,2,9,8,4,5,23,5,252,445,677,5};

  //Find position of 2
  itr it1 = std::find(v.begin(), v.end(), 2);   //O(n)

  //Find position of 5
  itr it2 = std::find(v.begin(), v.end(), 5);   //O(n)

  std::reverse(it1+1, it2);                   //O(n)

  for (auto i:v)
    std::cout<<i<<" ";
}
```

### Complexity
- 3O(n)
