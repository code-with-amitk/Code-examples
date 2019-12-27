/*
Left View:  These are set of nodes visible when tree is seen from the left side.

Working. Read Carefully.

        12
       /  \
      10  30
     /    / \
   14   25   40
             /
            50          left view: 12, 10, 14, 50

Logic(Modified BFS/level order Traversal): 
- Take 2 queues. currLevelQueue, nextLevelQueue. variable i=0.
- Push root into currLevelQueue
- Traverse all elements of currLevelQueue.
        -> Only Print 1st element
        -> while traversing Fill left,right children in nextLevelQueue.
        -> When currLevelQueue becomes empty. swap curr & next.
        

TIME COMPLEXITY:        O(n).   //Since we are traversing all elements
*/

#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
//using namespace std;

typedef struct node
{
    int data;
    struct node *left, *right;
}Node;

Node *newNode(int item)
{
    Node *temp =  (struct node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void bf_traversal(Node *ptr){
        if (ptr == NULL)
                return;

        std::queue<Node *> currLevelQueue;
        std::queue<Node *> nextLevelQueue;
        Node *temp;
        int i = 0;

        currLevelQueue.push(ptr);

        while(!currLevelQueue.empty()){

                temp = currLevelQueue.front();  currLevelQueue.pop();
                if(!i){
                        std::cout<<temp->data<<" ";
                        i++;
                }

                if(temp->left)  nextLevelQueue.push(temp->left);
                if(temp->right) nextLevelQueue.push(temp->right);

                if(currLevelQueue.empty()){
                        std::swap(currLevelQueue, nextLevelQueue);
                        i=0;
                }
        }
}

int main()
{
    Node *root = newNode(12);
    root->left = newNode(10);
    root->left->left = newNode(14);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    root->right->right->left = newNode(50);

    std::cout<<root->data<<" ";
    bf_traversal(root);

    std::cout<<"\n";
    return 0;
}

/*
Ouput:
12 12 10 14 50
*/
