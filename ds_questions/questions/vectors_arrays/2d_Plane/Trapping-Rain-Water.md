## [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)
- Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

<img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png"  width="500" />

```c
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
```

## [Self Video, Tough question](https://youtu.be/tIedNwFi0B0)

## 1. Approach (2 Pointer) 
### Logic
- *1.* Take 2 pointer left=0, right=arr.size()-1. Move until they cross
- *2.* if `arr[left] > arr[right]`    //means there is a bigger wall on left wrt any building on right
  - *2a.* Start moving from right hand side.
  - *2b.* Find rightMax. rightMax is maximum height of building on right.
  - *2c.* 
```c

Example: {2,0,1,0,3,0,1,0,1}

leftMax = 0
rightMax = 0
move until left right cross

1st iteration
  height[left=0]=2 > height[right=8]=1    //Start from right
				|  |
     |  |			|  |
     |  |	  |  |		|  |	  |  |		|   |
     -----------------------------------------------------
     2       0	    1	  0	 3    0	   1	 0	  1         <---Height
     0	     1	    2     3	 4    5	   6	 7	  8
    left					         right

  if (height[8]=1 > rightMax=0)
    rightMax = 1
out = 0
rightMax = 1

2nd iteration
				|  |
     |  |			|  |
     |  |	  |  |		|  |	  |  |		|   |
     -----------------------------------------------------
     2       0	    1	  0	 3    0	   1	 0	  1         <---Height
     0	     1	    2     3	 4    5	   6	 7	  8
	 left					right
   
if (rightMax > height[7]=0)
    out = 1                     //At index=7, area=1 water can be trapped
rightMax = 1

3rd iteration   //still lfet > right. Keep moving right
				|  |
     |  |			|  |
     |  |	  |  |		|  |	  |  |		|   |
     -----------------------------------------------------
     2       0	    1	  0	 3    0	   1	 0	  1         <---Height
     0	     1	    2     3	 4    5	   6	 7	  8
	 left				 right
   
if (height[6]=1 is not smaller than rightMax)
    do nothing              //At index=6 no water can be trapped since max
rightMax = 1

.. so on
```

<img src="https://i.ibb.co/pvQDzsV/trapping-rain-water-1.png"  width="1500" />

### Complexity
- **Time:** O(n)  //Only traversing 1 time
- **Space:** O(1) //no extra space used

### Code
```c++
class Solution {
public:
    int trap(vector<int>& height) {
    int out = 0, left = 0, right = height.size()-1;
    int leftMax = 0, rightMax = 0;

    while (left < right) {
      if (height[left] > height[right]) {

        //Find Maximum height present on my right
        if (height[right] >= rightMax)
          rightMax = height[right];
        else      //if myHeight < rightMax, means it forms a box. Because left>right. area = (rightMax - MyHeight)
          out += rightMax - height[right];
          --right;
      }
      else
      {
        if (height[left] >= leftMax)
          leftMax = height[left];
        else
          out += leftMax - height[left];
          ++left;
      }
    }
    return out;        
    }
};
```
