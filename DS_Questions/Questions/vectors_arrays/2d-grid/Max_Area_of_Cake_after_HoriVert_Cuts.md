- [Max Area 2](#ques)
- Approach-1, Sort
  - [Logic](#logic1)

<a name=ques></a>
## [Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)
- You are given a rectangular cake of size height x width and two arrays of integers horizontalCuts and verticalCuts where:
  - `horizontalCuts[i]` is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
  - `verticalCuts[j]` is the distance from the left of the rectangular cake to the jth vertical cut.
- Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 10<sup>9</sup> + 7.
- Examples
```c
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts.
After you cut the cake, the green piece of cake has the maximum area.
```
<img src=leetcode_max_area_2.png width=200/>

### Approach-1, Sort
<a name=logic1></a>
#### Logic
