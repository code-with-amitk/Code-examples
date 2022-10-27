**[Number of Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)**
- [Approach-1. Brute Force / O(n<sup>3</sup>)](#ap1)
- [Approach-2. Cumulative Sum / O(n<sup>2</sup>)](#ap2)
- [Approach-3. Cumulative Sum / O(n<sup>2</sup>) No Extra Space](#ap3)
- [Approach-4. Unordered_map O(n)](#ap4)


### Number of Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k. Examples
```c
Input: nums = [1,1,1], k = 2
Output: 2   //{1,1}, {1,1}

Input: nums = [1,2,3], k = 3
Output: 2   //{1,2}, {3}

Input: nums = [1,-1,0], k = 0
Output: 3   //{1,-1}, {0}, {1,-1,0}

Input: {-1,2,3,2,-2},  k = 5
Output: 3   //{2,3}, {3,2}, {2,3,2,-2}
```

<a name=a1></a>
### Approach-1 //Brute Force, O(n<sup>3</sup>)
**Logic:** Take every possible subarray and sum
```c
k = 5
-1  2  3  2  -2   //subarry[-1,2], possible sums: (-1+2=1)
 i  j
 
-1  2  3  2  -2   //subarry[-1,3], possible sums: (-1+2=-1), (-1+2+3=4) (2+3=5)
 i     j
 so on
```
#### Complexity
- **Time:** O(n<sup>3</sup>)  3 for loops
- **Space:** [O(1). Constant Space](/DS_Questions)
#### Code
```cpp
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

<a name=ap2></a>
### Approach-2. Cumulative Sum, Time:O(n<sup>2</sup>), Space:O(n+1)
#### Logic
- *1.* Find cumulative sum(ie sum of all prev elements of array upto this element) and store in seperate array `sum` size=arr+1
```c
arr =  -1  2  3  2  -2
        0  1  2  3   4
k = 5        
 
 Cumulative Sum Array.
 sum[0] = 0
 sum[1] = sum[0] + arr[0] = 0 + -1 = -1
 sum[2] = sum[1] + arr[1] = -1 + 2 = 1
 sum[3] = sum[2] + arr[2] = 1 + 3 = 4
 sum[4] = sum[3] + arr[3] = 4 + 2 = 6
 sum[5] = sum[4] + arr[4] = 6 + -2 = 4
   0 -1  1  4  6  4
   0  1  2  3  4  5
```
- *2.* Traverse through all subarrays. if cumulative_sum_upto_element - element == k. Increment count.
```c
k = 5
cum_sum        0    -1       1       4         6         4
cum_sum-ele(0)     -1-0     1-0     4-0       6-0       4-0
           (-1)    -1-1     1-1     4--1=5    6--1      4--1=5
           (1)     -1-1     1-1     4-1       6-1=5     4-1
```
#### Complexity
- **Time:** O(n<sup>2</sup>)
- **Space:** O(n+1)
#### Code
```c++
  int subarraySum(std::vector<int>& nums, int k) {
    int count=0;
    std::vector<int> cum_sum(nums.size()+1);
    cum_sum[0] = 0;
    
    for (int i=1; i <= nums.size() ; ++i)
      cum_sum[i] = cum_sum[i-1] + nums[i-1];

    for (int i=0; i<nums.size(); ++i) {
      for (int j=i+1; j <= nums.size(); ++j) {
        if(cum_sum[j] - cum_sum[i] == k)
          ++count;
      }
    }
    return count;
  }
```

<a name=ap3></a>
### Approach-3  //Cumulative Sum, Time:O(n<sup>2</sup>), Space:O(1)
#### Logic
Same as approach-2, But donot take seperate array to store cumulative sum(ie sum of all prev elements of array upto this element), calculate during for loop.
#### Complexity
- **Time:** O(n<sup>2</sup>)
- **Space:** O(1)
#### Code
```c++
  int subarraySum(std::vector<int>& nums, int k) {
    int count=0;

    for (int i=0; i<nums.size(); ++i){
      int sum=0;
      for (int j=i; j<nums.size(); ++j){
        sum += nums[j];
        if(sum == k)
          ++count;
      }
    }
    return count;
  }
```

<a name=ap4></a>
### Approach-4.  unordered_map. Time:O(n). Space:O(n)
#### Logic
  - *1.* if (cumulative_sum_i(sum of all prev elements of array upto this element) - cumulative_sum_j(sum of all prev elements of array upto this element)) == k. Then sum of elements lying between indices i and j is k.
  - *2.* Create unordered_map `<key = cumulative_sum_i, no. of occurrences of cumulative_sum_i)>`
  - *3.* Traverse the array, if we find new sum, create a new entry. If same sum is encountered, Update the value of this key.
  - *4.* Subseq with sum=k would be same as searching (cumulative_sum - k) in unordered_map.
```c
arr =  -1  2  3  2  -2
        0  1  2  3   4
k = 5
                                        unordered_map
                             key(cumulative_sum)   value          
       cumulative_sum                 0              1              cumulative_sum - k 
i=0        -1                         -1             1              -1 - 5 = -6   //Not present in um
i=1         1                         1              1              1 - 5 = -4    //Not present
i=2         4                         4              1              4 - 5 = -1    //Present in um. count=1
i=3         6                         6              1              6 - 5 = 1     //Present in um. count=2
i=4         4                         4              2              4 - 5 = -1    //Present in um. count=3
```
#### Complexity
- **Time:** O(n)
- **Space:** O(n+1)
#### Code
```cpp
  int subarraySum(std::vector<int>& nums, int k) {
    int count=0, sum=0;
    std::unordered_map<int, int> um;
    um[0] = 1;

    for (int i=0; i<nums.size(); ++i){
      sum += nums[i];
      auto it = um.find(sum-k);
      if (it != um.end())
        count += um[sum-k];
      auto it1 = um.find(sum);
      if (it1 != um.end())
        um[sum]++;
      else
        um[sum] = 1;
    }
    return count;
  }
```
