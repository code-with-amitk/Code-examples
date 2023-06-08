**Count Negative Numbers in a Sorted Matrix**
- [Approach-1. Traverse from Bottom left to top right. O(m+n)](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
    - [Python](#py)
    - [Java](#java)
    - [Rust](#rs)
    - [Go](#go)


### [1351. Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/)
- Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
- Find in O(m+n) Time
```c
Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0
```

<a name=a1></a>
### Approach-1. Traverse from Bottom left to top right. O(m+n)
<a name=l></a>
#### Logic
- Negative regions of the matrix will form a "staircase" shape. Trace the outline of the staircase.
- Start from bottom-left corner of the matrix, count in the negative numbers in each row.
```c
++++++
++++--
++++--
+++---
+-----
+-----
```
<a name=com></a>
#### Complexity
- **Time** O(m+n).
  - because when you traversing the outline of staircase, you can almost traverse (m+n)-1 steps. Take a grid of all positive integers and dry run it.
- **Space:** O(1)
#### Code
<a name=cpp></a>
**CPP**
```c
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        int rows = grid.size(), cols = grid[0].size();
        int r = rows-1, c=0;

        // Start from bottom left and traverse till top right
        while (r >= 0 && c < cols){
            if (grid[r][c] < 0) {
                count += (cols-c);
                r--;
            } else {
                ++c;
            }
        }
        return count;
    }
};
```
<a name=py></a>
**Python**
```py
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        rows = len(grid);
        cols = len(grid[0]);
        r = rows - 1;
        c = 0;
        count = 0;
        while (r >=0 and c < cols):
            if (grid[r][c] < 0):
                count += cols - c;
                r -= 1;
            else:
                c += 1;
        return count;
```
<a name=java></a>
**Java**
```java
class Solution {
    public int countNegatives(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int r = rows-1, c = 0, count=0;
        while (r >= 0 && c < cols) {
            if (grid[r][c] < 0) {
                count += (cols - c);
                r--;
            }
            else {
                c++;
            }
        }
        return count;
    }
}
```

<a name=rs></a>
**Rust**
```rs
impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let mut count = 0;

        let rows = grid.len();
        let cols = grid[0].len();
        let mut r = rows - 1;
        let mut c = 0;

        while r >= 0 && c < cols {
            if grid[r][c] < 0 as i32{
                count += (cols as i32) - (c as i32);
                if r == 0 {
                    break;
                }
                r -= 1;
            } else {
                c += 1;
            }
        }

        count as i32
    }
}
```
<a name=go></a>
**Go**
```go
func countNegatives(grid [][]int) int {
    var rows = len(grid);
    var cols = len(grid[0]);
    var r = rows -1;
    var c = 0; 
    var count = 0;

    for r >= 0 && c < cols {
        if (grid[r][c] < 0) {
            count += (cols - c);
            r--;
        } else {
            c++;
        }
    }
    return count;
}
```
