:toc:
:toclevels: 6

== link:https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions[2610. Convert an Array Into a 2D Array With Conditions]
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

```
Example 1:
Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.

Example 2:
Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
```

== Approach-1. Hashmap. O(n)
=== Logic
* Traverse array and create a hashmap containing key=array_element and value=number of times it occured
```c
[1,3,4,1,2,3,1,4,5,6,1,2,1]
key  value
1    5
3    2
4    2
5    1
6    1
```
* Traverse this hashmap and fill key in vector<int> and reduce value by 1
```
{1,3,4,5,6}
key  value
1    4
3    1
4    1
```
* Perform above until complete hashmap is not empty.

=== Complexity
* Time: O(n)
* Space: O(n)

=== Code
==== CPP
```cpp
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> um;
        vector<vector<int>> out;
        for(int&i:nums)
            um[i]++;
        
        while(um.size()) {
            vector<int> temp;
            vector<int> keysToRemove;
            for (auto& [key, value]:um) {
                temp.push_back(key);
                value--;
                if (value == 0)
                    keysToRemove.push_back(key);
            }
            out.push_back(temp);
            for (int key : keysToRemove)
                um.erase(key);
        }
        return out;
    }
};
```
