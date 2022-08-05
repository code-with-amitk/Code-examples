**The Maze**
- Approach DFS
  - [Logic](#l)
  - [Code](#c)
  - [Complexity](#co)

### [The Maze](https://leetcode.com/problems/the-maze/)
- There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
- Given the m x n maze, the ball's start position and the destination, where start = `[startrow, startcol]` and destination = `[destinationrow, destinationcol]`, return true if the ball can stop at the destination, otherwise return false.
- You may assume that the borders of the maze are all walls (see examples).
```c
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
```
<img src=maze1.jpg width=500 />

### Approach DFS
<a name=l></a>
### Logic
- Start from start coordinate. Take a visited matrix, mark node as visited once you reached to avoid coming back to same node.
- Traverse to right until stone is found, if stone is found turn down and traverse.

<a name=c></a>
#### Code
```cpp
using vecI = vector<int>;
using vecVecI = vector<vecI>;
using vecB = vector<bool>;
using vecVecB = vector<vecB>;

class Solution {
public:
    bool hasPath(vecVecI& m, vecI& start, vecI& end) {
		vecVecB visited(m.size(), vecB(m[0].size(), 0));
        return dfs(m, start, end, visited);
    }

	bool dfs(vecVecI& m, vecI& start, vecI& end, vecVecB& visited) {
	
		//Starting row and col
		int row = start[0], col = start[1];
		
		//if we have already visited this point return
        if (visited[row][col])
            return false;
			
		//We reached destination, return true
        if (row == end[0] && col == end[1])
            return true;
			
		//Mark this node as visited
        visited[row][col] = true;
		
		//4 directions
    int right = col + 1;
		int left = col - 1;
		int up = row - 1;
		int down = row + 1;
		
		//Move to right, ie next column until we find Wall ie 1
		//Move till entry = 0, ie no stone
        while (right < m[0].size() && m[row][right] == 0)
            right++;
		//Once We reach a point to right of which there is wall
		//Perform DFS on that point in 4 directions
        vecI newStart = {row, right - 1};
        if (dfs(m, newStart, end, visited))
            return true;
			
		//Move to left, ie prev column until we find Wall ie 1
		//Move till entry = 0, ie no stone
        while (left >= 0 && m[row][left] == 0)
            left--;
		//if stone is found ie entry=1, move to next 
        newStart = {row, left + 1};
        if (dfs(m, newStart, end, visited))
            return true;
			
		//Move till topmost row, do not move above 0th row
		//Move if entry = 0, ie no stone
        while (up >= 0 && m[up][col] == 0)
            up--;
        newStart = {up + 1, col};
        if (dfs(m, newStart, end, visited))
            return true;
			
		//Move down until last row and until we find a stone inbetween
        while (down < m.size() && m[down][col] == 0)
            down++;
		//if stone is found, move to prev row and perform dfs
        newStart = {down - 1, col};
        if (dfs(m, newStart, end, visited))
            return true;
			
        return false;
    }
};
```

<a name=co></a>
### Complexity
#### Time
- O(mn). Complete traversal of maze is done in worst case.
