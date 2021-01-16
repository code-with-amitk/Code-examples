## [1 Container having Max water](https://leetcode.com/problems/container-with-most-water/)
- Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
- Example
```c
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: In this case, the max area of water (blue section) the container can contain is 49.
```

<img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg"  width="500" />

## [Self Video](https://youtu.be/rH7AOvO2Hn0)

## 1. Approach-1 (2 Pointer)
### Logic
- *1.* left pointer = 0, right pointer = arr.size()-1
- *2.* Start from index = 0 and calculate areas, keep note of max area.
```c
  area = max(height of left pointer, height of right pointer) * (right-left)
```
- *3.* if `(height[left] < height[right])` move left pointer by 1 else decrement right pointer since we want max hegiht.
### Complexity
- **Time** O(n)
- **Space** O(1). Constant space
  - If space used by algorithm increases/decreases with input, then it's not constant. If algo always uses a fixed space everytime independent of input size, then its constant space.
  - Recursion? Stack is also counted in space complexity.
### Code-Approach-1
```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left, right, area, temp;
        left = 0, right = height.size() - 1, area = 0, temp = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                temp = height[left] * (right - left);
                ++left;
            } else {
                temp = height[right] * (right - left);
                --right;
            }
            
            if (temp > area)
                area = temp;
        }
        return area;
    }
};
```
