/*      linked_list_in_bt.cpp

Find LL is in binary tree or not?       
BT:             1
              /   \
             4     4
              \   / 
              2  2
             /  / \
            1  6   8
                  / \
                 1   3 
LL:     4->2->8
return:
        true //if LL is part of BT
        false //if LL is not part of BT
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
};

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
};

class Solution {
        ListNode* head;
        TreeNode* root;
public:
        bool isSubPath(ListNode* head, TreeNode* root) {
                if(!root) return false;

                return (dfs(head, root) ||
                        isSubPath(head, root->left) ||
                        isSubPath(head, root->right));

        }

        bool dfs(ListNode* head, TreeNode* root) {

                if(!head) return true;
                if(!root) return false;

                return (head->val == root->val &&
                        (dfs(head->next, root->left) ||
                         dfs(head->next, root->right))
                        );
        }

        TreeNode* createTree(){
                TreeNode *root1 = allocate(1);
                root1->left = allocate(4);
                root1->right = allocate(4);
                root1->left->right = allocate(2);
                root1->left->right->left = allocate(1);
                root1->right->left = allocate(2);
                root1->right->left->left = allocate(6);
                root1->right->left->right = allocate(8);
                root1->right->left->right->left = allocate(1);
                root1->right->left->right->right = allocate(3);
                cout<<"Tree created\n";
                root = root1;
                return root1;
        }
        TreeNode* allocate(int a){
                TreeNode *p = new TreeNode();
                p->val=a;
                p->left = p->right =nullptr;
                return p;
        }
        ListNode *createList(){
                ListNode* p = allo(1);
                p->next = allo(4);
                p->next->next = allo(3);
                p->next->next->next = allo(8);
                cout<<"List created\n";
                head = p;
                return p;
        }
        ListNode* allo(int a){
                ListNode* p = new ListNode();
                p->val = a;
                p->next = nullptr;
                return p;
        }
};

int main(){
        Solution s;
        TreeNode* t = s.createTree();
        ListNode* l = s.createList();
        cout<<s.isSubPath(l,t);
}
