## [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
- Examples
```c
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4 
```

### 1. Approach-1  //Sort  Time:O(nlogn)
- **Complexity**
  - **Time:** O(nlogn)
  - **Space:** O(1)
- **Code**   
```c++
int findKthLargest(vector<int>& nums, int k) {
  sort(nums.begin(),nums.end());
  return nums[nums.size()-k];
}   
```

### 2. Approach-2  //Max-Heap  Time:O(n), Space:O(n)
- **Logic**
  - *1.* Insert elements in maxHeap. Max element will be at top
  - *2.* Pop max Heap k times.
 - **Complexity**
   - **Time:** O(n)
   - **Space:** O(n)
- **Code**
```c++
int findKthLargest(vector<int>& nums, int k) {
  priority_queue<int> pq;
  int top = 0;
  for(auto i:nums)
    pq.push(i);

  while (k-->0){
    top = pq.top();
    pq.pop();
  }
  return top;
}
```
