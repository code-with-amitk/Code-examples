/*
                1
              /   \
             2     3
            / \   / \
           4   5  6  7
                    / \
                   8   9
Vertical Order Traversal of Tree? Nodes printed after traversing the tree vertically.
Calculate VO?
        1. Calculate Horizontal Distance(Hd) of nodes from Root
                -> Hd: root(0), left-node(parent-1), right-node(parent+1)
        2. Nodes having same Hd are on same vertical Line.
                -> Print nodes having horizontal distance as (-2,-1,0,1,2..)
                -> Vertically Traversed: 4, 2, 1, 5, 6, 3, 8, 7, 9
                 1(0)
               /      \
             2(-1)      3(+1)
            /   \      /   \
         4(-2)  5(0)  6(0)  7(+2)
                           /    \
                          8(+1)  9(+3)

Logic:
        1. Create and Store values in Hashtable. Hashtable is created using maps container in STL.
           For every Hd we maintain list of nodes in hashmap.
           During tree traversal, we calculate Hd and add the node to the hash map using HD as a key in map.

           Take a C++ map<key, value> = map < int, vector<int> >
                Key = hd of node.
                value = Array of Integers having same hd.
           Hashmap:
                |       |    |    |     |   |   |
                |0|1,5,6|-1|2|-2|4|1|3,8|2|7|3|9|
Map Addresses:  a       a+x  a+y  a+z   a+t
                -> 0, -1, -2, 1, 2, 3 are keys
                -> Respective nodes are stored at keys in map.
          Adding element at hd[-2]:
                m[-2].push_back(node->data);

        2. Printing the tree in Vert Order:
                - Take iterator for printing map. Example:
                   map :: iterator it;          std::map< int,std::vector<int> > :: iterator it;
                - Since iterator points to complete map. Traverse whole map using iterator
                   for (it=m.begin(); it!=m.end(); it++)
                - keys of map is stored in ascending order.
                - Print Second element(ie vector) of map using for loop.
                   for (int i=0; i<it->second.size(); ++i)
*/

#include<iostream>
#include<map>
#include<vector>
struct Node{
        int data;
        Node *left;
        Node *right;
};
Node* createTree(){
        Node *ptr;
        ptr = new Node;
        ptr->data = 1;
        ptr->left = new Node;
        ptr->left->data = 2;
        ptr->left->left = new Node;     ptr->left->right = new Node;
        ptr->left->left->data = 4;
        ptr->left->left->left = ptr->left->left->right = NULL;
        ptr->left->right->data = 5;
        ptr->left->right->left = ptr->left->right->right = NULL;
        ptr->right = new Node;
        ptr->right->data = 3;
        ptr->right->right = new Node;   ptr->right->left = new Node;
        ptr->right->right->data = 7;
        ptr->right->right->right = new Node;    ptr->right->right->left = new Node;
        ptr->right->right->right->data = 9;     ptr->right->right->right->right = ptr->right->right->right->left = NULL;
        ptr->right->right->left->data = 8;
        ptr->right->right->left->right = ptr->right->right->left->left = NULL;
        ptr->right->left = new Node;
        ptr->right->left->data = 6;     ptr->right->left->right = ptr->right->left->left = NULL;
        return ptr;
}

void getVertOrder(Node *root, int hd, std::map< int, std::vector<int> > &m){
        if(!root) return;

        m[hd].push_back(root->data);    //map[key]=value;

        getVertOrder(root->left, hd-1, m);      //store nodes in left subtree
        getVertOrder(root->right, hd+1, m);     //store nodes in right subtree
}

void verticalOrderTraversal(Node *root){
        std::map < int, std::vector<int> > m;
        int hd = 0;
        getVertOrder(root, hd, m);

        std::map< int,std::vector<int> > :: iterator it;
//      std::cout<<"m.size()="<<m.size()<<std::endl;

        for (it=m.begin(); it!=m.end(); it++) {
//              std::cout<<"it->second.size()="<<it->second.size()<<std::endl; 
                for (int i=0; i<it->second.size(); ++i)
                    std::cout << it->second[i] << " ";
                std::cout << std::endl;
        }
}

int main(){
        Node *root;
        root = createTree();
        std::cout<<"\nTree created root="<<root<<std::endl;

        verticalOrderTraversal(root);
        return 0;
}
/*
 Input: Above tree's root node
 Output:
4 
2 
1 5 6 
3 8 
7 
9 
 */
