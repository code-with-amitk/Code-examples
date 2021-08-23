**Tree**
- [Terms](#term)
- [Types of Tree](#ty)

## Tree
- Tree has a root, root has 0 or more children. children may or may not have links back to their parent nodes. 
- Tree cannot contain cycles. A tree is type of graph, but not all graphs are trees. A tree is a connected graph without cycles. Eg: Family tree, Unix file system.
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
## Types of Tree
#### 1. BINARY TREE 
Each node cannot have more than 2 children. Height = log2n for n number of nodes. Eg: Butterfly Network
```c
        1
       /  \
      2    3
```
#### 2. BINARY SEARCH TREE(BST)/ORDERED 
Mainly used for Searching. Duplicate elements cannot exist. `Left-child < parent, right-child > parent`. Insert/search/delete: O(log(n))
```c
        2
       /  \
      1   3
```
#### 3. FULL/PROPER/2-TREE  
Every node have 0 or 2 children. No node have 1 child
```c
        a
       /  \
     b      c
    /  \   /  \
  d   e   f    g
```  
#### 4. SUM TREE 
Each node is sum of all nodes in its tree
```c

        10
      /   \
     4     6
```    
#### 5. M TREE 
Max m children of any node
```c
              a
          /   |    \
          b   c    d
             | \  /|\ 
````
#### 6. PERFECT TREE
A full & complete BT. All leaves at same level.
```c
        a(Perfect)    a(not perfect)
      /    \              /\
    b       c           b  c
  /    \    /    \       /\  /
```
#### 7. COMPLETE TREE 
All levels are completely filled except possibly last.
```c
            a                       a [Not CT]
           /   \                   /
         b      c                b
      /    \    /               /
    d     e  f                c
```    
