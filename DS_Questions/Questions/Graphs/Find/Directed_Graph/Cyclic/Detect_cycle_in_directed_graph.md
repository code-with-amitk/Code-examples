**Cycle in Directed Graph**
- Approach-1: DFS+Backtracking (TLE:Time Limit Exceed)
  - [Logic](#l)
  - [Code](#c)
- [Approach-2: Topological Sort using Kahn's Algo](/DS_Questions/Data_Structures/Graphs/Toplogical_Sort/Detect_Cycle_using_Topological_Sort_Kahn_algo.md)

### Detect Cycle
Check is there any cycle in directed graph. Return true if present, else return false.
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

### Approach-1 (DFS+Backtracking) = TLE(Time Limit Exceed)
<a name=l1></a>
#### Logic
- _1._ Create a graph using `<unordered_map<int, unordered_set<int>>`
- _2._ Perform these steps for all nodes
  - _a._ Traverse to node
  - _b._ Check is there any cycle coming back to node (using [backtracking Template](/DS_Questions/Algorithms/Backtracking#tem))
```c
Take unordered_set<int> visited;
Insert present node in visited.
Check all neighbors of node.
	if neighbor is found in visited.	
		//cycle, return true
	else
		//insert neighbor in visited
All neighbors checked
erase present node from visited
```

#### Complexity
- **Time** O(E+V<sup>2</sup>) 
  - V=Vertices=Courses. E=Edge=Dependencies
  - Each vertex is atleast visited twice

<a name=c1></a>
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

    bool cycle(unMap& graph, int node) {    //Backtrack function
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
