**Duplicate elements in 2 arrays / Intersection of Two Arrays**
- [Approach-1 / O(mn)](#a1)
- [Approach-2 / O(nlogn)](#a2)
- Approach-3

### [Intersection of Two Arrays / Duplicate elements in 2 arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
```c
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```
<a name=a1></a>
### Approach-1 / O(mn)
- m = arr1.size(), n = arr2.size()
- Iterate using 2 for loops

<a name=a2></a>
### Approach-2 / O(nlogn)
#### Logic
- Sort both arrays. O(nlogn). O(mlogm)
```c
arr1 = [4,5,9]
arr2 = [4,4,8,9,9]
```
- Traverse both arrays simultneously and till end. O(m+n)

<a name=a3></a>
### Approach-3 / Time:O(n), Space:O(m)
#### Logic
- Store 1 array into HashSet. Time:O(m), Space:O(m)
- Iterate through other array and find duplicate.
#### Code
```c
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vecOut;
        unordered_set<int> usOut;
        
        //Insert Elements in HashSet
        unordered_set<int> usNums1;
        for (auto i:nums1)
            usNums1.insert(i);
        
        //Search each element in HashSet
        for (int i=0; i<nums2.size(); ++i){
            if (usNums1.find(nums2[i]) != usNums1.end()){
                usOut.insert(nums2[i]);
            }
        }
        
        //Create vector from HashSet
        for (auto i:usOut)
            vecOut.push_back(i);
        return vecOut;
    }
};
```
