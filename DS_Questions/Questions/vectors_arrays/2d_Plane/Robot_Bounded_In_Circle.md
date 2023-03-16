**Robot Bounded In Circle**
- [Approach-1. Add Direction to position. O(n)](#a1)
  - [Logic](#l)
  - [Complexity](#c)
  - Code
    - [CPP](#cpp)
    - [Rust](#rs)

## [Self Video](https://youtu.be/0bkQJuLlUI0)

## [1041. Robot Bounded In Circle](https://leetcode.com/problems/robot-bounded-in-circle/)
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

<a name=a1></a>
### Approach-1. Add direction to position
#### Logic
4 Directions
```c
                             N (0,1)
                    W(-1,0)             E(1,0)
                            S(0,-1)
```
- On 'L' and 'R' we will only change direction.
- On 'G' we will change direction position (not direction
```
start position (0,0)
start Direction=N
```c
- Input='G'
  - nextPostition = (0,0) + (0,1) = (0,1)
- Input='L'
  - nextDirection = (-y, x) = (-1,0). Turned Left=West
- Input='R'
  - nextDirection = (y, -x) = (0,1). Turned Right=North
```
- After processing input instructions
  - if my direction != North
  - OR if I am at (0,0)
    - I can reach (0,0). Return true

#### Complexity
- **Time:** O(n). Passing thru string only once
- **Space:** [O(1)](/DS_Questions).
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int,int> direction = {0,1};     //Starting Direction=North
        pair<int,int> position = {0,0};

        for (auto &i:instructions) {
            switch (i) {
/*
              N(0,1)
    W(-1,0)    0,0     E(1,0)
              S(0,-1)
*/
                case 'L':{
                /*
                             N (0,1)
                    W(-1,0)             E(1,0)
                            S(0,-1)
                  present Direction N(x=0,y=1)
                        L. New Direction=West. x=-y, y=x    (-1,0)
                        L. New Direction=South. x=-y, y=x   (0,-1)
                        L. New Direction=East. x=-y, y=x   (1,0)
                        L. New Direction=North. x=-y, y=x   (0,1)
                    present Direction N(x=0,y=1)
                        R. New Direction=East. x=y, y=-x    (1,0)
                        R. New Direction=South. x=y, y=-x   (0,-1)
                        R. New Direction=West. x=y, y=-x    (-1,0)
                        R. New Direction=North. x=y, y=-x   (0,1)
                */
                    // x = -y,  y = x
                    direction = {-direction.second , direction.first};
                    break;
                }
                case 'R':{
                    // x = y,  y = -x
                    direction = {direction.second, -direction.first};
                    break;
                }
                case 'G':{
                /*
                        New Position = old_position + direction
                        postition = (0,0).
                            Dir=N. G.    = (0,0)+(0,1) = 0,1
                        L
                        postition = (0,1).
                            Dir=L. G.    = (0,1)+(-1,0) = -1,1
                        R
                        postition = (-1,1).
                            Dir=R. G.    = (-1,1)+(0,1) = -1,2

                */
                    position = {position.first + direction.first, 
                                position.second + direction.second};
                    break;
                }
                default:
                    continue;
            }
        }
        cout << "position.0 " << position.first << ",position.1 " << position.second <<"\n";
        if (position.first == 0 && position.second == 0)
            return true;
        else if (direction.first != 0 || direction.second != 1)
            return true;
        return false;
    }
};
```
<a name=rs></a>
**Rust**
```rs
impl Solution {
    pub fn is_robot_bounded(instructions: String) -> bool {
        let mut direction = (0, 1);
        let mut position = (0, 0);

        for c in instructions.chars() {
            match c {
                /*
                             N (0,1)
                    W(-1,0)             E(1,0)
                            S(0,-1)
                  present Direction N(x=0,y=1)
                        L. New Direction=West. x=-y, y=x    (-1,0)
                        L. New Direction=South. x=-y, y=x   (0,-1)
                        L. New Direction=East. x=-y, y=x   (1,0)
                        L. New Direction=North. x=-y, y=x   (0,1)
                    present Direction N(x=0,y=1)
                        R. New Direction=East. x=y, y=-x    (1,0)
                        R. New Direction=South. x=y, y=-x   (0,-1)
                        R. New Direction=West. x=y, y=-x    (-1,0)
                        R. New Direction=North. x=y, y=-x   (0,1)
                */
                'L' => {
                    direction = (-direction.1, direction.0)
                },
                'R' => {
                    direction = (direction.1, -direction.0)
                },
                /*
                        New Position = old_position + direction
                        postition = (0,0).
                            Dir=N. G.    = (0,0)+(0,1) = 0,1
                        L
                        postition = (0,1).
                            Dir=L. G.    = (0,1)+(-1,0) = -1,1
                        R
                        postition = (-1,1).
                            Dir=R. G.    = (-1,1)+(0,1) = -1,2

                */
                'G' => {
                    position = (position.0 + direction.0,
                                position.1 + direction.1)
                },
                _ => {}
            }
        }
        if position == (0, 0) {
            // If i reached (0,0)
            return true;
        }
        else if direction != (0, 1) {
            // if direction is not North, Then after repetative steps, I can reach 0,0
            return true;
        }
        false        
    }
}
```
