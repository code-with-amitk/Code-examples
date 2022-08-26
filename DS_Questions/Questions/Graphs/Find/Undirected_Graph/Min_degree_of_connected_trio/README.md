**Minimum degree of connected Trio**
- Approach-1, 
  - [Logic](#l)

## Minimum Degree of a Connected Trio in a Graph
- Given number of nodes & edges between them, find min degree of connected trio or -1 if the graph has no connected trios.
- _Connected trio:_ is a set of three nodes where there is an edge between every pair of them.
- _Degree of a connected trio:_ is the number of edges where one endpoint is in the trio, and the other is not.
```c
Example-1:
Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
Output: 3
Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded in the figure above.

Example-2:
Input: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
Output: 0
Explanation: There are exactly three trios:
1) [1,4,3] with degree 0.
2) [2,5,6] with degree 2.
3) [5,6,7] with degree 2.
```
<img src=connected_trio.png width=800 />

### Approach-1, Find Trio and their degree
<a name=l></a>
#### Logic
```c
4 -- 1     2 -- 5
 \  /      |  / |
  3        6 -- 7
```
- _1._ Create graph using `unordered_map<int, unordered_set<int>>`. While creating graph note degree of node
```c
|        |          |          |          |            |            |          |
|1, <3,4>| 2, <5,6> | 3, <1,4> | 4, <1,3> | 5, <2,6,7> | 6, <2,5,7> | 7, <5,6> |
Graph

degree
| 2 | 2 | 2 | 2 | 3 | 3 | 2 | 
  1   2   3   4   5   6   7   < Node
```
- _2._ Iterate every node of graph and check if present node is neighbour's neighbour? if yes note the trio in `unordered_map<sum,<nodes in trio>>`
```c
node1 neighbours
 if 3's neighbour == node1. Yes //trio
 
 trio <8, <1,3,4>>
```
- _3._ Calculate in how many trios node is part of
  - if node is part of 2 trios, reduce degree by 3
  - if node is part of 1 trios, reduce degree by 2
- _4._ Calculate sum of degrees of nodes which are part of trio


#### Code
```cpp
#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
using vecI = std::vector<int>;
using vecB = std::vector<bool>;
using vecVecI = std::vector<vecI>;
using unSet = std::unordered_set<int>;
using unMap = std::unordered_map<int, unSet>;
using unMTuple = std::unordered_map<int, std::tuple<int,int,int>>;

class Graph {
    unMap um;
    unSet us;
public:
    void addNode(int from, int to){
        auto it = um.find(from);
        if (it != um.end())
            it->second.insert(to);
        else {
            unSet us;
            us.insert(to);
            um[from] = us;
        }
    }
    Graph(vecVecI& v){
        for (auto&i: v){
            addNode(i[0], i[1]);
            addNode(i[1], i[0]);
            us.insert(i[0]);
            us.insert(i[1]);
        }
    }
    unMap& GetGraph(){
        return um;
    }
    unSet& GetNodes(){
        return us;
    }
};

class Solution {
public:
    int minTrioDegree(int n, vecVecI& edges) {
        //Create Graph
        Graph g = Graph(edges);
        unMap graph = g.GetGraph();
        unSet nodes = g.GetNodes();

        //Count Degree
        std::unordered_map<int,int> degree;
        for(auto&i:graph)
            degree[i.first] =  i.second.size();

        //Create set of all nodes in trio
        unMTuple uTupTrios;

        //Check Trio
        for (auto&i:graph){
          for(auto&j:i.second){
            for (auto&k: graph.find(j)->second) {
              if (i.second.find(k) != i.second.end()){
                //Found Trio
                std::cout << i.first <<","<< j << "," << k << "\n";
                uTupTrios[i.first+j+k] = std::make_tuple(i.first,j,k);
              }
            }
          }
        }//for1

        int count = 0;
        if (!uTupTrios.size())
            return -1;
        
        std::unordered_map<int,int> nodeInTrio;
        for (auto&i:uTupTrios){
            int a,b,c;
            std::tie(a,b,c) = i.second;
            nodeInTrio[a]++;
            nodeInTrio[b]++;
            nodeInTrio[c]++;
        }

        for (auto&i:nodeInTrio){
            degree[i.first] -= i.second+1;
            count += degree[i.first];
        }

        return count;
    }
};
int main(){
    // int n = 6;
    // vecVecI e = {{1,2},{1,3},{1,4},{2,3},{2,5},{3,6}};
    // int n = 7;
    // vecVecI e = {{1,3},{4,1},{4,3},{2,5},{5,6},{6,7},{7,5},{2,6}};
    // int n = 3;
    // vecVecI e = {{3,1},{1,2}};
    int n = 6;
    vecVecI e = {{6,5},{4,3},{5,1},{1,4},{2,3},{4,5},{2,6},{1,3}};
    Solution s;
    std::cout << "count=" << s.minTrioDegree(n, e);
}
```

#### Complexity
**Time:** O(n<sup>3</sup>). 3 for loops
