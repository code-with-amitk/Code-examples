**Sum of Subarray Ranges**
- [Approach-1, Naive, 2 pointers, 3 loops. O(n3). TLE](#a1)

### [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)
- You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
- Return the sum of all subarray ranges of nums. A subarray is a contiguous non-empty sequence of elements within an array.
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
### Approach-1, Naive, 2 pointers, 3 loops. O(n3). TLE
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
