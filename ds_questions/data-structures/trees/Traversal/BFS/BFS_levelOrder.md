## Level Order
```c++

        12
       /  \
      10  30
     /    / \
   14   25   40
             /
            50
            
O/P -> 12 10 30 14 25 40 50
```
## Logic(Using QUEUES)
a. Take a queue
b. Push root in queue
c. while(!queue.empty())
     print(element)
     if(left) push_left_ele_in_queue;
     if(right) push_right_ele_in_queue;

## Complexity
- Time: O(n)
- Space: O(n)
        
 
## Code
```c++
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
//using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void bf_traversal(Node *ptr){
        if (ptr == NULL)
                return;

        std::queue<Node *> myqueue;
        Node *temp;

        myqueue.push(ptr);

        while(!myqueue.empty()){
                temp = myqueue.front();
                myqueue.pop();
                std::cout<<temp->data<<" ";

                if(temp->left)
                        myqueue.push(temp->left);
                if(temp->right)
                        myqueue.push(temp->right);
        }
}

int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->left->left = newNode(14);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    root->right->right->left = newNode(50);

    bf_traversal(root);

    std::cout<<"\n";
    return 0;
}        
```
