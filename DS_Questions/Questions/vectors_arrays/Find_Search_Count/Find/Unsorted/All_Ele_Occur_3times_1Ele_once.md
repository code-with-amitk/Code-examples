**All elements appears thrice and one element appears once**
- [Approach-1, unordered_map. Time:O(n), Space:O(m)](#apr1)

## [Single Number II](https://leetcode.com/problems/single-number-ii/)
- Given an integer array where every element appears 3 times except for one, which appears exactly once. Find the single element and return it.
- In Time:O(n), Space:O(1). Example
```c
Input: nums = [1,2,3,1,2,1,2]
Output: 3
```

<a name=apr1></a>
### Approach-1, unordered_map
- Create a unordered_map containing element and their count and return key having smallest value(will always be 1).
```c
unordered_map
  key count
  1   3
  2   3
  3   1
```
#### Complexity
- **Time:** Greater than O(n). Depends on complexity of comparator function.
- **Space:** O(m). m=Unique keys
#### Code
```cpp
class Solution {
public:
  static bool comp(pair<int,int> i, pair<int, int> j){
    return i.second < j.second;
  }
    
  int singleNumber(vector<int>& nums) {
                 //key, count
    unordered_map<int, int> um;
        
    for (auto i:nums)
      um[i]++;
        
    //Find key with count=1
    unordered_map<int,int>::iterator it;
    it = min_element(um.begin(), um.end(),comp);
    return it->first;
  }
};
```
