## Dijstra's Min Distance using MinHeap
- Task: Find Minimum distance of every node from Node=0.
```c++  
                [0]-10-[1]-20-[2]
                  \     |    /
                   \50  |30 /40
                    \   |  /
                       [3]
Answer:
Node  Cost
0     0
1     10
2     30
3     40
```

## Logic(very simple) O(ElogV)
1. Store graph in adjacency matrix `g[4][4]`.
2. Take 3 Datastructures. `visited[4], cost[4], minHeap<key=cost, value=node>`
  - minHeap/Priority Queue(Self Balanced Binary Tree). Balances itself and least element is at root.
```c++  
    |0|0|0|0|   bool visited[4]
     0 1 2 3    <-Nodes. Start at node=0
     
    |INF|INF|INF|INF| int cost[4]   //Means cost of reaching any node is infinite
     0  1  2   3    <-Nodes
     
    |       |
    | |0|0| |  minHeap = priority_queue<cost,node>    //push(0,0) on Heap. Cost of reaching 0 is 0
    |       |
```
3. Make `cost[0] = 0` because we are starting at node=0. Means cost of reaching node=0 is 0.
```c++  
    |0|INF|INF|INF| int cost[4]
     0  1  2   3    <-Nodes
```
4. Repeat until minHeap is not empty:
  - *4a.* pop top. node=top. Mark node as visited.
  - *4b.* Push all connected unvisited neighbours of popped node into minHeap
```c++
  if ((neighbour is unvisited) and (present_cost_of_reaching_unvisited_neighbour > cost_in_graph + selfcost))
    update neighbour_cost
    //push (neighbour-cost, neighbour) in minHeap
```

## Example Run
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

 ## Code
```c++
#include<iostream>
#include<vector>
#include<queue>         //priority_queue

typedef std::pair<int, int> mypair;

void dijkstra_sp(std::vector<std::vector<int> > v){
  int iSize = v.size();
  std::vector<bool> iVisited(iSize, 0);
  std::vector<int> iCost(iSize, INT32_MAX);

  iCost[0] = 0;   //Starting at node=0. Cost is 0

  //<cost, node>
  std::priority_queue<mypair, std::vector<mypair>, std::greater<mypair>> minHeap;
  minHeap.push(mypair(0,0));

  while (!minHeap.empty()) {
    int node = minHeap.top().second;
    minHeap.pop();
    std::cout<<"node="<<node<<"\n";

    iVisited[node]=true;

    for(int i=0;i<v.size(); ++i){
      if(v[node][i] && iVisited[i]==false){
        if(iCost[i] > v[node][i] + iCost[node]){
          iCost[i] = v[node][i] + iCost[node];
          minHeap.push (mypair(v[node][i],i));
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
