**BTree**

## BTree / B Tree / B-Tree
- Sorted self-balancing search tree (might not be binary). Nodes can have more than 1 children. This makes BTree a **Fat Tree**
  - **Fat Tree** Most of data on same level. Hence depth of tree is less wrt BST & makes efficient wrt BST.
- BTree is used to store huge amount of data that cannot fit in main memory. (Eg: DB)
- **BTree is better wrt Disk Access:** Since DB uses B-Tree/B+Tree. Search time is still better than disk.
- Time complexity(Search, Insert, Delete):	O(log n). n is no of nodes.
```
struct btree{
    int *keys;  // An array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    BTreeNode **C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
}    
```
