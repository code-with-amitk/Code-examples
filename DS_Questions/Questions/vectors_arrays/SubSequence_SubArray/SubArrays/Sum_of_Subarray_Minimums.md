**Sum of Subarray Minimums**
- [Approach-1, Naive, 2 pointers, 3 loops. O(n<sup>3</sup>). TLE](#a1)

### 907. Sum of Subarray Minimums
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10<sup>9</sup> + 7
```c
Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
  All Subarrays: [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
  Mins of subarrs:3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
```

<a name=a1></a>
### Approach-1, Naive, 2 pointers, 3 loops. O(n<sup>3</sup>). TLE
#### [Logic](/DS_Questions/Questions/Strings/SubString_SubSequence/SubString_SubArray/Find_All_SubSeq.md)
#### Code
```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        //Find All subarrays, 2 pointer approach
        /*
        3 1 2 4
        j b
            b
              b
        */
        long long sum = 0;
        int b = 0;
        for (int i=0; i<nums.size(); ++i) {
            long long mini = INT_MAX;
            b = i+1;
            while (b <= nums.size()) {
                for (int j=i; j<b; ++j) {
                    mini = nums[j] < mini ? nums[j] : mini;
                }
                sum = sum%1000000007;
                sum += mini;
                b++;
            }
        }
        return sum;
    }
};
```

<a name=a2></a>
### Approach-2, Monotonic Stack
