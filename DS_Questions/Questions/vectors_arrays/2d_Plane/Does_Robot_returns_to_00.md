**Robot Bounded In Circle**
- [Approach-1. Limit Cycle Trajectory](#a1)

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

#### Limit Cycle Trajectory?
- **What?** A limit cycle is a closed trajectory in phase space having the property that at least one other trajectory spirals into it either as time approaches infinity.
- **Conditions for LCT?**
  - If robot returns to the initial point(0,0) after one cycle, that's the limit cycle trajectory.
  - If the robot does not face north at the end of the first cycle, that's the limit cycle trajectory.

<a name=a1></a>
### Approach    //Identify Limit Cycle Trajectory
#### Logic
  - *1.* Take 4 points identifying the directions N=(0,1), E=(1,0), S=(0,-1), W=(-1,0)
  - *2.* Take variable `face` which tells about position of robot. N=0,E=1,S=2,W=3
  - *3.* Take x=0,y=0 identifying the position of robot. Initially at 0,0.
  - *4.* Iterate through input string and change x,y coordinates as per values in input string.
#### Complexity?
- **Time:** O(n). Passing thru string only once
- **Space:** [O(1)](/DS_Questions). We have allocated 4x4 vector and using it all times.
#### Code
**CPP**
```c++
bool isRobotBounded(string instructions) {
/*
              N(0,1)
    W(-1,0)    0,0     E(1,0)
              S(0,-1)
*/
  vector<vector<int>> direction = {                             //1
    {0,1},  //N
    {1,0},  //E
    {0,-1}, //S
    {-1,0}  //W
  };
/*
             N(face=0)
   W(face=3)           E(face=1)
             S(face=2)
*/
  int face = 0;           //Robot Facing North                 //2
  
  int x = 0, y = 0;       //Initial position of robot          //3
        
  for (auto i : instructions) {                                //4
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
