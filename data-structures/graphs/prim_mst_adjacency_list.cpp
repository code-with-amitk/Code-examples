/*
        prim_mst_adjacency_list.cpp

Amit: It took 1 week to understand this!!

Question: Find MST from         [0] -50- [1] -40- [2]   
                                   \80   |60      /70
                                         [3]
0,1,2,3 are graph nodes connected using weighted edges.

Answer:          [0]--[1]---[2]
                       |
                      [3]

Adjacency Matrix:
                   0   1   2   3
                0  0   50  0   80
                1  50  0   40  60
                2  0   40  0   70
                3  80  60  70  0
                        
What Prim's Algo says:
a. Choose arbitrary vertex to start.
b. Update cost of all edges connected to node.
c. Go to one minimum weight, unvisited node.
c. Repeat step-b until all edges are in mst.

*********Logic(is very Simple)*********
Step-1. Store the graph in adjacency Matrix int g[4][4]

Step-2. Take 3 arrays.
        int cost[4] |inf|inf|inf|inf|   //Array represents COST to reach nodes
                     0   1   2   3      <-Nodes

        bool visited |0|0|0|0|          //Array represents VISITED nodes in MST.
                      0 1 2 3           <-Nodes
        
        int parent[4] |0|0|0|0|         //Array represents PARENT of visited node.         
                       0 1 2 3          <-Nodes

Step-3. Start from node [0].
        int cost[4] |0|inf|inf|inf|   //Cost of reaching node[0] is 0
                     0   1   2   3      

        bool visited |1|0|0|0|        //Mark node[0] as visited
                      0 1 2 3         
        
        int parent[4] |0|0|0|0|       //Parent of node[0] as 0 itself
                       0 1 2 3        
                
Step-4. Carry these operations on every nodes.
        4a. Find distance of adjacent,unvisited nodes/vertices. Fill in cost[]
        4b. Find least cost edge/arc and move to that vertex.
        4c. Carry operation 3a & 3b for all nodes.

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

void primMST(int graph[noOfNodes][noOfNodes])
{
    int parent[noOfNodes], cost[noOfNodes];             /*****Step-1*******/
    bool visited[noOfNodes];
    for (int i = 0; i < noOfNodes; i++){
            cost[i] = INT_MAX, visited[i] = false, parent[i] = 0;
    }

    int min=INT_MAX, min_index, u=0;

    cost[0] = 0; parent[0] = -1;                        /******Step-2*******/


    for (int i = 0; i < noOfNodes - 1; i++){

        visited[u] = true;                              /******Step-2*******/


        /**********Step-3a***************/
        for (int j = 0; j < noOfNodes; j++){
            if (graph[u][j] && visited[j] == false){
                if(graph[u][j] < cost[j]){
                    cost[j] = graph[u][j];
                    parent[j] = u;
                    cout<<"parent["<<j<<"]="<<parent[j]<<", cost["<<j<<"]="<<cost[j]<<"\n";
                }
            }
        }


        /*********Step-3b***************/
        for (int k = 0; k < noOfNodes; k++){
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
        int graph[noOfNodes][noOfNodes] = { {0,50,0,80},
                            {50,0,40,60},
                            {0,40,0,70},
                            {80,60,70,0}
                          };

    primMST(graph);

    return 0;
}

/*
 * Output:
Edge    Weight
0 - 1   50
1 - 2   40
1 - 3   60
 */
