### Find Duplicates
- Given two sorted arrays arr1 and arr2 of passport numbers, implement a function findDuplicates that returns an array of all passport numbers that are both in arr1 and arr2. 
- Note that the output array should be sorted in an ascending order
- Example:
```c++
input:  
arr1 = [1, 2, 3, 5, 6, 7]       //Length=m
arr2 = [3, 6, 7, 8, 20]         //Length=n

output: [3, 6, 7]     //since only these three values are both in arr1 and arr2

1 ≤ arr1.length ≤ 100
1 ≤ arr2.length ≤ 100
```

### Approach-1 (Naive)
- Traverse array-1, array-2 until any 1 array is finished. 
- Find duplicates. Move on that array which has element smaller than other
- **Time Complexity** O(mn)

### Approach-2 (Binary-Search)
- Traverse array-1, array-2 until any 1 array is finished. 
- if element-array-1 < element-array-2. Find element-array-2 inside array-1 using binary search and viceversa
- **Time Complexity** O(logm)*O(logn)

### Code-Approach-2
```c++
#include <iostream>
#include <vector>

using vec = std::vector<int>;

int BinarySearch(const vec& v, int element, int start, int end){
  int mid = (start+end)/2;

  if (v[mid] == element)
    return mid;

  if (end <= start)
    return -1;

  if (element < v[mid])
    mid = BinarySearch(v, element, start, mid-1);
  else
    mid = BinarySearch(v, element, mid+1, end);

  return mid;
}

vec findDuplicates( const vec& arr1, const vec& arr2) {
  vec out;
  int i=0,j=0;

  while ((i < arr1.size()) and (j < arr2.size())){
    if (arr1[i] < arr2[j])
    {
      int ret = BinarySearch(arr1, arr2[j], i, arr1.size()-1);
      if(ret!=-1){
        i = ret;
        out.push_back(arr1[i]);
      }
    }
    else if (arr1[i] > arr2[j]) {
      int ret = BinarySearch(arr2, arr1[i], j, arr2.size()-1);
      if(ret!=-1){
        j = ret;
        out.push_back(arr1[j]);
      }
    }
    else if(arr1[i]==arr2[j])
      out.push_back(arr1[i]);

    ++i;
    ++j;
  }
  return out;
}

int main() {
  vec a = {1,2,3,4,5,6,7,8,9,10,11,50,51,52,53,54,55,56,57,58,59,60,61};
  vec b = {9,11,41,56};
  //vec a = {1, 2, 3, 5, 6, 7};
  //vec b = {3, 6, 7, 8, 20};
  vec out = findDuplicates(a,b);
  for (auto i:out)
    std::cout<<i<<" ";
  return 0;
}
```
