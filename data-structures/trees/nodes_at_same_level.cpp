/*      nodes_at_same_level.cpp
                1
               / \
              2   3
             / \  /\
            4  5 6  7

Situation/Task: Print nodes at same level in 1 line
Result:
1
2,3
4,5,6,7

**********Logic(BFS)***********
- Count number of nodes in queue
- Print nodes until count>0

Complexity:
Space: O(n+m).  m=max size of queue. n=no of nodes in tree
Time: O(logn*logn)
*******************************
*/

#include<iostream>
#include<queue>
using namespace std;

class tree{
        typedef struct node{
                int val;
                struct node *left,*right;
        }Node;
        Node *root;

public:
        void create();
        Node *allocate(int a){
                Node *t = new Node;
                t->val = a;
                t->left = t->right = NULL;
                return t;
        }
        void NodesAtSameLevel();
};

void tree::NodesAtSameLevel(){
        queue<Node *> q;
        int count=0;
        Node *temp;

        q.push(root);
        while(q.empty()!=1){
                count = q.size();

                while(count > 0){
                        temp = q.front();
                        q.pop();
                        cout<<temp->val<<" ";

                        if(temp->left)
                                q.push(temp->left);
                        if(temp->right)
                                q.push(temp->right);

                        count--;
                }
                cout<<"\n";
        }
}

void tree::create(){
        root = allocate(1);
        root->left = allocate(2);
        root->left->left = allocate(4);
        root->left->right = allocate(5);
        root->right = allocate(3);
        root->right->left = allocate(6);
        root->right->right = allocate(7);
}

int main(){
        tree t;
        t.create();
        t.NodesAtSameLevel();
}
/*
Output:
1 
2 3 
4 5 6 7
*/
