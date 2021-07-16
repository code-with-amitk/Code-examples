- [Asteroid Collision](#what)
- Approach-1, Stack
  - [Why Stack](#why)
  - [Logic](#logic)
  - [Complexity](#comp)
  - Code
    - [C++](#cpp)
    - [Rust](#rust)

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

#### Code

<a name=cpp></a>
#### C++
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

<a name=rust></a>
#### Rust
```rs
struct Solution{}      //Since impl is associated with struct

impl Solution {
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<i32> = Vec::new();
        let mut blow:bool;

        for i in asteroids.iter() {
            blow = false;
            while stack.len() != 0 && i < &0 && stack.last() > Some(&0) {
                if stack.last() < Some(&i.abs()) {
                    stack.pop();
                    continue;
                }
                else if stack.last() == Some(&i.abs()){
                    stack.pop();
                }
                blow = true;
                break;
            }//while
            if !blow {
                stack.push(*i);
            }
        }//for
        stack        
    }
}

#[cfg(test)]                               //Automated tests run with `cargo test`
mod all_tests {
    use super::*;

    #[test]
    fn test1 () {
        let mut v = vec![5,10];
        assert_eq!(v, Solution::asteroid_collision([5,10,-5].to_vec()));
        v = [10].to_vec();
        assert_eq!(v, Solution::asteroid_collision([10,2,-5].to_vec()));
        v = [-2,-1,-2].to_vec();
        assert_eq!(v, Solution::asteroid_collision([-2,-1,1,-2].to_vec()));
        v = [-2,-2].to_vec();
        assert_eq!(v, Solution::asteroid_collision([-2,1,-1,-2].to_vec()));
    }
}

fn main() {
    let v = vec![-2,1,-1,-2];
    let out = Solution::asteroid_collision(v);
    for i in out.iter() {
        println!("{}",i);
    }
}

$ cargo test
test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.01s

$ cargo build
./main.rs
```
