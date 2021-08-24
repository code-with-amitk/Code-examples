**297. Serialize and Deserialize Binary Tree**
- [Logic](#log)
- [Complexity](#comp)
- [Code](#cpp)


### [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
- **Serialization?** is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
```c
  tree-data-structure -> 0 1 0 0 1 1
Here,
  tree-data-structure -> string
```
- **Question?** Design an algorithm to serialize and deserialize a binary tree to/from string.
- Examples
```c
Ex-1:
    1
   / \
  2   3
     / \
    4   5
Input: [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Ex-2:
Input: root = [1,2]
Output: [1,2]
```

<a name=log></a>
### Logic
- **Serialize**
  - This function takes root pointer, and return `vector<string>`
  - Traverse tree in preorder manner, and store nodes in `vector<string>` //`vector<string> = {1, 2, 3, 4, 5}`
  - if `root* == null` return null
- **Deserialize**
  - Takes `vector<string>`, create BT and return `Tree Root*`. 
  - 1st element would be root. and then all will be left and right.
  - if `vector<string>.size() == 0` return null
  - else 
    - Allocate root node, convert string to int
      - Do it repetedly for left,rigth nodes and increment counter in `vector<string>`

<a name=comp></a>
### Complexity
- **Time:** O(n)
- **Space:** O(n)

### Code
<a name=cpp></a>
**C++**
```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
    using vecS = vector<string>;
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* root, vecS& out) {   //preorder traversal
        if (root == nullptr) {
            out.push_back("null");
            return;
        }
        
        out.push_back(to_string(root->val));
        dfs(root->left, out);
        dfs(root->right, out);
    }
    
    vector<string> serialize(TreeNode* root) {       //Returns vector<string>, BT converted to vector<string>
        vecS out;
        dfs(root, out);
        return out;
    }

    TreeNode* deserialize(vecS data) {              //Return root*
        int index = 0;
        return deserialize(data, index);
    }
    
    TreeNode* deserialize(vecS& data, int i) {
        if (i >= data.size() || data[i] == "null") {
            return nullptr;
        }
        
        TreeNode* n = new TreeNode(stoi(data[i]));
        n->left = deserialize(data, ++i);
        n->right = deserialize(data, ++i);
        
        return n;
    }
};
```
