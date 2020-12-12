## Problem
- Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
- Example
```c
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

## Logic
1. Find Area by multiplying length with min of height.
2. if a[left] < a[right] move left to next element
  - else move right to prev element
  - This is because we want to find max area. so we will move to bigger element only.

## Code
```c++
class Solution {
public:
    int maxArea(vector<int>& v) {
    int l=0, r, max=0, area=0;
    r = v.size()-1;

    while(l<r){
      if(v[l] < v[r])
        area = v[l]*(r-l);
      else
        area = v[r]*(r-l);

      if (area > max)
        max = area;

      if (v[l] <= v[r])
        l++;
      else
        r--;
    }
    return max;   
    }
};
int main(){
//  std::vector<int> v = {1,8,6,2,5,4,8,3,7}; //49
//  std::vector<int> v = {1,2,1};   //2
  std::vector<int> v = {2,3,4,5,18,17,6}; //17
//  std::vector<int> v = {4,3,2,1,4}; //16
  Solution s;
  std::cout<<s.maxArea(v);
}
```
