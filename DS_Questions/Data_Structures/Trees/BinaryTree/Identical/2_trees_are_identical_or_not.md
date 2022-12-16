**Same Tree**
- **Approaches**
  - [Approach-1: Extra space](#a1)
  - [Approach-2(Without Extra Space)](#a2)
- **Code**
  - C++
    - [Recursive](#cr)
    - [Iterative](#ci)

### [My Video. See it before Editing the page](https://youtu.be/ZTNCu_IiuZc)

### [100. Same Tree](https://leetcode.com/problems/same-tree/)
Compare 2 binary trees, return 1 if equal else 0.
```c
Input: p = [1,2,3], q = [1,2,3]
Output: true
   1          1
  / \        /  \
 2  3       2    3
    
Input: p = [1,2], q = [1,null,2]
Output: false
     1       1
    /         \
   2           2
```

<a name=a1></a>
#### Approach-1: Extra space
Traverse tree1 and tree2 in inorder traversal and save in vector1 and vector2. if vectors are same return 1 else 0

<a name=a2></a>
### Approach-2(Without Extra Space)
- Recursively iterate through same nodes of both trees, if at any level not found same, return false. else return true.
- Checks to perform and return false:
  - _1._ if root nodes are not equal
  - _2._ if values of any node not same
  - _3._ if left subtree is empty & right is not empty and viceversa.

#### Code
<a name=cr></a>
- **C++: Recursive**
 ```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

    bool isSameTree(TreeNode* a, TreeNode* b) {
        // if a is empty and b is not empty
        // OR b is empty and a is not empty
        if ((!a && b) || (!b && a))
            return false;
            
        // if a and b both are empty, return true
        if (!a && !b)
            return true;

        return check(a,b);
    }
    
    bool check(TreeNode* a, TreeNode* b) {
          bool ret1 = true, ret2 = true;
          
        // Symetrical trees
        if (a == nullptr && b == nullptr)
            return true;
        
        if (a->val != b->val)
            return false;
            
        // Non symmetrical subtrees, return false
        if ((a->left==nullptr && b->left) ||
            (b->left==nullptr && a->left) ||
            (a->right==nullptr && b->right) ||
            (b->right==nullptr && a->right)
           )
            return false;
        
        ret1 = check(a->left, b->left);
        ret2 = check(a->right, b->right);
        
        return ret1 && ret2;
    }

int main(){
    TreeNode* p2a = new TreeNode(2);
    TreeNode* p3a = new TreeNode(3);
    TreeNode* p1a = new TreeNode(1, p2a, p3a);

    TreeNode* p2b = new TreeNode(2);
    TreeNode* p3b = new TreeNode(3);
    TreeNode* p1b = new TreeNode(1, p2b, p3b);
    
   cout << identicalTrees(p1a, p1b));
}
```

<a name=ci></a>
- **C++: Iterative**
  - [We will use following approach To convert Itertive to recursive](/DS_Questions/Algorithms/Recursion/README.md#ci)
  - Take stack.
    - _1._ Push a,b root on stack.
    - _2._ Pop top 2 elements compare and repeat step-1
    - _3._ if stack becomes empty(that means no more child nodes are there to be added) return true.
```cpp
class Solution {
public:
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if ((a == nullptr && b) || (b == nullptr && a))
            return false;
        
        if (!a && !b)
            return true;
        if (a->val != b->val)
            return false;
        
        stack<TreeNode*> st;
        st.push(a);
        st.push(b);
        
        while (st.empty() != 1){
            auto a1 = st.top(); st.pop();
            auto b1 = st.top(); st.pop();
            
            if (a1->val != b1->val)
                return false;

            if ((a1->left == nullptr && b1->left) ||
                (b1->left == nullptr && a1->left) ||
                (a1->right == nullptr && b1->right) ||
                (b1->right == nullptr && a1->right)
                )
                return false;
        
            if (a1->left && b1->left){
                st.push(a1->left);
                st.push(b1->left);
            }
            if (a1->right && b1->right){
                st.push(a1->right);
                st.push(b1->right);
            }
        }
        return true;
    }
};
```

<a name=comp></a>
### Complexity
#### Time
O(n)
#### Space
O(logn) because at anytime we will only have logn stacks used.
