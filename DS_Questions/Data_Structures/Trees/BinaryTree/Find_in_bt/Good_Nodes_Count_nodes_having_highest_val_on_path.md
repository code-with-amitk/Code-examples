- Good Nodes
- Approach-1. DFS
  - [Logic](#logic1)
  - [Complexity](#comp1)
  - Code
    - [C++](#cpp1)
- Approach-2. BFS (queue). Seek leetcode

## [Count Good Nodes](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)
- In binary tree root, a node X in the tree is good if in the path from root to X there are no nodes with a value greater than X.
- Return the number of good nodes in the binary tree.
- Examples
<img src=https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png width=200 />

```c
Ex-1:
    3
   / \
  1   4
 /   / \
3    1  5
O/P=4.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

### Approach-1, DFS
<a name=logic1></a>
#### Logic
- _1._ Initialize prev_high to `root->val`. prev_high represents highest value on this branch.
- _2._ Reach every left, right of node.
- _3._ At everynode check, if my_value >= prev_high(ie until now highest value on branch). Change highest value = present_value and increase count.
<a name=comp1></a>
#### Complexity
- **Time** O(n)
- **Space** O(n). Allocated n stacks
#### Code
<a name=cpp1></a>
- **C++**
```cpp
//Good_Nodes.cpp
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  int goodNodes(TreeNode* root) {
    int min = numeric_limits<int>::min();   //Should use C++ way to get the range of types.
    dfs(root, min);
    return count;
  }

  void dfs (TreeNode* p, int prev_high) {
    if (p->val >= prev_high) {              //3
      count++;
      prev_high = p->val;
    }

    if (p->left)
      dfs(p->left, prev_high);              //2
    if (p->right)
      dfs(p->right, prev_high);
  }
private:
  int count = 0;
};

//main.cpp
#include"Good_Nodes.cpp"
#include <gtest/gtest.h>

TEST(Random, case1) {
  {
    Solution obj;
    TreeNode* p3 = new TreeNode(3);
    TreeNode* p1 = new TreeNode(1,p3,nullptr);
    TreeNode* p1_leaf = new TreeNode(1);
    TreeNode* p5 = new TreeNode(5);
    TreeNode* p4 = new TreeNode(4, p1_leaf, p5);
    TreeNode* p3_root = new TreeNode(3, p1, p4);
           //(Expected_Output, function call)    
    EXPECT_EQ(4, obj.goodNodes(p3_root));
  }
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//CMakeLists.txt
cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

$ cmake .
$ make
$ ./runtests
```
