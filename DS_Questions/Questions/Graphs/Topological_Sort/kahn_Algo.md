**Topological Sort using Kahn's Algo**
- [Logic](#l)
- [Complexity](#c)
- [Code](#co)

## [Topological Sort](/DS_Questions/Data_Structures/Graphs#t)
Task: Print topological sort/order of following graph
```c
        5 --> 0 <-- 4
        |           |
        \/         \/
        2 --> 3 --> 1
Result: 
 5 4 2 3 1 0      OR
 4 5 3 2 1 0
```
<a name=l></a>
### Logic (DFS = stack)
```c
        5 --> 0 <-- 4     //in-degree of node[5]=0, node[0]=2. In directed graph number of incoming edges
        |           |     //out-degree of node[5]=2, node[0]=0. number of outgoing edges
        \/         \/
        2 --> 3 --> 1

a. Perform DFS, when there is no outdegree of node. Push on stack

                                                                        Stack       visited
start node=5. Perform DFS from Node=5 reach 0.                          
                 Since 0 has no outdegree. Push on stack                | 0 |        0
              2-3-1. Since 1 has no outdegree. Push on stack            | 0 1 |      0 1
      Node=3, while recursing back. 
              Does node=3 connects to any node whose outdegree=0
              and not visited? No, push node=3 on stack.                | 0 1 3 |    0 1 3
      node=2. while recursing back.                    
              Does node=2 connects to any node whose outdegree=0 
              and not visisted? No, push node=2 on stack.               |0 1 3 2|   0 1 3 2
      node=5. no unvisited node, whose outdegree=0.                     |0 1 3 2 5| 0 1 3 2 5
                                                                        | 0 1 3 2 5 4 |
                                                                                    top
b. Topological Sort: Remove elements from stack. 4 5 2 3 1 0
```
#### Code Logic
```c
- _a._ Find in-degree of all nodes in graph store them in `vector<int>`
- _b._ Push all nodes having indegree=0 to queue.
while(queue!empty)
        - pop top of queue. 
        - Print
        - Check all connected nodes of popped node //for(auto i=p[u].begin(); i!=p[u].end(); i++)
                - Decrement inDegree by 1
                - if(inDegree ==0)
                        push on Queue
```
<a name=c></a>
### Complexity
- **Time:** O(V+E). V=vertices,E=Edges
  - Why complexity is not O(VE), as it has 2 nested for loops?
```c 
  V=6,E=2(max).   O(V+E)=8, O(VE)=12
        for(i=0;i<6;i++)
                for(auto j=p[i].begin()....)

Let's Calculate?
                     Cycles
        i=0, *j=NULL --> 1
        i=1  *j=NULL --> 1
        i=2  *j=3    --> 1
        i=3  *j=2    --> 1
        i=4  *j=0
             *j=1    --> 2
        i=5  *j=0
             *j=3    --> 2
             ---------------
             Total       8 = O(V+E)
```
<a name=co></a>
### Code
```cpp
#include<iostream>
#include<list>
#include <queue>
#include <vector>
using namespace std;

class graph{
        int vertices;           // No. of vertices
        list<int> *p;           // Pointer to an array of LL
public:
        graph(int a):vertices(a){
                p = new list<int>[a];
        }
        void addEdge(int u, int y){
                p[u].push_back(y);
        }
        void topologicalSort();
};

void graph::topologicalSort(){
        vector<int> inDegree(vertices,0);
        queue<int> q;
        int cnt = 0;
        vector <int> result;

        //Calculating indegree of all nodes
        // |2|2|1|1|0|0| 
        //  0 1 2 3 4 5
        for (int i=0; i<vertices; i++){         //O(V+E) V=vertices,E=edges
                for (auto j = p[i].begin(); j != p[i].end(); j++)
                     inDegree[*j]++;
        }

        //Create an queue and enqueue all vertices with indegree=0 
        for (int i = 0; i < vertices; i++)      //O(V)
                if (inDegree[i] == 0)
                    q.push(i);

        while (q.empty() != 1){                 //O(V)
                int u = q.front(); q.pop();

                cout<<u<<" ";

                for (auto i = p[u].begin(); i != p[u].end(); i++){      //O(E)
                        inDegree[*i] = inDegree[*i] - 1;
                        if(inDegree[*i] == 0)
                                q.push(*i);
                }

                cnt++;
        }

        if (cnt != vertices){
                cout << "There exists a cycle in the graph\n";
                return;
        }

        cout << endl;
}

int main(){
        graph g(6);
        g.addEdge(5, 0);        g.addEdge(5, 2);        //5->0,5->2
        g.addEdge(4, 0);        g.addEdge(4, 1);        //4->0,4->1
        g.addEdge(2, 3);                                //2->3
        g.addEdge(3, 1);                                //3->1  p[3].push_back(1);

        cout << "Topological Sort:\n";
        g.topologicalSort();
}
/*
Output:
Topological Sort:
4 5 0 2 3 1
*/
```
