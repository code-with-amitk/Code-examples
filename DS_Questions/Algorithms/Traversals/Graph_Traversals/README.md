**Traversals**
- **Single Source Shortest Path**
  - 1. Dijkstra Algo. For +ve(non-negative) weights only
    - [1a. Using cost, visited Array. O(EV)](#ev)
    - [1b. Using minHeap, Adjacency Matrix. O(ElogV)](#am)
    - [1c. Using minHeap. Adjacency List. O(ElogV)](#al)
  - 2. Bellman Ford, for +ve,-ve weights



# Single Source Shortest Path
<a name=ev></a>
## 1a. Dijkstra Algo Using cost, visited array. O(EV)
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

<a name=am></a>
## 1b. Dijkstra Algo using MinHeap, Adjacency Matrix
Task: Find Minimum distance of every node from Node=0.
```cpp
                                 [0] --10--[1]--20-- [2]   
                                   \50     |30      /40
                                    \      |       /
                                          [3]
Adjacency Matrix:
    0   1   2   3
0   0  10   0  50
1  10  0   20  30
2   0  20   0  40
3  50  30  40   0

Adjacency List: unordered_map<int, unordered_map<int,int>> graph;
  |            |                 |             |                  |
  |0 |1,10|3,50|1 |0,10|2,20|3,30| 2 |1,20|3,40| 3 |0,50|1,30|2,40|
  |            |                 |             |                  |
  
Answer:
Node  Cost
0     0
1     10
2     30
3     40
```
#### Logic(very simple) O(ElogV)
- Step-1. Take cost, visited array, `minHeap<key=cost, value=node>` and initialize.
```c
//NOTE: This array always represents cost to reach nodes from source node(node=0)
 cost | inf | inf | inf | inf |
         0    1      2     3      <-Nodes
         
bool visited | 0 | 0 | 0 | 0 |  //No nodes are visited presently
               0   1   2   3     <-Nodes

    |       |
    | |0|0| |  minHeap = priority_queue<cost,node>    //push(0,0) on Heap. Cost of reaching 0 is 0
    |       |

```
- Step-2. Start from node(0). Fill cost of directly connected nodes.
```c
cost | 0 | inf | inf | inf |    //From node=0, node=0 can be reached in cost=0
visited | 1 | 0 | 0 | 0 |       //Mark node=0 as visited
```
- Step-3. Repeat until minHeap is not empty:
  - *4a.* pop top. node=top. Mark node as visited.
  - *4b.* Push all connected unvisited neighbours of popped node into minHeap
```c++
  if ((neighbour is unvisited) { 
    if (assumed cost of reaching neighbour(in vecCost) >  Cost to reach myself from node=0(10) + cost to reach neighbour from me(30))
      update neighbour_cost
      //push (neighbour-cost, neighbour) in minHeap
  }      
```
#### Example Run
```c++
                [0]-10-[1]-20-[2]
                  \     |    /
                   \50  |30 /40
                    \   |  /
                       [3]
v
      0   1   2   3
  0   0   10  0   50    //Node 0 is connected to 1(cost=10), connected to 3(cost=50)
  1   10  0   20  30
  2   0   20  0   40
  3   50  30  40  0
                       
Operation                     minHeap<cost,node>        visited           cost          
                                                       |0|0|0|0|  |INF|INF|INF|INF|
cost[0]=0                                                         |0  |INF|INF|INF|
push(0,0)                            0,0         
pop top minHeap                     node=0
Mark poped node visited                                |1|0|0|0|
-----------------------------------------------------------------------------------
Calculate cost of reaching unvisited neighbours of popped node
 if(cost[1] > edge-cost + src-node-cost cost[0]){ //neighbour=1
    INF         10          0
    cost[1] = 10;                                                  |0  |10|INF|INF|   //Node-1 can be reached with cost=10 from Node-0
  }  
  push <cost, node>                <10, 1>

 if(cost[3] > edge-cost + src-node-cost cost[0]){ //neighbour=3
    INF         50          0
    cost[3] = 50;                                                  |0  |10|INF|50|   //Node-3 can be reached with cost=50 from Node-0
  }
  push <cost, node>                <10, 1>
                                   <50, 3>
-------------------------------------------------------------------------------------                                   
pop top minHeap, key=cost          node = 1
Mark poped node visited                                 |1|1|0|0|
Calculate cost of reaching unvisited neighbours of popped node
  neighbour=0   //visited discarded
  
 if(cost[2] > edge-cost + src-node-cost cost[1]){ //neighbour=2
    INF         20          10
    cost[2] = 30;                                                  |0  |10|30|50|
  }  
  push <cost, node>                 <30, 2>
                                    <50, 3>  
  neighbour=3    
 if(cost[3] > edge-cost + src-node-cost cost[1]){ //neighbour=2
    50         30          10
    cost[3] = 40;                                                  |0  |10|40|50|
  }  
  push <cost, node>                 <30, 2>
                                    <40, 3>
                                    <50, 3>
-------------------------------------------------------------------------------------   
pop top minHeap, key=cost          node = 2
Mark poped node visited                                 |1|1|1|0|
Calculate cost of reaching unvisited neighbours of popped node
  neighbour=1   //visited discarded
  
 if(cost[3] > edge-cost + src-node-cost cost[1]){ //neighbour=3
    50         40          30
    //not changed                                                  |0  |10|30|50|
    //not pushed
  }  
                                    <40, 3>
                                    <50, 3>
-------------------------------------------------------------------------------------   
pop top minHeap, key=cost          node = 3
Mark poped node visited                                 |1|1|1|1|
Calculate cost of reaching unvisited neighbours of popped node
  neighbour=0   //visited discarded
  neighbour=1   //visited discarded
  neighbour=2   //visited discarded                               |0  |10|30|50|
                                    <50, 3>
-------------------------------------------------------------------------------------   
pop top minHeap, key=cost          node = 3
Mark poped node visited                                 |1|1|1|1|
Calculate cost of reaching unvisited neighbours of popped node
  neighbour=0   //visited discarded
  neighbour=1   //visited discarded
  neighbour=2   //visited discarded                               |0  |10|30|50|  
```
<a name=co></a>
#### Code
```c++
#include<iostream>
#include<vector>
#include<queue>         //priority_queue

                //<cost, node> bcoz need to be sorted using cost
typedef std::pair<int, int> mypair;

std::priority_queue<mypair, std::vector<mypair>, std::greater<mypair>> minHeap;

void dijkstra_sp(std::vector<std::vector<int> > v){
  int iSize = v.size();
  
  //Take visited array, Mark all nodes unvisited
  std::vector<bool> iVisited(iSize, 0);
  
  //Take cost array, Mark all nodes infinity
  //NOTE: This array represents cost of reaching all nodes from start_node
  std::vector<int> iCost(iSize, INT32_MAX);

  iCost[0] = 0;   //Starting at node=0. Cost is 0

  //To reach node=0, cost=0
  minHeap.push(mypair(0,0));

  while (!minHeap.empty()) {
    int node = minHeap.top().second;
    minHeap.pop();

    iVisited[node] = true;

    //Check all connected neighbours and update cost
    for(int i=0;i<v.size(); ++i){
    
      //Check only unvisited Neighbours
      if(v[node][i] && iVisited[i]==false){
      
        //if (present cost of reaching neighbour >
        //      cost of reaching neighbour from me +
        //      cost of reaching me from start_node)  
        if (iCost[i] > v[node][i] + iCost[node]) {
          iCost[i] = v[node][i] + iCost[node];    //Update cost of reaching neighbour from start node
          minHeap.push (mypair(v[node][i],i));    //Push all unvisited Neighbours into minHeap
        }
      }
    }
  }

  std::cout<<"Node\tCost\n";
  for(int i=0;i<v.size();++i)
    std::cout<<i<<"\t"<<iCost[i]<<"\n";
}

int main(){
  std::vector<std::vector<int>> v = {
    {0,10,0,50},
    {10,0,20,30},
    {0,20,0,40},
    {50,30,40,0}
  };
  dijkstra_sp(v);
}
# ./a.out
Node	Cost
0	    0
1	    10
2	    30
3	    40
```

<a name=al></a>
### 1b2. Dijstra's using minHeap, Adjacency List
#### Code
```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
using VecI = vector<int>;
using VecVecI = vector<VecI>;
using UsI = unordered_set<int>;

                //cost, node
using mpair = pair<int, int>;

class Solution {
    priority_queue <mpair, vector<mpair>, greater<mpair>> minHeap;
    unordered_map<int/*src*/, unordered_map<int/*dst*/, int/*cost*/>> graph;

    void create_weighted_graph(int cities, VecVecI& flights) {
        for (int i=0;i<flights.size();++i) {
            int src = flights[i][0];
            int dst = flights[i][1];
            int cost = flights[i][2];
            graph[src].insert(make_pair(dst,cost));
        }
    }

public:
    int FindShortestPath(int n, VecVecI& flights, int start) {
        //Create a Weighted DAG
        create_weighted_graph(n, flights);
        
        //Take visited array, Mark all as unvisited
        vector<bool> vecVisited(n, false);

        //Cost of reaching all nodes from start is infinity
        vector<int> vecCost(n, INT_MAX);

        //There is no outgoing path from start
        if (graph.find(start) == graph.end())
            return -1;

        vecVisited[start] = true;
        vecCost[start] = 0;

        //Cost of reaching start node=0
        minHeap.push(make_pair(start, 0));

        while (minHeap.empty() != 1) {
            mpair p = minHeap.top();
            int cost = p.first;
            int node = p.second;
            minHeap.pop();

            //Check all unvisited Neighbours of node
            for (auto it=graph[node].begin(); it!=graph[node].end(); ++it) {
                int neighbour = it->first;
                int cost_to_reach_neighbour = it->second;
                if (vecVisited[neighbour] == false) {
                    if (vecCost[neighbour] > cost_to_reach_neighbour + vecCost[node]) {
                        vecCost[neighbour] = cost_to_reach_neighbour + vecCost[node];
                        minHeap.push({cost_to_reach_neighbour, neighbour});
                    }
                }
            }
        }
        return vecCost;
    }
};

int main(){
    Solution s;
                //src,dst,cost
    //VecVecI a = {{0,1,100},{1,2,100},{0,2,500}};
    //cout << s.findCheapestPrice(3, a, 0,2, 0);  //src=0, dst=2, stops=0

    // VecVecI a = {{4,1,1},{1,2,3},{0,3,2},{0,4,10},{3,1,1},{1,4,3}};
    // cout << s.findCheapestPrice(5, a, 2, 1, 1);  //src=2, dst=1, stops=1
    // cout << "test";
    
    //VecVecI a = {{1,2,10},{2,0,7},{1,3,8},{4,0,10},{3,4,2},{4,2,10},{0,3,3},{3,1,6},{2,4,5}};
    //cout << s.findCheapestPrice(5, a, 2, 1, 1);  //src=2, dst=1, stops=1
    VecI cost = {{0,1,10},{0,3,40},{1,2,50},{3,2,10},{1,3,10},{3,0,10}};
    s.FindShortestPath(4, a, 0, 2, 1);  //src=2, dst=1, stops=1  //ans=20
}
```
