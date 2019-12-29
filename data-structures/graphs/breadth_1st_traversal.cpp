/*

Amit Read Algo and try understand. Whole day is spent on this.

Question: Print nodes of graph in BFS fashion, where starting node is 0

 Graph: 8 Nodes, 10 edges

                2---------------
                /\             |
                |              |
        4<------0------>1      |
        |       |       |      |
        |       |       |      |
        \/      \/      \/     |
        6<------3       5<------
        |               |
        |               |
        ------->7<-------   

****************Logic********************
1. Create Graph, Take boolean visitedNodes array.
- Check Code-examples/data-structures/graphs/create_using_adjacency_matrix.cpp

a. Create a Adjacency Matrix:
         0   1   2   3   4   5   6   7
        ------------------------------
      0 |0   1   1   1   1   0   0   0          //0 is connected to 1,2,3,4
      1 |0   0   0   0   0   1   0   0          //1 is connected to 5
      2 |0   0   0   0   0   1   0   0          //2 is connected to 5
      3 |0   0   0   0   0   0   1   0          //3 is connected to 6
      4 |0   0   0   0   0   0   1   0          //4 is connected to 6
      5 |0   0   0   0   0   0   0   1          //5 is connected to 7
      6 |0   0   0   0   0   0   0   1          //6 is connected to 7
      7 |0   0   0   0   0   0   0   0

        vector <int> v[8];      //8 Arrays of int vector.
  v[0] = Shows connections of Node 0 to other nodes 
  v[1] = Shows connections of Node 1 to other nodes so on
            
b. Take a boolean array of size=NumberOfNodes. 
|0|0|0|0|0|0|0|0|       //This means none of nodes are visited
 0 1 2 3 4 5 6 7        //Indexes denotes the nodes of graph

|1|1|0|0|0|0|0|0|       //This means nodes(1,2) are visited
 0 1 2 3 4 5 6 7        

Initialize to 0. We will mark entry=1 once node gets visited.
        bool visitedNodes[8] ={0};


2. Breadth 1st Traversal(starting from Node=0):
We will take a queue, push 1st node on queue. Carry these operation until queue is empty:
        - element = pop top of queue
        - print the element.
        - Iterate through this element's Adjacency list. AL will contain all connected nodes.
                -> Check visitedNode[] boolen array
                if(visitedNode[entry] == 0)
                        this means node is not visited yet.
                        Mark node as visited.
                        push the node on queue
*******************************************
Inspired from: https://www.geeksforgeeks.org/bfs-using-stl-competitive-coding/      
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector <int> v[], bool visitedNodes[], int startingNode){
        queue<int> q;
        int temp;

        q.push(startingNode);           //Push 0

        visitedNodes[startingNode] = true;      //Mark 0 as visited

        while(!q.empty()){

                temp = q.front();       q.pop();        //Pop and print front
                cout<< temp << " ";

                for(auto i = v[temp].begin(); i != v[temp].end(); i++){         //Traverse popped Node's Adjacency list to find connected nodes

                        //*i is entry in Adjacency list, 0 -> 1,2,3,4. Connected nodes

                        if(visitedNodes[*i] == 0){                              //Check whether node retrieved from Adjacency list is not visited?

                                visitedNodes[*i] = true;                        //Mark retrieved node as visisted.

                                q.push(*i);                                     //Push retrieved node on queue.

                        }
                }
        }
}

int main()
{
        bool visitedNodes[8] ={0};

        vector<int> v[8];               //Vector storing Adjacecy Matrix of graph

        v[0].push_back(1);      v[0].push_back(2);      v[0].push_back(3);      v[0].push_back(4);
        v[1].push_back(5);
        v[2].push_back(5);
        v[3].push_back(6);
        v[4].push_back(6);
        v[5].push_back(7);
        v[7].push_back(7);

        cout<<"BFS Traversal\n";
        BFS(v, visitedNodes, 0);

        return 0;
}

/*
Output:
# ./a.out
BFS Traversal
0 1 2 3 4 5 6 7
 */
