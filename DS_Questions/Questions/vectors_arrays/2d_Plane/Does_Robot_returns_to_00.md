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

