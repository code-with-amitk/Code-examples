- **Modified Cord**
- **Code**
  - [1. Find character at nth index](#c1)

### Find Character at nth index, find substring, delete substring in cord {Modified Cord}
- Unlike [cord](/DS_Questions/Data_Structures/Trees/BinaryTree/README.md), in modified cord every
  - Leaf node       : same as cord (stores string, length)
  - Non-leaf nodes  : Unlike cord stores length of both left and right children's string.
- Problem:
1. Find character at nth index.		findNthChar(root, int n).	findNthChar(root, 6) => c
2. return substring from n to m         substring(int n, int m).        //May span across two nodes
3. Delete substring from n to m         deleteSubstring(int n, int m)   //May span across two nodes
```c
string = t e s t a b c d e f a m
         0 1 2 3 4 5 6 7 8 9 10 11
  
                      14
                    /     \
                  1        13
                /       /     \		 
             t,1       5        6
                     /  \     /   \ 
	                  2    3   cde,3 fam,3
                   / \    \
                 e,1 s,1  tab,3	
```


### Code
<a name=c1></a>
#### 1. Find character at nth index
```cpp
struct Tree {
    bool isLeaf;
    int len;
    string data;
    Tree* left;
    Tree* right;
    Tree(int len, string data):
        left(nullptr),right(nullptr),
        len(len), data(data), isLeaf(true){}
    Tree(int len, Tree* left, Tree* right):
        left(left), right(right), len(len), isLeaf(false){}
};

class Solution {
    char find(Tree*, int);
public:
    Tree* create() {
        Tree* n_tab3 = new Tree(3, "tab");
        Tree* n_s1 = new Tree(1, "s");
        Tree* n_e1 = new Tree(1, "e");
        Tree* n_fam3 = new Tree(3, "fam");
        Tree* n_cde3 = new Tree(3, "cde");
        Tree* n_3 = new Tree(3, nullptr, n_tab3);
        Tree* n_2 = new Tree(2, n_e1, n_s1);
        Tree* n_5 = new Tree(5, n_2, n_3);
        Tree* n_6 = new Tree(6, n_cde3, n_fam3);
        Tree* n_13 = new Tree(13, n_5, n_6);
        Tree* n_t1 = new Tree(1, "t");
        Tree* n_1 = new Tree(1, n_t1, nullptr);
        Tree* n14_root = new Tree(14, n_1, n_13);
        return n14_root;
    }
    char findNthChar(Tree*, int);
};
char Solution::find (Tree* root, int n) {
    char ch;
    if (!root || n > root->len)
        return ' ';

    if (!root->isLeaf) {
        if (n > root->left->len)
            ch = find(root->right, n-root->left->len);
        else
            ch = find(root->left, n);
    } else {
        ch = root->data[n-1];
    }
    return ch;
}

char Solution::findNthChar(Tree* root, int n){
    return find(root, n+1);
}

int main() {
    Solution s;
    Tree* root = s.create();
    cout << s.findNthChar (root, 6) << endl;  //c
    cout << s.findNthChar (root, 0) << endl;  //t
    cout << s.findNthChar (root, 10) << endl;  //a
    return 0;
}
```
