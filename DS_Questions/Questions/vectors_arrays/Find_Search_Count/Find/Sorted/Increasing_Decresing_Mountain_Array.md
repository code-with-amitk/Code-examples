**Peak Index in a Mountain Array**
- [Approach-1. Linear. O(n)](#a1)
- [Approach-2. Binary Search. O(logn)](#a2)
  - [Logic](#l)
  - Code
    - [Python](#py)
    - [CPP](#cpp)
    - [Rust](#rs)

### [852. Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)
- An array arr a mountain if the following properties hold:
```c
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
```
- You must solve it in O(log(arr.length)) time complexity.
```c
Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1
```

<a name=a1></a>
### Approach-1. Linear. Time:O(n)
```py
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        for i in range(0, len(arr)-1):
            if arr[i+1] < arr[i]:
                return i
        return -1
```

<a name=a2></a>
### Approach-2. Binary Search. Time: O(logn)
<a name=l></a>
#### Logic
- Search for a element whose next element and prev element both are smaller than element.
```c
1 2 3 4 5 6 3 2 1 0
        | | |
```
#### Code
<a name=py></a>
**Python**
```py
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        return self.binarysearch (arr, 0, len(arr))
    
    def binarysearch(self, arr: List[int], left:int, right:int) -> int:
        """
        Use mid = left + (right - left) // 2 to calculate the middle index.
        This is the recommended way because it prevents potential integer
        overflow when dealing with large values of left and right.
        """
        #mid = (left + right)//2
        mid = left + (right-left)//2

        if arr[mid+1] < arr[mid] and arr[mid-1] < arr[mid]:
            return mid
        elif arr[mid+1] > arr[mid]:
            return self.binarysearch (arr, mid+1, right)
        else:
            return self.binarysearch (arr, left, mid-1)

```
