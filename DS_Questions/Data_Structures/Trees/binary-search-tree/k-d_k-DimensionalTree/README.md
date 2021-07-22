- [What is k-d Tree](#what)
- Variants
  - [2-d Tree](#2d)
    - [1. Creating 2-d Tree](#create)
    - [2. Implementation](#impl)
    - [if not clear, Good Video from Geeksfgeeks](https://www.geeksforgeeks.org/k-dimensional-tree/)
  - [3-d Tree](#3d)
    - [1. Create 3-d Tree](#3create)

<a name=what></a>
## K-d Tree / k-Dimensional Tree
- This is binary search tree where data in each node is a K-Dimensional point in space. This is a space partitioning data structure for organizing points in a K-Dimensional space.
- A non-leaf node in K-D tree divides the coordinate space into two parts. [See Explanations at geekfgeeks](https://www.geeksforgeeks.org/k-dimensional-tree/)

## Variants

<a name=2d></a>
### 2-d Tree
- For sake of simplicity let's understand 2-d tree. Every node contains 2 values.
<a name=create></a>
#### 1. Create
- Consider following points in a 2-D plane to be inserted into k-d tree:
> (3, 6), (17, 15), (13, 15), (6, 12), (9, 1), (2, 7), (10, 19)
- On level 0,2,4 x corrdinate is compared. On levels 1,3,5 y corrdinate is compared.
- _1._ Since tree is empty insert (3,6) at root
- _2._ (17,15). {Compare (3,6) & (17,15)} 17>3,go right and insert.
- _3._ (13,15). {Compare (3,6) & (13,15) 13>3,go right}, {Compare (17,15) & (13,15) 15=15,go right and insert}
- _4._ (6,12). {Compare (3,6) & (6,12) 6>3,go right} {Compare (17,15) & (6,12) 15>12,go left and insert}
- _5._ (9,1). {Compare (3,6) & (9,1) 9>3,go right}, {Compare (17,15) & (9,1) 15>1,go left}, {Compare (6,12) & (9,1) 9>6,go right, insert}
- _6._ (2,7). {Compare (3,6) & (2,7) 3>2,go left and insert}
- _7._ (10,19). {Compare (3,6) & (10,19) 10>3,go right}, {Compare (17,15) & (10,19) 19>15,go right} {Compare (13,15)&(10,19) 13>10,go left and insert}
```c
      [3,6]                     ........X       //1
      /   \
   [2,7]  [17,15]               ........Y       //2,6
            /   \
        [6,12]  [13,15]         ........X       //3,4
         \         /
         [9,1]  [10,19]         ........Y       //5,7
```

<a name=impl></a>
#### 2. Implementation
```c
const int k = 2;
struct Node {                 // A structure to represent node of kd tree
    int point[k];             // To store k dimensional point
    Node *left, *right;
};

struct Node* newNode(vector<int>& v) {   //Creating new node in kd Tree
    struct Node* temp = new Node;
  
    for (int i=0; i < k; i++)
       temp->point[i] = v[i];
  
    temp->left = temp->right = NULL;
    return temp;
}

// The parameter depth is used to decide axis of comparison
Node *insertRec(Node *root, int point[], unsigned depth) {

    if (root == NULL)               //if tree is empty
       return newNode(point);
  
    // Calculate current dimension (cd) of comparison
    unsigned cd = depth % k;
  
    // Compare the new point with root on current dimension 'cd'
    // and decide the left or right subtree
    if (point[cd] < (root->point[cd]))
        root->left  = insertRec(root->left, point, depth + 1);
    else
        root->right = insertRec(root->right, point, depth + 1);
  
    return root;
}
  
Node* insert(Node *root, int point[]) {         //Inserting new node in kd tree
    return insertRec(root, point, 0);
}
```

<a name=3d></a>
### 3-d Tree
- Every node contains 3 values, ie every point can be represented on 3-d plane.
<a name=3create></a>
#### 1. Create
- _1._ Since tree is empty insert root node there.
- _2._ Inserting (10,2,12) 10>6,go right
- _3._ Inserting (4,12,6) 6>4,go left. Since nothing there insert node.
- _4._ Inserting (9,6,2) 9>6,go right. 6>2,go right. 
```c
Create 3-d tree from points:
(6,8,9), (10,2,12), (4,12,6), (9,6,2)

              (6,8,9)             ........X axis  //1
               /   \
         (4,12,6)  (10,2,12)      ........Y axis  //2,3
                      \
                     (9,6,2)      ........Z axis  //4
```
