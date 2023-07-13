**Course Schedule**
- [Approach-1. Topological Sort](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

### [207. Course Schedule](https://leetcode.com/problems/course-schedule/)
- There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
- You are given an array prerequisites where `prerequisites[i] = [ai, bi]` indicates that you must take course bi first if you want to take course ai.
- For example, the pair `[0, 1]`, indicates that to take course 0 you have to first take course 1.
- Return true if you can finish all courses. Otherwise, return false.

<a name=a1></a>
### Approach-1. Topological Sort
<a name=l></a>
#### Logic
- This is about finding cycle in directed graph.
- if cycle is present its not possible to finish the courses, else yes
#### Code
<a name=cpp></a>
**CPP**
```cpp
using vvI = vector<vector<int>>;
using vI = vector<int>;
class Solution {
public:
    bool canFinish(int numCourses, vvI& prerequisites) {

        // Create incoming nodes graph, outdegree
        vvI incomingNodes(numCourses);
        vI outdegree(numCourses, 0);
        for (int i=0; i<prerequisites.size(); ++i) {
            /* Since we have a pair we can directly tell a,b 
                b-->a */
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            incomingNodes[a].push_back(b);
            outdegree[b]++;
        }

        // Push all nodes in queue whose outdegree=0
        queue<int> q;
        for (int i=0; i<outdegree.size(); ++i) {
            if (!outdegree[i])
                q.push(i);
        }
        
        while (!q.empty()) {
            int tempNode = q.front(); q.pop();

            // Reduce outdegree by 1 of all nodes, which have directed edge to tempNode
            for (auto &i: incomingNodes[tempNode]){
                if (--outdegree[i] == 0)
                    q.push(i);
            }
        }

        // if any node has left outdegree > 0, that means those nodes have cycles.
        for (auto&i:outdegree)
            if (i)
                return false;
        return true;
    }
};
```
