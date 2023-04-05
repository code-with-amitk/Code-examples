**Majority Element 2**
- [Approach-1. HashMap. O(n)](#a1)
  - [Logic](#l)
  - [Complexity](#c)
  - Code
    - [CPP](#cpp)
    - [Rust](#r)

### [229. Majority Element 2](https://leetcode.com/problems/majority-element-ii/description/)
- Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
```c
Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]
```

<a name=a1></a>
### Approach-1. HashMap. O(n)
<a name=l></a>
#### Logic
- Iterate thorough array. Count number of times element appears in array
```c
arr = [3,2,3]
HashMap = <3, 2> <2,1>
```
- Iterate hashmap and note keys(elements) whose `value>size/3`

<a name=c></a>
#### Complexity
- Time: O(n)
- Space: O(n)

#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        for (auto&i:nums)
            um[i]++;
        int size=nums.size()/3;

        vector<int> out;
        //Iterate map and pick elements value>size
        for (auto it=um.begin(); it!=um.end(); ++it){
            if (it->second>size)
                out.push_back(it->first);
        }

        return out;
    }
};
```

<a name=r></a>
**Rust**
```rs
use std::collections::HashMap;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut hm:HashMap<i32,i32> = HashMap::new();

        // Iterate thorough nums and create a hashamp
        for (i,v) in nums.iter().enumerate() {
          //get current occurrences of element or default to 0
            let count = hm.entry(*v).or_insert(0);
          //increase count by 1
            *count+=1;
        }

        let size = nums.len() / 3;
        let mut out:Vec<i32> = Vec::new();
        for (k,v) in hm {
            if v > size as i32 {
                out.push(k);
            }
        }
        out
    }
}
```
