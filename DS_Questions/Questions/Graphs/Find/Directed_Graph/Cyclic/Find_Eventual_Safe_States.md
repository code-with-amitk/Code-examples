**Find Eventual Safe States**
- [Approach-1. Topological Sort](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

### [Self Video](https://youtu.be/szJDR5g-9wM)

### [802. Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/description/)
- There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where `graph[i]` is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in `graph[i]`.
- A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
- Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
- Example-1
<img src=https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/17/picture1.png size=500 />

```c
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
```

<a name=a1></a>
### Approach-1. Topological Sort
<a name=l></a>
#### Logic
- _1._ Question statement is tricky,
  - But under the hood, we need to find all those nodes in graph which **donot have cycle**.
  - if a node is part of a cycle, it cannot be "eventually safe" as it will have at least one outgoing edge that leads back to the cycle.
  - Therefore, by eliminating nodes with no outgoing edges and their corresponding edges, we gradually remove nodes that are part of cycles until only the "eventually safe" nodes remain.
- _2._ We can find nodes having cycles using topological sort.
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    /* Graph: [[1,2],[2,3],[5],[0],[5],[],[]]
    */
    int size = graph.size();
    vector<vector<int>> incomingNodes(size);
    vector<int> outdegree(size, 0), out;
    queue<int> q;

    /* Create a incoming node vector and 
    incomingNodes 
     | 3 | 0 | 0,1 | 1 | | 2,4 |  |
       0   1    2    3  4   5   6
    
    outdegree
     | 2 | 2 | 1 | 1 | 1 | 0 | 0 |
       0   1   2   3  4    5   6
    */
    for (int i = 0; i < size; ++i) {
        for (int j=0; j<graph[i].size(); ++j) {
            int node = graph[i][j];
            incomingNodes[node].push_back(i);
        }
        outdegree[i] = graph[i].size();
        if (outdegree[i] == 0) 
          q.push(i);
    }

    while (!q.empty()) {
        int front = q.front();  q.pop();
        out.push_back(front);

        /*
          Go to node connecting front
          Reduce outdegree of that node by 1
          if outdegree becomes=0 push on queue.
        */
        for (auto&i : incomingNodes[front]) {
          /*  13% faster
          outdegree[i]--;
          if (!outdegree[i]) 
            q.push(i);
          */
          // 22.32% faster
          if (--outdegree[i] == 0)
            q.push(i);
        }
    }

    sort(out.begin(), out.end());
    return out;
  }
};
```
