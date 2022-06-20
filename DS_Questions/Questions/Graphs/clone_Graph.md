 **Clone Graph**
 - [Logic](#l)
 - Code
  - [CPP](#c)
 
### Clone Graph
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

<a name=l></a>
### Logic
Perform DFS, and while doing traversal copy the node into new node.

### Code
<a name=cpp></a>
#### C++
```cpp
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

class Solution {
                  //orig, new
    unordered_map<Node*, Node*> visited;         //Original, Newnode. We return newNode if original is queried
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        
        auto it = visited.find(node);
        if (it != visited.end())
            return it->second;
        
        //Create clone of present node
        Node* clone = new Node(node->val);
        visited.insert({node, clone});
        
        //Iterate thru all neighbors of given node and clone
        for (auto it:node->neighbors){
            clone->neighbors.push_back(cloneGraph(it));
        }
        return clone;
    }
    
};
```
