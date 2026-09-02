**Tree**
- Representation
  - [C++](cpp)
  - [Rust](#r)
- [Terms](#term)
- [Types of Tree](#ty)

## Tree
- Tree has a root, root has 0 or more children. children may or may not have links back to their parent nodes. 
- Tree cannot contain cycles. A tree is type of graph, but not all graphs are trees. A tree is a connected graph without cycles. Eg: Family tree, Unix file system.

### Representation
<a name=cpp></a>
#### CPP
```c
        a                  <-Level 0
    /   |   \    <-Edge
   b     c    z            <-Level 1    //Each Node can have any number of children
 /  \        / \
r    t      g   p

    struct node{        //n children of any node
        int value;
        struct node *leftChild;
        struct node *ImmediateRightSibling;
    }OR
    vector <Node *> children;
```
<a name=r></a>
#### Rust
```rs
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,                //TreeNode*
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
```
- Tree node pointer `Option<Rc<RefCell<TreeNode>>>`
  - Option: `Option<T>` is an enum that represents an optional value (Some or None)
  - Rc: `Rc<T>` (Reference Counted) is a type in Rust that provides shared ownership of a value.
  - RefCell: `RefCell<T>`. Allows mutable borrowing of a value even when it is shared

<a name=term></a>
## Terms
- **1. Height:**   `int h = (max (ht(r->right), ht(r->left)))+1`
  - _a. Of a Node_: Number of edges(Note: edges not node) on the longest path from the node to a leaf. `height of node g=1 (g->h)`
  - _b. Of BT:_ Number of edges from root on longest path to a leaf.    `height=3 (a->z, z->g, g->h)`
- **2. Balancing Factor of a node:** BF = Height_of_left_subtree - Height_of_right_subtree.  If balance factor is not -1,0,1 tree is not balanced, it requires rotation. `bf = ht(t->right) - ht(t->left)`
- **3. External Nodes/Leaves:** nodes which donot have any children.    
- **4. Internal Nodes:** Nodes which are not leaves. they have atleast 1 child.    
- **5. Siblings:** nodes with same parent.
- **6. Depth of a node:** Number of edges(Note: Edges not node) between root and particular node.    `depth of g=2(a->z, z->g).`    Depth of root=0
- **7. Diameter of Tree:** Number of nodes on longest path between 2 nodes of Tree. 

<a name=ty></a>
## [Types of Tree](https://code-with-amitk.github.io/Data_Structures/)
#### 1. Binary Trees
##### 1a. Complete BT
#### 1b. Full BT
##### 1c. Perfact BT
#### 2. Binary Search Tree(BST)/Ordered
#### 3. Sum Tree
#### 4. M Tree
