### [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
- Given two arrays, write a function to compute their intersection.
- Examples
```c++
Example1
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
```

### Approach-1(Linear Search)
- Traverse array-1, array-2 until any 1 array is finished.
- Find duplicates. Move on that array which has element smaller than other
- **Time Complexity** O(mn)

### Approach-2 (Binary Search)
- *1.* Sort both array. O(nlogn), O(mlogm)
- *2.* Remove duplicates. O(n), O(m)
- *3.* if element-array-1 < element-array-2. Find element-array-2 inside array-1 using binary search and viceversa. O(logn) + O(logm)
- **Time Complexity** O(nlogn) + O(mlogm) + O(n) + O(m) + O(logn) + O(logm)

### Code-Approach-2
```c++
class Solution {
    
public:
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
    
    void Insert(vec& out, int& ele){
		out.push_back(ele);
    }
    
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {

      vec out;
      int i=0,j=0;
        
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
        
  //Remove Duplicates
  std::vector<int>::iterator it;
  it = std::unique(arr1.begin(), arr1.end());
  arr1.resize(std::distance(arr1.begin(), it));
  it = std::unique(arr2.begin(), arr2.end());
  arr2.resize(std::distance(arr2.begin(), it));
        

  while ((i < arr1.size()) and (j < arr2.size())){
    if (arr1[i] < arr2[j])
    {
      int ret = BinarySearch(arr1, arr2[j], i, arr1.size()-1);
      if(ret!=-1){
        i = ret;
        Insert(out, arr1[i]);  
      }
    }
    else if (arr1[i] > arr2[j]) {
      int ret = BinarySearch(arr2, arr1[i], j, arr2.size()-1);
      if(ret!=-1){
        j = ret;
          Insert(out, arr2[j]);
      }
    }
    else if(arr1[i]==arr2[j])
        Insert(out, arr1[i]);

    ++i;
    ++j;
  }
  return out;        
    }
};
```
