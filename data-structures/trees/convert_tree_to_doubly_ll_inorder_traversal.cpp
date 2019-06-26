/*
struct tree{
        int data;
        tree *left;
        tree *right;
};
Question: Convert binary tree to Doubly LL, where:
        - left child of node will become previous node and right will become next node in DLL.
        - Order of nodes should be same as Tree traversed in inorder fashion
        - Since, 1st node in inorder traversal is left-most node. So head of DLL is left-most node of tree

        10
       /  \
      12   15
     / \   / 
    25 30 36
 Inorder Traversal: 25 12 30 10 36 15
 Doubly LL to be created: 25 <-> 12 <-> 30 <-> 10 <-> 36 <-> 15

Logic:
1. Traverse Tree in inorder way.
2. take a pointer Node *prev, Which points to previously visited node.
3. if (prev != NULL)
        currentNode's->left = prev
        prev->right = currentNode
4. prev = currentNode

*/
#include<iostream>
struct Node{
        int data;
        Node *left;
        Node *right;
};

Node *createTree(int val){
        Node* ptr = new Node;
        ptr->data = val;
        ptr->left = ptr->right = NULL;
        return ptr;
}

void convertToDLL(Node *root, Node **head){
        if (root == NULL) return;

        static Node* prev = NULL;

        convertToDLL(root->left, head);

        if (prev == NULL)
                *head = root;
        else{
                root->left = prev;
                prev->right = root;
        }
        prev = root;

        convertToDLL(root->right, head);
}

int main(){
        Node *root = createTree(10);
        root->left = createTree(12);
        root->left->left = createTree(25);
        root->left->right = createTree(30);
        root->right = createTree(15);
        root->right->left = createTree(36);
        std::cout<<"Tree Created root="<<root<<std::endl;

        Node *head = NULL;
        std::cout<<"Converting to DLL\n";
        convertToDLL(root, &head);

        while (head!=NULL){
                std::cout << head->data << " ";
                head = head->right;
        }
}
