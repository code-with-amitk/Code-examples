**Jump Game**
- [Approach-1. Backtracking. O(2<sup>n</sup>) TLE](#a1)
- [Approach-2. DP, Top Down. O(n)](#a2)

### [55. Jump Game / Selecting Ladder to reach end](https://leetcode.com/problems/jump-game/)
- Array of non-negative integers, which represents max JUMPS from that position. We are initially positioned at the 0th index of the array, Determine can we reach LAST index?
- Each element in the array represents **maximum jump/ladder length** from that position, we can choose smaller jump from that position also.
- **Examples**
```c
Input: nums = [2,3,1,1,4]
Output: true
Explanation: jump 1 -> 3(end)  
            index 0    1          
//Jump 1 step from index 0 to 1, then 3 steps to the last index.
  
Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, 
which makes it impossible to reach the last index.
```

<a name=a1></a>
### Approach-1, Backtracking. O(2<sup>n</sup>) TLE
- [Backtracking Template](/DS_Questions/Algorithms)
- _Why Backtracking?_ We need to find all ways/combinations to reach end.
```c
Backtrack Tree
a = 3  2  1  0  4
    0  1  2  3  4
                                 []
                  ------------------------------------         
                  |                 |         |      |
                  0                 1         2      3(f)
           -------------         ---------    |
           |     |     |         |       |    3(f)
           3(f)  2     1         3       2
                /     / \                 \
               3(f)  3(f) 2                 3(f)
                           \
                            3(f)
                            
rb(2) -> rb(3) function will get called again and again.
```
#### Logic
- _1._ Start from index=0. Jump to all possible indexes from 0.
```c
nums = [2,3,1,1,4]
        0 1 2 3 4

From index=0, we can jump to index=2 and index=1
```
- _2._ Jump to index=2, check whether I can reach end from here, if not jump to all possible indexes
#### Complexity
- **Time:** O(2<sup>n</sup>)
  - Look at backtrack tree. For n=5 elements, consider only n-1=4 elements.
  - For n elements there can be n levels and every node can have n children. So its traversing n array tree.
- **Space:** O(n). Recursion requires additional memory for the stack frames.

#### Code
**C++**
```cpp
class Solution {
    int lastIndex;
public:
    bool rb (vector<int>& nums, int index) {
        bool ret = false;
        
        // Base case
        // if from present index I can reach end, return true
        if (nums[index] >= lastIndex - index)
            return true;

        // All possible candidates
        // Start from last possible index where I can reach
        for (int i=nums[index]; i>0; --i) {
            // Jump to index
            ret = rb (nums, i + index);
            if (ret)
                break;
        }
        return ret;
    }
    bool canJump(vector<int>& nums) {
        lastIndex = nums.size() - 1;
        
        // Start jump from index=0
        return rb (nums, 0);
    }
};
```
- **Rust**
  - _1._ vector.len() return usize `pub fn len(&self) -> usize` should be typecasted
  - _2._ Arrays need to be indexed by a [usize type](/Languages/Programming_Languages/Rust/Data_Types), typecasted
```rs
fn fun(v:&Vec<i32>, i:i32) -> bool {
    let size = v.len() as i32;                  //1
    if i >= (size -1) {
        return true;
    }

    for j in i+1..v[i as usize]+i+1 {         //2
        if fun (v, j) {
            return true;
        }
    }
    false
}

fn can_jump(v:&Vec<i32>) -> bool {
    fun(v, 0)
}


fn main() {
    let v = vec![3,2,1,0,4];
    if can_jump(&v) == true {
        print!("Yes");
    }
    else{
        print!("No");
    }
}
```

<a name=a2></a>
### Approach-2, DP with Backtracking         //[Dynamic Programming, Top Down](/DS_Questions/Algorithms)
#### Problem with Approach-1
- if we see backtrack tree some functions are called again and again. if we store result when we visited those for 1st time in `vector<bool>` we can avoid complete repetative recursive stack.
#### Logic
- _1._ Take a `vector<bool> dp` of same size as input array
- _2._ Intialize all elements to true. Initialize elements of dp array to false whose which are 0 in original array
```c
a =  3  2  1  0  4
     0  1  2  3  4
dp = t  t  t  f  t
```
- _3._ Check dp array as 1st step when we enter rb() function, `if dp[index] == false`, return false.
- _4._ update `dp[index] = false` when found, cannot reach end from index ie after for loop.
#### Complexity
- **Time:** O(n) 
  - After nearly 1st filling of dp array we return, instantly.
```c
                                     []
                        ---------------------------
                        |         |        |       |
                        0         1(f)     2(f)    3(f)
                       /  \
                    3(f)   2(f)
                           /
                          3(f) 

```
- **Space:** O(n). Usage of the dpArray table.
#### Code
- **C++**
```c++
class Solution {
    int lastIndex;
public:
    bool rb (vector<int>& nums, vector<bool>& dp, int index) {

        // Check dp array 1st, if cannot reach end from this element
        // return false
        if (dp[index] == false)
            return false;

        bool ret = false;
        // Base case
        if (nums[index] >= lastIndex - index)
            return true;

        for (int i=nums[index]; i>0; --i) {
            // Jump to index
            ret = rb (nums, dp, i + index);
            if (ret)
                break;
        }
        
        // We cannot reach end from present index, set dp[index]=false
        if (ret == false)
            dp[index] = false;

        return ret;
    }

    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
            
        // Whichever element in 0 in nums array
        // make that dp[i] = false, because for sure we 
        // cannot reach end from that element
        vector<bool> dp(nums.size(), true);
        for (auto&i:nums){
            if (!i) {
                int index = &i-&nums[0];
                dp[index]=false;
            }
        }
        
        lastIndex = nums.size() - 1;
        return rb (nums, dp, 0);
    }
};
```
