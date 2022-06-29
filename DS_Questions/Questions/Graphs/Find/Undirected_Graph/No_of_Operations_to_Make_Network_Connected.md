**Number of Operations to Make Network Connected**
- [Approach-1, Connected Components in Graph](#a1)
  - [Code](#c1)


## [Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)
- There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where `connections[i] = [ai, bi]` represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
- You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
- Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1
```
Example-1:
Input: number of nodes = 4, edges = [[0,1],[0,2],[1,2]]
0 -- 2          0 -- 2
|  /      =>    |
1    3          1 -- 3
Output: 1   //Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example-2:
Input: number of nodes = 6, edges = [[0,1],[0,2],[0,3],[1,2],[1,3]]
0 -- 1                    0 -- 1 -- 4
| \ /|      4             |    |
| / \|            =>      |    |
2    3      5             2    3 -- 5

Output: 2
```

<a name=a1></a>
### Approach-1, Connected Components in Graph
- This is similar to finding [number of Islands](/DS_Questions/Questions/vectors_arrays/2d-grid/Matrix_of_0_1/Count_No_of_Islands.md)
- We know
```c
number of edges to connect n nodes is n-1

if (edges < number_of_nodes+1)
  Not possible//return -1
```
- Perform DFS(without stack) just mark all nodes in connected component as visited.
- When new DFS is started that means new connected componenet, increment count by 1
- wires needed = component - 1

<a name=c1></a>
#### Code
```cpp
using vecI = std::vector<int>;
using vecB = std::vector<bool>;
using vecVecI = std::vector<vecI>;
using ListI = std::list<int>;
using UnM = std::unordered_map<int, ListI>;

class Solution {
    void dfs(vecVecI &adj, vecB &visited, int src) {
        visited[src] = true;
        for(int i : adj[src])
            if(!visited[i])      //if connected node is not visited, Perform DFS on it
                dfs(adj, visited, i);
    }
public:
    int makeConnected(int no_of_nodes, vecVecI& edges) {
        
        //n-1 edges are needed to connect n nodes
        //if nodes are Greater than edges+1, we cannot connect
        if(no_of_nodes > edges.size() + 1)
            return -1;

        //if above condition does not return -1, we are sure solution exists
        //(ie we have enough wires=edges) to connect nodes, solution = connected_components - 1
        //Consider 0123 as 1 node, 4,5 as seperate nodes, We need 2 wires to connect 0123, 4, 5
        vecVecI adj(no_of_nodes);
        for(auto v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        //Create visited array of size=number of nodes
        vecB visited(no_of_nodes, false);
        int components = 0;

        //Traverse through all nodes in graph
        for(int i=0; i<no_of_nodes; i++)

            //if node is not visited, Perform DFS from that node
            if (visited[i] == false) {
                components++;
                dfs(adj, visited, i);
            }
        return components - 1;
    }

};
```
