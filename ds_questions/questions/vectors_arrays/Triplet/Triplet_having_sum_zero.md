### [3sum](https://leetcode.com/problems/3sum/)
- Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
- Examples
```c++
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = []
Output: []

Input: nums = [0]
Output: []
```

### Approach-1  //O(n<sup>3</sup>)
- 3 for loops check every element with each other
```c++
  vector<vector<int>> out;
  for(int i=0; i<nums.size(); ++i)
    for(int j=i+1; j<nums.size(); ++j)
      for(int k=j+1; k<nums.size(); ++k)
        if (nums[i]+nums[j]+nums[k] == 0)
          out.push_back({nums[i],nums[j],nums[k]});
  return out;    
```
