/*      connect_nodes_at_same_level.cpp
                        1
                       / \
                      2   3
                     / \ / \
                    4  5 6  7

Situation/Task: Connect all adjacent nodes in BT.
Result:
                         1->N
                       /  \
                      2 -> 3
                     / \  / \
                    4->5->6->7

****************Logic*****************
- Use modified BFS(Level Order Traversal). BFS uses Queue
- Also Insert NULL into queue with regular elements.
Step1: Insert root & NULL on queue.
Step2: temp=q.front();q.pop()
       temp->nextRight = q.front();

Complexities:
- Time: O(n)
- Space: Maximum number of nodes at any level
**************************************
*/
#include<iostream>
#include<queue>
using namespace std;

typedef struct node{
        int val;
        struct node *left,*right,*nextRight;
}Node;

Node *TreeNodeAllocate(int val){
        Node *t = new Node;
        t->left=t->right=t->nextRight=NULL;
        t->val=val;
        return t;
}

Node *createBT(Node *root){
        root = TreeNodeAllocate(1);
        root->left = TreeNodeAllocate(2);
        root->right = TreeNodeAllocate(3);
        root->left->left = TreeNodeAllocate(4);
        root->left->right = TreeNodeAllocate(5);
        root->right->left = TreeNodeAllocate(6);
        root->right->right = TreeNodeAllocate(7);
        cout<<"Binary Tree Created\n";
        return root;
}

void connect_nodes_at_same_level(Node *root){
        Node *temp;
        queue<Node *> q;
        q.push(root); q.push(NULL);

        while(q.empty()!=1){
                temp = q.front(); q.pop();

                if(temp != NULL){
                        temp->nextRight = q.front();

                        if(temp->left)
                                q.push(temp->left);
                        if(temp->right)
                                q.push(temp->right);
                }else{
                        if(q.empty()!=1)
                                q.push(NULL);
                }
        }
        cout<<"connect_nodes_at_same_level worked\n";
}

int main(){
        Node *root;
        root = createBT(root);
        connect_nodes_at_same_level(root);
}
