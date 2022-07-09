**Graph Valid Tree**
- [Approach-1](#a1)
  - [Logic](#l)
  - [Complexity](#co)
  - [Code](#c)

### [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)
- You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where `edges[i] = [ai, bi]` indicates that there is an undirected edge between nodes ai and bi in the graph.
- Return true if the edges of the given graph make up a valid tree, and false otherwise.
```c
    0           //Valid
  / | \
 1  2  3
 |
 4 
      
    0           //InValid
  / | \
 1--2  3
      
 4
  \
   5
```

<a name=a1></a>
### Appproach
This can be seen as undirected graph, just we need to find 2 things.
- _1._ Find Graph has any Disjoint set or not.
  - if graph has disjoint sets then its not valid tree
- _2._ Find whether graph has cycle or not.
  - if graph has cycle then also its also not a valid tree.

<a name=l></a>
#### Logic
- _1._ Create graph as `unordered_map<int, unordered_set<int>>`
```c
  |0, <1,2,3>|1, <0,2>|2, <1,0>|3, <0>|4, <5>|5, <4>|
```
- _2._ [Find whether graph has any disjoint set or not](/DS_Questions/Data_Structures/Graphs/ConnectedComponents_DisjointSet/)
- _3._ [Find undirected graph has cycle or not](/DS_Questions/Questions/Graphs/Find/Undirected_Graph/Cycle_in_undirected_graph.md)

<a name=co></a>
#### Complexity
- **Time:** V:Vertices/nodes. E:Edges/Neighbors
  - Creating Graph: O(V)
  - Finding disjoint set: O(V)
  - Finding cycle in directed Graph
- **Space**
  - Store graph: O(VE)

<a name=c></a>
#### Code
```cpp
using us = std::unordered_set<int>;
using vecI = std::vector<int>;
using vecVecI = std::vector<vecI>;
using unMap = std::unordered_map<int, vecI>;

class Graph {
    unMap graph;
    void addNode(int from, int to){
        auto it = graph.find(from);
        if (it != graph.end())
            it->second.push_back(to);
        else {
            vecI v;
            v.push_back(to);
            graph[from] = v;
        }
    }
public:
    Graph(vecVecI& edges){
        for (auto&i:edges){
            addNode(i[0],i[1]);
            addNode(i[1],i[0]);
        }
    }
    unMap& GetGraph(){
        return graph;
    }
};

class Solution {
    bool dfs (unMap& graph, std::unordered_set<int>& visited, int node, int parent){
        visited.insert(node);
        bool ret = false;

        //Traverse all neighbours of node
        auto it = graph.find(node);
        for (auto&neighbour:it->second){

            if (parent == neighbour)    //I have came from this direction donot move back
                continue;

            if (visited.find(neighbour) != visited.end())     //Neighbour not yet visited
                return true;

            if (true == dfs(graph, visited, neighbour, node))
                return true;
        }
        return false;
    } 
    bool disjointSets (int n, unMap& graph){
        std::stack<int> s;
        s.push(0);
        std::unordered_set<int> visited;
        while (!s.empty()){
            int u = s.top(); s.pop();
            visited.insert(u);

            auto it = graph.find(u);
            if (it != graph.end()){
                for (auto&i:it->second){
                    if (visited.find(i) == visited.end())
                        s.push(i);
                }
            }
        }
        return visited.size() == n ? false : true;
    }    
public:
    bool validTree(int n, vecVecI& edges) {
        //Create Graph
        Graph g(edges);
        unMap graph = g.GetGraph();
        
        if (disjointSets(n, graph))
            return false;
        std::unordered_set<int> visited;

        for (auto&i:graph){
            if (visited.find(i.first) != visited.end())
                continue;
            if (true == dfs (graph, visited, i.first, -1))
                return false;
        }
        return true;        
    }
};
```
