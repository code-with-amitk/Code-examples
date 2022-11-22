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
#### Logic
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
- **Backtrack Tree**
```c
A B C E A B		//Search:ABCCED
S F C S B C
A D E E R Z
						[]
				-------------------------------------------
				|			|		
				A(0,0)			A(0,4)
			------------------		----------------
			|	|			|		|
			AB	AS			AB(1,4)		AB
			|	(stop)			|
  		-------------------------		-----------------
  		|     |					|	|	|
 		ABC	ABF				ABS	ABR	ABC
  		|	(stop)
	-------------------
	|	   |	   |
	ABCE	  ABCC	   
	(stop)	   |
	 --------------------------------
	 |		|		|
	 ABCCS		ABCCF		ABCCE		//At any level 3 directions can be traversed.
	 (stop)		(stop)		|
	 			-----------------------------
				|		|
				ABCCEE		ABCCED
				(stop)		(found)
```
 ### Code
 ```cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;
using VecC = vector<char>;
using VecVecC = vector<VecC>;
using VecC = vector<char>;
using vecVecC = vector<VecC>;

class Solution {
        int maxRows, maxCols;
        string target;
public:
    bool recursive_backtrack(int row, int col, vecVecC& board, int presentIndex) {
    
        /// Base cases
        if (presentIndex >= target.size())
            return true;

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
		
        int dRow[] = {-1,0,0,1};
        int dCol[] = {0,-1,1,0};
        for (int i=0; i<4; ++i) {
            int nextRow = row + dRow[i];
            int nextCol = col + dCol[i];
            
            if (nextRow >= maxRows || nextCol >= maxCols || nextRow < 0 || nextCol < 0)
                    continue;
        
            /// Break only when matching character is found
            /// Donot break if after going on path we donot find match
            ret = recursive_backtrack(nextRow, nextCol, board, presentIndex+1);
            if (ret)
                break;
        }

        /// Place character on board again
        /// This is same as Removing last element from candidate list
        board[row][col] = ch;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        maxRows = board.size();
        maxCols = board[0].size();
        target = word;
        int presentIndex = 0;   //This is index of character in target word to be searched
        
        /// if board has 1 alphabet and word also has 1
        if(maxRows == 1 && maxCols == 1 && target.size() == 1 && board[0][0] == target[0])
                return true;

        /// Iterate thru every character on board
        for (int i=0; i < maxRows; ++i) {
            for (int j=0; j < maxCols; ++j) {
                if (board[i][j] == target[presentIndex]) {
                        if (recursive_backtrack(i, j, board, presentIndex))
                        return true;
                }
            }
        }
        return false;
    }
};
```

#### [Complexity Analysis for Backtracking](/DS_Questions/Algorithms/Backtracking/README.md#t)
- **Time:** O(N x 3<sup>L</sup>)
  - Look at backtrack Tree above. At any level 3 children are allowed, since we cannot traverse back to path from where we came. if levels=L. Complexity = 3<sup>L</sup>
  - N=Number of letters in grid. From Every letter there can be a path to target word.
- **Space:** 
  - O(k) where k is the length of the word to be matched.
