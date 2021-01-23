## [Problem](https://www.pramp.com/challenge/15oxrQx6LjtQj9JK9XqA)
- Find min cost path. Ans=7
- Example

<img src="https://www.pramp.com/img/content/img_01.png" width="500" />

```c++
      0
    / /  \
   5  3   6
  /  / \   /\
 4   2  0 1  5 
     \   \
      1   10
        \
          1
Paths in Tree:
0->5->4         = 9
0->3->2->1->1   = 7
0->3->0->10     = 13
0->6->1         = 7
0->6->5         = 11
Ans = 7
```
## Complexity
- Time: O(n). Since traversing all nodes
- Space: O(h). h=height of shortest path on tree. System Stack occupied by function call.

## Code
```c++
struct TreeNode{
  int cost;
  vector<Node *> children;
  TreeNode *parent;
};

int GetMinCost(TreeNode* pRoot) {
  if(!pRoot->children.size()){
    return pRoot->cost;
  }
  
 int low = INT_MAX;
  for(auto itr:pRoot->children)
      low = std::min(mini, GetMinCost(itr));

  return pRoot->cost + low;
}
```
