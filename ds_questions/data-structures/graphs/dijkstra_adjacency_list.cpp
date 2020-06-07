/*
        dijkstra_shortest_path.cpp

Question: Find shortest path from given node to all other nodes in graph.

                                 [0]-10-[1]-20-[2]   
                                   \50   |30    /40
                                    \    |     /
                                        [3]
Answer: Source vertex:0
Vertex  Distance from Source
 0              0
 1              10
 2              30
 3              40

Adjacency Matrix:
                   0   1   2   3
                0  0   10  0   50
                1  10  0   20  30
                2  0   20  0   40
                3  50  30  40  0

*********Logic(is very simple)***********
-> Dijkstra algo is derived from Prim's Algo

Step-1. For every graph traversal we need to take these DS
        int cost[4] |inf|inf|inf|inf|   //Array represents COST to reach nodes
                     0   1   2   3      <-Nodes
        bool visited |0|0|0|0|          //Array represents VISITED nodes in MST.
                      0 1 2 3           <-Nodes

Step-2. Start from node [0].
        int cost[4] |0|inf|inf|inf|   //Cost of reaching node[0] is 0
                     0   1   2   3
        bool visited |1|0|0|0|        //Mark node[0] as visited
                      0 1 2 3

Step-3. Carry these operations after reaching every node.
        3a. Find min cost unvisited neighbour. Fill in cost[]
                if(present_cost_of_neighbour > cost[self] + cost_of_vertex_connecting_neighbour)
                        cost_of_neighbour = cost[self] + cost_of_vertex_connecting_neighbour

        3b. Find least cost edge/arc and move to that neighbour.

        3c. Carry operation 3a & 3b for all nodes.

*****************************************


*********Time Complexity**************
Adjacency Matrix: O(n2)
Binary Heap: O(E + logV)
*************************************
*/

#include <limits.h>
#include <stdio.h>
#include<iostream>
using namespace std;

#define noOfNodes 4

void printSolution(int dist[]){
        cout<<"\nSource vertex=0\n\n";
    cout<<"Vertex \t\t Distance/Cost from Source\n";
    for (int i = 0; i < noOfNodes; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}


void dijkstra(int graph[noOfNodes][noOfNodes], int startingNode){
    int cost[noOfNodes], u=0, min=INT_MAX, min_index;           /******Step-1*******/
    bool visited[noOfNodes];

    for (int i = 0; i < noOfNodes; i++)                         /*****Step-2*******/
        cost[i] = INT_MAX, visited[i] = false;
    cost[startingNode] = 0;

    for (int i = 0; i < noOfNodes - 1; i++) {

        visited[u] = true;

        //cout<<"u="<<u<<"\n";
        for (int j = 0; j < noOfNodes; j++){                    /******Step-3a*******/
            if (graph[u][j] && visited[j] == false){
                if(cost[u] + graph[u][j] < cost[j]){
                    //cout<<"graph["<<u<<"]["<<j<<"]="<<graph[u][j]<<", visited["<<j<<"]="<<visited[j]<<", cost["<<u<<"]="<<cost[u]<<", cost["<<j<<"]="<<cost[j]<<"\n";
                    cost[j] = cost[u] + graph[u][j];
                }
            }
        }

        for (int k = 0; k < noOfNodes; k++){                    /*******Step-3b******/
            if (visited[k] == false && cost[k] <= min)
                min = cost[k], min_index = k;
        }

        u = min_index;
    }

    printSolution(cost);
}

int main()
{
    int graph[noOfNodes][noOfNodes] = { {0,10,0,50},
                                        {10,0,20,30},
                                        {0,20,0,40},
                                        {50,30,40,0}
                                      };

    dijkstra(graph, 0);         //Take source vertex=0

    return 0;
}

/*
Output:
# ./a.out 

Source vertex=0

Vertex           Distance/Cost from Source
0                0
1                50
2                90
3                80
*/
