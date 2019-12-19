/*
                 1
               /   \
              3     2 
             / \   / \
            4  5  6   7 

Datastructure used:
a. struct Node {                                        //Node of Tree
    int data;
    struct Node *left, *right;
};
b. Two stacks
        std::stack<struct Node*> currentlevel;          //Stores current level nodes
        std::stack<struct Node*> nextlevel;             //Stores all nodes present at next level

Logic:
a. Take 2 stacks, variable 'lefttoRight = true'
b. Create Tree. Pass root of tree to zigzagprint() function.
c. Fill root into currentLevel stack.
d. Perform these operation until currentLevel stack is not empty.
        while(!currentlevel.empty()){
                temp = currentLevel.top();Pop();        //Store top of currentlevel stack in temp.
                if(temp != NULL)                        //if element is present
                        if(lefttoRight)
                                push_in_nextlevel(temp->left), push_in_nextlevel(temp->right)   //if lefttoRight=1. Fill nextlevel stack from lefttoright
                        else
                                push_in_nextlevel(temp->right), push_in_nextlevel(temp->left)


                e. if currentlevel stack becomes empty, (switch the variable lefttoright = !lefttoright)&(swap currentlevel and nextlevel)
                if(currentlevel.empty())
                        lefttoright = !lefttoright
                        swap(currentlevel, nextlevel)

        }

Working Example:
a.      | |             ||              lefttoright=1
        |1|             ||
     currentlevel     nextlevel

     a1. pop->topcurrentlevel.
           top!=NULL &&  lefttoright == 1
                                |2|
                                |3|
                              nextlevel
     a2. currentlevel becomes empty
     - lefttoright =0
     - swap stacks
                |2|     ||
                |3|     ||
           currentlevel nextlevel

     a1. pop->topcurrentlevel
                top!=NULL && lefttoright=0
                  | |           |6|
                  |3|           |7|
                currentlevel    nextlevel

          pop->topcurrentlevel
                top!=NULL && lefttoright=0
                               |4|
                               |5|
                 ||            |6|
                 ||            |7|
                currentlevel    nextlevel
 */


#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

void zizagtraversal(struct Node* root)
{
        stack<struct Node*> currentlevel;
        stack<struct Node*> nextlevel;
        bool lefttoright = true;
        struct Node* temp;

        if (!root) return;

        currentlevel.push(root);

        while (!currentlevel.empty()){

                temp = currentlevel.top(); currentlevel.pop();

                if (temp) {

                        cout << temp->data << " ";

                        if (lefttoright) {
                                if (temp->left) nextlevel.push(temp->left);
                                if (temp->right) nextlevel.push(temp->right);
                        }
                        else{
                                if (temp->right) nextlevel.push(temp->right);
                                if (temp->left) nextlevel.push(temp->left);
                        }
                }

                if (currentlevel.empty()) {
                        lefttoright = !lefttoright;
                        swap(currentlevel, nextlevel);
                }
    }
}

struct Node* newNode(int data)
{
        struct Node* node = new struct Node;
        node->data = data;
        node->left = node->right = NULL;
        return (node);
}

int main()
{
        struct Node* root = newNode(1);
        root->left = newNode(3);
        root->right = newNode(2);
        root->left->left = newNode(7);
        root->left->right = newNode(6);
        root->right->left = newNode(5);
        root->right->right = newNode(4);
        cout << "ZigZag Order traversal of binary tree is \n";

        zizagtraversal(root);

        return 0;
}
