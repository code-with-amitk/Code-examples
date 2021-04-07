### [Word Search](https://leetcode.com/problems/word-search/)
- Given 2D board and a word, find if the word exists in the grid traversing horizontally & vertically
- The same letter cell cann not be used more than once.
- Example: 
<img src=https://assets.leetcode.com/uploads/2020/11/04/word2.jpg width=300 />
word = "ABCCED", Output: true

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

class Solution {
public:
        bool matchSingleCharacter( vector<vector<char>>& board,
                              string& word, int row, int col,
                              int presentIndex)
        {
                int numberOfRows = board.size();
                int numberOfColomns = board[0].size();

                //Not crossing array boundaries
                if ((row < 0 || row >= numberOfRows||
                     col < 0 || col >= numberOfColomns))
                        return false;

                if ((word[presentIndex] == board[row][col]) && (presentIndex == (word.length()-1))){
                //      cout<<"presentIndex="<<presentIndex<<"\n";
                        return true;
                }

                //if character does not match on board & word.
                if (board[row][col] != word[presentIndex])
                        return false;

                board[row][col] = '#';

                return matchSingleCharacter (board, word, row+1, col, presentIndex+1)||
                       matchSingleCharacter (board, word, row-1, col,presentIndex+1)||
                       matchSingleCharacter (board, word, row, col+1, presentIndex+1)||
                       matchSingleCharacter (board, word, row, col-1, presentIndex+1);
        }

        bool exist(vector<vector<char>>& board, string word)
        {
                int numberOfRows = board.size();
                int numberOfColomns = board[0].size();

                //if board has 1 alphabet and word also has 1
                if(numberOfRows == 1 &&
                   numberOfColomns == 1 &&
                   word.length() == 1 &&
                   board[0][0] == word[0])
                {
                        return true;
                }

                for(int i = 0; i < numberOfRows; i++)
                {
                        for(int j = 0; j < numberOfColomns; j++)
                        {
                                if(board[i][j] == word[0])
                                {
                                        if (matchSingleCharacter(board, word, i, j, 0))
                                                return true;
                                }
                        }
                }
                return false;
        }
};

int main()
{
        Solution s;
        vector<vector<char>> v =
        {
                {'a','b','c','e'},
                {'s','f','c','s'},
                {'a','d','e','e'}
        };
        //cout<<s.exist(v, "abcced");   //1
        cout<<s.exist(v, "see");        //1
        cout<<s.exist(v, "aab");
}
```
