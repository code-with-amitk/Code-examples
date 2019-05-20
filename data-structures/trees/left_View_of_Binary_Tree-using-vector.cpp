#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<iostream>
//using namespace std;
/*
Input
        12
       /  \
      10  30
     /    / \
   14   25   40
             /
            50
Output:
12 10 14 50

Logic: 
- Create a tree
- func()             //Method-1
    if(root->left != NULL) print(root->left)
    if(root->left) fun(root->left)
    if(root->right) fun(root->right)
 */
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

/* list[Doubly LL]            <--> | 4 | <--> | 1 | <--> | 8 | <-->
    Insertion & remove?   At any place in list->Fast.
    Search:    Slow, Linear time. Much slower than vector.
    
*/
void leftView(node* root){         //Correct!!
        if (root == NULL)   return;

        std::list<node*> queue; //create an empty queue and enqueue root node
        queue.push_back(root);

        node* curr = nullptr;   //pointer to store current node

        while (!queue.empty()){         //run till queue is not empty
                int size = queue.size();        //calculate number of nodes in current level
                int i = 0;

                while (i++ < size){     //process every node of current level and enqueue their, non-empty left and right child to queue
                        curr = queue.front();
                        queue.pop_front();

                        if (i == 1)     std::cout << curr->data << " ";

                        if (curr->left) queue.push_back(curr->left);
                        if (curr->right) queue.push_back(curr->right);
                }
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
 
    //Method using lists in C++
    leftView(root);

    std::cout<<"\n";
    return 0;
}
