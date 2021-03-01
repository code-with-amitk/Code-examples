/*
    1
   / \
  2   3
     / \
    4   5

Question:
- Serailize the Tree as "[1,2,3,null,null,4,5]"
- Deserialize will create the tree back again
*/

class Codec {
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* root, vector<string>& sol) {   //preorder traversal
        if (root == nullptr) {
            sol.push_back("null");
            return;
        }
        
        sol.push_back(to_string(root->val));
        dfs(root->left, sol);
        dfs(root->right, sol);
    }
    vector<string> serialize(TreeNode* root) {
        vector<string> sol;
        dfs(root, sol);
        return sol;
    }

    TreeNode* deserialize(vector<string> data) {
        int index = 0;
        return deserialize(data, index);
    }
    TreeNode* deserialize(vector<string>& data, int& i) {
        if (i >= data.size() || data[i] == "null") {
            return nullptr;
        }
        
        TreeNode* n = new TreeNode(stoi(data[i]));
        n->left = deserialize(data, ++i);
        n->right = deserialize(data, ++i);
        
        return n;
    }
};
