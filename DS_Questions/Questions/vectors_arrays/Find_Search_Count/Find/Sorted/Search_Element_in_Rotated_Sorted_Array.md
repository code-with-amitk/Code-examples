**Search in Rotated Sorted Array / Search in V Shaped Array**
- [Approach-1, 2 times Binary Search](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
- [Approach-2, 1 pass Binary Search](#a2)

### [113. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- Array is rotated at some point [0,1,2,4,5,6,7] becomes [4,5,6,7,0,1,2]
- If target is found in the array return its index, otherwise, return -1.
- Examples
```c++
Input: nums = [4,5,6,7,0,1,2], target = 1
Output: 5   //Index of element 5

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

<a name=a1></a>
### Approach-1 //2 times Binary Search
<a name=l></a>
#### Logic
- *1.* Find point of rotation ie `arr[mid+1]<arr[mid]` using Binary Search. This divides the array into 2 halves.
- *2.* Search target element in two sub-arrays(Again using Binary Search).
<a name=com></a>
#### Complexity
  - **Time:** 2O(logn)
  - **Space:** O(1)
#### Code
**CPP**
```cpp
class Solution {
public:
  using vec = vector<int>;    
  int binarySearch (vec& v, int left, int right, int target) {
    while (left <= right) {
      int mid = left + (right-left)/2;
      if (v[mid] == target)
        return mid;
      else if (v[mid] > target)
        right = mid-1;
      else
        left = mid+1;
    }
    return -1;
  }
  int search(vec& v, int target){
    int left = 0, right = v.size()-1;

    // Find rotation point/smallest value in array
    while (left <= right) {
      int mid = left + (right-left)/2;
      if (v[mid] > v[v.size()-1])
        left = mid+1;
      else
        right = mid-1;
    }

    if (v[left] == target)
      return left;

    int a = binarySearch (v, 0, left-1, target);
    if (a != -1)
      return a;

    // else binary search in right
    return binarySearch (v, left, v.size()-1, target);
  }
};
```

<a name=a2></a>
### Approach-2  //1 pass Binary Search
#### Logic
```c
v[] = [4,5,6,7,0,1,2], target = 2
       0 1 2 3 4 5 6

if (v[mid] >= target and target >= v[start])
  - Search in left subarray
else
  - Search in right array

   start   end    mid   v[mid]    
    0       6      3       7      (7>=1 and 2>=4)   Search in right subarray
    4       6      5       1      (1>=2 and 2>=2)   Search in right subarray          
```  
#### Complexity
  - **Time:** O(nlogn)
  - **Space:** O(1)
#### Code
```c++
#include<iostream>
#include<vector>
using vec = std::vector<int>;

int BinarySearch (vec& v, int start, int end, int ele){
  int mid = (start+end)/2;

  if (start > end)
    return -1;

  if (v[mid] == ele)
    return mid;

  if(v[mid] >= v[start]){                     //1

    if (ele >= v[start] and ele <= v[mid])    //1a
       return BinarySearch(v,start,mid-1,ele);

    return BinarySearch(v,mid+1,end,ele);
  }

  if (ele >= v[mid] and ele <= v[end])          //1b
    return BinarySearch(v, mid+1, end, ele);

  return BinarySearch(v, start, mid-1, ele);
}

int search(vec& v, int target){
  int end = v.size() - 1;
  int start = 0, mid = -1;

  return BinarySearch(v, start, end, target);
}
```
