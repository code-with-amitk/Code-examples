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

### Approach-1, All pairs, TLE O(V<sup>2</sup>E)
<a name=l></a>
#### Logic
- _1._ Create graph, Find all outgoing nodes from a particular node, as neighbours(store as string).
  - Create string with lesser node 1st then greater node.
```c
| "01" "03" | "01" "12" "13" | "12" | "03", "13" | "45" | "45" |
    0              1             2        3         4       5
```
- _2._ Check every pair of nodes and insert neighbours in `unordered_set<string>` and note length of largest set.
  - Inserted into unordered_set bcoz not to take duplicate neighbours twice
```c
                    unordered_set             len
node=0, node=1      "01" "03" "12" "13"         4
node=0, node=2      "01" "03" "12"              3
node=0, node=3      "01" "03" "13"              3
..
```
- _3._ greatest len is the answer.

<a name=co></a>
#### Complexity
- **Time:** O(E) + O(V<sup>2</sup>E) = O(V<sup>2</sup>E)
  - O(E): Creating Graph
  - O(V<sup>2</sup>E): Finding Max network path between all pairs, we run 2 for loops then find edges of every node.

<a name=c></a>
#### Code
```cpp
using vecI = std::vector<int>;
using vecS = std::vector<std::string>;
using vecVecS = std::vector<vecS>;
using vecVecI = std::vector<vecI>;
using vecB = std::vector<bool>;
using String = std::string;
using USet = std::unordered_set<String>;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    
        //Create Graph
        vecVecS graph(n);
        for (int i=0;i<roads.size();++i) {
            int from = std::min(roads[i][0], roads[i][1]);
            int to = std::max(roads[i][0], roads[i][1]);
            std::stringstream ss;
            ss << from << to;
            String s = ss.str();
            graph[to].push_back(s);
            graph[from].push_back(s);
        }

        int out = -1;
        //Traverse every pair of nodes and check network path
        //between those nodes
        for (int i=0;i<n-1;++i){
            for (int j=i+1;j<n;++j){
                USet us;
                for(auto it = graph[i].begin(); it!=graph[i].end();++it)
                    us.insert(*it);
                for(auto it = graph[j].begin(); it!=graph[j].end();++it)
                    us.insert(*it);
                out = std::max(out, int(us.size()));
            }
        }
        return out;        
    }
};
```
