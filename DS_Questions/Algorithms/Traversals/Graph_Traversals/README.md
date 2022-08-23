**Traversals**
- **Single Source Shortest Path**
  - 1. Dijkstra Algo. For +ve(non-negative) weights only
    - [1a. Using cost, visited Array](#ev)
    - [1b. ]
  - 2. Bellman Ford, for +ve,-ve weights



## Single Source Shortest Path
### 1. Dijkstra Algo
<a name=ev></a>
#### 1a. Using cost, visited array. O(EV)
Find shortest path from node(0) to all other nodes in graph.
```c
                                 [0] --10--[1]--20-- [2]   
                                   \50     |30      /40
                                    \      |       /
                                          [3]
Adjacency List: unordered_map<int, unordered_map<int,int>> graph;

  |            |                 |             |                  |
  |0 |1,10|3,50|1 |0,10|2,20|3,30| 2 |1,20|3,40| 3 |0,50|1,30|2,40|
  |            |                 |             |                  |

Answer:
Vertex  Distance from Source(node=0)
 0              0
 1              10
 2              30
 3              40
```
#### Logic
- Step-1. Take cost, visited array and initialize.
```c
//NOTE: This array always represents cost to reach nodes from source node(node=0)
 cost | inf | inf | inf | inf |
         0    1      2     3      <-Nodes
         
bool visited | 0 | 0 | 0 | 0 |  //No nodes are visited presently
               0   1   2   3     <-Nodes
```
- Step-2. Start from node(0). Fill cost of directly connected nodes.
```c
cost | 0 | inf | inf | inf |    //From node=0, node=0 can be reached in cost=0
visited | 1 | 0 | 0 | 0 |       //Mark node=0 as visited
```
- Step-3. Present node=0. Check all connected nodes of present node. ie if you are sitting on Node what other nodes you can see and at what distance? Update cost.
```c
  cost | 0 | 10 | inf | 50 |    
         0   1     2    3
         
  visited |1|0|0|0|
```
- Step-4. Move to least cost neighbour of present node. if present node=0, least cost neighbour=node1.
  - Mark node as visited   `  visited |1|1|0|0|`
  - Perform step-3. ie if I am sitting on node=1, which all nodes can I see and in what distance?
```c
Sitting on Node=1. 
  if ((neighbour is unvisited) { 
    if (assumed cost of reaching neighbour(in vecCost) >  Cost to reach myself from node=0(10) + cost to reach neighbour from me(30))
      update neighbour_cost
      //push (neighbour-cost, neighbour) in minHeap
  }
  
  if (Assumed cost to reach node=2 (inf) > Cost to reach myself from start node + cost to reach 2 from me)
    update cost

  cost | 0 | 10 | 10+20 | 50 |
         0   1     2      3
         
  if (Assumed cost to reach node=3 (inf) > Cost to reach myself from start node + cost to reach 3 from me)
    update cost
         
  cost | 0 | 10 | 10+20 | 10+30 |
         0   1     2      3
```
#### Complexity
- **Time:** O(VE)
  - Traverse through all node, ie Vertices=V. O(V)
  - Reach every edge from every Node. Edges=E. O(E)
- **Space:** O(1). if stored graph is provided
#### Code
```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using VecI = vector<int>;
using UnMapI = unordered_map<int, int>;

class Solution {
public:
    VecI dijkstra(int nNodes, unordered_map<int, UnMapI>& graph, int start_node){
        int min = INT_MAX, go_to_neighbour = -1, node = start_node;

        //Take visited array, Mark all nodes unvisited
        vector<bool> vecVisited(nNodes, false);

        //Take cost array, Mark all nodes infinity
        //NOTE: This array represents cost of reaching all nodes from start_node
        VecI vecCost(nNodes, INT_MAX);

        vecCost[node] = 0;          //Start at start_node

        //Visit all nodes in graph
        for (int i=0; i<nNodes; ++i) {

            vecVisited[node] = true;    //Mark present node as visited

            //Check all connected neighbours and update cost
            for (auto it=graph[node].begin(); it != graph[node].end(); ++it){
               
                int neighbour = it->first;
                int neighbour_reach_cost = it->second;

                //Check only unvisited Neighbours
                if (vecVisited[neighbour] == false) {

                    //if (present cost of reaching neighbour >
                    //      cost of reaching neighbour from me +
                    //      cost of reaching me from start_node)
                    if (vecCost[neighbour] > neighbour_reach_cost + vecCost[node])
                        vecCost[neighbour] = neighbour_reach_cost + vecCost[node];

                    if (min > neighbour_reach_cost) {
                        min = neighbour_reach_cost;
                        go_to_neighbour = neighbour;
                    }
                }
            }
            node = go_to_neighbour;
        }
        return vecCost;
    }
};

int main() {
    unordered_map<int, UnMapI> umGraph;

    //Create Undirected, Weighted Graph
    umGraph[0].insert(make_pair(1,10));
    umGraph[0].insert(make_pair(3,50));

    umGraph[1].insert(make_pair(3,30));
    umGraph[1].insert(make_pair(2,20));
    umGraph[1].insert(make_pair(0,10));

    umGraph[2].insert(make_pair(3,40));
    umGraph[2].insert(make_pair(1,20));

    Solution s;
    VecI out = s.dijkstra(4, umGraph, 0);
}

# ./a.out

Vertex           Distance/Cost from Source
0                0
1                50
2                90
3                80
```

