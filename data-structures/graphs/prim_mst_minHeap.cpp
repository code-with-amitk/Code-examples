/*            prim_mst_minHeap.cpp  //Optimized Prim's Algo

Question: Find MST from         
        [0] -10- [1] -20- [2]
           \      |       /
            \40   |30   /50
             \    |   /
                 [3]
                 
Answer:          [0]--[1]---[2]
                       |
                      [3]
                      
"prim_mst_adjacency_list.cpp" vs "prim_mst_minHeap.cpp"?
                 prim_mst_adjacency_list.cpp       |  prim_mst_minHeap.cpp
                                                   |
Storing Graph     Adjacency Matrix                 |    Doubly LL //Takes less space wrt AM
                                                   |
Calcuation DS     int visited[4] = {0}             |    vector<bool> visited(4, false) 
                  int cost[4] = {INF}              |    vector<int> distance(4, INT_MAX); 
                  int parent[4] = {-1}             |    vector<int> parent(4, -1);
                                                   |
Logic             Start at node=0                  |
                  visited[0] = 1                   |    visited[0] = 1                 
                  cost[0] = 0                      |    cost[0] = 0
                  parent[0] = 0                    |    parent[0] = 0
                                                   |                      key, value
                                                   |    Insert in minHeap<cost, node>   //Since minHeap is sorted using Key
                                                   |              minHeap.push(0,0)   

What Prim's Algo says:
a. Choose arbitrary vertex to start.
b. Update cost of all edges connected to node.
c. Go to one minimum weight, unvisited node.
c. Repeat step-b until all edges are in mst.


*********Logic(is very Simple)*********
Step-1: Store the graph in Doubly LL list<pair<int,int>> *ptr[4];

Step-2. Take 3 vectors
        vector cost[4] |inf|inf|inf|inf|   //Array represents COST to reach nodes
                         0   1   2   3      <-Nodes
                         
        vector visited |0|0|0|0|          //Array represents VISITED nodes in MST.
                        0 1 2 3           <-Nodes
        
        vector parent[4] |-1|-1|-1|-1|         //Array represents PARENT of visited node.         
                           0  1  2  3          <-Nodes
                          
Step-3. Start from node [0].
            cost[4] |0|inf|inf|inf|   //Cost of reaching node[0] is 0
                     0  1   2   3      
                     
             visited |1|0|0|0|        //Mark node[0] as visited
                      0 1 2 3         
        
            parent[4] |0|0|0|0|       //Parent of node[0] as 0 itself
                       0 1 2 3        
  
                      key,value
            minHeap.push(0,0)       //minHeap<cost, node>.  Insert Node0 and cost to reach node.
                                    //minHeap is sorted using Key, so cost is taken as 1st and node as 2nd
                
Step-4. Carry these operations until minHeap is not Empty. 
        3a. Find Least cost Edge. PopTop of MinHeap -> O(1)
        3b. From DLL storing Graph, find adjacent,unvisited vertices. Update cost[], push.minHeap<cost, Adjacentnode>
        3c. Carry operation 3a & 3b for all nodes.
-> minHeap is used to store (cost, adjacentVertex).
-> By poping top of minHeap O(1), we reach on least cost adjacent vertex, Which need O(n) time in array case.
******************************************

*********Time Complexity**************
min Heap/Priority Queues: O(E + logV)
Array Implementation: O(n2)
*************************************
 */

#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

#define noOfNodes 4

        //dstNode,cost
typedef pair<int, int> mypair;

list <mypair> *ptr;             //Pointer to list<int,int>

void optimizedPrimMST(int src){

    priority_queue <mypair, vector <mypair>, greater<mypair>> minHeap;  //minHeap

    vector<int> cost(noOfNodes, INT_MAX);               //distance or cost array
    vector<int> parent(noOfNodes, -1);                  //parent array
    vector<bool> visited(noOfNodes, false);             //visited Nodes array

    minHeap.push(make_pair(0, src));
    cost[src] = 0;

    while (minHeap.empty() != 1)
    {
        int u = minHeap.top().second;                   //Extract cost of top
        minHeap.pop();

        visited[u] = true;

        for(auto i = ptr[u].begin(); i != ptr[u].end(); i++){

            int node = (*i).first;
            int distance = (*i).second;

            if (visited[node] == false && cost[node] > distance)
            {
                cost[node] = distance;
                minHeap.push(make_pair(cost[node], node));
                parent[node] = u;
            }
        }
    }

    // Print edges of MST using parent array
    cout<<"Vertex  Cost\n";
    for (int i = 1; i < noOfNodes; ++i)
            cout<<parent[i]<<"-"<<i<<"\t"<<cost[i]<<endl;
}

int main(){

        /*Creating Graph*/
        ptr = new list<mypair> [4];

        ptr[0].push_back(make_pair(1,10));      //0 is connected to 1 by distance 10
        ptr[0].push_back(make_pair(3,40));

        ptr[1].push_back(make_pair(0,10));
        ptr[1].push_back(make_pair(2,20));      //1 is connected to 2 by cost 20
        ptr[1].push_back(make_pair(3,30));

        ptr[2].push_back(make_pair(1,20));      //2 is connected to 1 by cost 20
        ptr[2].push_back(make_pair(3,50));

        ptr[3].push_back(make_pair(0,40));
        ptr[3].push_back(make_pair(1,30));      //3 is connected to 1 by cost 30
        ptr[3].push_back(make_pair(2,50));
        cout <<"Graph Created \n";

        optimizedPrimMST(0);    //Starting node = 0
        return 0;
}
#define noOfNodes 4

        //dstNode,cost
typedef pair<int, int> mypair;

list <mypair> *ptr;             //Pointer to list<int,int>

void optimizedPrimMST(int src){

    priority_queue <mypair, vector <mypair>, greater<mypair>> minHeap;  //minHeap

    vector<int> cost(noOfNodes, INT_MAX);               //distance or cost array
    vector<int> parent(noOfNodes, -1);                  //parent array
    vector<bool> visited(noOfNodes, false);             //visited Nodes array

    minHeap.push(make_pair(0, src));
    cost[src] = 0;

    while (minHeap.empty() != 1)
    {
        int u = minHeap.top().second;                   //Extract cost of top
        minHeap.pop();

        visited[u] = true;

        for(auto i = ptr[u].begin(); i != ptr[u].end(); i++){

            int node = (*i).first;
            int distance = (*i).second;

            if (visited[node] == false && cost[node] > distance)
            {
                cost[node] = distance;
                minHeap.push(make_pair(cost[node], node));
                parent[node] = u;
            }
        }
    }

    // Print edges of MST using parent array
    cout<<"Vertex  Cost\n";
    for (int i = 1; i < noOfNodes; ++i)
            cout<<parent[i]<<"-"<<i<<"\t"<<cost[i]<<endl;
}

int main(){

        /*Creating Graph*/
        ptr = new list<mypair> [4];

        ptr[0].push_back(make_pair(1,10));      //0 is connected to 1 by distance 10
        ptr[0].push_back(make_pair(3,40));

        ptr[1].push_back(make_pair(0,10));
        ptr[1].push_back(make_pair(2,20));      //1 is connected to 2 by cost 20
        ptr[1].push_back(make_pair(3,30));

        ptr[2].push_back(make_pair(1,20));      //2 is connected to 1 by cost 20
        ptr[2].push_back(make_pair(3,50));

        ptr[3].push_back(make_pair(0,40));
        ptr[3].push_back(make_pair(1,30));      //3 is connected to 1 by cost 30
        ptr[3].push_back(make_pair(2,50));
        cout <<"Graph Created \n";

        optimizedPrimMST(0);    //Starting node = 0
        return 0;
}
/*
# ./a.out 
Graph Created 
Vertex  Cost
0-1   	10
1-2	    20
1-3	    30
*/
