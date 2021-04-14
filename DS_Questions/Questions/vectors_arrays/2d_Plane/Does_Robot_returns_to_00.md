## [Robot Bounded In Circle](https://leetcode.com/problems/robot-bounded-in-circle/)
- On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of 3 instructions:
- "G":Go straight 1 unit; "L":Turn 90 degrees to the left; "R":Turn 90 degrees to the right.
- The robot performs the instructions given in order, and repeats them forever.
- Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
- **Examples**
```c
Example-1
Input: Instructions = "GGLLGG"
        ||
        ||
       0,0
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).

Example-2:
Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely to north.

Example-3:
Input: instructions = "GL"
         _
        | |
         - 
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
```

### Limit cycle trajectory?
- **What?** A limit cycle is a closed trajectory in phase space having the property that at least one other trajectory spirals into it either as time approaches infinity.
- **How to identify?**
  - If robot returns to the initial point after one cycle, that's the limit cycle trajectory.
  - If the robot does not face north at the end of the first cycle, that's the limit cycle trajectory.

### Approach    //Identify Limit Cycle Trajectory
- **Logic**
- **Code**
```c++
    bool isRobotBounded(string instructions) {
/*
              N(0,1)
    W(-1,0)    0,0     E(1,0)
              S(0,-1)
*/
        vector<vector<int>> direction = {
            {0,1},  //N
            {1,0},  //E
            {0,-1}, //S
            {-1,0}  //W
        };
        
        int x = 0, y = 0;       //Initial position of robot
        
/*
                N(face=0)
    W(face=3)               E(face=1)
                S(face=2)
*/
        int face = 0;           //Robot Facing North
        
        for (auto i : instructions) {
            if (i == 'L')
                face = (face + 3) % 4;
            else if (i == 'R')
                face = (face + 1) % 4;
            else {
                x += direction[face][0];
                y += direction[face][1];   
            }    
        }
        
        //After 1 cycle, robot returned to 0,0
        if(x == 0 && y == 0)
            return true;
        
        //After 1 cycle, robot does not face north
        if(face != 0)
            return true;
        
        return false;
    }
```
