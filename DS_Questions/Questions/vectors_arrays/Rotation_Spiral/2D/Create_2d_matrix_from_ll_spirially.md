**Spiral Matrix IV**
- Approach-1
  - [Code](#c)


### Spiral Matrix IV
- You are given two integers m and n, which represent the dimensions of a matrix.
- You are also given the head of a linked list of integers.
- Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
- Return the generated matrix.

```c
Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]

Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
```
<img src=spiral_from_ll.jpg width=400 />

### Approach
<a name=c></a>
#### Code
```cpp
#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
using vecI = std::vector<int>;
using vecB = std::vector<bool>;
using vecVecI = std::vector<vecI>;
using unSet = std::unordered_set<int>;
using unMap = std::unordered_map<char, char>;
using unMTuple = std::unordered_map<int, std::tuple<int,int,int>>;
using namespace std;

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    void spiral_fill(vecVecI& v, int tmp1, int tmp2, int m, int n, ListNode* head){
        int i;
        if (tmp1 >= m && tmp2 >= n)
            return;
        if (head == nullptr)
            return;

        //Fill top row.
        //for (int i=tmp1; i<n-2; i++) {
        for (int i=tmp1; i<n; i++) {
            v[tmp1][i] = head->val;
            if (!head->next)
                return;
            head=head->next;
        }

        //Fill last Coloum from Top to Bottom
        for (int i = tmp1+1; i < m; i++){
            v[i][n-1] = head->val;
            if (!head->next)
                return;
            head=head->next;
        }

        //Fill last row in reverse order from right to left
        if ((m - 1) != tmp1)
                for (int i = n - 2; i >= tmp2; i--){
                    v[m-1][i] = head->val;
                    if (!head->next)
                      return;
                    head=head->next;
                }

        //Fill 1st Col in reverse order bottom to up
        if ((n - 1) != tmp2)
                for (i = m - 2; i > tmp1; i--){
                    v[i][tmp2] = head->val;
                    if (!head->next)
                      return;
                    head=head->next;
                }

        spiral_fill(v, tmp1 + 1, tmp2 + 1, m - 1, n - 1, head);
    }
public:
    vecVecI spiralMatrix(int m, int n, ListNode* head) {
        vecVecI v(m, vecI(n, -1));
        spiral_fill(v,0,0,m,n,head);
        return v;
    }
};

int main(){
    ListNode l0(0);
    ListNode l5a(5,&l0);
    ListNode l5b(5,&l5a);
    ListNode l2(2,&l5b);
    ListNode l4(4,&l2);
    ListNode l9(9,&l4);
    ListNode l7(7,&l9);
    ListNode l1(1,&l7);
    ListNode l8(8,&l1);
    ListNode l6(6,&l8);
    ListNode l2b(2,&l6);
    ListNode l0b(0,&l2b);
    ListNode l3(3,&l0b);

    Solution s;
    int m=3,n=5;
    vecVecI out = s.spiralMatrix(m,n,&l3);
    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            cout << out[i][j] << " ";
        }
        cout << "\n";
    }
 }
```
