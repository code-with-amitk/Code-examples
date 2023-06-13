**Equal Row and Column Pairs**
- [Approach-1. O(n<sup>3</sup>)](#a1)
  - Code
    - [CPP](#cpp1)
- [Approach-2. O(n<sup>2</sup>). 102ms](#a2)
  - [Logic](#l2)
  - [Complexity](#com2)
  - Code
    - [CPP](#cpp2)

### [2352. Equal Row and Column Pairs](https://leetcode.com/problems/equal-row-and-column-pairs/description/)
Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).
```c
Example-1
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
3 2 1
1 7 6
2 7 7
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]

Example-2
Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
3 1 2 2
1 4 4 5
2 4 2 2
2 4 2 2
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
```

<a name=a1></a>
### Approach-1. O(n<sup>3</sup>)
<a name=l2></a>
#### Logic
- Visit every element and check its corresponding row, col that all elements are equal or not, if yes increment count by 1
#### Complexity
- **Time:** O(n<sup>3</sup>). Since its square matrix. m=n. 
  - Traversing every row, col `(m*n)`.
  - Then at every element, that check row and col. O(n)
- **Space:** O(1)
#### Code
<a name=cpp1></a>
**CPP**
```cpp
class Solution {
    int out, rows;
    void check (int r, int c, vector<vector<int>>& grid) {
        for (int i = 0; i <rows; ++i){
            if (grid[i][c] != grid[r][i])
                return;
        }
        out++;
    }
public:
    int equalPairs(vector<vector<int>>& grid) {
        out = 0;
        rows = grid.size(); //nxn matrix

        for (int i=0;i<rows;++i) {
            for (int j=0;j<rows;++j) {
                // Check each element's row and cols
                check (i, j, grid);
            }
        }
        return out;
    }
};
```

<a name=a2></a>
### Approach-2
<a name=l></a>
#### Logic
- _1._ Store coloumns in `map<vector<int>, int>`, where key=coloumn and value=count
- _2._ Traverse the input grid rowwise and search whether row is present in map. If its present, increment count by value of entry from map.
<a name=com2></a>
#### Complexity
- **Time:** 
  - O(n<sup>2</sup>): Storing coloumns in map
  - O(n<sup>2</sup>): Traverse row and compare.
- **Space:** (n<sup>2</sup>). Storing grid in map.
#### Code
<a name=cpp2></a>
**CPP**
```cpp
class Solution {
    int out, rows;
public:
    int equalPairs(vector<vector<int>>& grid) {
        out = 0;
        rows = grid.size(); //nxn matrix

        map<vector<int>, int> m;
        //                          column, count
        // Keep coloumns in map<vector<int>, int>>
        for (int i=0;i<rows;++i){
            vector<int> v;
            for (int j=0;j<rows;++j)
                v.push_back(grid[j][i]);
            
            auto it = m.find(v);
            if (it == m.end())
                m.emplace(v, 1);
            else
                it->second++;
        }

        //Traverse rows, if row is found in map increment count by value of unordered_map
        for (auto &row:grid) {
            if (m.find(row) != m.end())
                out += m[row];
        }
      return out;
    }
};
```
