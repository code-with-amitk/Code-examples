### [Problem](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)
- You are given a rows x cols matrix. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
- Find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
- Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative return -1.
- **Examples**
```c++
Example-1:
Input: grid = [[-1,-2,-3],
               [-2,-3,-3],
               [-3,-3,-2]]
Output: -1
Explanation: It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.

Example-2:
Input: grid = [[1,-2,1],
               [1,-2,1],
               [3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is in bold (1 * 1 * -2 * -4 * 1 = 8).
```

### Logic (Dynamic Programming)
- Take 2 matrices of same size as input array
  - Matrix-1(maxProduct): stores max(present-box*aboveBox, presentBox*prevBox)
  - Matrix-2(minProduct) 

### Code
```c++
```
