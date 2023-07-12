**Detect Cycle using Topological Sort**
- **Approach-1, Kahn's Algo**
  - [Logic](#l)
  - [Code](#c)
  - [Complexity](#co)


### Detect Cycle using Topological Sort
Provided edge list and number of nodes.
```c
Example-1:
Input:  vector<vector<int>> edges = {{0,1},{1,2},{4,1},{2,3},{2,4},{3,4}}; ,  number of nodes = 5
Output:    No cycle
0 --> 1 --> 2 --> 3
      |     |     |
      |    \/     |
       ---> 4 <---

Example-2:    
Input:  vector<vector<int>> edges = {{0,1},{1,2},{4,1},{2,3},{2,4},{3,4}}; ,  number of nodes = 5
Output: cycle present
0 --> 1 --> 2 --> 3
      /\    |     |
      |    \/     |
       ---- 4 <---

Example-3:    cycle present
0 --> 1 --> 2 --> 3 --> 5 --> 6
      |    |     |
      |    \/    |
       ---> 4 <---      7 ---> 8
                        /\     |
                        |-------
```

#### Logic
- _1._ Create adjacency list using `unordered_map<int, vector<int>>`
```cpp
0 --> 1 --> 2 --> 3
      |     |     |
      |    \/     |
       ---> 4 <---

|0,<1>|1,<2,4>|2,<3,4>|3,<4>|
```
- _2._ Calculate indegree of all nodes. 
```c
What is indegree? Number of incoming edges to a node.
  node  indegree
  0     0
  1     1
  2     1
  3     1
  4     3
  
How to calculate indegree?  
  a. Take a vector<int> indegree(size=number_of_nodes, 0).
  b. Traverse thru adjacency list created above and increase indegree of neighbours
  node  outgoing_edge   indegree
  0       1             | 0 | 1 | 0 | 0 | 0 |
                          0   1   2   3   4    <nodes
  
  1       2,4           | 0 | 1 | 1 | 0 | 1 | 
                          0   1   2   3   4

  2       3,4           | 0 | 1 | 1 | 1 | 2 | 
                          0   1   2   3   4
  
  3       4             | 0 | 1 | 1 | 1 | 3 | 
                          0   1   2   3   4  
  
  4       -
```
- _3._ Traverse through graph. 
```c
  Find node whose indegree is 0.
  if (node found) { 
    reduce present node's indegree (ie make it -1) 
    reduce all neighbour's indegree by 1
  }
  else (node not found) { 
    There is cycle in graph 
  }
  - Repeat for all nodes in graph
```

<a name=c></a>
#### Code
```cpp
#include <vector>
#include <iostream>
#include <unordered_map>
using vecI = std::vector<int>;
using vecVecI = std::vector<vecI>;
using unMap = std::unordered_map<int, vecI>;
using unMapI = std::unordered_map<int, int>;

class Graph {
    std::unordered_map<int, vecI> graph;
    vecI indegree;
    int nodes;
    vecI fromNodes;
public:
    void addNode(int from, int to){
        auto it = graph.find(from);
        if (it != graph.end())
            it->second.push_back(to);
        else {
            vecI v;
            v.push_back(to);
            graph[from] = v;
        }
        fromNodes.push_back(from);
    }
    Graph(int n, vecVecI& v):nodes(n),indegree(n){
        for (auto&i: v){
            addNode(i[0], i[1]);
        }
    }
    unMap& GetGraph(){
        return graph;
    }
    vecI& GetIndegree(){
        for (auto&i:graph){
            for (auto&j:i.second){
                indegree[j]++;
            }
        }
        return indegree;
    }
};
class Solution {
public:
    bool findCycle(int n, vecVecI& edges){
        //Create Graph and find indegree
        Graph g = Graph(n, edges);
        unMap graph = g.GetGraph();
        vecI indegree = g.GetIndegree();

        int j = 0;
        for (int i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (!indegree[j])
                    break;
            }
          
            //No node found with indegree=0. It means cycle
            if (j == n)
                return false;

            //Reduce indegree of present node. Make it -1
            indegree[j]--;
          
            //Reduce indegree of neighbour nodes by 1
            auto it = graph.find(j);
            if (it != graph.end()) {
                for (auto& v : it->second) {
                    indegree[v]--;
                }
            }
        }
        return true;
    }
};

int main(){
    int n = 8;
    vecVecI e = {{0,1},{1,2},{1,4},{2,3},{2,4},{3,4},{3,5},{5,6},{7,8}};
    //int n = 5;
    //vecVecI e = {{0,1},{1,2},{4,1},{2,3},{2,4},{3,4}};
    Solution s;
    std::cout << s.findCycle(n, e);
}
```

<a name=co></a>
#### Complexity
- **Time:** O(V+E). V=vertices,E=Edges
  - [Why complexity is not O(VE), as it has 2 nested for loops?](/DS_Questions/Data_Structures/Graphs/Toplogical_Sort/Topological_sort_kahn_Algo.md)
