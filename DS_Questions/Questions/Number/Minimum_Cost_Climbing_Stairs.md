**Min Cost Climbing Stairs**
- Approach-1, Dynamic Programming
  - [Logic](#l)
  - [


### [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs)
- You are given an integer array cost where `cost[i]` is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
- You can either start from the step with index 0, or the step with index 1.
- Return the minimum cost to reach the top of the floor, top is considered as 1 step after last stair.
```c
Example 1:
Input: cost = [10,15,20].   10 15 20 TOP
Output: 15
Explanation: Start at index 1. Pay 15 and climb two steps to reach the top. The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```

### Approach-1, Dynamic Programming
<a name=l></a>
#### Logic = [DP Template](/DS_Questions/Algorithms/Dynamic_Programming)
- _1. Define State:_ Minimum cost to reach ith stair.
  - We will store costs to reach particular stair in `vecMinCost[]` and will return the last element.
  - But sizeof(`vecMinCost[]`) would be (stairs+1) because TOP is 1 step above last stair
- _2. Function to return state:_
```c
int dp(i) {
}
```
- _3. Reoccurance Relationship:_ Define relationship between states. Can we derive state from prev states?
  - Min cost of reaching ith stair is min of cost of reaching (i-1) or (i-2) stair.
```c
  vecMinCost[i] = min(vecMinCost[i - 1] + cost[i - 1], vecMinCost[i - 2] + cost[i - 2])
```
#### Code
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        if (cost.size() == 2)
            return min(cost[0], cost[1]);
        
        vector<int> vecMinCost(cost.size()+1, 0);
        
        
        for (int i=2; i < vecMinCost.size() ; ++i) {
            vecMinCost[i] = min((vecMinCost[i-2] + cost[i-2]), (vecMinCost[i-1] + cost[i-1]));
        }
        
        return vecMinCost.back();
    }
};
```
#### Complexity
- **Time:** O(n)
- **Space:** O(n+1) = O(n). Taken n+1 sized array since we need to reach top which is 1 step above last stair.
