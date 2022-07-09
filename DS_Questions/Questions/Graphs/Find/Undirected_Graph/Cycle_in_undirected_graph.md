**Detect Cycle**
- **Approach-1, Marking Parent**
  - [Logic](#l)
  - [Complexity](#co)
  - [Code](#c)

### Detect cycle in Undirected Graph

### Approach-1
<a name=l></a>
#### Logic
- _1._ Create adjacency list representation of graph
```c
        1 -- 2
        |  /
        3 -- 4
unordered_map<int, unordered_set<int>>

|           |           |             |         |
| 1 | <2,3> | 2 | <1,3> | 3 | <1,2,4> | 4 | <3> |
|           |           |             |         |
```
- _2._ Take `unordered_set<int> visited`
- _3._ For every node, perform dfs and take parent = -1. Parent here represents previous node which calls this dfs function.
  - _Why parent?_ So that we donot travel back to same node and detect cycle.
```
int parent = -1;
for (auto&i:graph)
  dfs (i->first, parent)
```
- _4._ On reaching neighbour node, if its neighbour==parent continue. ie donot go back to same parent.

<a name=co></a>
#### Complexity
- **Time:** V:Vertices/Nodes, E:Edges/Neighbors
  - O(V+E). We traverse only once per node
- **Space:**
  - Storing graph: O(V+E)
  - visited: O(V)

<a name=c></a>
#### Code
```cpp
#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
using vecI = std::vector<int>;
using vecB = std::vector<bool>;
using vecVecI = std::vector<vecI>;
using us = std::unordered_set<int>;
using um = std::unordered_map<int, us>;

class graph{
    um g;
public:
    void addNode(int from, int to){
        auto it = g.find(from);
        if (it != g.end())
            it->second.insert(to);
        else{
            us u;
            u.insert(to);
            g[from] = u;
        }
    }
    graph(vecVecI& v){
        for(auto&i : v){
            addNode(i[0], i[1]);
            addNode(i[1], i[0]);
        }
    }
    um& GetGraph(){
        return g;
    }
};
class Solution{
    bool dfs (um& graph, us& visited, int node, int parent){
        visited.insert(node);

        //Traverse all neighbours of node
        auto it = graph.find(node);
        for (auto&neighbour:it->second){

            if (parent == neighbour)    //I have came from this direction donot move back
                continue;
            if (visited.find(neighbour) != visited.end())  //Neighbour not yet visited
                return true;
            if (true == dfs(graph, visited, neighbour, node))
                return true;
        }
        return false;
    }
public:
    bool hasCycle(vecVecI& edges){
        graph g(edges);
        um graph1 = g.GetGraph();
        std::cout << "tts";

        int parent = -1;
        us visited;

        for (auto&i:graph1){
            if (visited.find(i.first) != visited.end())
                continue;
            if (dfs (graph1, visited, i.first, parent) == true)
                return true;
        }
        return false;
    }
};
int main(){
    /*
        1 -- 2
        |  /
        3 -- 4
    */
   vecVecI edges = {{1,2},{1,3},{2,3},{3,4}};
   Solution s;
   std::cout << s.hasCycle(edges);
}
```
