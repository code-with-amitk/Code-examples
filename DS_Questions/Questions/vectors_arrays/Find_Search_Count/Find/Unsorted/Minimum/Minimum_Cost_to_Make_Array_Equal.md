**Minimum Cost to Make Array Equal**
- [Approach-1. Convex Function. Binary Search. O(logn)](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

### [2448. Minimum Cost to Make Array Equal](https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/)
- You are given two 0-indexed arrays nums and cost consisting each of n positive integers.
- You can do the following operation any number of times:
- Increase or decrease any element of the array nums by 1.
- The cost of doing one operation on the ith element is `cost[i]`.
- Return the minimum total cost such that all the elements of the array nums become equal.
```c
Example 1:
Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.
```

<a name=a1></a>
### Approach-1. Convex Function. Binary Search. O(logn)
#### Logic
- _1._ How this is convex function?
```c
nums = [1,3,5,2], cost = [2,3,1,14]
can be thought a         1,1, 3,3,3,     5, 14,14

Cost of making all 1's   0,0  2,2,2      4  13,13  => sum=36
Cost of making all 3's   2,2  0,0,0      1  11,11  => sum=26
Cost of making all 5's   4,4  2,2,2      10  9,9   => sum=32
Cost of making all 14's  13,13 10,10,10  10  0,0   => sum=62
--> See cost dips in between, hence it convex function
                            /
                        \  /
                         \/

```
- _2._ 

#### Code
<a name=cpp></a>
**CPP**
```cpp
using vI = vector<int>;
using ll = long long;
class Solution {
    ll cost_of_making_all_elements_equal_to_n(int n, vI& nums, vI& costs) {
        ll cost = 0;
        for (int i=0;i<nums.size();++i){
            cost += (ll(abs(nums[i] - n)) * ll(costs[i]));
        }
        return cost;
    }
public:
    ll minCost(vI& nums, vI& cost) {
        int low = INT_MAX, high = INT_MIN;
        for (auto&i:nums){
            if (i<low)
                low = i;
            if (i>high)
                high = i;
        }
        // All elements are equal
        if (low == high)
            return 0;
        high += 1;

        ll cost_mid = 0;
        ll cost_mid_plus1 = 0;
        while (low < high) {
            int mid = (low + high)/2;
            cost_mid = cost_of_making_all_elements_equal_to_n (mid, nums, cost);
            cost_mid_plus1 = cost_of_making_all_elements_equal_to_n (mid+1, nums, cost);
            if (cost_mid_plus1 > cost_mid)
                high = mid;
            else
                low = mid + 1;
        }
        return min(cost_mid, cost_mid_plus1);
    }
};
```
