**word search**
- [Approach-1, Backtracking](#a1)

### [Word Search](https://leetcode.com/problems/word-search/)
- Given 2D board and a word, find if the word exists in the grid traversing horizontally & vertically
- The same letter cell cann not be used more than once.
- Example: 
<img src=https://assets.leetcode.com/uploads/2020/11/04/word2.jpg width=200 />
word = "ABCCED", Output: true

<a name=a1></a>
### Approach-1, Backtracking
### Logic
```c++
- Start from board[0][0]
- if(board[i][j] == word[0])
        -> Compare neighbours (left,right,top,bottom)
        -> Keep on comparing neighbours until
                - Find a mis-match
                - OR word ends
        -> if alphabets keep matching replace with '#'
           so that it should not be retravelled.
```
 ### Code
 ```c++
#include<iostream>
#include<string>
#include<vector>
using namespace std;
using VecC = vector<char>;
using VecVecC = vector<VecC>;
class Solution {
    int maxROws, maxCols;
    string target;
public:
    bool recursive_backtrack(int row, int col, VecVecC& board, int presentIndex){
    
        /// Base cases
        if (presentIndex >= target.size())
            return true;

        /// Should not cross boundaries
        if (row >= maxRows || col >= maxCols || row < 0 || col < 0)
            return false;

        /// Character does not match
        if (board[row][col] != target[presentIndex])
            return false;
        
        //Iterate thru all directions
        /*
                    N(r-1,c)(-1,0)
        (0,-1)E(r,c-1)   rc      W(r,c+1)(0,1)
                    S(r+1,c)(1,0)
        */
        bool ret = false;
        
        int ch = board[row][col];
        board[row][col] = '#';
		
        int rowOffset[] = {-1,0,0,1};
        int colOffset[] = {0,-1,1,0};
        for (int k=0;k<4;++k){
            int r = row+rowOffset[k];
            int c = col+colOffset[k];
            //Placing candidate, backtrack
            ret = recursive_backtrack(r, c, board, index+1);
            if (ret)
                break;
        }

        board[row][col] = ch;
        return ret;
    }
    
    bool exist(vecVecC& board, string word) {
        maxROws = board.size();
        maxCols = board[0].size();
        target = word;
        int presentIndex = 0;   //This is index of character in target word to be searched
        
        /// Iterate thru every character on board
        for (int i=0; i < maxRows; ++i) {
            for (int j=0; j < maxCols; ++j) {
                if (recursive_backtrack(i, j, board, presentIndex))
                    return true;
            }
        }
        return false;
    }
};
```
