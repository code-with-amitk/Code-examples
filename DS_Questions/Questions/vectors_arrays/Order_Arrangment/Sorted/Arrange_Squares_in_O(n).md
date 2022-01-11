**Squares of a Sorted Array**
- [Approach-1. O(nlogn)](#a1)
- [Approach-2. Two pointer. O(n)](#a2)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
    - [Rust](#rs)
    - [Python](#py)

### [Squares of a Sorted Array in O(n)](https://leetcode.com/problems/squares-of-a-sorted-array/)
Given an integer array sorted in ascending order, return an array of the squares of each number sorted in ascending order.
```c
Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100]. After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

<a name=a1></a>
### Approach-1. O(nlogn)
```c
input = [-4,-1,0,3,10]

Step-1: [16,1,0,9,100]    //Find squares. O(n)
Step-2: [0,1,9,16,100]    //Sort. O(nlogn)
```

<a name=a1></a>
### Approach-2. Two pointer. O(n)
- _1._ Take left and right pointer, to left and right of array. Take out array, size=input. We will insert elements in out array from end.
```c
input = [-4,-1,0,3,10]
          l         r
output   0  0  0  0 0          
```
- _2._ if abs(left) < abs(right)
  - insert square of right from end of output array
```c
    -4  -1  0  3  10
    0    1  2  3  4
    l             r
                                  Output    
    i=4   abs(-4) <= abs(10)    | | | | |100|     right--
    i=3   abs(-4) <= abs(3)     | | | |16|100|    left++
    i=2   abs(-1) <= abs(3)     | | |9|16|100|    right--
    i=1   abs(-1) <= abs(0)     | |1|9|16|100|    left++
    i=0   abs(0) <= abs(0)      |0|1|9|16|100|    left++
```

### Code
<a name=cpp></a>
#### CPP
```c
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> out(size,0);
        
        int left = 0, right = size - 1;
        int i = right, val=0;
        while (left <= right){
            if (abs(nums[left]) <= abs(nums[right]))
            {
                val = right--;
            }
            else
            {
                val = left++;           
            }
            out[i--]=nums[val]*nums[val];
        }
        return out;
    }
};
```
<a name=rs></a>
#### Rust
```rs
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let size = nums.len();
        let mut out = vec![0; size];
        
        let mut left = 0; 
        let mut right = size - 1;
        let mut i = right;
        let mut val = 0;
        
        //Why check of 10000, since right is usize. -1 becomes 2pow64
        while  left <= right && right<=10000 {
            if nums[left].abs() <= nums[right].abs() {
                val = right;
                right = right - 1;
            } else {
                val = left;           
                left = left + 1;
            }
            
            out[i]=nums[val]*nums[val];
            i = i - 1;
        }
        out
    }
}
```

<a name=py></a>
#### Python
```py
class Solution(object):
    def sortedSquares(self, A):
        out = collections.deque()
        left, right = 0, len(A) - 1
        i = 0
        while left <= right:
            if abs(A[left]) > abs(A[right]):
                out.appendleft(A[left] * A[left])
                left += 1
            else:
                out.appendleft(A[right] * A[right])
                right -= 1
        return list(out)
```
