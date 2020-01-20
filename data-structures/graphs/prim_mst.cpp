*
        prim_mst.cpp

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
c. Choose and go to one minimum weight edge that is non-visited.
c. Repeat step-b until all edges are in mst.

*********Logic*********
Step-1. Start with 3 arrays.
        int cost[4] |inf|inf|inf|inf|   //This array represents COST of nodes
                     0   1   2   3      <-Nodes

        bool visited |0|0|0|0|  //This array represents VISITED nodes in MST.
                     0 1 2 3    <-Nodes
        
        int parent[4] |0|0|0|0| //This array represents PARENT of visited node.    
                       0 1 2 3  <-Nodes

Step-2. Let's take [0] as starting node.
                cost[4] |0|inf|inf|inf| //0 is 0 distance aways from itself
                         0   1   2   3

                visited |1|0|0|0|  //0 is visited

                parent[4] |0|0|0|0|  //Parent of 0 is 0 itself
                           0 1 2 3      <Nodes

Step-3. 
        Do this iteratively for all nodes Except node[0].
        for(i=0;i<3;i++)
                a. Find node's Index with minimum weight edge connected to 0, should not be visited & (cost-of-reaching-node < already-present-cost-in-cost[])
                        update the cost
                        mark parent.
                b. Find the edge with minCost in cost[].
                        Perform step-a on that node
*************************
 */



#include <bits/stdc++.h>
using namespace std;

#define noOfNodes 4

int findMinCostEdgeIndex(int cost[], bool visited[])
{
    int min = INT_MAX, index;
    for (int i = 0; i < noOfNodes; i++){
        if (visited[i] == false && cost[i] < min){
            min = cost[i], index = i;
        }
    }
    cout<<"\n\nIndex of Node at Min weight edge = "<<index<<"\n";
    return index;
}

void printMST(int parent[], int graph[noOfNodes][noOfNodes])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < noOfNodes; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[noOfNodes][noOfNodes])
{
    int parent[noOfNodes], cost[noOfNodes], min=INT_MAX, min_index, u=0;
    bool visited[noOfNodes];

    for (int i = 0; i < noOfNodes; i++){
            cost[i] = INT_MAX, visited[i] = false, parent[i] = 0;
    }

    cost[0] = 0; parent[0] = -1;


    for (int i = 0; i < noOfNodes - 1; i++)
    {

        visited[u] = true;      //Mark node[0] as visited

        //Find All connected, non-visited nodes, Update reaching cost.
        for (int j = 0; j < noOfNodes; j++){
                if (graph[u][j] && visited[j] == false){
                        if(graph[u][j] < cost[j]){
                                cost[j] = graph[u][j];
                                parent[j] = u;
                                cout<<"parent["<<j<<"]="<<parent[j]<<", cost["<<j<<"]="<<cost[j]<<"\n";
                    }
                }
            }
            //Go to that node whose cost is Minimum from cost[]
            u = findMinCostEdgeIndex(cost, visited);
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
