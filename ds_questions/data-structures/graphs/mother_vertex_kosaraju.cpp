/*
        mother_vertex_kosaraju.cpp

Mother Vertex? 
        - Vertex from which every other vertex in graph is reachable.
        - There can be more than 1 mother verteces in graph.

Situation/Task: Find mother verteces in this graph?
        [1] --> [0] --> [3] --> [4]
        /\       |
        |       \/
        --------[2]
Answer: 0,1,2.  These 3 are mother nodes,since all other vertices are reachable from them.

SCC(Strongly connected Components)?
A directed graph is strongly connected if each node can reach other.
- In above example, there are 3 SCCs
0,1,2: Because every node can reach other 2 nodes.
3: bcoz 3 can only reach itself not any other node.
4

****************Solution-1(Naive)******************
- From every node perform DFS or BFS and check all other nodes are reachable or not?
Complexity: O(N(E+N))
        N-Number of nodes
        E-Connected neighbours
***************************************************

**************Solution-2(Kosaraju Algorithm)**********
Step-1. Push nodes on stack in reverse order
  - Take visited[5]={0}.
  - Take stack, start from vertex 0
  - push nodes on stack using recursion, also mark nodes as visited[u]=true

Step-2: Find transpose of graph and store in new graph

Step-3: Again, mark all nodes as unvisited visited[5]={0}
  - Print the nodes recursively
Complexity: O(N+E).
        N-Number of nodes
        E-Connected neighbours
******************************************************
*/
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

stack<int> s;
vector<int> v[5];       //Stores original graph
vector<int> t[5];       //Stores transpose of v[]
bool visited[5];

void getTranspose(){
        for(int i=0;i<5;i++){
                for(auto j=v[i].begin();j!=v[i].end();j++){
                        t[*j].push_back(i);
                }
        }
}

void fillReverse(int u){
        visited[u] = true;

        for(auto i=v[u].begin();i!=v[u].end();i++){
                if(visited[*i] == false)
                        fillReverse(*i);
        }
        s.push(u);
}

void printDFS(int u){
        visited[u]=true;
        cout<<u<<" ";

        for(auto i=t[u].begin();i!=t[u].end();i++){
                if(visited[*i] == false)
                        printDFS(*i);
        }
}

void printSCC(){
        for(int i = 0; i < 5; i++)
                if(visited[i] == false)
                    fillReverse(i);
        cout<<"Step-1: Stack filled in reverse order\n";

        getTranspose();
        cout<<"Step-2: Transpose created\n";

        for(int i = 0; i < 5; i++)
                visited[i] = false;             //Step-3

        while(s.empty()!=1){
                int u = s.top();        s.pop();

                if(visited[u]==false){
                        printDFS(u);
                }
        }
}

int main(){
        vector<int> v[5];
        v[0].push_back(2);
        v[0].push_back(3);

        v[1].push_back(0);
        v[2].push_back(1);
        v[3].push_back(4);

        cout << "Following are strongly connected components in "
            "given graph \n";
        printSCC();
}
