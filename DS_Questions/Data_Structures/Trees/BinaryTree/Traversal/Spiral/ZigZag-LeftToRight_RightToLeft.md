**Left to Right, Right to Left**
- Approach-1 / 2 stacks
  - [Logic](#log)
  - [Complexity](#c)
  - [Code](#cpp)

## Zig Zag Traversal
Traverse binary tree in zigzag fashion. Example
```c
40 60 20 10 30 50 70 55 5
Traversal on Levels:
  - Even: Traverse from Left to Right
  - Odd:  Traverse from Right to Left
```
    
<img src=spiralTraversalExample.jpg width=500/>

## [Self Youtube Video](https://youtu.be/aWKOMRt3wVs)

## Approach-1 / 2 Stacks
<a name=log1></a>
### Logic
- Take 2 stacks. `mainStack<TreeNode*>, tempStack<TreeNode*>`.
  - *1.* mainStack for traversing a particular level
  - *2.* tempStack for storing children at time of traversal of level.
- When mainStack is empty (ie all nodes on particular level) are traversed. Swap mainStack and tempStack.
- On Odd Level, fill (Right,Left). On Even level fill(left,right).
```c
			mainStack 		tempStack
			| |			| |
			
			push 40
			|40|

Level=0			pop 40			push 20		|20|
						push 60		|60|20|
			empty		
swap			|60|20|			| |

level=1			pop 60			push 70		|70|
						push 50		|50|70|
					
			pop 20			push 30		|30|50|70|
						push 10		|10|30|50|70|
			empty
swap			|10|30|50|70|		| |

Level=2			pop 10			Donot push NULL
						push 5		|5|
			pop 30			
			pop 50			push 55		|55|5|
			pop 70
			empty
swap			|55|5|			| |			
		
Level=3			pop 55			| |
			pop 5			| |
	
			//pop are printed
			40 60 20 10 30 50 70 55 5
``` 

<a name=cpp1></a>
### Code
```cpp
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  void ZigZagTraversal (TreeNode* root) ;
  void PrintZigZag();
  bool isEvenOddTree(TreeNode* root);
private:
  stack<TreeNode*> mainStack;
  stack<TreeNode*> tempStack;
  int level = 0;
};

void Solution::PrintZigZag() {
    while (mainStack.empty() != 1) {
      while (mainStack.empty() != 1) {

        TreeNode* top = mainStack.top();
        mainStack.pop();

        if (!top)
          continue;

        cout<<top->val<<" ";

        if (level%2 == 0) {     //Even level
          tempStack.push(top->left);
          tempStack.push(top->right);
        }
        else                    //Odd level
        {
          tempStack.push(top->right);
          tempStack.push(top->left);
        }
      }//while inner

      if (tempStack.empty() != 1)
        tempStack.swap(mainStack);

      ++level;
    }//while outer
}

void Solution::ZigZagTraversal (TreeNode *root) {
  if (!root)
    return;

  mainStack.push(root);
  PrintZigZag();
  cout<<"\n";
}

int main(){
  TreeNode a5(5);
  TreeNode a55(55);
  TreeNode a30(30);
  TreeNode a70(70);
  TreeNode a10(10,&a5,nullptr);
  TreeNode a50(50,nullptr,&a55);
  TreeNode a20(20,&a10,&a30);
  TreeNode a60(60,&a50,&a70);
  TreeNode r(40,&a20,&a60);
  
  TreeNode* root = &r;

  Solution s;
  s.ZigZagTraversal(root);
}
```
