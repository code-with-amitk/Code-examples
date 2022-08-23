**Topological Sort using Kahn's Algo**
- [Logic](#l)
- [Complexity](#c)
- [Code](#co)

## [Topological Sort](/DS_Questions/Data_Structures/Graphs#t)
- Print topological sort/order of following graph
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
#### Logic 
```c
        5 --> 0 <-- 4     //in-degree of node[5]=0. Number of incoming edges
        |           |     //out-degree of node[5]=2. Number of outgoing edges
        \/         \/
        2 --> 3 --> 1

1. Create a vector containing in-degrees of nodes
        |2|2|1|1|0|0| 
         0 1 2 3 4 5

2. Take queue and enqueue all vertices with indegree=0.
   - if no node has indegree=0 that means graph has a cycle.
        |4 5|
         q

3. Iterate through queue until empty.
- pop top                      	//4
- push top in out vector	//out |4|
- Reduce indegree of all connected neighbours of u by 1, if any indegree=0, push on queue.
	//Neighbors of 4=0,1. Reduce indegree by 1. Since 0,1 does not have indegree=0, nothing to push in q
        |1|1|1|1|0|0|   
         0 1 2 3 4 5		 

|5|
q

pop top	//5			//out |4 5|
	//Neighbors of 5=0,2
        |1|1|1|1|0|0| 
         0 1 2 3 4 5		 
         
	Reduce indegree of all connected neighbours of u by 1, if any indegree=0, push on queue.
        0,2 Both's indegree became 0, hence push both on q.
        |0|1|0|1|0|0| 
         0 1 2 3 4 5		 
	
	|0 2|
	q

Repeat
```
<a name=c></a>
#### Complexity
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
#### Code
```cpp
#include <vector>
#include <iostream>
#include <list>
#include <queue>
using vecI = std::vector<int>;
using vecVecI = std::vector<vecI>;
using ListI = std::list<int>;
using QueI = std::queue<int>;

class graph{
    int vertices;                // No. of vertices
    ListI *p;           // Pointer to an array of LL
public:
    graph(int a):vertices(a){
        p = new std::list<int>[a];
    }
    void addEdge(int u, int y){
        p[u].push_back(y);
    }
    ListI* GetList(){
        return p;
    }
};

class Solution {
    QueI q;
public:
    vecI ToplogicalSort(int numCourses, vecVecI& prerequisites) {
                vecI out;
        int cnt = 0;

        /*Create Graph, number of nodes=numCourses
            3 <-- 1 <-- 0
            /\           |
            |           \/
            |---------- 2
        */
        graph g(numCourses);
        for (auto& i:prerequisites){
            g.addEdge(i[1],i[0]);
        }

        /*Calculate indegree of all nodes
            |0|1|1|2|
             0 1 2 3
        */
        vecI inDegree(numCourses, 0);
        ListI* p = g.GetList();
        //std::cout << "p=" << p << "\n";
        for (int i=0; i<numCourses; i++){         //O(V+E) V=vertices,E=edges
            for (auto j = p[i].begin(); j != p[i].end(); j++)
                inDegree[*j]++;
        }

        //Create an queue and enqueue all vertices with indegree=0 
        for (int i = 0; i < numCourses; i++)      //O(V)
            if (inDegree[i] == 0)
                q.push(i);

        while (q.empty() != 1){                 //O(V)
            int u = q.front(); q.pop();

            //std::cout<<u<<" ";
            out.push_back(u);

            for (auto i = p[u].begin(); i != p[u].end(); i++){      //O(E)
                inDegree[*i] = inDegree[*i] - 1;
                if(inDegree[*i] == 0)
                    q.push(*i);
            }
            cnt++;
        }
         if (cnt != numCourses){
            //There is a loop
            out.clear();
        }
        return out;
    }
};

int main(){
    Solution s;
    vecI o = s.ToplogicalSort(4, {{1,0},{2,0},{3,1},{3,2}});
    for (auto&i:o)
        std::cout << i << ",";
}
/*
Output:
Topological Sort:
4 5 0 2 3 1
*/
```
