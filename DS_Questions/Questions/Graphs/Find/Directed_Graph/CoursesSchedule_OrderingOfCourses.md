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
- What is [Toplogical Sort of Directed cyclic graph](/DS_Questions/Data_Structures/Graphs/).
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
#### Logic
- _1._ Create Adjacency list representing directed graph
```c
vector<vector<int>> al;

 | 1,2 | 3 | 3 |  |
   0     1   2   3
```
- _2._ Start from node=0. Traverse all its neighbours(connected nodes) recursively.
```c
  for (auto i : al) 
    dfs (i)
```
- _3._ if node does not have any outdegree push on vector.
```c
  node=3
  out.push_back(3)
```
- _4._ Reverse the vector and return.

<a name=cpp></a>
#### Code
```cpp
class Solution {
    using VectorInt = vector<int>;
    using VectorBool = vector<bool>;
    using VectorVectorInt = vector<VectorInt>;
    
    VectorInt out;

    bool dfs(VectorVectorInt& g, VectorBool& todo, VectorBool& done, int node) {
        if (todo[node])
            return false;

        if (done[node])
            return true;

        todo[node] = done[node] = true;

        for (int neigh : g[node]) {
            if (!dfs(g, todo, done, neigh)) {
                return false;
            }
        }
        out.push_back(node);
        todo[node] = false;
        return true;
    }   
public:
    VectorInt findOrder(int numCourses, VectorVectorInt& prerequisites) {
        VectorVectorInt adjList(numCourses);          //Minmum size should be 2
        if (!prerequisites.size()) {
            if (numCourses == 1)
                out.push_back(0);
            return out;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (numCourses == 2 && i == 1) {
                continue;
            }
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        VectorBool todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !dfs(adjList, todo, done, i)) {
                return {};
            }
        }
        reverse(out.begin(), out.end());
        return out;
    }
};
```
