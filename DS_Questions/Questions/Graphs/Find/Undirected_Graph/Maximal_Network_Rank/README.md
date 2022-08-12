**Maximal Network Rank**
- Approach
  - [Logic](#l)
  - [Code](#c)
  - [Complexity](#co)

## [Maximal Network Rank](https://leetcode.com/problems/maximal-network-rank/)
- There is an infrastructure of n cities with some number of roads connecting these cities. Each `roads[i] = [ai, bi]` indicates that there is a bidirectional road between cities ai and bi.
- The network rank of two different cities is defined as the total number of directly connected roads to either city. 
- If a road is directly connected to both cities, **it is only counted once.**
- The maximal network rank of the infrastructure is the maximum network rank of **all pairs** of different cities.
- Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
- Examples
```c
0 -- 1 -- 2
 \   |
   \ |
     3   4 -- 5
Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3],[5,6]]
Output: 4
Explanation:
  - Roads from:
    - 0: 01, 03     => 2
    - 1: 01, 12, 13 => 3
    - 2: 12         => 1
    - 3: 03, 13     => 2
    - 4: 45         => 1
    - 5: 45         => 1
  - Network Paths:
    - Of Node=0 & Node=1: 4    //Since Common path(01) is only taken once
    - Of Node=0 & Node=2: 3
    - Of Node=0 & Node=3: 3    //Since Common path(03) is only taken once
    - Of Node=0 & Node=4: 3
    - Of Node=0 & Node=5: 3     //Path of disconnected Nodes is also counted
    
    - Of Node=1 & Node=2: 3    //Since Common path(12) is only taken once
    - Of Node=1 & Node=3: 4    //Since Common path(13) is only taken once
    
    - Of Node=2 & Node=3: 3
```
