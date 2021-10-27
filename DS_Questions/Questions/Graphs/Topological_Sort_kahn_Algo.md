- [What is Topological Sort](/DS_Questions/Data_Structures/Graphs)

## Topological Sort
Task: Print topological sort/order of following graph
```c
        5 --> 0 <-- 4
        |           |
        \/         \/
        2 --> 3 --> 1
Result: 
 5 4 2 3 1 0 or 4 5 3 2 1 0
```
### Logic 
a. Find in-degree of all nodes in graph store them in `vector<int>`
b. Push all nodes having indegree=0 to queue.
```c
while(queue!empty)
        - pop top of queue. 
        - Print
        - Check all connected nodes of popped node //for(auto i=p[u].begin(); i!=p[u].end(); i++)
                - Decrement inDegree by 1
                - if(inDegree ==0)
                        push on Queue
```
### Complexity:
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
