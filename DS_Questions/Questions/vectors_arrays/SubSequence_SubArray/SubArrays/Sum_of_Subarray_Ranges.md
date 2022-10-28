**Sum of Subarray Ranges**
- [Approach-1, Naive, 2 pointers, 3 loops. O(n<sup>3</sup>). TLE](#a1)
- [Approach-2, 2 for loops. O(n<sup>2</sup>)](#a2)

### [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)
- You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
- Return the sum of all subarray ranges of nums. A subarray is a contiguous non-empty sequence of elements within an array.
- **This is to be achieved in O(n) time complexity**
```c
Example-1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
            largest-smallest
[1]         //0
[1,2]       //1
[1,2,3]     //2
[2]         //0
[2,3]       //1
[3]         //0
```

<a name=a1></a>
### Approach-1, Naive, 2 pointers, 3 loops. O(n<sup>3</sup>). TLE
#### [Logic. Find All Subarrys](/DS_Questions/Questions/Strings/SubString_SubSequence/SubString_SubArray/Find_All_SubSeq.md)
#### Code
```cpp
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int b = 0;
        for (int i=0; i<nums.size(); ++i) {
            long long maxi = INT_MIN, mini = INT_MAX;
            b = i+1;
            while (b <= nums.size()) {
                for (int j=i; j<b; ++j) {
                    maxi = nums[j] > maxi ? nums[j] : maxi;
                    mini = nums[j] < mini ? nums[j] : mini;
                }
                sum += (maxi-mini);
                b++;
            }
        }
        return sum;
    }
};
```
#### [Complexity](/DS_Questions/Questions/Strings/SubString_SubSequence/SubString_SubArray/Find_All_SubSeq.md)

<a name=a2></a>
### Approach-2 for loops O(n<sup>2</sup>)
#### Logic
- _1._ Take min, max values as 1st value in subarray, then compare all other values and find min, max.
- _2._ Iterate 
```c
  1  2  3  4         min            max         sum += max-min          subarray
  .
  *                   1              1           0                       [1]
     *                1              2           0+1=1                   [1,2]
         *            1              3           1+2=3                   [1,2,3]
            *         1              4           3+3=6                   [1,2,3,4]

     .                
     *                2              2           6                       [2]
         *            2              3           6+1=7                   [2,3]
            *         2              4           7+2=9                   [2,3,4]

         .
         *            3              3           9                       [3]
            *         3              4           9+1=10                  [3,4]
            
            .
            *         4              4           10

```
#### Code
```cpp
using ll = long long;

class Solution {
public:
    ll subArrayRanges(vector<int>& nums) {
        ll sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            ll maxi = nums[i], mini = nums[i];                         //1
                for (int j=i; j<nums.size(); ++j) {
                    maxi = nums[j] > maxi ? nums[j] : maxi;
                    mini = nums[j] < mini ? nums[j] : mini;
                    sum += (maxi-mini);
                }
            }
        return sum;
    }
};
```
#### Complexity
- **Time:** O(n<sup>2</sup>)
- **Space:** O(1)
