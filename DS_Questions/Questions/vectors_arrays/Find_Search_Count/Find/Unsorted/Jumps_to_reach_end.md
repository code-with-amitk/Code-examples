## [Minimum number of jumps to reach end / Selecting Ladder to reach end](https://leetcode.com/problems/jump-game/)
- Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
- Each element in the array represents **maximum jump/ladder length** from that position, we can choose smaller jump from that position also.
- Determine if you are able to reach the last index.
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
    bool fun(int position, vec& a) {
        int size = a.size();
        if (position == size - 1)
            return true;

        int jump = std::min(position + a[position], size - 1);

        for (int i = position + 1; i <= jump; ++i) {
            if (fun(i, a))
                return true;
        }
        return false;
    }

    bool canJump(vec& a) {
        return fun(0, a);
    }
};
int main() {
    vec a = { 3,2,1,0,4 };
    Solution s;
    cout << s.canJump(a);
}
```

 ### Approach-2         //[Dynamic Programming, Top Down](/DS_Questions/Algorithms/Dynamic_Programming)
