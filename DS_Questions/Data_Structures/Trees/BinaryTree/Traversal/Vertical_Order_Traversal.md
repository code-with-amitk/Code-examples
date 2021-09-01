**Vertical Order Traversal**
- [Horizontal Distance](#hd)
  - [Logic](#lh) 

Video: https://www.youtube.com/watch?v=PQKkr036wRc

## Vertical Order Traversal(VOT) 
- Nodes printed after traversing the tree vertically.
- To print nodes in VOT we need to calculate Horizontal Distance(HD) of each node.

<a name=hd></a>
### Horizontal Distance
- **HD?** This is horizontal distance of nodes from a imaginary wall placed on left side of tree.
- **Why HD?** Nodes having same HD fall on same vertical line. NOTE: WE CANNOT DRAW PERFACT BT having nodes falling under each other perfactly.
- **Calculating HD**
```c
  HD of root = 0   //HD of root is taken 0
  if node is left child, its HD = (hd_of_parent - 1)
  if node is right child, its HD = (hd_of_parent + 1)
```
- **Example:** Calculating HD of each node on this tree
```c
                         1
                      /      \
                    2         3
                   /   \      /   \
                  4     5    6     7
                                  /   \
                                 8    9                             
HD of nodes represented:
  Imaginary_wall        
        |                 1(0)
        |              /      \
        |            2(-1)      3(+1)
        |           /   \      /   \
        |        4(-2)  5(0)  6(0)  7(+2)
        |                          /    \
        |                         8(+1)  9(+3)
        -----------number line------------------>

HD of node 1 = 0
HD of node 2 = 0-1 = -1
HD of node 3 = 0+1 = 1
HD of node 4 = -1-1 = -2

HD ->   -2      -1      0       1       2       3
--------------------------------------------------
nodes->  4       2      1       3       7       9
                        5       8
                        6
Vertical_order_traversal = 4 2 1 5 6 3 8 7 9   //Node 4 is nearest, Node 9 is farthest from Imaginary_wall
Nodes(1,5,6), (3,8) fall on same vertical line
```
<a name=lh></a>
#### Logic of Calculating HD
```c
1. Calculate and store HD of nodes.   createMapStoringHD_and_NodeVector(Node* root, int hd, map<int, vector<int>> &m)
   Take map<key,value> to store map<horizontal_distance,(values)>.   map <int, vector<int>> m
   Store key=horizontal_distance and value=list_of_all_nodes_having_key_as_HD
      map < int, vector<int> >
      Key = hd of node.                 -> 0, -1, -2, 1, 2, 3
      value = Array of values from tree having same hd.
           Hashmap:
                |       |    |    |     |   |   |
                |0|1,5,6|-1|2|-2|4|1|3,8|2|7|3|9|
                |       |    |    |     |   |   |

         m[-2].push_back(node->data);       //Adding element at hd[-2]. Map cannot have duplicate keys so, when same key 
         is encounterd again. push_back() performs pushing back on same key's vector element.

2. Printing the tree in Vert Order:   printVerticalOrder(map<int, vector<int>> &m)
  - Pass the created map to print fuction.
  - Take iterator. point it passed map
  - Print Second element(ie vector) of map using for loop
```  

<a name=co></a>
### Complexity
- **Time:** O(nlogn)
a. createMapStoringHD_and_NodeVector(): map in STL is Self-Balancing BST. Search for key = O(Logn)
b. printVerticalOrder(): n

<a name=c></a>
### Code
```c
#include<iostream>
#include<map>
#include<vector>
struct Node{
        int key;
        Node *left, *right;
};

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

void createMapStoringHD_and_NodeVector(Node* root, int hd, map<int, vector<int>> &m){
        if (root == NULL)       return;

        m[hd].push_back(root->key);

        createMapStoringHD_and_NodeVector(root->left, hd-1, m);

        createMapStoringHD_and_NodeVector(root->right, hd+1, m);
}

void printVerticalOrder(map<int, vector<int>> &m){
    map<int,vector<int>>::iterator it;

    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)   //first:key, second:value
            cout << it->second[i] << " ";
        cout << endl;
    }
}


int main(){
        Node *root;
        root = createTree();
        std::cout<<"\nTree created root="<<root<<std::endl;

        int hd = 0;
  
        //map<key,value>
       //key=horizontal_distance, value=vector storing all nodes having 'key' horizontal distance
        map <int,vector<int>> m;
        createMapStoringHD_and_NodeVector (root, hd, m);

        printVerticalOrder(m);
        return 0;
}
/*
Output:
Tree created
4 
2 
1 5 6 
3 8 
7 
9 
 */
```
