**Minimum Moves to Reach Target**

### [Minimum Moves to Reach Target Score](https://leetcode.com/problems/minimum-moves-to-reach-target-score/)
- You are playing a game with integers. You start with the integer 1 and you want to reach the integer target. In one move, you can either:
  - Increment the current integer by one (i.e., x = x + 1).
  - Double the current integer (i.e., x = 2 * x).
- You can use the increment operation any number of times, however, you can only use the double operation at most maxDoubles times.
- Given the two integers target and maxDoubles, return the minimum number of moves needed to reach target starting with 1.
```c
Example-1
Input: target = 19, maxDoubles = 2
Output: 7
Explanation: Initially, x = 1
Increment 3 times so x = 4
Double once so x = 8
Increment once so x = 9
Double again so x = 18
Increment once so x = 19
Example 3:

Example-2
Input: target = 10, maxDoubles = 4
Output: 4
Explanation: Initially, x = 1
Increment once so x = 2
Double once so x = 4
Increment once so x = 5
Double again so x = 10
```

### Logic //Move Backward from target to 1
```c
target = 19, doubles = 2.
  if (target%2 !=0)         //if we cannot jump decrement 1 step
    target -= 1;
  else                      //we can jump. jump to half
    target /= 2;
  out ++;                   //In every case increment the steps.
```

### Code
#### CPP
```c
int minMoves(int target, int maxDoubles) {
    int minMoves(int target, int maxDoubles) {
        int out = 0;
        while (target && maxDoubles) {
            if (target % 2) {            //We cannot jump, move 1 step back
                --target;
            } else {                     //We can jump, jump to half.
                --maxDoubles;
                target /= 2;
            }
            ++out;                       //In either case, count the steps
        }
        return out + target - 1;
    }
}
```
#### Rust
```rs
impl Solution {
    pub fn min_moves(tar: i32, maxd: i32) -> i32 {
        let mut target = tar;
        let mut max_doubles = maxd;
        let mut out = 0;
        while target != 0 && max_doubles != 0 {
            let mut modu = target % 2;
            if modu != 0 {
                target -= 1;
            }
            else {
                max_doubles -= 1;
                target /= 2;
            }
            out += 1;
        }
        out + target - 1
    }
}
```
