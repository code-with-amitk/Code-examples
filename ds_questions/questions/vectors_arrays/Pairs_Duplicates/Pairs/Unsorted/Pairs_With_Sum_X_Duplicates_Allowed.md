## [Two Sum](https://leetcode.com/problems/two-sum/solution/)
- Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
- Examples
```c++
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Input: nums = [3,3], target = 6
Output: [0,1]
```

## 1. Approach-1  //Brute Force
- **Logic** Using 2 for loops iterate over element, find index
- **Complexity**  O(n<sup>2</sup>)
- **Code**
```c++
  for(int i=0; i<v.size(); ++i)
    for(int j=i; j<v.size(); ++j)
      if(v[i] + v[j] == target)
        //Return i,j
```

## 2. Approch-2   //Hash-Table    `unordered_multimap`
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

## 3. Approch-3   //Hash-Table, check while insertion    `unordered_multimap`
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
