## [First Bad Version](https://leetcode.com/problems/first-bad-version/)
- You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad
- Suppose you have n versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.
- You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
- Examples
```c
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
```

## Approach //Binary Search
- **Logic**
  - *1.* if mid is bad and (mid-1) is good then mid is the item which we are searching for.
- **Complexity**
  - Time: O(logn) //Binary Search
  - Space: [O(1)](/DS_Questions)
- **1. Code(Binary Search using recursion)**
```c
int BinarySearch(long low, long high){
  int ret = -1;
  long mid = (low+high)/2;
        
  bool iCheck = isBadVersion(mid);
        
  if (iCheck && !isBadVersion(mid-1))
    return mid;
        
  if(!iCheck)     //Means mid is good
    ret = return BinarySearch(mid+1, high);
  else            //mid is Bad. But prev to mid is also bad
    ret = return BinarySearch(low,mid-1);
    
  return ret;
}
    
int firstBadVersion(int n) {
  return BinarySearch(1, n);
}
```
- **2. Code(Binary Search with while loop)**
```c
int firstBadVersion(int n) {
    int low = 1;
    int high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}    
```
