## [Problem]()
- Input={'A','B','C','D','E','F','G','H'}
- Output={'A','B','G','D','E','F','C','H'}    //C swapped with G

### Approach-1  //Linear Search
- Search 2 elements linearly till end. Swap after completing traversal.

### Approach-2  //Binary Search
- Run 2 binary searches simultaneously and find positions of characters.
- **Complexity**
  - Time: 2O(logn)
  - Space: O(1)
### Code
```c++
#include<iostream>
#include<vector>
using vec = std::vector<char>;

void BinarySearch(vec& v, int start, int end, char first, char second, int& pos1, int& pos2){
  int mid = (start+end)/2;
  if(v[mid] == first)
    pos1 = mid;
  if(v[mid] == second)
    pos2 = mid;

  if(start>end)
    return;

  if (v[mid]>first)
    BinarySearch(v,start,mid-1,first,second,pos1,pos2);
  if(v[mid]<second)
    BinarySearch(v,mid+1,end,first,second,pos1,pos2);
}

int main(){
  vec v = {'A','B','C','D','E','F','G','H'};
  char first = 'C', second = 'G';

  int pos1=-1,pos2=-1;

  int start=0, end=v.size();
  BinarySearch(v,start,end,first,second,pos1,pos2);
  if(pos1>-1 and pos2>-1)
    std::swap(v[pos1],v[pos2]);
  for (auto i:v)
    std::cout<<i<<" ";
}
```
