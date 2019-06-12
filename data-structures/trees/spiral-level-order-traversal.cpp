/*              1       //Tree-1 Spiral Traversal:  1 2 3 4 5 6 7
 *            /   \
             2     3
            / \   / \
           7  6   5  4

                0               //Tree-2 Spiral Traversal: 0 1 2 6 5 4 3
              /   \
             1     2
            / \   / \
           3  4   5  6

                 0              //Tree-3 Spiral Traversal: 0 1 2 6 5 4 3 7 8 9 10 11 12 13 14
              /    \
             1       2
            / \     / \
           3  4     5   6
          /\  /\   /\   /\
         7 8 9 10 11 12 13 14
Logic:
- Take 2 stacks stackEven<Node>, stackOdd<Node>. Even Stack will contain all nodes at Even levels and odd at odd levels.
- Push root node into stackEven.
- Take level as EVEN
- Pass root node to spiralPrint function
        if(level == EVEN)
                pop stackEven.
                print value.
                if(popedNode->right) push stackOdd(right)
                if(popedNode->left) push stackOdd(left)
        if(level == ODD)
                pop stackOdd.
                print value.
                if(popedNode->right) push stackEven(right)
                if(popedNode->left) push stackEven(left)

Algorithm:
1. rootNode. push evenStack [Considering level=0]
2. 
 */
#include<iostream>
#include<stack>
struct Node{
        int data;
        Node *left;
        Node *right;
};
#define EVEN 0
#define ODD 1

std::stack <Node *> stackOdd;
std::stack <Node *> stackEven;

int level = EVEN;

void print(int level){
        Node *ptr;
//      std::cout<<"Inside print() level="<<level<<std::endl;
        if(level == EVEN){      //Even Level
//              std::cout<<"Inside level%2 == 0\n";
                while(!stackEven.empty()){
                        ptr = stackEven.top();
                        std::cout<<ptr->data<<" ";
                        if(ptr->right) stackOdd.push(ptr->right);
                        if(ptr->left) stackOdd.push(ptr->left);
                        stackEven.pop();
                }
                if(!stackOdd.empty())print(ODD);
        }else{          //Odd Level
//              std::cout<<"Inside level%2 != 0\n";
                while(!stackOdd.empty()){
                        ptr = stackOdd.top();
                        std::cout<<ptr->data<<" ";
                        if(ptr->left) stackEven.push(ptr->left);
                        if(ptr->right) stackEven.push(ptr->right);
                        stackOdd.pop();
                }
                if(!stackEven.empty())print(EVEN);
        }
}

void spiral(Node *root){
        print(level);
}

Node *create(int val){
        Node* ptr = new Node;
        ptr->data = val;
        ptr->left = ptr->right = NULL;
        return ptr;
}

#include<iostream>
int main(){
/*      Tree-1
        Node *root = create(1);
        root->left = create(2);
        root->right = create(3);
        root->left->left = create(7);
        root->left->right = create(6);
        root->right->left = create(5);
        root->right->right = create(4);
*/

        //Tree-2-> Working
/*      Node *root = create(0);
        root->left = create(1);
        root->right = create(2);
        root->left->left = create(3);
        root->left->right = create(4);
        root->right->left = create(5);
        root->right->right = create(6);
*/

        //Tree-3
        Node *root = create(0);
        root->left = create(1);
        root->right = create(2);
        root->left->left = create(3);
        root->left->right = create(4);
        root->right->left = create(5);
        root->right->right = create(6);
        root->left->left->left = create(7);
        root->left->left->right = create(8);
        root->left->right->left = create(9);
        root->left->right->right = create(10);
        root->right->left->left = create(11);
        root->right->left->right = create(12);
        root->right->right->left = create(13);
        root->right->right->right = create(14);


        std::cout<<"Tree created";
        stackEven.push(root);
        //std::cout<<"\nPushed";
        //Node *ptr = stackEven.top();
        //std::cout<<"\nvalue="<<ptr->data;
        spiral(root);
        std::cout<<std::endl;
}
