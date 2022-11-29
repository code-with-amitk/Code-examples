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
|MaxHere(//a)| 0 (0-2<0) | 1=0+1 | 0 (1-3<0) | 4=0+4 | 3=4-1 | 5=3+2 | 6=5+1 | 1=6-5 | 5=4+1 |
|MaxSoFar(//b)| 0 | 1 | 1 | 4 | 4 | 5 | 6 | 6 | 6 |

#### Code
```cpp
class Solution {
public:
  int maxSubArray(vector<int>& a) {
    int maxSoFar = INT_MIN
    int maxHere = 0; 
  
    for (int i = 0; i < a.size(); i++) { 
        maxHere = maxHere + a[i]; 
        maxSoFar = std::max(maxHere, maxSoFar);   //b
        if (maxHere < 0) 
            maxHere = 0;                        //a
    } 
    return maxSoFar;         
  }
};
```
