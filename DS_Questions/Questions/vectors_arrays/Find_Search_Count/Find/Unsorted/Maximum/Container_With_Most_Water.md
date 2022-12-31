**Container with Most Water**
- [Approach-1, 2 Pointer. O(n)](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
    - [Java](#j)
    - [Python](#py)
    - [C](#c)
    - [Rust](#r)

### [11. Container with most water](https://leetcode.com/problems/container-with-most-water/)
- Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
- Example
```c
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: In this case, the max area of water (blue section) the container can contain is 49.
```

<img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg"  width="500" />

## [Self Video](https://youtu.be/rH7AOvO2Hn0)

### Approach-1. 2 Pointer. O(n)
#### Logic
- *1.* left pointer = 0, right pointer = arr.size()-1
- *2.* Start from index = 0 and calculate areas, keep note of max area.
```c
  area = min(height of left pointer, height of right pointer) * (right-left)
```
- *3.* if `(height[left] < height[right])` move left pointer by 1 else decrement right pointer since we want max hegiht.
#### Complexity
- **Time** O(n)
- **Space** O(1). Constant space
  - If space used by algorithm increases/decreases with input, then it's not constant. If algo always uses a fixed space everytime independent of input size, then its constant space.
  - Recursion? Stack is also counted in space complexity.
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (!height.size())
            return 0;
        int left = 0, right = height.size() - 1;
        long out=0;
        while (left < right) {
            long area = min(height[left], height[right]) * (right-left);
            out = max(area, out);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return out;
    }
};
```
<a name=j></a>
**Java**
```j
class Solution {
    public int maxArea(int[] height) {
        int out = 0, left = 0, right = height.length-1;
        while (left < right) {
            int area = Math.min(height[left], height[right]) * (right-left);
            out = Math.max(out, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return out;
    }
}
```
<a name=py></a>
**Python-3**
```py
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1
        out=0
        while left < right:
            area = min(height[left], height[right]) * (right-left)
            out = max(out, area)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return out
```
<a name=c></a>
**C**
```c
int max(int num1, int num2) {
    return (num1 > num2 ) ? num1 : num2;
}

int min(int num1, int num2) {
    return (num1 > num2 ) ? num2 : num1;
}

int maxArea(int* height, int heightSize){
    int left=0, right=heightSize-1, out=0;
    while (left < right) {
        int area = min(height[left], height[right]) * (right-left);
        out = max(out, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return out;
}
```
<a name=r></a>
**Rust**
```rs
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = height.len()-1;
        let mut out = 0;
        loop {
            if left >= right {
                break;
            }
            let mut area = std::cmp::min(height[left], height[right]) * ((right-left) as i32);
            out = std::cmp::max(out, area);
            if height[left] < height[right]{
                left += 1;
            }
            else {
                right -= 1;
            }
        }
        out
    }
}
```
