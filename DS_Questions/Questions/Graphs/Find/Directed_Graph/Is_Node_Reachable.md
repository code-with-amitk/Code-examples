- [Problem](#p)
- [Approach : DFS](#a)
- [Complexity](#c)
- [Code](#c)

<a name=p></a>
## Problem
- Given a directed graph, find whether there is a route between two nodes?
```c
        0 ---> 1 ----> 2 <----- 4
        |     |        |
        |    \/        |
        ----> 3 <------
```

<a name=a></a>
### Approach : DFS
- _a._ Store graph in Adjacency List.
- _b._ Take 2 DS
```c
        visited[nodes] = {0}
        stack<int>              //Push 0 on stack
```
- _c._ Perform the operations until stack is empty:
```c
        - u = pop,top
        - visited[u] = true
        - if(u==dst) -> We found the dst. break
        - if any unvisited neighbours of u
                push-on-stack
```

<a name=c></a>
### Complexity
O(mn)
```c
n: Number of nodes in Graph
m: Max Number of connected vertices to a node
```

<a name=c></a>
### Code
```c
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(vector<int> v[5], int src, int dst){
        stack<int> s;
        int u=0;

        bool visited[5];
        for(int i=0;i<5;i++)            //O(n)
                visited[i]=false;

        s.push(src);

        while(s.empty()!=1){                    //O(n). Considering last node is searched for
                u = s.top(); s.pop();
                visited[u] = true;

                if(u==dst)
                        break;

                for(auto i=v[u].begin();i!=v[u].end();i++){     //O(m). No of connected nodes to a particular node
                        if((*i) && !visited[*i]){
                                s.push(*i);
                        }
                }
        }
        /*cout<<"visited nodes=\n";
        for(int i=0;i<5;i++){
                if(visited[i])
                        cout<<i<<"\n";
        }*/

        if(visited[dst])
                cout<<"Node "<<dst<<" is reachable from Node "<<src<<"\n";
        else
                cout<<"Node "<<dst<<" is not reachable from Node "<<src<<"\n";
}

int main(){
        /*int g[5][5] = {{0,1,0,1,0},   //Adjacency Matrix
                       {0,0,1,1,0},
                       {0,0,0,1,0},
                       {0,0,0,0,0},
                       {0,0,1,0,0},
                      };*/

        //Adjacency List
        vector<int> v[5];
        v[0].push_back(3);      v[0].push_back(1);
        v[1].push_back(2);      v[1].push_back(3);
        v[2].push_back(3);
        v[4].push_back(2);

        dfs(v,0,4);
        dfs(v,2,3);
}

/*
# ./a.out 
Node 4 is not reachable from Node 0
Node 3 is reachable from Node 2
*/
```
