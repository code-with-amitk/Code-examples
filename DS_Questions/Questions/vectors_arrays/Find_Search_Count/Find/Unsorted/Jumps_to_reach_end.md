## [Minimum number of jumps to reach end / Selecting Ladder to reach end](https://leetcode.com/problems/jump-game/)
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
```
- **Logic**
  - _1._ Jump from position 0 to 4, 0 to 3, 0 to 2, 0 to 1. if no jump is possible return false.
- **Complexity**
  - **Time:** O(2<sup>n</sup>)
    -  There are 2<sup>n</sup> ways of jumping from the first position to the last, n is the length of input array.
  - **Space:** O(n)O(n). Recursion requires additional memory for the stack frames.
- **Code** 
```c++
class Solution {
public:
    bool CanJumpFromPosToEnd(int position, vec& a) {
        int size = a.size();
        if (position == size - 1)
            return true;

        int jump = std::min(position + a[position], size - 1);

        for (int i = position + 1; i <= jump; ++i) {
            if (CanJumpFromPosToEnd(i, a))
                return true;
        }
        return false;
    }

    bool canJump(vec& a) {
        return CanJumpFromPosToEnd(0, a);
    }
};
int main() {
    vec a = { 3,2,1,0,4 };
    Solution s;
    cout << s.canJump(a);
}
```

 ### Approach-2         //[Dynamic Programming, Top Down](/DS_Questions/Algorithms/Dynamic_Programming)
- **Logic**
  - 1. Create a bool dpArray which tells whether we can reach end particular index or not.
    - if end can be reached from index. `dp[index] = true`
    - if end cannot be reached from index. `dp[index] = false`
    - Initially all elements of dpArray are Bad `vector<bool> dpArray(array.size()-1, false);`
    - Last element of dpArray is always good. Since element can reach itself always.
```c
array	2	4	2	1	0	2	0
Indexes	0	1	2	3	4	5	6

dpArray	1(G)	1(G)	0(B)	0(B)	0(B)	1(G)	1(G)    //G=Good, B=Bad
vector<bool> dpArray(array.size()-1, false);    //Initially all dpArray is bad 

index=0, We can reach end.  index=0 --> index=1 --> index=5 --> end     //Index=0 is good
index=1, We can reach end.  index=1 --> index=5 --> end                 //Index=1 is good
index=2, We cannot reach end.
                            index=2 --> index=4 -> Stop at index 4      //Index=2 is bad
                            index=2 --> index=3 -> Stop at index 4
index=3, Bad
index=4, We cannot jump from here and its not last index.               //Index=4 is bad
index=5, Good
index=6, This is last index and not jump is needed.                     //Index=6 is bad
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
public:
  bool fun(int position, vec& a, vector<State>& dpArray){
    if (dpArray[position] != State::Unknown)
      return dpArray[position] == State::Good ? true : false;

    int size = a.size();

    int jump = std::min(position + a[position], size - 1);

    for (int nextJump=position+1; nextJump<=jump; ++nextJump) {
      if (fun(nextJump, a, dpArray)) {
        dpArray[position] = State::Good;
        return true;
      }
    }
    dpArray[position] = State::Bad;
    return false;
  }

  bool canJump(vec& a) {
    vector<State> dpArray(a.size(), State::Unknown);
    dpArray[a.size()-1] = State::Good;       //Last index can always reach itself

    return fun(0, a, dpArray);
  }
};
int main() {
  vec a = {3,2,1,0,4};
  Solution s;
  cout<<s.canJump(a);
}
```
