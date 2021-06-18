## [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
- Graph contains n verteces. Given and an array edges where `edges[i] = [ai, bi]` indicates that there is an edge between ai and bi in the graph.
- Return the number of connected components in the graph.
```c
Example-1
  0 -- 1    3 -- 4
       |
       2
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
  
Example-2:
  0 -- 1 -- 2 -- 3 -- 4
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
```
