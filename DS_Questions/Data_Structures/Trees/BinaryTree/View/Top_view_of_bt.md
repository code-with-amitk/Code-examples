**Top View of Binary Tree**
- [Logic](#l)
- [Complexity](#co)
- [Code](#c)

## Top View
Set of nodes visible when the tree is viewed from the top.
```c
       1
    /     \
   2       3
  /  \    / \
 4    5  6   7          //Top view:4 2 1 3 7

        1
      /   \
    2       3
      \
        4  
          \
            5
             \
               6        //Top view:2 1 3 6
```

<a name=l></a>
### Logic
- We calculate top view using [Vertical-order-traversal of Binary Tree]().
```c
Logic: 
 Considering You read and understood(verticalOrderTraversal.cpp), printing topView is very simple.
 - Only print 1st element of vector storing nodes.      map<int, vector<int>> &m
```

<a name=co></a>
### Complexity
- **Time**: O(nlogn)
a. createMapStoringHD_and_NodeVector(): map in STL is Self-Balancing BST. Search for key = O(Logn)
b. printVerticalOrder(): n
 
<a name=c></a>
### Code
```c
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

void createMapStoringHD_and_NodeVector(Node* root, int hd, map<int, vector<int>> &m){
        if (root == NULL)       return;

        m[hd].push_back(root->key);

        createMapStoringHD_and_NodeVector(root->left, hd-1, m);

        createMapStoringHD_and_NodeVector(root->right, hd+1, m);

}

void printVerticalOrder(map<int, vector<int>> &m){
    map<int,vector<int>>::iterator it;

    for (it=m.begin(); it!=m.end(); it++){
            cout<<it->second.front()<<" ";
    }
}

struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node* createTree(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    return root;
}

int main(){
        Node *root;
        root = createTree();
        cout<<"Tree created\n";
        cout<<"Top View:";
        int hd = 0;
        //map<key,value>
        map <int,vector<int>> m;        //key=horizontal_distance, value=vector storing all nodes having 'key' horizontal distance
        createMapStoringHD_and_NodeVector (root, hd, m);

        printVerticalOrder(m);
    return 0;
}
/*
Output:
# ./a.out 
Tree created
Top View:4 2 1 3 7 9
*/
```
