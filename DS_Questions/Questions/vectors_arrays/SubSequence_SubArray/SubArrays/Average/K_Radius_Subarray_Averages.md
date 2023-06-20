**K Radius Subarray Averages**
- [Approach-1. Sliding Window. O(n)](#a1)
- Code
  - [CPP](#cpp)

### [Self Video](https://youtu.be/axTIIfymxAs)

### [2090. K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/description/)
- You are given a 0-indexed array nums of n integers, and an integer k.
- The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.
- Build and return an array avgs of length n where `avgs[i]` is the k-radius average for the subarray centered at index i.
- The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.
- For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.
- Example:
```c
Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
- The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.
```

<a name=a1></a>
### Approach-1. Sliding Window. O(n)
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        bool first_avg = true;
        long long sum = 0;
        vector<int> avg (nums.size(), -1);
        vector<long long> sum_arr (nums.size(), -1);
        if (2*k >= nums.size())
            return avg;
        
        for (int i=k; i<nums.size()-k; ++i) {
            if (first_avg) {
                int j = i;
                while (j >= i-k) {
                    sum += nums[j];
                    --j;
                }
                j = i+1;
                while (j <= i+k) {
                    sum += nums[j];
                    ++j;
                }
                sum_arr[i] = sum;
                first_avg = false;
            } else {
                sum_arr[i] = sum_arr[i-1] - nums[i-k-1] + nums[i+k];
            }
        }
        for (int i=k; i<avg.size()-k; ++i) {
            sum_arr[i] /= (2*k+1);
            avg[i] = sum_arr[i];
        }
        return avg;
    }
};
```

