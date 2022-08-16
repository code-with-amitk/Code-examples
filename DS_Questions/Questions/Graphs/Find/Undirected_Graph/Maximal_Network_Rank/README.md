**Maximal Network Rank**
- **Approach, TLE, Find all edges, O(V<sup>2</sup>E)**
  - [Logic](#l)
  - [Code](#c)
  - [Complexity](#co)

## [Maximal Network Rank](https://leetcode.com/problems/maximal-network-rank/)
- There is an infrastructure of n cities with some number of roads connecting these cities. Each `roads[i] = [ai, bi]` indicates that there is a bidirectional road between cities ai and bi.
- The network rank of two different cities is defined as the total number of directly connected roads to either city. 
- If a road is directly connected to both cities, **it is only counted once.**
- The maximal network rank of the infrastructure is the maximum network rank of **all pairs of different cities**.
- Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
- Examples
```c
0 -- 1 -- 2
 \   |
   \ |
     3   4 -- 5
Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3],[4,5]]
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
    - Of Node=0 & Node=1: 4    //Common path(01) is only taken once
    - Of Node=0 & Node=2: 3
    - Of Node=0 & Node=3: 3    //Common path(03) is only taken once
    - Of Node=0 & Node=4: 3
    - Of Node=0 & Node=5: 3     //Path of disconnected Nodes is also counted
    
    //01 already counted
    - Of Node=1 & Node=2: 3    //Common path(12) is only taken once
    - Of Node=1 & Node=3: 4    //Common path(13) is only taken once
    - Of Node=1 & Node=4: 3    //2 for node=0, 1 for node=4
    - Of Node=1 & Node=5: 3    //2 for node=0, 1 for node=5
    
```

### Approach-1, O(V<sup>2</sup>)
<a name=l></a>
#### Logic
- _1._ Create graph, All outgoing nodes from a particular node, as neighbours.
```c
| <1,3> | <0,2,3> | <1> | <0,1> | <5> | <4> |
    0        1        2     3      4     5
```
- _2._ Find maximal network rank for every pair of nodes and keep record of maximal rank.
```c
01  =>  (number_of_neighbours_of_0 + number_of_neighbours_of_1) - 1     //Since 0 and 1 are connected
02  =>  (number_of_neighbours_of_0 + number_of_neighbours_of_2)         //Since 0 and 2 are not connected
```
- _3._ Greatest rank is the answer.

<a name=co></a>
#### Complexity
- **Time:** O(E) + O(V<sup>2</sup>) = O(V<sup>2</sup>)
  - O(E): Creating Graph
  - O(V<sup>2</sup>E): Finding Max network path between all pairs, we run 2 for loops.

<a name=c></a>
#### Code
```cpp
using vecI = std::vector<int>;
using vecS = std::vector<std::string>;
using vecVecS = std::vector<vecS>;
using vecVecI = std::vector<vecI>;
using vecB = std::vector<bool>;
using String = std::string;
using USet = std::unordered_set<int>;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //Create Graph
        std::vector<USet> graph(n);
        for (int i=0;i<roads.size();++i) {
            int to = roads[i][0];
            int from = roads[i][1];
            graph[to].insert(from);
            graph[from].insert(to);
        }

        int out = -1;
        for (int i=0;i<n-1;++i){
            for (int j=i+1;j<n;++j){
                //Find Rank of all pair
                //if two nodes are connected  (01)
                  //Rank = neighbour_count_of_0 + neighbour_count_of_1 - 1
                //if two nodes are not connected  (02)
                  //Rank = neighbour_count_of_0 + neighbour_count_of_2
                int rank = graph[i].size() + graph[j].size();

                //if there is common road, subtract 1
                if (graph[i].find(j) != graph[i].end())
                    --rank;

                out = std::max(out, rank);
            }
        }
        return out;        
    }
};
```
