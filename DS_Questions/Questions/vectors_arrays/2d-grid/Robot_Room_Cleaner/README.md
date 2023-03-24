**Robot Room Cleaner**
- [Approach = backtracking](#ap)
- [Logic](#l)
- Code
  - [CPP](#cpp)
  - [Rust](#rs)


### [489. Robot Room Cleaner](https://leetcode.com/problems/robot-room-cleaner/)
- You are controlling a robot that is located somewhere in a room. The room is modeled as an m x n binary grid where 0 represents a wall and 1 represents an empty slot.
- The robot starts at an unknown location in the room that is guaranteed to be empty, and you do not have access to the grid, but you can move the robot using the given API Robot.
- You are tasked to use the robot to clean the entire room (i.e., clean every empty cell in the room). The robot with the four given APIs can move forward, turn left, or turn right. Each turn is 90 degrees.
- When the robot tries to move into a wall cell, its bumper sensor detects the obstacle, and it stays on the current cell.
- Design an algorithm to clean the entire room using the following APIs:
```
interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}
```

<a name=ap></a>
### Approach = Backtracking
- We can solve all backtracking questions using a [backtracking template](/DS_Questions/Algorithms/Backtracking/README.md#tem)
- This problem also uses backtracking template, see that 1st.

<a name=l></a>
### Logic
- Consider robot is at position=r, facing up. Consider current position of robot as (0,0). 
  - if robot moves up in these direction, its corrdinates becomes up(-1,0), right(0,1), down(1,0), left(0,-1)
```c
    0  1  2  3  4  5  6
0               0
1            r  0
2               
3   0  0  0     0  0  0
4
```
- Take a visited unordered_set, which notes all positions of robot which are visited and marked cleaned.
- Move up, if we find obstacle
  - turn right, move. if find obstacle
  - turn right, move. if find obstacle so on.. we move always in clockwise direction.
- Apply the backtrack template. Find all candidates from candidate list, iterate in for loop and backtrack.

<a name=c></a>
### Complexity
#### Time complexity 
O (n-m). where N is a number of cells in the room and M is a number of obstacles. We visit each non-obstacle cell once and only once.

#### Space complexity
- O(N−M). We employed a hashtable to keep track of whether a non-obstacle cell is visited or not.

<a name=cpp></a>
### Code
#### CPP
```c
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
        // {-1, 0} -> go up
        // {0, 1} -> go right
        // {1, 0} -> go down
        // {0, -1} -> go left
        // face direction: 0(up) 1(right) 2(down) 3(left)    
    vector<vector<int>> arr = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    unordered_set<string> visited;
public:
    void cleanRoom(Robot& robot) {
        backtrack(robot, 0, 0, 0);
    }
private:
    void backtrack(Robot &robot, int row, int col, int faceDirection) {
        visited.insert(to_string(row) + "," + to_string(col));
        robot.clean();
        
        //Iterate thru all candidates
        for (int k = 0; k < 4; ++k) {
            int nextFaceDirection = (faceDirection + k) % 4;
            int nrow = row + arr[nextFaceDirection][0];
            int ncol = col + arr[nextFaceDirection][1];
            
            //Candidate is valid, Mark visited
            if (!visited.count(to_string(nrow) + "," + to_string(ncol)) && robot.move()) {
                
                //Backtrack
                backtrack(robot, nrow, ncol, nextFaceDirection);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            
            robot.turnRight();
        }
    }
};
```
