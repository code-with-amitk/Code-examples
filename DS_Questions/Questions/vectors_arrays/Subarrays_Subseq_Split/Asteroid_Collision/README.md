- [Asteroid Collision](#what)
- [Approach-1, Stack](#apr1)
  - [Why Stack](#why)
  - [Logic](#logic)
  - [Complexity](#comp)
  - [Code](#code)

<a name=what></a>
## [Asteroid Collision](https://leetcode.com/problems/asteroid-collision/)
- Given an array asteroids of ints which represents moving asteroids.
- Value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
- Find out the state of the asteroids after all collisions. 
- If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
- Examples
```c
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: 5,10 moving towards right. Note 5,10 are weights. All asteriods move with same speed. 10 and -5 collide resulting in 10. The 5 and 10 will never collide

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Input: {-2,-1,1,2};
output: {-2,-1,1,2}
Explaination: -2,-1 moves towards left. 1,2 moves towards right noone will collide

Input: {-2,1,-1,-2};
Ouput: {-2,-2};
Explanation: -2 moving towards left. 1 towards right. -1 towards left. (1,-1) collide and both vanished. -2,-2 both moving towards left will never collide.
```

<a name=apr1></a>
### Approach-1. Stack

<a name=why></a>
#### Why Stack?
- Questions where we have to move backward while moving forward in array should be dealt with stack.

<a name=logic></a>
#### Logic
- _1._ Take a stack. Start traversing array from left.
- _2._ Push on stack on following conditions:
  - _a._ 1st element is -ve. ie 1st asteriod moving left
  - _b._ Any element is +ve. ie asteriod moving right
- _3._ if (stack != empty) and (asteriod is moving to left ie -ve value)
  - if (top of stack is +ve)
    - if (top == abs(-ve))  Blow -ve and asteriod at top
    - if (top > abs(-ve))   Blow -ve asteriod only
    - if (top < abs(-ve))   Blow asteriod on top of stack, still keep going into stack
 - _4._ Create vector from stack and return

<a name=comp></a>
#### Complexity
- **Time:** O(n). Gone n. Then traversed back n, and popped all stack.
```c
1,1,1,1,1,1,-2
```
- **Space:** O(n). Stack size. All asteriods are on stack
```c
1,1,1,1,1,1
```

<a name=code></a>
#### Code
```c++
class Solution {
public:
  vector<int> asteroidCollision(vector<int>& v) {
    stack<int> s;
    bool bBlow = false;

    for (int i: v) {
      bBlow = false;
      while (s.empty() != 1 && i < 0 && 0 < s.top()) {
        if (s.top() < abs(i)) {                         //3c
          s.pop();
          continue;
        } else if (s.top() == abs(i)) {                 //3a
          s.pop();
        }
        bBlow = true;                                  //3b
        break;
      }//while
      if (!bBlow)
        s.push(i);                                      //2
    }//for

    vec o;
    while (s.empty() != 1){
      o.insert(o.begin(),s.top());
      s.pop();
    }
    return o;

  }
};

//Tested using googleTest
```
