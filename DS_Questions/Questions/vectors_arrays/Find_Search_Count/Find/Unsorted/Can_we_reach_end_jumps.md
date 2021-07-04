## [Can we reach end / Selecting Ladder to reach end](https://leetcode.com/problems/jump-game/)
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

### Approach-1  //[Backtracking](/DS_Questions/Algorithms)  //O(2<sup>n</sup>), Time limit exceed
```c
a = 3  2  1  0  4
    0  1  2  3  4
                        [0]                     //From index 0. 3 possible jumps.
                0/      1|       2\
               [1]      [2]       [3]       //From index=1. 2 possible jumps. 
              /  \       |         |        //From index=2. 1 possible jump.
            [2]  [3]    [3]       No        //From index=3. No possible jump. Cannot reach end.
             |           |
            [3]          No
             |
            No
//See calculation of [2]->[3]->No gets repeated.            
```
- **Logic:** Jump from position 0 to 4, 0 to 3, 0 to 2, 0 to 1. if no jump is possible return false.
- **Complexity**
  - **Time:** O(2<sup>n</sup>)
    -  There are 2<sup>n</sup> ways of jumping from the first position to the last, n is the length of input array.
  - **Space:** O(n)O(n). Recursion requires additional memory for the stack frames.
- **Code** 
  - **C++**
```c++
class Solution {
  using vec = vector<int>;
public:
  
  bool fun(vec& a, int i){     //i=index
    int size = a.size();

    //Reached last index or beyond
    if (i >= size -1)
      return true;

    //Jump from present+1 index
    for (int j = i+1; j < a[i]+i+1; ++j) {
       if (fun(a, j))
          return true;
    }
    return false;
  }

  bool canJump(vec& a) {
    //Start jump from index=0
    return fun(a, 0);
  }
};
int main() {
    vec a = { 3,2,1,0,4 };
    Solution s;
    cout << s.canJump(a);
}
```
- **Rust**
  - _1._ vector.len() return usize `pub fn len(&self) -> usize` should be typecasted
  - _2._ Arrays need to be indexed by a [usize type](/Languages/Programming_Languages/Rust/Data_Types), typecasted
```rust
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

 ### Approach-2         //[Dynamic Programming, Top Down](/DS_Questions/Algorithms)
- **Logic**
  - 1. Create a bool dpArray which tells whether we can reach end from particular index or not.
    - if end can be reached from index. `dp[index] = true`
    - if end cannot be reached from index. `dp[index] = false`
    - Initially all elements of dpArray are Bad `vector<bool> dpArray(array.size()-1, false);`
    - Last element of dpArray is always good. Since element can reach itself always.
    - This array is calculated in reverse(ie from last to 1st). if 1st index is good, we can reach end.
```c
array	2	4	2	1	0	2	0
Indexes	0	1	2	3	4	5	6
dpArray	1	1	0	0	0	1	1    //Good=1, Bad=0
vector<bool> dpArray(array.size()-1, false);    //Initially all dpArray is bad 

index=0, We can reach end.  index=0 --> index=1 --> index=5 --> end     //Index=0 is good
index=1, We can reach end.  index=1 --> index=5 --> end                 //Index=1 is good
index=2, We cannot reach end.
                            index=2 --> index=4 -> Stop at index 4      //Index=2 is bad
                            index=2 --> index=3 -> Stop at index 4
index=3, Bad
index=4, We cannot jump from here and its not last index.               //Index=4 is bad
index=5, Good
index=6, This is last index and not jump is needed.                     //Index=6 is good
```
  - *2.* Modify above backtracking algorithm, such that the recursive step first checks if the index is known (GOOD / BAD). 
    - If it is known then return True / False. Otherwise perform the backtracking steps as before. 
    - Once value of the current index is determined, store in dpArray.
- **Complexity**
  - **Time:** O(n<sup>2</sup>) 
    - For every element in the array, we are looking at the next `a[i]` elements to its right which is GOOD index. 
    - `a[i]` can be at most n, where n is the length of array a.
  - **Space:** O(2n)=O(n). First n originates from recursion. Second n comes from the usage of the dpArray table.
- **Code**
```c++
class Solution {
  enum class State{
    Good,
    Bad,
    Unknown
  };
  using vecS = vector<state>;
  using vecI = vector<int>;
public:
  bool calc(int i, vecI& a, vecS& dp){
    if (dp[i] != State::Unknown)
      return dp[i] == State::Good ? true : false;

    int size = a.size();

    int jump = std::min(i + a[i], size - 1);

    for (int j=i+1; j<=jump; ++j) {
      if (calc(j, a, dp)) {
        dp[i] = State::Good;
        return true;
      }
    }
    dp[i] = State::Bad;
    return false;
  }

  bool canJump(vecI& a) {
    vecS dp(a.size(), State::Unknown);
    dp[a.size()-1] = State::Good;       //Last index can always reach itself

    return calc(0, a, dp);
  }
};
int main() {
  vec a = {3,2,1,0,4};
  Solution s;
  cout<<s.canJump(a);
}
```
