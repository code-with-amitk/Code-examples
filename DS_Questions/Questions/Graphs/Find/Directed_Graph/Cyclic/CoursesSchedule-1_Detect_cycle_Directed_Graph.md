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
- This is about finding cycle in directed graph. if cycle is present its not possible to finish the courses, else yes
```c
input = [[1,0], [2,1], [4,3], [5,4], [3,5]]
 0 -> 1 -> 2     3->4->5
                 /\    |
                  |----|
output = false

1. Create incomingNodes graph
  |   |  0  |  1  | 5 | 3 | 4 |
    0    1     2    3   4   5

2. Create outdegree(number of edges going out) vector.
  | 1 |  1  |  0  | 1 | 1 | 1 |
    0    1     2    3   4   5

3. Push all nodes having outdegree=0 in queue
queue | 2 |
  - pop queue. element    //This is like removing node from graph
  - Reduce outdegree of all elements which have edge coming to popped node by 1.
  | 1 |  0  |  0  | 1 | 1 | 1 |
    0    1     2    3   4   5
  - if recently reduced outdegree == 0. Push in queue.
queue | 1 |

4. Finally if outdegree has any element>0, that means there is a cycle in graph.
```

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
