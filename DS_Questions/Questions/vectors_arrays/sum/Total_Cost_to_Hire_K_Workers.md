**Total Cost to Hire K Workers**
- [Approach-1. 2 Min Heaps. Sliding Window](#a1)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)

### [Self Video](https://youtu.be/tYEpt_P0hI0)

### [2462. Total Cost to Hire K Workers](https://leetcode.com/problems/total-cost-to-hire-k-workers/description/)
- You are given a 0-indexed integer array costs where `costs[i]` is the cost of hiring the ith worker.
- You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:
- You will run k sessions and hire exactly one worker in each session.
  - In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
  - For example, if costs = `[3,2,7,7,1,2]` and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost `[3,2,7,7,1,2]`.
  - In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index `[3,2,7,7,2]`. Please note that the indexing may be changed in the process.
  - If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
  - A worker can only be chosen once.
  - Return the total cost to hire exactly k workers.
```c
Example 1:
Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
The total hiring cost is 11.
```

<a name=a1></a>
### Approach-1. 2 Min Heaps. Sliding Window
#### Logic
- **Problem understanding**
  - _1._ We need to take candidate sized windows from front and back
```c
costs = [17,12,10,2,7,2,11,20,8].  candidates = 4
sum = 0
    17  12  10  2  7  2  11  20  8
    |leftwindow |     |Rightwindow|
```
- _2._ Get minimum cost(element) from any window, and increase the window in other direction.
```c
sum = 2
  Note 2 is taken from leftWindow and 7 is included in window
    17  12  10    7      2  11  20  8
    | leftwindow  |      |RightWindow|

sum = 2+2
  - When windows collide, then take min element from (left, right window) and decrment appropriate.
    17  12  10    7        11  20  8
    | leftwindow  |      RightWindow|

```
<a name=com></a>
#### Complexity
- **Time:** O(logn). Rebalance of BBT = Min Heap.
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long sum = 0;

        priority_queue<int,vector<int>,greater<int>> leftq, rightq;

        int i = 0;
        int left_ptr = 0, right_ptr=costs.size()-1;

        while (i < k) {

            while(leftq.size()<candidates && left_ptr<=right_ptr) {
                leftq.push(costs[left_ptr]);
                left_ptr++;
            }

            while(rightq.size()<candidates && right_ptr>=left_ptr) {
                rightq.push(costs[right_ptr]);
                --right_ptr;
            }

            int min_cost_from_leftpq = leftq.size()>0?leftq.top():INT_MAX;
            int min_cost_from_rightpq = rightq.size()>0?rightq.top():INT_MAX;

            if (min_cost_from_leftpq <= min_cost_from_rightpq) {
               sum += min_cost_from_leftpq;
               leftq.pop();
            }
            else{
              sum += min_cost_from_rightpq;
              rightq.pop();
            }

            i++;
        }

        return sum;
    }
};
```
