**Height Balanced BST**
- HBT Types
  - [1. AVL Tree](#avl)
  - [2. RBT](#rbt)
  - [3. BTree](#bt)


## Self Balanced / Height Balanced BST / HBT
- HBT always keeps itself balanced by rotation if its BF is not equal to -1,0,1.
```c
BF = Right_Height - Left_Height.    //if bf>2 rotation is needed
```
- **Insert/delete/search** O(logn) even in worst case
- **Problem with BST?** 
  - BST may not be balanced all times, BF depends on incoming data in Real time. Ex: `[t = 1. data=9] [t=2 data=8] [t=3 data=7]`. Instead of BST linear array is created.
```c
            9
          /
        8
      /
    7
```
- HBT Example:
```c
     3 (bf:-2). Not Balanced. Need rotation at this node              5(bf: -1). HBT 
    /                                                                /  \
   2(bf:-1)                                                 (bf: -1)4      6(bf: 0)
  /                                                                /
 1(bf:0)                                                          3(bf: 0)
```

## HBT Types
<a name=avl></a>
### 1. AVL / Adelson-Velsky and Landis
- Rotation Examples in AVL Tree
- *a. Left & right rotation:* Similarly we can perform right,left rotation.
```c
      6              6
     /              /
    3     -->      4    -->      4
     \            /            /   \
      4          3            3     6
```

<a name=rbt></a>
### 2. Red Black Tree
- [Tushar Roy Video](https://www.youtube.com/watch?v=UaLIHuR1t8Q&t=883s)
- Each node have color(red or black). 
```c
  struct node{ 
    int item;  
    enum{red, black}color;
    struct node *parent, *left, *right; 
  };
  
                          |
      |item|color|*left|*parent|*right|
                  /                 \
```
#### Creating RBT
> Create RBT using `1,2,3,4,5,6,7,8`. 
- *a.* Node is inserted based on bst `if (node>root) right else left`. After insertion [Rules to check RBT](Rules_to_Check_RBT_or_not).
- **b. Rules of Insertion**
  - *1.* If tree is empty add a black node.
  - *2.* Insert new leaf node as Red.
    - *2a.* 2 adjacent Red Nodes
```c
Rule-1     Rule-2      Rule-2
1,B   ->    1,B          1,B
             \     ->     \
              2,R          2,R
                            \
                             3,R //Voilates a. Two adjacent
                                   Red not allowed. 
```
#### Rules to check RBT or Not?
- *a.* Each node has color either red or black.
- *b.* Root is always black.   
- *c.* 2 adjacent red nodes Not Allowed. 2 adjacent black nodes allowed. ie No Red-Red parent child relationship.
- *d.* Every path from a node to its leaf NULL child has the same number of black nodes.
- *e.* Add null children at leaf. null children are always black(But donot consider null while considering rule-d).
```html
    B(not RBT                  B(RBT)              B(not RBT, violates rule-c)
   /  violates rule-d)       /    \               /
   B                        R      B             R
  /                        / \    /               \
 B                        B  B  R                  R
```
#### Correcting Rule Voilation
- **Rules of Insertion**
  - *1.* If tree is empty add a black node.
  - *2.* Insert new leaf node as Red. 
  - Check Rules to be RBT
```c
    if (self_color == RED && self->parent_color == RED){
            if(self == right_child && self->parent == right_child){
                if(uncle == black){                                                                                   //2a
                    Recolor self->parent=black, grandparent=red. No change in self color
                    single_rotation,                                                                                    
                }else if(uncle == Red){
                    push blackness down from grandparent.                                                 //2b
                    Colorflip grandparent
                    if root becomes red, Recolor to Black
                }
```                
  - *3.* Color properties are satisfied, But tree is not Balanced. BF != 0,1,-1
```c
    Rotate on Root.
    if(root==Red) 
        Recolor root=Black
        Recolor children of Root to Red
        Recolor Grandchild/children to Black to adjust color property
```        

<a name=bt></a>
### BTree / B Tree / B-Tree
- Sorted self-balancing search tree (might not be binary). Nodes can have more than 1 children. This makes BTree a **Fat Tree**
  - **Fat Tree** 
    - Most of data on same level. Hence depth of tree is less wrt BST & makes efficient wrt BST.
    - Each node contain B-1 to 2B-1 elements in a contiguous array, hence we need not allocate every time element is inserted & improve cache efficiency.
    - _Searching_ might become linear but its better wrt BST.
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

