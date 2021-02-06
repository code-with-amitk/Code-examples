## [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
- Examples
```c
Input: nums = [1,1,1], k = 2
Output: 2

Input: nums = [1,2,3], k = 3
Output: 2

Input: nums = [1,-1,0], k = 0
Output: 3

Input: {-1,2,3,2,-2},  k = 5
Output: 3
```

## 1. Approach-1 //Brute Force //O(n<sup>3</sup>)
- **Logic**
  - *1.* Take every possible subarray and sun
```c
-1  2  3  2  -2   //subarry[-1,2], possible sums: (-1+2=1)
 i  j
 
-1  2  3  2  -2   //subarry[-1,3], possible sums: (-1+2=-1), (-1+2+3=4) (2+3=5)
 i     j
 so on
```
- **Complexity**
  - **Time:** O(n<sup>3</sup>)  3 for loops
  - **Space:** [O(1). Constant Space](https://github.com/amitkumar50/Code-examples/tree/master/DS_Questions)
- **Code**
```c++
  int subarraySum(std::vector<int>& nums, int k) {
    int count=0;
    for (int i=0; i < nums.size() ; ++i){
      for (int j=i+1; j <= nums.size() ; ++j){
        int sum = 0;
        for (int l = i; l < j ; ++l)
          sum += nums[l];
        if (sum == k)
          ++count;
      }
    }
    return count;
  }
```

## 2. Approach-2  //Cumulative Sum  //O(n<sup>2</sup>)
