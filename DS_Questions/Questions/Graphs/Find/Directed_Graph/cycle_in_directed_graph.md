**Cycle in Directed Graph**
- Approach: DFS+Backtracking
  - [Logic]
  - [Code]

### Detect Cycle
- Check is there any cycle in directed graph. Return true if present, else return false.
```c
Example-1:    No cycle
  1 --> 2 --> 3
  |     |     |
  |    \/     |
   ---> 4 <---

Example-2:    cycle present
  1 --> 2 --> 3
  /\    |     |
  |    \/     |
   ---- 4 <---

Example-3:    cycle present
  1 --> 2 --> 3 --> 5 --> 6
  |    |     |
  |    \/     |
   ---> 4 <---      7 ---> 8
                    /\     |
                    |-------
```

### Approach (DFS+Backtracking)
- 

### Code
**C++**
```cpp
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using vecI = std::vector<int>;
using vecB = std::vector<bool>;
using vecVecI = std::vector<vecI>;
using unSet = std::unordered_set<int>;
using unMap = std::unordered_map<int, unSet>;

class Graph {
    unMap um;
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
        }
    }
    unMap& GetGraph(){
        return um;
    }
};

class Solution {
    unSet visited;

    bool cycle(unMap& graph, int node) {
        bool ret = false;
        visited.insert(node);
        auto it = graph.find(node);
        if (it != graph.end() && it->second.size()){
            //Check all neighbours of this node
            for (auto&i:it->second){
                if (ret)
                    return ret;
                if (visited.size()) {
                    if(visited.find(i) == visited.end())
                        ret = cycle(graph, i);
                    else 
                        ret = true;
                }
            }
        }
        visited.erase(node);
        return ret;
    }
public:
    bool findCycle(int n, vecVecI& edges){
        //Create Graph
        Graph g = Graph(edges);
        unMap graph = g.GetGraph();

        //Call DFS for all nodes
        for (auto&i:graph){
            //Only check if node has any neighbours
            if (i.second.size()) {
                if(cycle(graph, i.first))
                    return true;
            }
        }
        return false;
    }
};
int main(){
    int n = 4;
    vecVecI e = {{1,2},{4,1},{2,3},{2,4},{3,4}};
    //vecVecI e = {{1,2},{1,4},{2,3},{2,4},{3,4},{3,5},{5,6},{7,8},{8,7}};
    Solution s;
    std::cout << s.findCycle(n, e);
}
```
