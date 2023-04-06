**Two Out of Three**
- [Approach-1. HashMap. O(n)](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

## For every problem, How To Fit HashMap in it. HashMap Structure

### [2032. Two Out of Three](https://leetcode.com/problems/two-out-of-three/description/)
Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.
```c
Example 1:
Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
Explanation: The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
```

<a name=a1></a>
### Approach-1. HashMap
<a name=l></a>
#### Logic
- _1._ Take `unordred_map<key=array_num, value=struct FIND>`
```c
struct FIND {
  bool a;   //Set true, if value is present in nums1
  bool b;   //Set true, if value is present in nums2
  bool c;   //Set true, if value is present in nums3
};
```
- _2._ Iterate all 3 arrays and set key,value
```c
HashMap
  <1, {true, false, false}>
  <2, {true, true, false}>
  <3, {true, true, true}>
```

#### Code
**CPP**
```cpp
class Solution {

public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        typedef struct present{
            bool a;
            bool b;
            bool c;
        }PRESENT;
        unordered_map<int, PRESENT> um;
        vector<int> out;
        // 1st loop, Fill a
        for (auto&i:nums1){
            auto it = um.find(i);
            if (it == um.end())
                um.insert({i, {true, false, false}});
        }
        for (auto&i:nums2){
            auto it = um.find(i);
            if (it != um.end())
                um[i].b = true;
            else
                um.insert({i, {false, true, false}});
        }
        for (auto&i:nums3){
            auto it = um.find(i);
            if (it != um.end())
                um[i].c = true;
            else
                um.insert({i, {false, false, true}});
        }
        for (auto it = um.begin(); it!=um.end(); ++it) {
            if (it->second.a + it->second.b + it->second.c >=2)
                out.push_back(it->first);
        }
        return out;
    }
};
```
