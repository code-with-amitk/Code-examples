**kth Ansector of Node in Binary Tree**
- **Approaches**
  - [Approach-1, Linear, O(n)](#a1)
  - **Approach-2, Binary Lifting, O(logn)**
    - [Idea](#i)
    - [Logic](#l)
    - [Complexity](#c)
- [Leetcode problem, Kth Ancestor of a Tree Node](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/)
  - [Problem](#p)
  - [Logic](#l)
  - [Complexity](#c)
  - **Code**
    - [C++](#cpp)



https://www.youtube.com/watch?v=oib-XsjFa-M

## Find kth Ansector of Node in Binary Tree
**Problem?** Find kth(k=6) ansector of node=10. Answer=0
```c
          0   <6th
         / 
        1     <5th
         \
          4   <4th
         /
        7     <3rd
         \
          8    <2nd
           \ 
            9  <1st
             \
              10
```
<a name=a1></a>
## Approach-1 / Linear / O(n)
To find nth ansector of node, Traverse from node n times up.

## Approach-2 / Binary Lifting / log(n)
<a name=i></a>
### Idea
> (1,2,4,8,16,32,64,128.. These are Power of 2)
- _1._ Precompute/Precreate a dp-table which stores nodes present at power of 2 from last node in tree.
```c
dp-Table of 10
Place   Node
1       9         //At 1st place from 10, 9 is present
2       8         //At 2nd, 8
4       4         //At 4th, 4
```
- _2._ For k=6. Perform 2 Jumps, Since 6=4+2. Hence only in 2 steps we can find kth ansector
```c
Jump=1. Place=4. Node=4
Jump=2. From 4 to 2 places. Node=0
```
<a name=l></a>
### Logic
- _1._ How know parent(k=1), Grandparent(k=2), Grand-grand-grandParent(k=4) so on..
  - Parent(steps=1). So for node=10, k=1 we can know. 
  - Grandparent(steps=2). For (node=10, grandparent=parent_of_parent=8), if we note parent of 9 while traversing down, we will know grandparent of 10.
  - Grandparent(number=4), node=4. Same as step-2.
- _2._ Create a 2-d array storing 2<sup>n</sup> ancestor of node.
```c
       x   0   1   2   3   4     <-Ancestor
 1     0   
 2     1       
 3     4       0                   //0 is 2^1=2nd ancestor of node=4.
 4     7 
 5     8
 6     9
 7     10  9   8  4                //9 is parent=2^0 ancestor of 10. 8 is grandparent=2^1=2nd ansector of node=10. 4 is 2^2=4th ansector of 10
index  /\
      Node
  
dp[10][0] = parent = 8
dp[10][1] = dp[ dp[10][0] ][0] = 9       //GrandParent(is parent of parent) = parent[parent].
dp[10][2] = 4 = dp [ dp[10][1] ][1]      //dp[10][1] is 10th Grandparent(2nd ancestor). My 2nd ancestor's, 2nd anscestor is my 4th anscestor
..

for i=0 .. n               //For every node(i=0 to n). Here i means nodes
  dp[i][0] = parent[i]
  for j=1 .. 2,4,8..          //Every 2^n ancestor
    dp[i][j] = dp[ dp[i][j-1] ][j]            //Derived from above
```
<a name=c></a>
### Complexity
- **Time:** O(nlogm).   n=nodes, m=max depth
- **Space:** O(nlogm)

<a name=p></a>
## Leetcode Problem
- We are given a tree with n nodes numbered from (0 .. n - 1).
- Also parent array where `parent[i]` is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.
- The kth ancestor of a tree node is the kth node in the path from that node to the root node.
- Implement the TreeAncestor class:
```c
TreeAncestor(int n, int[] parent) 
  Initializes the object with the number of nodes in the tree and the parent array.
  
int getKthAncestor(int node, int k) 
  Return the kth ancestor of the given node node. If there is no such ancestor, return -1.
```
- Example
```c
      0
     / \
    1   2 
  /  \  / \
 3   4  5  6
 
Input
["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]    //Function called
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]                     //Arguments to function

            numberofNodes parent
TreeAncestor(7,           {-1, 0, 0, 1, 1, 2, 2})
-1: no parent of 0
0,0: 0 is parent of 1,2
1,1: 1 is parent of 3,4
2,2: 2 is parent of 5,6

getKthAncestor(3, 1)                            //Get 1st ancestor of 3. Ans=1
getKthAncestor(5, 2)                            //Get 2nd ancestor of 5. Ans=0
getKthAncestor(6, 3)                            //Get 3rd ancestor of 6. Ans=-1

Output
[null, 1, 0, -1]
```

### Code
<a name=cpp></a>
#### C++
```cpp
class TreeAncestor {
    vector<vector<int>> dp; // int up[N][20];
    vector<int> depth;
    int logNDepth;
public:
    TreeAncestor(int n, vector<int>& parent) {
        logNDepth = 0;
        //Find log2(size), this will be number of coloumns of our 2d dp array
        logNDepth = log2(n) + 1;

        dp = vector<vector<int>>(n, vector<int>(logNDepth));
        
        depth = vector<int>(n);
        
        // dp[i][j] is 2^j -th ancestor of node i
        //dp[1][2] is 2^2=4th ansector of Node=1
        //dp[2][3] is 2^3=8th ansector of Node=2
        parent[0] = 0;
        for(int i = 0; i < n; i++) {
            dp[i][0] = parent[i];
            if(i)
                depth[i] = depth[parent[i]] + 1;
            
            for(int j = 1; j < logNDepth; j++)
                dp[i][j] = dp[ dp[i][j-1] ][j-1];
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) {
            return -1;
        }
        for(int j = logNDepth - 1; j >= 0; j--) {
            if(k >= (1 << j)) {                 //if jth bit is found, then we will go up
                node = dp[node][j];
                k -= 1 << j;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
```
