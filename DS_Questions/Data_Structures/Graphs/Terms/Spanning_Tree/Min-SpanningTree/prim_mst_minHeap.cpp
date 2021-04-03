/*            prim_mst_minHeap.cpp      //Optimized Prim's Algo

Question: Find MST from graph
        [0] -10- [1] -20- [2]
           \      |       /
            \40   |30   /50
                 [3]
                 
Answer:          [0]--[1]---[2]
                       |
                      [3]

We are using: 'minimum Heap' <cost,node>, minHeap will be sorted using key=cost and min cost node will be at root.
 - Insert all unvisited neighnours into minHeap.
 - Extract top until minHeap is not empty.

*********Logic(is very Simple)*********
Step-1: Store the graph in Adjacency list.    <node,cost>
list<pair<int,int>> *ptr[4];             //Doubly LL 

Step-2. Take 4 Data structures and intialize.
Let's start from Node 0. visited[0]=1, cost[0]=0, parent[0]=0
        vector cost[4] | 0 |inf|inf|inf|   //Array represents COST to reach nodes
                         0   1   2   3      <-Nodes
                         
        vector visited |1|0|0|0|          //Array represents VISITED nodes in MST.
                        0 1 2 3           <-Nodes
        
        vector parent[4] | 0 |-1|-1|-1|         //Array represents PARENT of visited node.         
                           0   1  2  3          <-Nodes
                           
        priority_queue <mypair, vector <mypair>, greater<mypair>> minHeap;
        minHeap.push(make_pair(0, 0));          //Start with (cost,node = 0,0) on min Heap
                          
Step-3: Carry operations for all nodes
        3a. Push unvisited neighbours into minHeap.
        3b. if cost[] > graph's cost. Update cost.
        3c. Perform step-3a,3b until minHeap is not empty.

Code-wise
Step-3: Perform until minHeap is not empty.                     while(minHeap.empty() != 1)
        3a. Reach least cost neighbour ie top()                    int u = top().second; pop();
        3b. Mark this as visited                                   visited[u] = true
        3b. Find unvisited neighbours from list<>                  for(auto i=ptr[0].begin;..){
                                                                     if(visited[*i]==false && cost[] > (*i).second)
            Update cost                                                  cost[] = (*i).second;
            push on minHeap                                              minHeap.push(pair(cost,node))
            Update parent                                                parent[(*i).first] = u
                                                                   }
        3c. Carry operation 3a & 3b for all nodes.             }
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
