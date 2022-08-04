**Minimum Height Trees**
- **Approach-1 (Topological Sort)**
  - [Logic](#l)
  - [Code](#co)
  - [Complexity](#c)
- **[Approach-2 DFS = TLE](#a2)**
  - Code


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

<a name=a2></a>
### Approach-2 DFS=TLE. O(n<sup>2</sup>)
#### Logic
- For every node, find height till deepest node. Note that height for all nodes.
- In end whatever nodes which have least heights, output those
#### Code
```c
#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<unordered_map>
#include<queue>
#include<stack>
#include<unordered_set>
#include<atomic>
using vecI = std::vector<int>;
using vecVecI = std::vector<vecI>;
using String = std::string;
using graph = std::unordered_map<int, std::unordered_set<int>>;
bool bStart = false;
std::condition_variable cv;
std::mutex m;

class Solution {
    graph g;
    void add_node(int from, int to){
            std::unordered_set<int> us;
            auto it = g.find(from);
            if (it != g.end())
                us = it->second;

            us.insert(to);
            g[from] = us;
    }
    void create_graph (int n, vecVecI& edges){
        for (int i=0;i<edges.size();++i){
            int from = edges[i][0], to = edges[i][1];
            add_node(from, to);
            add_node(to, from);
        }
    }
public:
    vecI findMinHeightTrees(int n, vecVecI& edges) {
        vecI out;
        if (n==1)
            return {0};
        create_graph(n, edges);

        graph umHeightNode;
        std::unordered_set<int> usNodeIterator;
        int minimum = INT_MAX;

        using mpair = std::pair<int, std::vector<int>>;
        std::priority_queue <mpair, std::vector<mpair>, std::greater<mpair>> pq;
        
        //Perform DFS
        std::stack<int> st;
        for (int i=0;i<n; ++i){
            //We will calculate distance of every node from given node
            st.push(i);
            std::vector<bool> visited(n, false);
                            //distance, node
            std::unordered_map<int, int> um;
            um[i] = 0;
            int distance = 0;

            while (!st.empty()){
                int node = st.top(); st.pop();
                visited[node] = true;
                //Check all unvisited neighbours of this node
                auto us = g.find(node)->second;
                for (auto it=us.begin(); it!=us.end();++it){
                    if (!visited[*it]) {    //Only for unvisited neighbours
                        int dis = um.find(node)->second + 1;
                        um[*it] = dis;
                        st.push(*it);
                        distance = std::max(dis, distance);
                    }
                }
            }
            //Insert in unordered_map
            std::unordered_set<int> usNode;
            auto it = umHeightNode.find(distance);
            if (it != umHeightNode.end())
                usNode = it->second;
            usNode.insert(i);
            umHeightNode[distance] = usNode;

            if (minimum >= distance) {
                usNodeIterator = umHeightNode[distance];
                minimum = distance;
            }

            //pq.emplace({distance, i});
            std::cout << "Max height of tree rooted at:" << i << " is:" << distance << "\n";
        }
        for (auto it=usNodeIterator.begin(); it!=usNodeIterator.end();++it)
            out.push_back(*it);

        return out;
    }
};

int main() {
    Solution s;
    //int n =4, vecVecI edges = {{1,0},{1,2},{1,3}};
    //int n=6; vecVecI edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    int n=2; vecVecI edges = {{0,1}};
    vecI out = s.findMinHeightTrees(n, edges);
    for (auto&i:out)
        std::cout << i << ",";
}
```
