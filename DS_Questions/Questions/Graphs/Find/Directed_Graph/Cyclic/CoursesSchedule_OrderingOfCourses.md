**[Course Schedule II](#p)**
- [Approach-1, Directed Cyclic Graph](#a1)
  - [Logic](#l)
  - [Code](#cpp)

<a name=p></a>
## [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
- There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
- You are given an array prerequisites where `prerequisites[i] = [a, b]` indicates that you must take course b first if you want to take course a.
- Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
```c
Example-1
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
//0 is prerequisite of 1,2.
//1,2 are prerequisites of 3
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example-2
Input: numCourses = 1, prerequisites = []
Output: [0]
```

<a name=a1></a>
### Approach-1, Topological Sort of Directed Cyclic Graph
- What is [Toplogical Sort of Directed cyclic graph](/DS_Questions/Data_Structures/Graphs/#t).
- We can represent course relationships with directed, cyclic graph, where 
  - Each course would represent a vertex in the graph
  - Edges are modeled after the prerequisite relationship between courses. For pair `[a, b]` means the course b is a prerequisite for the course a. `b ➔ a`.
```c
[[1,0],[2,0],[3,1],[3,2]]

  0 ------> 1 -----> 3
  |                  /\
  --------> 2 -------|
  
```
<a name=l1></a>
#### Logic => [Kahn's Algo Topological sort](/DS_Questions/Data_Structures/Graphs/Toplogical_Sort/kahn_Algo.md)

<a name=cpp></a>
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
    vecI findOrder(int numCourses, vecVecI& prerequisites) {
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

        // for (int i=0; i<numCourses; i++){
        //     std::cout << inDegree[i] << "\n";
        // }
        // std::cout<<"\n";

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
    vecI o = s.findOrder(4, {{1,0},{2,0},{3,1},{3,2}});
    for (auto&i:o)
        std::cout << i << ",";
}
```
