**Maximum Subarray**
- [Approach-1, Brute Force. O(n<sup>2</sup>)](#a1)
- [Approach-2, Kadane's Algo. O(n)](#a2)


### [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
Find max subarray with largest sum. Subarrays are contigious.
```c
Ex-1
Input:    A = [1, 2, 3, 4, -10]
Output:   10   //The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Ex-2
Input:   A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output:  6    //SubArray [4,-1,2,1] has the maximum possible sum of 6.
```

### [Self Video](https://youtu.be/G1EpmNrd1W8)

<a name=a1></a>
### Approach-1. Brute Force. TLE
- _1._ What all subarrays can exist?
```c
{1, 2, 3, 4, -10}
1
1,2
1,2,3
1,2,3,4
1,2,3,4,-10
2
2,3
2,3,4
2,3,4,-10
3
3,4
3,4,-10
4
4,-10
-10
```
- _2._ Use 2 nested for loops and find all subarrays.
#### Code
```c
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;

        for (int i=0;i<nums.size();++i) {
            int sum = 0;
            for (int j=i;j<nums.size();++j) {
                sum += nums[j];
                if (sum>max)
                    max = sum;
            }
        }
        return max;
    }
};
```

<a name=a1></a>
### Approach-2 (Kadane's Algo)
#### Logic
- _1._ Take variable maxHere. This variable stores maximum sum till present element.
  - Initialize maxHere = 0
  - if (maxHere + present_element `<` 0). maxHere = 0.
```c
maxHere=0;
maxHere = maxHere + present_element;
if (maxHere + present_element < 0)
    maxHere = 0;
    
arr         1 3 -6 9 -10 -4 -3 6
index       0 1  2 3   4  5  6 7       
       
maxHere     1 4  0 9  0   0  0 6

maxHere=0
i   maxHere
0   1
1   4
2   0       4-6<0
3   9
4   0       9-10<0
5   0       0-4<0
6   0       0-3<0
7   6
```

#### Code
**C++**
```cpp
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
        int maxHere = 0;
        int out = INT_MIN;
        for (int i=0;i<nums.size();++i){
            maxHere += nums[i];
            out = max(out, maxHere);
            if(maxHere < 0)
                maxHere = 0;
        }
        return out;       
  }
};
```
**Rust**
```rs
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut max_here = 0;
        let mut out = core::i32::MIN;
        for i in nums.iter() {
            max_here += i;
            if max_here > out {
                out = max_here;
            }
            if max_here < 0 {
                max_here = 0;
            }
        }
        out
    }
}
```
