/*
 Bottom View? set of nodes visible when the tree is viewed from the bottom

                      20
                    /    \
                  8       22
                /   \      \
              5      3      25
                    / \
                  10    14      //bottom view: 5, 10, 3, 14, 25

 We calculate bottom view using Vertical-order-traversal of Binary Tree.

 You are required to understand,
 a. What is Vertical-order-traversal
 b. How it is calculate using Horizontal_distance
 github/Code-examples/data-structures/trees/verticalOrderTraversal.cpp

TO UNDERSTAND TOP VIEW CODE:
READ VERITICAL_ORDER_TRAVERSAL
        -> github/Code-examples/data-structures/trees/verticalOrderTraversal.cpp

Logic: 
 Considering You read and understood(verticalOrderTraversal.cpp), printing bottom View is very simple.
 - Only print last element of vector storing nodes.     map<int, vector<int>> &m
 
TIME COMPLEXITY: O(nlogn)
a. createMapStoringHD_and_NodeVector(): map in STL is Self-Balancing BST. Search for key = O(Logn)
b. printVerticalOrder(): n
*/

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
            cout<<it->second.back()<<" ";
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
        cout<<"Bottom View:";
        int hd = 0;
        //map<key,value>
        map <int,vector<int>> m;        //key=horizontal_distance, value=vector storing all nodes having 'key' horizontal distance
        createMapStoringHD_and_NodeVector (root, hd, m);

        printVerticalOrder(m);
    return 0;
}
/*
Output:
# g++ bottom_view_of_bt.cpp 
# ./a.out 
Tree created
Bottom View:4 2 6 8 7 9 
*/
