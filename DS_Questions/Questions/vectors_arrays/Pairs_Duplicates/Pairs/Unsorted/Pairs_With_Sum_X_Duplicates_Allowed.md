**Two Sum / Pair with Sum of X**
- [Approach-1, O(n^2), Brute Force](#a1)
- [Approach-2, ](#a2)
- [Approach-3](#a3)

## [Two Sum](https://leetcode.com/problems/two-sum/solution/)
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
```c
Input: nums = [2,11,15,7], target = 9
Output: [0,3] //index

Input: nums = [3,3], target = 6
Output: [0,1]
```

<a name=a1></a>
### Approach-1  //Brute Force, O(n<sup>2</sup>)
#### Logic 
Use 2 for loops iterate over element, find duplicate
```cpp
  for(int i=0; i<v.size(); ++i)
    for(int j=i; j<v.size(); ++j)
      if(v[i] + v[j] == target)
        //Return i,j
```

<a name=a2></a>
### Approch-2, HashTable, 
#### Logic
*1.* Take hash-table allowing duplicates. key is value of input array and value=index. Insert all elements into map
```c
    arr           HashSet
[2,11,15,7]       [2]
map:
  first second 
   7      1
   2      0
   11     2
   15     3
```
  - *2.* Iterate through input array and search (target-self), Also consider Element searched is not same as myself.
```c
  if (it != umm.end() and it->second != i){
  ..
  }
```
- **Complexity:** Time:O(n), Space:O(n)
- **Code**
```c++
std::vector<int>fun(std::vector<int>& v, int target){

  std::vector<int> out;
  std::unordered_multimap<int,int> umm;

  for (int i=0;i<v.size();++i)
    umm.insert({v[i], i});

  for (auto [i,j]:umm)
    std::cout<<i<<","<<j<<"\n";
    
  for (int i=0;i<v.size();++i) {
    auto it = umm.find(target-v[i]);
    if (it != umm.end() and it->second != i){
      out.push_back(it->second);
      umm.erase(it);
    }
  }

  return out;
}
```

## 3. Approch-3   //Hash-Table, check while insertion >> Most Optimized
- **Logic** 
  - *1.* Take hash-table allowing duplicates. key is value of input array and value=index. Insert all elements into map
```c
  nums = [2,7,11,15]
  unordered_multimap<key=nums[i], value=i> umm
map:
  first second 
   7      1
   2      0
   11     2
   15     3
```
  - *2.* Iterate through input array and insert `<key=arr_element, value=element_index>` into unordered_multimap.
    - if(target - self) exists in array, push indexes and return.
    - else insert `<key, value>` into array.
- **Complexity:** 
  - Time:O(n). Worst case O(n) when pair exists at 1st and last element. else smaller than O(n)
  - Space:O(n) Same as time complexity
- **Code**
```c++
#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        
        vector<int> out;
        unordered_multimap<int,int> umm;

        for (int i=0; i<v.size(); ++i) {
            auto it = umm.find(target-v[i]);
            
            if (it == umm.end()) {
                umm.insert({v[i], i});
            }
      
            if (it != umm.end() and it->second != i) {
                out.push_back(it->second);
                out.push_back(i);
                break;
            }
        }
        return out;  
    } 
};
```
