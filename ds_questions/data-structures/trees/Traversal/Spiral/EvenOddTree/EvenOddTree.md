## [Problem](https://leetcode.com/contest/weekly-contest-209/problems/even-odd-tree/)
- A binary tree is named Even-Odd if it meets the following conditions:
- The root of the binary tree is at level index 0, its children are at level index 1,2 and so on.
- For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
- For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
- Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
- **Examples** See examples with pictures on Leetcode only.

### Logic
```c
                       mainStack 		tempStack		//FIFO

			| |			| |

			push 1		
			|1|			| |
												Even Level = push left right
												Even odd = push right left
Level=0		         pop 1			push 10		|10|
						push 4		|4|10|
								top
			empty	
check 						tempStack sorted=Yes						
swap		       |4|10|			| |


level=1		       pop 4			push 9		|9|
						push 7		|7|9|
					
		       pop 10			N		|7|9|
						push 3		|3|7|9|
		       empty	
check 			 		        tempStack sorted=Yes
swap		      |3|7|9|			| |

Level=2		        pop 3			push 12		|12|
						push 8		|8|12|
							
			pop 7			push 6		|6|8|12|
						Null
							
			pop 9			Null
						push 2		|2|6|8|12|
			empty
check 			  		        tempStack sorted=Yes
swap		      |2|6|8|12|		| |			
		
Level=3		        pop 2			| |
			pop 6			| |
			pop 8			| |
			pop 12			| |
			empty
```

### Code
```c++
#include<iostream>
#include<stack>
#include<vector>
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

  bool Comparator(const int &a, const int &b) {
    //cout<<"\nComparator a="<<a<<", b="<<b<<endl;
    return a > b ? false : true;
  }
  
class Solution {
public:
  bool CheckZigZag();
  bool isEvenOddTree(TreeNode* root);
private:
  stack<TreeNode*> mainStack;
  stack<TreeNode*> tempStack;
  vector<int> vecSorted;
  int level = 0;
};

bool Solution::isEvenOddTree(TreeNode* root){
  if (!root)
    return false;

  mainStack.push(root);
  return CheckZigZag();
}

bool Solution::CheckZigZag() {

    while (mainStack.empty() != 1) {
      while (mainStack.empty() != 1) {

        TreeNode* top = mainStack.top();
        mainStack.pop();

        if (!top)
          continue;

        vecSorted.push_back(top->val);

        cout<<top->val<<" ";

        if (level%2 == 0) {     //Even level

          if (!(top->val % 2))
            return false;

          tempStack.push(top->left);
          tempStack.push(top->right);
        }
        else                    //Odd level
        {
          if ((top->val % 2))
            return false;

          tempStack.push(top->right);
          tempStack.push(top->left);
        }
      }
      if(!is_sorted(vecSorted.begin(), vecSorted.end(), Comparator))
        return false;

      vecSorted.clear();

      if (tempStack.empty() != 1)
        tempStack.swap(mainStack);

      ++level;
    }
    return true;
}

int main(){
  TreeNode a3l(3);        //0
  TreeNode a3r(3);
  TreeNode a7(7);
  TreeNode a4(4,&a3l,&a3r);
  TreeNode a2(2,&a7,nullptr);
  TreeNode r(5,&a4,&a2);

  TreeNode* root = &r;

  Solution s;
  cout<<s.isEvenOddTree(root);
}
```
