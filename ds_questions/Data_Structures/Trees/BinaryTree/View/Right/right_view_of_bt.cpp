/*
Right View:  These are set of nodes visible when tree is seen from the right side.

Working. Read Carefully.

        12
       /  \
      10  30
     /    / \
   14   25   40
             /
            50          Right view: 12, 30, 40, 50
            
Logic(Modified BFS/level order Traversal): 
- Take 2 queues. currLevelQueue, nextLevelQueue.
- Push root into currLevelQueue
- while(currLevelQueue is not empty){
        temp = top_of_currLevelQueue
        
        if temp->left
          Fill element in nextLevelQueue
          
        if temp->right 
          Fill element in nextLevelQueue
          
        if currLevelQueue is empty{
            print temp->data           //THIS IS the Last element of currLevelQueue and last element on level-order-traversal        
            swap currLevelQueue & nextLevelQueue
        }
}


TIME COMPLEXITY:        O(n).   //Since we are traversing all elements
*/

#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
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

void bfs_to_print_rightView(Node *ptr){
        if (ptr == NULL)
                return;

        std::queue<Node *> currLevelQueue;
        std::queue<Node *> nextLevelQueue;
        Node *temp;
        int i = 0;

        currLevelQueue.push(ptr);

        while(!currLevelQueue.empty()){

                temp = currLevelQueue.front();  currLevelQueue.pop();

                if(temp->left)  nextLevelQueue.push(temp->left);
                if(temp->right) nextLevelQueue.push(temp->right);

                if(currLevelQueue.empty()){
                        std::swap(currLevelQueue, nextLevelQueue);
                        std::cout<<temp->data<<" ";
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

    bfs_to_print_rightView(root);

    std::cout<<"\n";
    return 0;
}

/*
Output:
# ./a.out 
12 12 30 40 50 
*/
