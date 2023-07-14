**Longest Arithmetic Subsequence of Given Difference**
- Approach-1. Hashtable. Time: O(n), Space: O(n)
  - [Logic]
  - Code
    - [CPP](#cpp)

### [1218. Longest Arithmetic Subsequence of Given Difference](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/)
- Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
- A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.
```cpp
 Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
```

<a name=a1></a>
### Approach-1. HashMap. Time: O(n), Space:O(n)
#### Logic
- _1._ Take `hashmap<key=element, value=length of AP till this element>`
- _2._ Iterate through the array and keep filling hashmap, Also not the largest value(that will be answer)
  - Find (current_element - ap_difference) in hashmap. if found increment count by 1.
```cpp
arr [1,5,7,8,5,3,4,2,1] difference = -2
     0 1 2 3 4 5 6 7 8

arr        1     5      7      8      5      3      4      2      1
index      0     1      2      3      4      5      6      7      8

hashmap   1,1   5,1   7,1     8,1    5,2    3,3    4,1    
index 
  0    1,1 => Cannot find (1--2=3) in hashmap. Hence AP to this element is of len=1 (value=1)
  1    5,1 => Cannot find (5--2=7) in hashmap. Hence AP to this element is of len=1 (value=1)
  2    7,1 => Cannot find (7--2=9) in hashmap. Hence AP to this element is of len=1 (value=1)
  3    8,1 => Cannot find (8--2=10) in hashmap. Hence AP to this element is of len=1 (value=1)
  4    5,2 => Found (5--2=7) in hashmap. 2 = (value of (7,1) + 1). AP to this element is of len=2 (7,5)
  5    3,3 => Found (3--2=5) in hashmap. 3 = (value of (5,2) + 1). AP to this element is of len=3 (7,5,3)
  6    4,1 => Cannot Find (4--2=6) in hashmap. Hence AP to this element is of len=1 (value=1)
  7    2,2 => Found (2--2=4) in hashmap. 2 = (value of (4,1) + 1). AP to this element is of len=2 (4,2)
  8    1,4 => Found (1--2=3) in hashmap. 4 = (value of (3,3) + 1). AP to this element is of len=2 (7,5,3,1)
```
#### Code
<a name=cpp></a>
```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> um;
        int longest = 1;

        for (auto& i : arr) {
            auto it = um.find(i - difference);    // Search difference
            if (it != um.end()) {
                um[i] = it->second + 1;
                longest = max(longest, um[i]);
            } else {
                um[i] = 1;
            }
        }

        return longest;
    }
};
```
