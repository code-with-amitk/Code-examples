**Minimum Height Trees**
- Approach(Topological Sort)
  - [Logic](#l)
  - [Code](#co)
  - [Complexity](#c)


### [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/)
- A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
- Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where `edges[i] = [ai, bi]` indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
- Return a list of all MHTs' root labels. You can return the answer in any order.
- The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.)
- A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
- Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where `edges[i] = [ai, bi]` indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
- Return a list of all MHTs' root labels. You can return the answer in any order.
- The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
- Examples
```c
Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
```
<img src=minimum_height_tree1.jpg width=400 />

### Approach (Topological Sort)
<a name=l></a>
#### Logic
- _1._ Create Graph using adjacency list. indegree vector
```c
| 3 | 3 | 3 | 0,1,2,4 | 3,5 | 4 |   //Graph
  0   1   2     3        4    5
  
| 1 | 1 | 1 | 4 | 2 | 1 |            //indegree. Means number of edges
 0    1   2   3   4   5
```
- _2._ Fill all nodes with indegree=1 into queue.
```c
  | 0 1 2 5 |   queue
```
- _3._ Iterate through queue and reduce indegree of neighbours of elements of q by 1
```c
  | 0 1 2 5 |   queue
  top   neighbour   indegree
  0       3         | 0 | 0 | 0 | 3 | 2 | 0 |
  1       3         | 0 | 0 | 0 | 2 | 2 | 0 |
  2       3         | 0 | 0 | 0 | 1 | 2 | 0 |
  5       4         | 0 | 0 | 0 | 1 | 1 | 0 |
  
  Now graph is reduced to:  
  3 -- 4                      (which is the answer)
```
- _4._ We will trim all leaf nodes and finally move towards center of graph and this is how topological sort applies here.
 
<a name=co></a>
#### Code
```cpp
using vecI = std::vector<int>;
using vecVecI = std::vector<vecI>;
using String = std::string;
using graph = std::unordered_map<int, std::unordered_set<int>>;
/*
    n = 4, edges = [[1,0],[1,2],[1,3]]
*/
class Solution {
    public:
    vecI findMinHeightTrees(int n, vecVecI& edges) {
        vecI out;
        if(n == 1)
            out.push_back(0);
        
        /*Indegree for Toplogical Sort
            
            |1|3|1|1|
             0 1 2 3
        */
        vecI indegree(n, 0);
        
        /*Create a Graph using Adjacency List
        
            | 1 | 0,2,3 | 1 | 1 |
              0     1     2   3
        */
        vecVecI graph(n);
        for(auto&i: edges) {
            int from = i[0], to = i[1];
            graph[from].push_back(to);
            graph[to].push_back(from);

            indegree[from]++;
            indegree[to]++;
        }
    
        queue<int> q;
    
        /*Take all nodes having indegree=1
         | 0 2 3 |
         q
        */
        for(int i=0; i<n; i++) {
            if(indegree[i] == 1)
                q.push(i);
        }
    
        while(!q.empty()) {
            out.clear();
        
            for(int i=0; i<q.size(); i++) {
                int top = q.front();
                q.pop();
                
                out.push_back(top);
         
                /*
                top = 0         q|2 3|
                Decrease indegree of neighbours of 0 by 1
                |1|2|1|1|
                 0 1 2 3
                 
                top = 2         q|3|
                |1|1|1|1|
                 0 1 2 3
                */
                for(auto&i: graph[top]) {
                    indegree[i]--;
                
                    //q|3 1|
                    if(indegree[i] == 1)
                        q.push(i);
                }
            }
        }   
        return out;
    }
};
```
