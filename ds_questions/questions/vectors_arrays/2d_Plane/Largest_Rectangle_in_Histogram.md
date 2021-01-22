## [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
- Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
- Example
```c
heights[] = [2,1,5,6,2,3]
Output = 10     //The largest rectangle is shown in the shaded area, which has area = 10 unit.
```
<img src="https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png" width="200" />

## 1. Approach-1      //O(n<sup>2</sup>)
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

## 2. Approach-2    //Divide & Conquer  //Avg:O(nlogn), Worst:O(n<sup>2</sup>)
- **Rationale behind approach** The rectangle with maximum area will be the maximum of:
  - *1.* The widest possible rectangle with height equal to the height of the shortest bar    OR
  - *2.* The largest rectangle confined to the left of the shortest bar(subproblem).    OR
  - *3.* The largest rectangle confined to the right of the shortest bar(subproblem).
  
<img src="https://assets.leetcode.com/static_assets/media/original_images/84_Largest_Rectangle2.PNG" width="250" />

- **Logic**
  - *1.* Find minimum Height at each step. Area = minHeight x length  //area1
  - *2.* Find min Height on left. //area2
  - *3.* Find min Height on right.  //area3
  - Return max of these 3 areas at any step.
```c
  [6, 4, 5, 2, 4, 3, 9]
   0  1  2  3  4  5  6
  
                      Divide(A,0,6)
                        miniIndex = 3       //O(n)
                        area1 = 3*5 = 15
                        area2 = Divide(A, 0, 2)
                        area2 = Divide(A, 3, 6)
                      
          Divide(A,0,2)
            miniIndex = 1   //O(n-3)
            area1 = 4*3 = 12
            area2 = Divide(A,0,0) = 6
            area3 = Divide(A,2,2) = 5
            
    Divide(A,0,0)         Divide(A,2,2)
      return 6*1            return 5*1
```
- **Complexity**
  - *Time:* 
    - Worst case: O(n<sup>2</sup>). if array is sorted either in ascending or descending order, at every step we need to go n-1 elements. `O(n) + O(n-1) + O(n-2)..1 = n(n+1)/2`    
    - Average case: O(nlogn)
      - *1.* Index of minimum element(miniIndex) is calculated at every divide for subarray whose size keep on decreasing and these for loops are not nested. = O(n). `O(n)  +   O(n-m)  + O(m)  ..`
      - *2.* Divide array into 2 parts = logn
  - *Space:* O(n). Allocation of stacks in recursion would be n times.      
- **Code**
```c++
int Divide(vector<int>& A, int low, int high){
  if(low > high)
    return 0;

  if (low == high)      //if only 1 element. Area = HeightofElement x 1
    return A[low];
    
  //Find index of least element between low and high
  int miniIndex = low;
  for (int i = low; i <= high; ++i)
    if(A[miniIndex] > A[i])
      miniIndex = i;

  /*
  int area1 = area2 = area3 = -1;
  area1 = A[miniIndex]*(high-low+1);  //Area of least height box
  area2 = Divide(A, low, miniIndex-1)
  area3 = Divide(A, miniIndex+1, high)
  return max(area1, area2, area3)
  */
  
  return std::max (A[miniIndex]*(high-low+1),
                  std::max (Divide(A, low, miniIndex -1),
                            Divide(A, miniIndex+1, high)));
}

int largestRectangleArea(vector<int> &A) {
  //Divide around least element
  return Divide(A, 0, A.size()-1);
}
```

## Approach-3 //Stack   //O(n)

<img src="https://i.ibb.co/jT6zGDg/max-area-histogram-stack.png" width="400" />
### Logic
- *1.* Take a stack to store indexes. Fill -1 to mark end of stack.
```c
a[] = {1, 3, 4, 5, 2, 6, 10, 1}
       0  1  2  3  4  5   6  7 

stack<int> | -1 |
```
- *2.* Start from index=0, keep filling indexes until we find a decreasing sequence.
```c
a[] = {1, 3, 4, 5, 2, 6, 10, 1}
       0  1  2  3  4  5   6  7 

stack | 3 |
      | 2 |
      | 1 |
      | 0 |
      | -1|
```
- *3.* Start from index=0, keep filling indexes until we find a decreasing sequence.
```c
a[] = {1, 3, 4, 5, 2, 6, 10, 1}
       0  1  2  3  4  5   6  7 

stack | -1| 0 | 1 | 2 | 3 |   //Found a[4] < a[3]
      bottom            top
```
- *4.* On finding decreseasing sequence, start popping and find area. compare with max.
```c
a[] = {1, 3, 4, 5, 2, 6, 10, 1}
       0  1  2  3  4  5   6  7 

  a[3] > a[4]         (5 > 2)

popped 3.   Area = a[3]x1 = 5x1 = 5
stack | -1| 0 | 1 | 2 |
      bottom         top  
      
Still a[2] > a[4]      (4 > 2)

popped 2.   Area = a[2]x2 = 4x2 = 8
stack | -1| 0 | 1 |
      bottom     top        

Still a[1] > a[4]      (3 > 2)

popped 1.   Area = a[1]x3 = 3x3 = 9
stack | -1| 0 |
    bottom    top        

Still a[0] < a[4]      (1 < 2)

////////////////Donot pop, start pushing///////////////
stack | -1| 0 | 4 |
    bottom       top        

stack | -1| 0 | 4 | 5 | 6 |
    bottom                top        
    
Still a[6] > a[7]      (10 > 1)    

/////////////////Start poping///////////////////////
popped 6.   Area = a[6]x1 = 10x1 = 10
stack | -1| 0 | 4 | 5 |
    bottom          top        

Still a[5] > a[7]    (6 > 1)

popped 5.   Area = a[5]x2 = 6x2 = 12
stack | -1| 0 | 4 |
    bottom      top        

Still a[4] > a[7]    (2 > 1)

popped 5.   Area = a[5]x3 = 2x3 = 6
stack | -1| 0 |
    bottom   top        
```
- *5.* Keep updatating maxArea variable
### Complexity
- **Time:** O(n). How O(n)?
  - Let's suppose `a[]=2,3,4,5,6,1`. for() reached last element O(n)
  - Start popping stack `stack=2 3 4 5 6(top)`. This is O(n). These are not nested. Hence O(n)+O(n) = O(n)
- **Space** O(n). Stack size
### Code
```c++
class Solution {
public:
  int largestRectangleArea(vector<int>& A) {
    stack<int> stIndex;
    stIndex.push(-1);   //Marking stack bottom
    int size = A.size();
    int maxArea = 0;

    for (int i=0; i<A.size(); ++i){
      while (stIndex.top() != -1 and A[stIndex.top()] >= A[i]){
        int currentHeight = A[stIndex.top()];
        stIndex.pop();
        int currentWidth = i - stIndex.top() - 1;
        maxArea = std::max(currentHeight*currentWidth, maxArea);
      }
      stIndex.push(i);
    }

    //Still few entries left on stack
    while(stIndex.top() != -1) {
      int currentHeight = A[stIndex.top()];
      stIndex.pop();
      int currentWidth = A.size() - stIndex.top() - 1;
      maxArea = std::max(currentHeight*currentWidth, maxArea);
    }
    return maxArea;        
  }
};
```
