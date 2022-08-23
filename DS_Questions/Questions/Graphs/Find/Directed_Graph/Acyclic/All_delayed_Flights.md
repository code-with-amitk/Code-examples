**All Delayed Flights**
- [Logic](#l)
- [Code](#c)

### All delayed Flights
Given flights from src to dst. Flights are `1->2, 2->3, 1->4, 4->3`.
```c
        1 ----> 2 ----> 3
        /\              /\
        |------ 4 ------|
```
- Find all delayed flights, if provided some flights are delayed. delayed={1,2}
```c
Flight 1,2 are delayed.
Since 3 depends on 2, so 3 will also be delayed.
All Delayed flights = {1,2,3}
```

<a name=l></a>
### Logic
- _1._ Create [graph hashmap of linked-lists](/DS_Questions/Data_Structures/Graphs/Directed_Undirected#d1)
```c
           2       3               1,3
graph | 1, /\ | 2, /\ | 3, <> | 4, /\ |
```
- _2._ For every delayed node, perform DFS(using stack). and insert reached nodes in set(to avoid duplicates)
  - We know delayed={1,2}
```c
   DFS for              unordered_set
        1               1,2,3
        2               2,3
                        output=> 1,2,3
```

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

/*
        1 ----> 2 ----> 3
        /\              /\
        |------ 4 ------|

           2    3    1,3
        |1,/\|2,/\|4,/\|
*/
class graph{
    std::unordered_map<int, ListI> um;
public:
    void addNode(int from, int to){
        ListI l;
        auto it = um.find(from);
        if (it != um.end())
            l = it->second;
        
        l.push_back(to);
        um[from] = l;
    }
    std::unordered_map<int, ListI>& GetGraph(){
        return um;
    }
};
class Solution {
public:
    vecI find_all_delayed(vecI from, vecI to, int no_of_stations, vecI delayed){
        //Set having all delayed flights
        std::set<int> sAllDelayed;

        //Create the Graph, adjacency list
        graph g;
        for (int i=0;i<no_of_stations;++i){
            g.addNode(from[i], to[i]);
        }
        std::unordered_map<int, ListI>& adjList = g.GetGraph();

        //Perform DFS
        std::stack<int> s;
        for (auto&i:delayed){
            s.push(i);
            while(s.empty() != 1){
                int u = s.top();
                s.pop();
                sAllDelayed.insert(u);

                //Traverse all connected neighbours of node
                for (auto&j:adjList[u]){
                    if (sAllDelayed.find(j) == sAllDelayed.end())
                        s.push(j);
                }
            }
        }

        vecI out;
        //Convert set to vector
        for (auto&i:sAllDelayed)
            out.push_back(i);
        return out;
    }
};

int main() {
    /*
        1 ----> 2 ----> 3
        /\              /\
        |------ 4 ------|
    */
   vecI from = {1,2,4,4};
   vecI to = {2,3,1,3};
   vecI delayed = {1,2};
   int number_of_stations = 4;
    Solution s;
    vecI out = s.find_all_delayed(from, to, number_of_stations, delayed);
    for(auto&i:out)
        std::cout << i <<",";
}
```
