**Clone Graph**
- [Approach-1, DFS](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#c)
    - [Java](#j)
 
### 133. Clone Graph
- Given a reference of a node in a connected undirected graph. Return a deep copy (clone) of the graph.
- Each node in the graph contains a value (int) and a list `(List[Node])` of its neighbors.
```c
class Node {
    public int val;
    public List<Node> neighbors;
}
```
- Example
```c
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
```

<a name=a1></a>
### Approach-1, DFS
#### Logic
- _1._ We will perform [DFS in graph](/DS_Questions/Algorithms/Traversals/DFS/Graphs/). In DFS we traverse all negihbours, keep on marking node visited(to avoid revisit).
- _2._ `unordered_map<old_node*, new_node*> visited;` is used to keep visited nodes. For every node in graph we will clone a new node. key=original_node, value=clone
- _3._ if entry is present in map, we will return the entry else create a new node and return clone.

#### Complexity
- **Time:** O(V+E). V=vertices, E=edges. DFS has time complexity of V+E.
  - O(n). n is number of nodes. At each node visits to neighbouring nodes is reduced, as node is found in map
- **Space:**

#### Code
<a name=cpp></a>
- **CPP**
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* dfs(Node* node){
        Node* clone = nullptr;

        // if node is visited
        // then return clone of node because we
        // need to create new graph with new nodes
        auto it = visited.find(node);
        if (it != visited.end())
            return it->second;

        // If node is not visited, create a deep copy
        // Store copy as value of original node
        clone = new Node(node->val);
        visited.insert({node, clone});

        // Visit all neighbors
        for (auto it:node->neighbors){
            Node* t = dfs(it);
            clone->neighbors.push_back(t);
        }
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        return dfs(node);
    }
};
```

<a name=java></a>
- **Java**
```rs

```
