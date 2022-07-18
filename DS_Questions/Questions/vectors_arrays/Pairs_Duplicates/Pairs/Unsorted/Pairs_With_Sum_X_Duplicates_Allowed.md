**Two Sum / Pair with Sum of X**
- [Approach-1, O(n^2), Brute Force](#a1)
- [Approach-2, HashTable](#a2)

## [Two Sum](https://leetcode.com/problems/two-sum)
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
### Approch-2, HashTable
#### Logic
*1.* Take hash-tables. key is value of input array and value=index. Check whether target-present_value exist in map. 
  - if it exists pair exists
#### Complexity
Time:O(n), Space:O(n)
#### Code
```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int> out;
        unordered_map<int,int> umm;

        for (int i=0; i<v.size(); ++i) {
            auto it = umm.find(target-v[i]);
            if (it == umm.end())
                umm.insert({v[i], i});
            else {
                out.push_back(it->second);
                out.push_back(i);
                break;
            }
        }
        return out;  
    }
};
int main(){
    Solution s;
    vector<int> v = {2,7,11,15}; int target = 9;
    vector<int> o = s.twoSum(v, target);
    cout << o[0] << "," << o[1] << "\n";
}
```
