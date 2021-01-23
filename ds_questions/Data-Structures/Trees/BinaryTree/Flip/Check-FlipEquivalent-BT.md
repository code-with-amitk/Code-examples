## [Problem](https://leetcode.com/problems/flip-equivalent-binary-trees/)
- Given 2 binary trees we need to check whether 1 can be obtained by flipping the other or not?
- A BT X is flip equivalent to a BT Y if and only if we can make X equal to Y after some number of flip operations.
- Given 2 BT's return True if both are flip equivalents false otherwise

### Example-1
```c
- Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
- Output: true
- Explanation: root2 is obtained after flipping at nodes 1,3,5
       1                  1                   
     /   \              /  \
    2     3            3     2
   / \    /            \    / \
  4   5  6              6  4   5
     / \                      / \
    7   8                    8   7
    root1                 root2
```

### Logic (Modified Pre-order Traversal)
- How pre-order works. Print node go left,right(recursively). Now if we modfiy pre-order that print node and go to smaller node 1st, then in both cases print would be 1,2,3. And this is the flip.
- Store both trees pre-order traversal in vectors. if vectors are equal return 1 else not.
```c++
    1        1
   / \      / \
  2   3    3   2
  
  Print node
  Find which child is smaller
    if(left<right)  goto left 1st
    else    goto right 1st
```

### Code
```c++
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//T1 = bool, T2 = int
//Coding Convention
  //prefix i:int, p:pointer, st:Structure, pst:pointer to Structure
  //Function name: CamelCase
template< typename T1, typename T2 >
class Solution {
public:
  void DepthFirstSearch(TreeNode* pstNode, vector< T2 >& v) {
    if (pstNode != NULL) {
      v.push_back(pstNode->val);
      T2 iLeft = pstNode->left != NULL ? pstNode->left->val : -1;
      T2 iRight = pstNode->right != NULL ? pstNode->right->val : -1;

      //Modified Pre-order. Goto smaller node
        //Print node
        //Find which child is smaller
        //if(left<right)  goto left 1st
        //else    goto right 1st
        //Go to the node which is s
      if (iLeft < iRight) {
        DepthFirstSearch(pstNode->left, v);
        DepthFirstSearch(pstNode->right, v);
      } else {
        DepthFirstSearch(pstNode->right, v);
        DepthFirstSearch(pstNode->left, v);
      }
    }
  }
  T1 flipEquiv(TreeNode* pstRoot1, TreeNode* pstRoot2) {
    vector< T2 > v1, v2;
    DepthFirstSearch(pstRoot1, v1);
    for(auto i:v1)      //1 2 4 5 7 8 3 6 Pre-order traversal
      cout<<i<<" ";
    cout<<endl;

    DepthFirstSearch(pstRoot2, v2);
    for(auto i:v2)      //1 2 4 5 7 8 3 6
      cout<<i<<" ";
        cout<<endl;

    return v1 == v2;
  }
};

int main(){
  TreeNode a7(7);
  TreeNode a8(8);
  TreeNode a5(5,&a7,&a8);
  TreeNode a4(4);
  TreeNode a2(2,&a4,&a5);
  TreeNode a6(6);
  TreeNode a3(3,&a6,nullptr);
  TreeNode a1(1,&a2,&a3);

  TreeNode b8(8), b7(7);
  TreeNode b5(5,&b8,&b7);
  TreeNode b6(6), b4(4);
  TreeNode b2(2,&b4,&b5);
  TreeNode b3(3,nullptr,&b6);
  TreeNode b1(1,&b3,&b2);

  Solution < bool, int >s;
  cout<<s.flipEquiv(&a1,&b1);
}  
```
