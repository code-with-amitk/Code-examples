### [Maximum Subarray LC](https://leetcode.com/problems/maximum-subarray/)
- Find the contiguous subarray within an array, A which has the largest sum.
- Examples
```c++
Input 1:    A = [1, 2, 3, 4, -10]
Output 1:    10   //The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Input 2: A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output 2:  6    //SubArray [4,-1,2,1] has the maximum possible sum of 6.
```

### [Self Video](https://youtu.be/zXB9SQ5kqJA)

### Logic Kadane's Algo
- Only consider +ve subarrays in array. Do not consider -ve.
- Use 2 variables:
  - MaxHere: Maximum upto this array entry
  - MaxSoFar: 
- Example
```c++
Input array: -2, 1, -3, 4, -1, 2, 1, -5, 4
        
If (MaxHere+array_element < 0)
  MaxHere = 0
```

MaxHere = 0, MaxSoFar = 0
        
|| -2 | 1 | -3 | 4 | -1 | 2 | 1 | -5 | 4 |
|---|---|---|---|---|---|---|---|---|---|
|int MaxHere| 0 if(MaxHere+array_element<0) MaxHere=0 | 1=0+1 | 0 (1-3=-2. Take 0 when sum<0) | 4=0+4 | 3=4-1 | 5=3+2 | 6=5+1 | 1=6-5 | 5=4+1 |
|int MaxSoFar| 0 | 1 | 1 | 4 | 4 | 5 | 6 | 6 | 6 |

### Code
```c
class Solution {
public:
  int maxSubArray(vector<int>& a) {
    int MaxSoFar = INT_MIN
    int MaxHere = 0; 
  
    for (int i = 0; i < a.size(); i++) { 
        MaxHere = MaxHere + a[i]; 
        if (MaxSoFar < MaxHere) 
            MaxSoFar = MaxHere; 
  
        if (MaxHere < 0) 
            MaxHere = 0; 
    } 
    return MaxSoFar;         
  }
};
```
