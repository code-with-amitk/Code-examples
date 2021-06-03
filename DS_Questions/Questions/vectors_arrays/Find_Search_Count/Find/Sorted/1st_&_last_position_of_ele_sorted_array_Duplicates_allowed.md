## [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- Given sorted array in ascending order, find the starting and ending position of a given target value.
- Duplicates are allowed. If target is not found in the array, return [-1, -1].
- Algorithm must take **O(log n) runtime complexity**.
- **Examples**
```c
Input: nums = [5,7,7,8,8,8,8,8,8,10], target = 8
               0 1 2 3 4 5 6 7 8 9
Output: [3,8]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

### Approach-1     //Binary + Linear search. O(mlogn)
```c
a = [5,7,7,8,8,8,8,8,8,10], target = 8
     0 1 2 3 4 5 6 7 8 9
```
- **Logic**
  - _1._ Find index of element using binary search. It will find index=4. O(logn)
  - _2._ Search linearly 1st and last index of element. O(m)
- **Complexity**
  - **Time:** O(mlogn)
  - **Space:** O(1)
- **Code**
```c++
class Solution {
  using vec = vector<int>;    
  int Find(vec& a, int index, bool isFirst){
    if (isFirst) {
      while (index > 0 && a[index] == a[index-1])
        --index;
    } else {
      while (index < a.size()-1 && a[index] == a[index+1])
        ++index;
    }
    return index;
  }

  int search(vec& a, int low, int high, int ele, bool isFirst){
    if (low > high)
      return -1;
    int mid = (low + high)/ 2;
    if (a[mid] == ele)
      return Find(a, mid, isFirst);
    else if (a[mid] > ele)
      return search(a, low, mid-1, ele, isFirst);
    else
      return search(a, mid+1, high, ele, isFirst);
    return -1;
  }    
  
public:
  vector<int> searchRange(vector<int>& a, int ele) {
    vec o;
    if(a.size() == 1 && a[0] == ele) {
      o.push_back(0);
      o.push_back(0);
    }else if (a.size() > 1){
      o.push_back(search(a, 0, a.size()-1, ele, true));
      o.push_back(Find(a, o[0], false));
    }else {
      o.push_back(-1);
      o.push_back(-1);
    }
    return o;        
  }
};
```

## Approach-2     //Modified Binary Search  O(logn)
