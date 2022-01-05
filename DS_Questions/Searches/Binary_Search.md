Binary Search
- Code
  - [C++ Recursive](#cpp1)
  - [C++ Iterative](#cpp2)
  - [Rust](#r)
  - [Python](#p)


### Code
<a name=cpp1></a>
#### C++ Recursive
```cpp
class Solution {
public:
    int bs(vector<int>& nums, int target, int start, int end) {
        if (start==end && nums[start]==target)
            return start;
        if (start >= end)
            return -1;
        
        int val = -1;
        int mid = (start+end)/2;                          //OR start + (end-start)/2;
        if (nums[mid] == target)
            return mid;
        
        if (nums[mid] > target) 
            val = bs(nums, target, start, mid-1);
        else
            val = bs(nums, target, mid+1, end);
        
        return val;
    }
    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size()-1);
    }
};
```
<a name=cpp2></a>
#### C++ Iterative
```cpp
class Solution {
public:
    int bs(vector<int>& nums, int target, int start, int end) {
        if (start==end && nums[start]==target)
            return start;
        if (start >= end)
            return -1;

        while (start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] == target)
                return mid;
            
            if (nums[mid] < target) 
                start = mid + 1;
            else
                end = mid - 1;   
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size()-1);
    }
};
```
<a name=r></a>
#### Rust
```rs

```
