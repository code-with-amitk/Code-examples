/*
Maximum Path Sum?
- Given a binary tree in which each node element contains a number. Maximum path sum is [Maximum possible sum from one leaf node to another].
- The path may start and end at any node in the tree.
       -15
      /   \
     5     6
    / \   / \
   -8  1 3   9
  / \       / \
 2  -3         0
              / \
             4   -1
                 /
                10
Logic:
For each node there can be four ways that the max path goes through the node:
1. Node only
2. Max path through Left Child + Node
3. Max path through Right Child + Node
4. Max path through Left Child + Node + Max path through Right Child
The idea is to keep trace of four paths and pick up the max one in the end. An important thing to note is, root of every subtree need to return maximum path sum such that at most one child of root is involved. 

*/
#include<iostream>
#include<climits>
struct Node{
        int data;
        Node *left;
        Node *right;
};

Node *createNode(int val){
        Node *temp = new Node;
        temp->data = val;
        temp->left = temp->right = NULL;
        return temp;
}

Node *createTree(){
        Node *ptr = createNode(-15);
        ptr->left = createNode(5);      ptr->right = createNode(6);
        ptr->left->left = createNode(-8);       ptr->left->right = createNode(1);
        ptr->right->right = createNode(9);      ptr->right->left = createNode(3);
        ptr->left->left->left = createNode(2);  ptr->left->left->right = createNode(-3);
        ptr->right->right->right = createNode(0);       ptr->right->right->right->right = createNode(-1);       ptr->right->right->right->left = createNode(4);
        ptr->right->right->right->right->left = createNode(10);
        return ptr;
}

int findMaxUtil(Node* root, int &res)
{
        if (root == NULL)       return 0;

        // l and r store maximum path sum going through left and right child of root respectively 
        int l = findMaxUtil(root->left,res);
        int r = findMaxUtil(root->right,res);

        //Max path for parent call of root. This path must include at-most one child of root 
        int max_single = std::max(std::max(l, r) + root->data, root->data);

        //Max Top represents the sum when the Node under consideration is the root of the maxsum path and no ancestors of root are there in max sum path 
        int max_top = std::max(max_single, l + r + root->data);

        res = std::max(res, max_top);    // Store the Maximum Result.
        return max_single;
}

int findMaxSum(Node *root)
{
        int res = INT_MIN;      //Initialize to least -ve value. -2147483648
        std::cout<<"res = "<<res<<std::endl;
        findMaxUtil(root, res);
        return res;
}

int main(){
        Node *root;
        root = createTree();
        std::cout<<"Tree created:"<<root<<std::endl;
        std::cout<<"Max sum="<<findMaxSum(root);
}
