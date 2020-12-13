## Dijstra's Min Distance using MinHeap
- Task: Find Minimum distance of every node from Node=0.
```c++  
                [0]-10-[1]-20-[2]
                  \     |    /
                   \50  |30 /40
                    \   |  /
                       [3]
Answer:
Node  Code
0     0
1     10
2     30
3     40
```

## Logic(very simple) O(ElogV)
1. Store graph in adjacency matrix `g[4][4]`.
2. Take 3 DS.
```c++  
    |1|0|0|0|   visited[4]
     0 1 2 3    <-Nodes. Start at node=0
     
    |0|INF|INF|INF| cost[4]
     0  1  2   3    <-Nodes
     
    |       |
    | |0|0| |  minHeap = priority_queue<cost,node> //minHeap.push((0,0));
    |       |
```
3. Repeat this for all nodes in graph
  - *3a.* Check if present_cost_of_reaching_unvisited_neighbour > cost_in_graph + selfcost
    - update cost
  - *3b.* Move to unvisited,leastcost neighbour
```c++
3. Until Heap is not empty.                                     while(!minHeap.empty()){
  3a. Extract top from heap. (cost,u=node)                        int u = minHeap.top().second;
  3b. Check unvisited neighbours of u                             for(int i=0;i<4;i++){
                                                                    if(fl[u][i] && visited[i]==false){
    if presnt_cost_of_reaching_neighbour > g[cost]+selfcost           if(cost[i]>fl[u][i]+cost[u]){
      update cost                                                       cost[i] = fl[u][i]+cost[u];
      push (cost,node) on minHeap                                       minHeap.push(mypair(fl[u][i],i));
  3c. Goto step-3                                               }
```                                                                      

 ## Code
```c++
#include<iostream>
#include<queue>         //Provides priority_queue
using namespace std;

void dijkstra_sp(int fl[4][4]){
        int visited[4];
        int cost[4];            //Considering 1000 as INFINITY, since no node will have cost>100
        for(int i=0;i<4;i++){
                cost[i]=1000;visited[i]=0;
        }
        cost[0]=0;

        priority_queue<mypair, vector<mypair>, greater<mypair>> minHeap;        //<cost,node>

        minHeap.push(mypair(0,0));

        while(!minHeap.empty()){
                int u = minHeap.top().second;
                minHeap.pop();
                cout<<"u="<<u<<"\n";

                visited[u]=true;
                for(int i=0;i<4;i++){                                 //O(n). Can be minimized by taking list<>
                        if(fl[u][i] && visited[i]==false){
                                if(cost[i]>fl[u][i]+cost[u]){
                                        cost[i] = fl[u][i]+cost[u];
                                        minHeap.push(mypair(fl[u][i],i));
                                }
                        }
                }
        }

        cout<<"Node\tCost\n";
        for(int i=0;i<4;i++){
                cout<<i<<"\t"<<cost[i]<<"\n";
        }
}

int main(){
        int fl[4][4] = {{0,10,0,50},
                        {10,0,20,30},
                        {0,20,0,40},
                        {50,30,40,0}
                       };
        dijkstra_sp(fl);
}
# ./a.out
Node	Cost
0	    0
1	    10
2	    30
3	    40
```
