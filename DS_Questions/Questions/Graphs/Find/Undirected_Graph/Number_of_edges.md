**Count Number of Edges in Graph**
- [Logic](#l)
- [Code](#c)

### [Count Number of Edges in Graph](https://www.geeksforgeeks.org/count-number-edges-undirected-graph/)
- Given adjacency list representation of undirected graph. Count the number of edges in the undirected graph.
- Expected time complexity : O(V)
```c
Total Edges = 5
3 
|  \
0----1
|  /
2
```

<a name=l></a>
### Logic
- Traverse all vertices, compute sum of sizes of their adjacency lists, and finally returns sum/2
- if sum is odd return (sum/2 + 1)
- if sum is even return sum/2

<a name=c></a>
### Code
```cpp
#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>
#include <stack>
#include <set>
using vecI = std::vector<int>;
using vecVecI = std::vector<vecI>;
using ListI = std::list<int>;

class graph {
    std::unordered_map<int, ListI> g;
public:
    void add_node(int from, int to){
        ListI l;
        auto it = g.find(from);
        if (it != g.end())  //Node exists
            l = it->second;

        l.push_back(to);
        g[from] = l;
    }
    graph(vecVecI& v){
        for (auto&i:v){
            add_node(i[0],i[1]);
        }
    }
    std::unordered_map<int, ListI>& GetGraph(){
        return g;
    }
};

class Solution {
public:
    int count_edges(vecVecI& v){
        //Create Adjacency List
        graph g(v);
        std::unordered_map<int, ListI> graph = g.GetGraph();
       
        int count=0;
        //Traverse all neighbours of all nodes
        for (auto&i:graph){
            auto list = i.second;
            count += list.size();
       }
       return count%2 ? (count/2)+1 : count/2;
    }
};

int main(){
    int n = 4;
    vecVecI v = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,0},{2,1},{3,0},{3,1}};
    Solution s;
    std::cout << s.count_edges(v);
}
```
