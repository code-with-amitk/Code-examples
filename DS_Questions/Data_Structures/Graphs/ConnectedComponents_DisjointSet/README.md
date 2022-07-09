**Disjoint Set**
- [Finding Weather Graph has Disjoint set or not](#fds)

## Disjoint Set

<a name=fds></a>
#### Finding Weather Graph has Disjoint set or not
- _1._ Take `unordered_set<int> visited` (size=0)
- _2._ Start from Node=0, Perform DFS. Keep inserting nodes into visited array as you reach them
- _3._ After DFS
```c
  if (sizeof(visited) == number_of_node)
    no Disjoint set
  else
    Disjoint set present
```

##### Code
```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using us = std::unordered_set<int>;
using vecI = std::vector<int>;
using vecVecI = std::vector<vecI>;
using unMap = std::unordered_map<int, vecI>;

class Solution {
public:
    bool AreDisjointSets (int n, vecVecI& edges){
        //Create Graph
        Graph g(edges);
        unMap graph = g.GetGraph();
    
        //Find connected components
        if (disjointSets(n, graph))
            return true;
            
        return false;
    }
private:
    bool disjointSets (int n, unMap& graph){
        std::stack<int> s;
        s.insert(0);
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
};

int main(){
    // int n = 5; vecVecI edges = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    int n = 5; vecVecI edges = {{0,1},{0,2},{0,3},{1,4},{3,4}};
    Solution s;
    std::cout << s.AreDisjointSets(n ,edges);
}
```
