**Maximum Subarray**
- Approach, Kadane's Algo
  - [Logic](#l1)
  - Code
    - [CPP](#c1)


### [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
Find max subarray with largest sum. Subarrays are contigious.
```c
Ex-1
Input:    A = [1, 2, 3, 4, -10]
Output:   10   //The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Ex-2
Input:   A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output:  6    //SubArray [4,-1,2,1] has the maximum possible sum of 6.
```

### [Self Video](https://youtu.be/zXB9SQ5kqJA)

### Approach(Kadane's Algo)
<a name=l1></a>
#### Logic
- Only consider +ve subarrays in array. Do not consider -ve.
- Use 2 variables:
  - MaxHere: Maximum upto this array entry
  - MaxSoFar: 
```cpp
Input array: -2, 1, -3, 4, -1, 2, 1, -5, 4
  
MaxHere = 0, MaxSoFar = INT_MIN
if (MaxHere + array_element < 0)
  MaxHere = 0
else
  maxHere = maxHere + array_element
```
        
|element| -2 | 1 | -3 | 4 | -1 | 2 | 1 | -5 | 4 |
|---|---|---|---|---|---|---|---|---|---|
|MaxHere| 0 (0-2<0) | 1=0+1 | 0 (1-3<0) | 4=0+4 | 3=4-1 | 5=3+2 | 6=5+1 | 1=6-5 | 5=4+1 |
|MaxSoFar| 0 | 1 | 1 | 4 | 4 | 5 | 6 | 6 | 6 |

<a name=c1></a>
#### Code
```cpp
class Solution {
public:
  int maxSubArray(vector<int>& a) {
    int maxSoFar = INT_MIN
    int maxHere = 0; 
  
    for (int i = 0; i < a.size(); i++) { 
        maxHere = maxHere + a[i]; 
        maxSoFar = std::max(maxHere, maxSoFar);
        if (maxHere < 0) 
            maxHere = 0; 
    } 
    return maxSoFar;         
  }
};
```
