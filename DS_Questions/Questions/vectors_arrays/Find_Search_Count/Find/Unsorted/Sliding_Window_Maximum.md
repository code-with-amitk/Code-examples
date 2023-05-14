**Sliding Window Maximum**
- [Approach-1. nlog(k). Keep Window in `multiset<int>`](#a1)
  - [Logic](#l)
  - [Complexity](#c)
  - Code
    - [CPP](#cpp)


### [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/)
- You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
- Return the max sliding window.
```c
Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 ```
 
 <a name=a1></a>
 ### Approach-1. Maintain window in `multiset<int>`
 <a name=l></a>
 #### Logic
 - _1._ Keep window inside `multiset<int>`. multiset can have duplicate elements and stores elements in sorted order.
 ```c
 multiset<int>              will store {1,3,5,6,7}
 multiset<int, greter<int>> will store {7,6,5,3,1}
 ```
 - _2._ When number of elements becomes greater than k, Search 1st element 
 ```c
 1 3 -1 -3 5 3 6 7    multiset
 |    |                {3,1-1}

1 3 -1 -3 5 3 6 7      {3,-1,-3}  //Search 1 and remove from multiset
  |     |
 ```
 <a name=c></a>
 #### Complexity
 - **Time:**
  - `set<int>` search,rebalance = nlog(n). Since window size=k. klog(k)
  - n=number of elements. nklog(k)
 - **Space:** k. Window size
 #### Code
 <a name=cpp></a>
 **CPP**
 ```cpp
 class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       // set<> stores values in sorted order
        // Stores in BBT. Complexity nlog(n)
        multiset<int, greater<int>> msWindow;
        int i = 0;
        vector<int> out;
        if (k==0)
            return out;

        while (i < nums.size()) {
            if (i >= k)
                msWindow.erase (msWindow.find(nums[i-k]));

            msWindow.insert (nums[i]);
            if (msWindow.size() == k) {
                auto it = msWindow.begin();
                out.push_back (*it);
            }
            i++;
        }
        return out;
    }
};
 ```
