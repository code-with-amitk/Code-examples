**Word Search**
- Approach, Backtracking
  - [Logic](#l)
  - [Code](#c)
  - [Complexity](#co)


### [Word Search](https://leetcode.com/problems/word-search)
- Given an m x n grid of characters board and a string word, return true if word exists in the grid.
- The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
- Examples
<img src=word_in_grid.jpg width=300 />
```c
Input: 
  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
  word = "ABCCED"
Output: true
```

### Approach, Backtracking
<a name=l></a>
#### Logic
- **Why Backtracking?**
  - We will keep going in the grid until we find matching character, when mismatch happens we start removing 1 last character(this is backtrack).
- Search character by character(in all 4 directions) until word is found or we reach end.

<a name=c></a>
#### Code
We have applied [BackTracking Template](/DS_Questions/Algorithms/Backtracking#tem)
```cpp
#include<iostream>
#include<vector>
using namespace std;
using VecC = vector<char>;
using VecVecC = vector<VecC>;

class Solution {
    int ROW;
    int COL;
public:
    bool recursive_backtrack(int row, int col, VecVecC& board, string& word, int index){
        //Base case
        if(index >= word.size())
            return true;

        //Should not cross boundaries
        if (row >= ROW || col >= COL || row < 0 || col < 0)
            return false;

        //Character does not match
        if (board[row][col] != word[index])
            return false;
        
        //Iterate thru all directions
        /*
                    N(r-1,c)
            E(r,c-1)   rc      W(r,c+1)
                    S(r+1,c)
        */
       bool ret = false;
    //    ret = recursive_backtrack(row-1,col,board,word,index+1); //N
    //    if(!ret)
    //         ret = recursive_backtrack(row,col-1,board,word,index+1); //E
    //     if(!ret)
    //         ret = recursive_backtrack(row,col+1,board,word,index+1); //W
    //     if(!ret)
    //         ret = recursive_backtrack(row+1,col,board,word,index+1); //S
        
        board[row][col] = '#';

        //Iterate thru all candidates
        int rowOffset[] = {-1,0,0,1};
        int colOffset[] = {0,-1,1,0};
        for (int k=0;k<4;++k){
            int r = row+rowOffset[k];
            int c = col+colOffset[k];
            
            //Placing candidate, backtrack
            ret = recursive_backtrack(r,c,board,word,index+1);
            if (ret)
                break;
        }

        //Remove the placed candidate so that it can be used in next search
        board[row][col] = word[index];
        
        return ret;
    }

    bool exist(VecVecC& board, string word) {
        ROW = board.size();
        COL = board[0].size();
        for (int i=0;i<board.size();++i){
            for (int j=0;j<board[0].size();++j){
                if (recursive_backtrack(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }
};
int main(){
    VecVecC board = {{'A','B','C','E'},
                    {'S','F','C','S'},
                    {'A','D','E','E'}};
    //string word = "ABCCEE";   //true
    string word = "SEE";        //true
    Solution s;
    cout << s.exist(board, word);
}
```
<a name=co></a>
#### Complexity
**Time** O(N.3<sup>L</sup>). 
  - N is the number of cells in the board 
  - L is the length of the word to be matched. Intially we have 4 directions but only 3 since we wont go back if ch matches.
- **Space** O(L). Length of word to be matched.
