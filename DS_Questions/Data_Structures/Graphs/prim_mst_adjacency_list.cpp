/*      prim_mst_adjacency_list.cpp     Amit: It took 1 week to understand this!!

Task: Find MST from             [0] -10- [1] -20- [2]   
                                   \50   |30    /40
                                         [3]
Answer:          [0]--[1]---[2]
                       |
                      [3]

Adjacency Matrix:
                   0   1   2   3
                0  0   10  0   50
                1  10  0   20  30
                2  0   20  0   40
                3  50  30  40  0
                        
*********Logic(is very Simple)*********
Step-1. Store the graph in adjacency Matrix int g[4][4]

Step-2. Take 3 Data structures and intialize. 
Let's start from Node 0. visited[0]=1, cost[0]=0, parent[0]=0
        bool visited |1|0|0|0|          //Array represents VISITED nodes in MST.
                      0 1 2 3            <-Nodes
                      
        int cost[4] | 0 |inf|inf|inf|   //Array represents COST to reach nodes
                      0   1   2   3      <-Nodes

        int parent[4] |-1|-1|-1|-1|     //Array represents PARENT of visited node.         
                        0  1  2  3      <-Nodes

Step-3. Carry these operations on every node.           for (int i = 0; i < 4 - 1; i++){        //All 4  nodes
                                                             for (int j = 0; j < 4; j++)     //Every node
        3a. if node have unvisited Neighour                        if (graph[][] && visited[] == false){
                if(cost_in_cost[] > graph_cost)                            if(cost[] > graph[][]){
                        update cost[]                                           cost[] = graph[][]
                        
        3b. Move to unvisited, least cost neighbour          for(int k=0;k<4;k++)
                                                                   if(!visited[k] && cost[k]<min)
        3c. Carry operation 3a & 3b for all nodes.      }
******************************************

*********Time Complexity**************
Array Implementation(Present): O(n2)
min Heap/Priority Queues: O(ElogV)
*************************************
*/



#include <bits/stdc++.h>
using namespace std;

#define noOfNodes 4

void printMST(int parent[], int graph[noOfNodes][noOfNodes])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < noOfNodes; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[4][4])
{
    int parent[4], cost[4];                             //Taking mandatory 3 DS
    bool visited[4];
    for (int i = 0; i < noOfNodes; i++){
            cost[i] = INT_MAX, visited[i] = false, parent[i] = 0;
    }

    int min=INT_MAX, min_index, u=0;

    cost[0] = 0; parent[0] = 0;                        //Starting from Node=0

    for (int i = 0; i < 4 - 1; i++){

        visited[u] = true;                              //Marking node as visited

        for (int j = 0; j < 4; j++){            
                
            if (graph[u][j] && visited[j] == false){    //3a.Finding unvisited Neighbours
                    
                if(cost[j] > graph[u][j]){              //if(cost[] > graph_cost) update_cost
                    cost[j] = graph[u][j];
                    parent[j] = u;
                    cout<<"parent["<<j<<"]="<<parent[j]<<", cost["<<j<<"]="<<cost[j]<<"\n";
                }
                    
            }
                
        }

        for (int k = 0; k < 4; k++){                    //3b. Move to least cost Neighbour
            if (visited[k] == false && cost[k] < min){
                min = cost[k], min_index = k;
            }
        }
            
        u = min_index;
    }

    cout<<"\n\n";
    printMST(parent, graph);
}

int main()
{
    int g[4][4] = { {0,10,0,50},
                    {10,0,20,30},
                    {0,20,0,40},
                    {50,30,40,0}
                  };

    primMST(graph);

    return 0;
}

/*Output:
Edge    Weight
0 - 1   10
1 - 2   20
1 - 3   30
*/
