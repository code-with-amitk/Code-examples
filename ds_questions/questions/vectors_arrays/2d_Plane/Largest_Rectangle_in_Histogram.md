## [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
- Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
- Example
```c
heights[] = [2,1,5,6,2,3]
Output = 10     //The largest rectangle is shown in the shaded area, which has area = 10 unit.
```
<img src="https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png" width="300" />

### Approach-1      //O(n<sup>2</sup>)
- **Logic**
  - *1.* Take a variable max = INT_MIN
  - *2.* Find 
```c

i = 0
  area = 2*1      //myHeight * 1
  if (area > max)
    max = area
    
  j=1   area = (smallest height in (2,1)=1) area = 1*2    //smallestHeight x Length
  j=2   area = (smallest height in (2,1,5)=1) area = 1*3    //smallestHeight x Length
  j=3   area = (smallest height in (2,1,5,6)=1) area = 1*4    //smallestHeight x Length
  
  so on
```
- **Complexity**
  - **Time:** O(n<sup>2</sup>)
  - **Space:** O(1)
- **Code**
```c++
int largestRectangleArea(vector<int> &A) {
    int max = INT_MIN;
    int minHeight;
    int k = 1;

    for (int i=0; i<A.size(); ++i){
        minHeight = A[i];
        
        if (A[i] > max)     //self
            max = A[i];
        k = 2;
        for (int j=i+1; j<A.size(); ++j){

            if (A[j]<minHeight)
                minHeight = A[j];

            if (minHeight*k > max)
                max = minHeight*k;

            ++k;
        }
    }
    return max;
}
```
