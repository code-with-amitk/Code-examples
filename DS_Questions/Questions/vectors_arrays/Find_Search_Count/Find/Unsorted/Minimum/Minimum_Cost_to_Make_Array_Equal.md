**Minimum Cost to Make Array Equal**
- [Approach-1. Convex Function. Binary Search. O(logn)](#a1)
  - [Logic](#l)
  - [Complexity](#com)
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
- _1._ This is convex function, and we need to find weighted median.
  - We will try finding out central tendency(ie where convex function converges) then we will find median.
  - But to find median all elements need to be sorted.
```c
nums = [1,3,5,2], cost/weight/frequency = [2,3,1,14]
sorted=[1,2,3,5], cost/weight/frequency = [2,14,3,1]

can be thought a         1,1,   2,2,2,2,2,2,2,2,2,2,2,2,2,2  3,3,3    5

Cost of making all 1's   0,0    1,1,1,1,1,1,1,1,1,1,1,1,1,1  2,2,2    4  =  24
Cost of making all 2's   1,1    0,0,0,0,0,0,0,0,0,0,0,0,0,0  1,1,1    3  =  8
Cost of making all 3's   2,2    1,1,1,1,1,1,1,1,1,1,1,1,1,1  0,0,0    2  =  20
Cost of making all 5's   4,4    3,3,3,3,3,3,3,3,3,3,3,3,3,3  2,2,2    0  =  56    
--> See cost dips in between, hence it convex function
                            /
                        \  /
                         \/
                      Central Tendency
Ans = min(mid values)
```
- _2._ Nums is not sorted, But we will find smallest, largest element from array and perform binary search to find weighted mean.
- _3._ Binary Search
  - Take low=smallest, high=largest element from nums array
```c
nums = [1,3,5,2], cost/weight/frequency = [2,3,1,14]
smallest element = low = 1
largest element = high = 5+1

  1 2 3 4 5 6
  |         |
low       high
```
  - Find `mid = (low?high)/2`. Now calculate cost of converting all elements to mid element and mid+1
```c
  mid = (1+6)/2 = 7/2 = 3
              1   2   3   4   5   6
              |       |           |
            low      mid         high

                      20  38
Cost of converting all elements to mid=3 is 20
Cost of converting all elements to mid+1=4 is 38

Since 38 > 20. Move to left

              1   2   3   4   5   6
              |       |  
            low      high
```
  - Loop until `(low < high)`
    - And once we are out of loop, return min(cost_of_mid, cost_of_mid_1)

<a name=com></a>
#### Complexity
- **Time:**  O(logn)
- **Space:** O(1)

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
