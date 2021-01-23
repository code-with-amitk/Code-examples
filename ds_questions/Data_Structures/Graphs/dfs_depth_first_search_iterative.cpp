/*
        dfs_depth_first_search_iterative.cpp
        
Depth First Traversal: Reach to deepest node, instead of reaching all neighbors.

        0 -- 1 -- 2
         \   |   /
           \ | /
             3

Starting node=2, dfs=2 1 0 3

We can store graph using 2 methods
Method-1: Adjacency Matrix:
         0   1   2   3
        --------------
      0 |0   1   0   1
      1 |1   0   1   1
      2 |0   1   0   1
      3 |1   1   1   0

Method-2: Adjacency-list        //USED HERE
        0 -> 1,3
        1 -> 0,2,3
        2 -> 1,3
        3 -> 0,1,2

***********************Logic**********************
1. Store the graph nodes in Adjacency List: Take vector array to store Adjacency list.
        vector<int> v[4];

2. For Depth 1st Search
 - Take a boolen array for marking visitedNodes. visited[4]
 - Take a stack. push startingnode on it.
 - Perform these operations until stack is empty
        - Pop top of stack. store value in u.
        - Print and mark this node as visited
        - Find unvisited neighbours of this node. //Iterate through vector
                push_on_stack
                break;
**************************************************

*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(vector<int> g[], int startingNode){
        bool visited[4] = {0};
        stack<int> s;
        int u;

        s.push(startingNode);

        while (s.empty() != 1){

                u = s.top();         s.pop();

                visited[u] = true;
                cout<<u<<" ";

                for (auto i = g[u].begin(); i != g[u].end(); ++i){
                        if (visited[*i] == false){
                                s.push(*i);
                                break;
                        }
                }
        }

}

int main()
{
        vector<int> v[4];
        v[0].push_back(1);      v[0].push_back(3);              //v[0]={1,3}
        v[1].push_back(0); v[1].push_back(2); v[1].push_back(3);//v[1]={0,2,3}
        v[2].push_back(1); v[2].push_back(3);                   //v[2]={1,3}
        v[3].push_back(0); v[3].push_back(1); v[3].push_back(2);//v[3]={0,1,2}

        int startingNode = 2;                     //Let's start traversal from node=2
        cout<<"Starting node="<<startingNode<<"\n";
        cout << "Depth First Traversal:\n";
        dfs(v, startingNode);

        return 0;
}


/*
Output:
# ./a.out 
Starting node=2
Depth first Traversal
2 1 0 3
*/
