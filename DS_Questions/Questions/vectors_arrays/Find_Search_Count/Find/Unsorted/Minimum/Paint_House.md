**Paint House**
- [Approach-1. Dynamic Programming](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
    - [C](#c)
    - [Rust](#r)
    - [Go](#go)

### [256. Paint House](https://leetcode.com/problems/paint-house/description/)
- There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
- The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.
- For example, `costs[0][0]` is the cost of painting house 0 with the color red; `costs[1][2]` is the cost of painting house 1 with color green, and so on...
- Return the minimum cost to paint all houses.
```c
Example 1:
Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.

Example 2:
Input: costs = [[7,6,2]]
Output: 2
```

<a name=a1></a>
### Approach-1. Dynamic Programming
**[Why DP?](/DS_Questions/Algorithms/Dynamic_Programming/)**
#### Logic
```c
                Red     Blue    Green
    House-1     17      2       17        |   00  01  02
    House-2     16      16      5         |   10  11  12
    House-3     14      3       19        |   20  21  22
    House-4     5       8       7         |   30  31  32
    House-5     12      21      13        |   40  41  42
    
- cost of painting house-2
    - With red color = 16 + min(2(01), 17(02))    = 18
    - With blue color = 16 + min(17(00), 17(02))  = 33
    - With green color = 5 + min(17(00), 2(01))   = 7

dp array
    house-1     17      2       17
    house-2     18      33      7
    
- cost of painting house-3
    - With red color = 14 + min(33(01), 7(02))    = 21
    - With blue color = 3 + min(18(00), 7(02))  =   10
    - With green color = 19 + min(18(00), 33(01))   = 37

dp array
    house-1     17      2       17
    house-2     18      33      7
    house-2     21      10      37

...
```
#### Complexity
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    /*
    costs:  rows=5, cols=3
                Red     Blue    Green
    House-1     17      2       17
    House-2     16      16      5
    House-3     14      3       19
    House-4     5       8       7
    House-5     12      21      13

    dp:
            17                    2                 17
            16+                  16+                5+
            min(costs[0][1]+    min(costs[0][0]+    min(costs[0][0]+
            costs[0][2])        costs[0][2])        costs[0][1])
    */
    int minCost(vector<vector<int>>& costs) {
        
        int rows = costs.size();
        if (!rows)
            return 0;

        int cols = costs[0].size(); //Would always be 3

        // Create a dp array of same size as costs
        vector<vector<int>> dp (rows, vector<int>(cols, -1));

        // Initialize 1st row of dp same as 1st row of costs
        for (int i=0;i<cols; ++i)
            dp[0][i] = costs[0][i];
        
        for (int i=1; i<rows; ++i) {
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }

        return min(dp[rows-1][0], min(dp[rows-1][1], dp[rows-1][2]));
    }
};
```
<a name=c></a>
**C**
```c
int minCost(int** costs, int costsSize, int* costsColSize){
/*
    costs:  rows=5, cols=3
                Red     Blue    Green
    House-1     17      2       17
    House-2     16      16      5
    House-3     14      3       19
    House-4     5       8       7
    House-5     12      21      13
*/
    int rows = costsSize;
    int cols = 3;

    // Take a dp Array
    int dp[rows][3];

    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for (int i=1;i<rows;++i) {
        dp[i][0] = costs[i][0] + fmin(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = costs[i][1] + fmin(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = costs[i][2] + fmin(dp[i-1][0], dp[i-1][1]);
    }

    return fmin(dp[rows-1][0], fmin(dp[rows-1][1], dp[rows-1][2]));
}
```
