- **[Cord / Rope](#c)**
- [1. Find character at nth position](#f)

<a name=c></a>
### [Cord / Rope](/DS_Questions/Data_Structures/Trees/BinaryTree)
Problem:
- Find character at nth index. findNthChar(root, int n). findNthChar(root, 6) => _  `H=1,e=2,l=3,l=4,o=5,_=6`
- return substring from n to m substring(int n, int m). //May span across two nodes
- Delete substring from n to m deleteSubstring(int n, int m) //May span across two nodes
```c
Storing: "Hello_my_name_is_Amit"
H e l l o _ m y _ n a m e _ i s _ A m i t
0 1 2 3 4 5 6 7 8 9 1011121314151617181920

                        21
                      /    
                    9
               /         \
              6             6
            /   \        /      \
     Hello_,6  my_,3    2          1
                      /   \      /    \
                  na,2  me_i,4  s,1   _Amit,5 
```

<a name=f></a>
### 1. Find character at nth index
```c
//cord.h
#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Cord {
    string data;
    int len;
    Cord* left, * right;
    Cord(Cord* l, Cord* r, int len) :
        left(l), right(r), len(len) {
        data = "";
    }
    Cord(Cord* l, Cord* r, int len, string d) :
        left(l), right(r), len(len), data(d) {}
};
class Solution {
    char find(Cord*, int);
public:
    Cord* create() {
        Cord* n_hello = new Cord(nullptr, nullptr, 6, "Hello_");
        Cord* n_my = new Cord(nullptr, nullptr, 3, "my_");
        Cord* n_na = new Cord(nullptr, nullptr, 2, "na");
        Cord* n_me = new Cord(nullptr, nullptr, 4, "me_i");
        Cord* n_s = new Cord(nullptr, nullptr, 1, "s");
        Cord* n_amit = new Cord(nullptr, nullptr, 5, "_Amit");
        Cord* n_6_1 = new Cord(n_hello, nullptr, 6);
        Cord* n_2 = new Cord(n_na, n_me, 2);
        Cord* n_1 = new Cord(n_s, n_amit, 1);
        Cord* n_6_2 = new Cord(n_2, n_1, 6);
        Cord* n_9 = new Cord(n_6_1, n_6_2, 9);
        Cord* n_21 = new Cord(n_9, nullptr, 21);
        return n_21;
    }
    char findNthChar(Cord*, int);
};

//cord.cpp
#include "Cord.h"
char Solution::find(Cord* root, int n) {
    char ch = ' ';
    if (!root || n > root->len)
        return ' ';

    if (root->data.empty()) {      //Non-Leaf Node
        if (root->left && n <= root->left->len)
            ch = find(root->left, n);
        else if (root->right)
            ch = find(root->right, abs(n - root->right->len));
    }
    else {                //Leaf Node
        ch = root->data[n - 1];
    }
    return ch;
}
char Solution::findNthChar(Cord* root, int n) {
    return find(root, n);
}
int main() {
    Solution s;
    Cord* root = s.create();
    cout << "Cord Created\n";
    cout << s.findNthChar(root, 6);     //_
}
```
