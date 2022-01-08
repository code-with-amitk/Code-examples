First Bad Version
- [Logic](#l)
- [Complexity](#c)
- Code
  - [CPP](#cpp)
  - [Rust](#r)
  - [Python](#p)
  - [Java](#j)

## [First Bad Version](https://leetcode.com/problems/first-bad-version/)
- You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad
- Suppose you have n versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.
- You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.Examples
```c
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
```

<a name=l></a>
### Logic(Binary Search)
if mid is bad and (mid-1) is good then mid is the item which we are searching for.
<a name=c></a>
### Complexity
  - Time: O(logn) //Binary Search
  - Space: [O(1)](/DS_Questions)
### Code
<a name=cpp></a>
#### CPP
```c
///////////Binary Search using recursion///////////
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

/////////Binary Search with while loop//////////
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
<a name=r></a>
#### Rust
```rs
impl Solution {
    pub fn bs (&self, start:u32, end:u32) -> i32 {
        if end == 1 {
            return end as i32;
        }
        let mid = (start+end)/2;
        let mut val:i32 = 0;
        
        if  self.isBadVersion(mid as i32) == false {  //Good
            if self.isBadVersion(mid as i32+1) == true {   //Bad
                val = mid as i32+1;
            }
            else{
                return Solution::bs(self, mid+1,end);
            }
        }
        else{   //Bad
            if self.isBadVersion(mid as i32-1) == false {   //Good
                val = mid as i32;
            }else{
                return Solution::bs(self, start,mid-1);
            }
        }
        val
    }
    pub fn first_bad_version(&self, n: i32) -> i32 {
		Solution::bs (self, 1, n as u32)
    }
}
```
<a name=p></a>
#### Python
```py
class Solution(object):
    def bs(self, start, end):
        if end == 1:
            return end;
        mid = (start+end)/2;
        val=0;
        
        if isBadVersion(mid) == False:  #Good
            if isBadVersion(mid+1) == True:
                val = mid+1;
            else:
                return self.bs(mid+1,end);
        else:
            if isBadVersion(mid-1) == False:   #Good
                val = mid;
            else:
                return self.bs(start,mid-1);            
        return val;
        
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.bs (1, n);
```
<a name=j></a>
#### Java
```java
public class Solution extends VersionControl {
    public int bs(long start, long end){
        if (end==1)
            return (int)end;
        long mid = (start+end)/2;
        int val=0;
        
        if (isBadVersion((int)mid) == false){  //Good
            if(isBadVersion((int)mid+1) == true) {   //Bad
                val = (int)mid+1;
            }
            else{
                return bs(mid+1,end);
            }
        }
        else{   //Bad
            if(isBadVersion((int)mid-1) == false) {   //Good
                val = (int)mid;
            }else{
                return bs(start,mid-1);
            }
        }
        return val;
    }
    public int firstBadVersion(int n) {
        return bs(1,n);
    }
}
```
