[Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
- **Approach-1, DFS**
  - [Logic](#logic)
  - [Complexity](#comp)
  - Code
    - [C++](#cpp)

## Number of connected Components
- [Connected Components?](/DS_Questions/Data_Structures/Graphs)
- Graph contains n verteces. Given and an array edges where `edges[i] = [ai, bi]` indicates that there is an edge between ai and bi in the graph.
- Return the number of connected components in the graph.
```c
Example-1
  0 -- 1    3 -- 4
       |
       2
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
  
Example-2:
  0 -- 1 -- 2 -- 3 -- 4
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
```

### Approach-1, DFS
<a name=logic></a>
#### Logic
- _1._ Create Adjacency List(2-D Vector) representing graph using input.
```c
Input: [[0,1],[1,2],[3,4]]

adjacenyList 
        |     |      |     |    |     |
        |1    |0,2   |1    |4   |3    |
index   |0    |1     |2    |3   |4    |
0 is connected to 1
1 is connected to 0,2
2 is connected to 1
3 is connected to 4
4 is connected to 3
```
- _2._ Take bool array called visited, to track number of nodes traversed. size=no of nodes
- _3._ Start from 1st node, traverse all nodes using DFS(stack) until any unvisited node is left.
- _4._ Perform DFS using stack
- _5._ For every disjoint graph, perform DFS. Number of seperate DFS performed=connected Components.

<a name=comp></a>
#### Complexity
> E = No of Edges, V = No of Vertices
**Time:** O(E+V)
  - O(E): Create adjaceny matrix
  - O(V): Visting all nodes using visited bool array
**Space** O(E+V). visited array=V, AdjacencyList=E

#### Code
<a name=cpp></a>
**C++**
```c
class Solution {
    using vec = vector<int>;
    using vecB = vector<bool>;
    using vecVec = vector<vec>;
    uint32_t visitedNodes;
    stack<int> st;

    void dfs(vecVec& adjList, vecB& visited, int start) {           //4
        st.push(start);

        while (st.empty() != 1) {
            int top = st.top(); st.pop();
            visited[top] = true;

            //Find neighbour
            for (int i = 0; i < adjList[top].size(); ++i) {
                if (!visited[adjList[top][i]]) {
                    st.push(adjList[top][i]);
                }
            }
        }
    }
public:
    Solution() {
        visitedNodes = 0;
    }
    int countComponents(int n, vecVec& edges) {
        if (!n)
            return n;

        int connectedComp = 0;
        vecB visited(n, 0);                                 //2
        vecVec adjList(n);

        for (int i = 0; i < edges.size(); ++i) {            //1
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        //If any unvisited node, Perform DFS
        for (int i = 0; i < n; ++i) {                        //3
            if (!visited[i]) {
                dfs(adjList, visited, i);
                connectedComp++;                            //4
            }
        }
        return connectedComp;
    }
}
int main()
{
    Solution o;
    //vector<vector<int>> v = { {0, 1},{1, 2},{3, 4} };    cout << o.countComponents(5, v);
    vector<vector<int>> v = { {0,1},{1,2},{2,3},{3,4} };    cout << o.countComponents(5, v);
}
```
