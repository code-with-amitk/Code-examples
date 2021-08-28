**[Kth Largest Element in unsorted Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)**
- **Approach-1 / Sort / O(nlogn)**
  - [Complexity](#co1)
  - [Code](#cpp1)
- **Approach-2 / Max-heap / O(nlogn)**
  - [Logic](#l2)
  - [Complexity](#co2)
  - [Code](#cpp2)
- **Approach-3 / Quick Select / O(n)**
  - [Logic](#l3)
  - [Complexity](#co3)
  - [Code](#cpp3)

## Problem
Find the kth largest element in an unsorted array. Examples
```c
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4 
```

### Approach-1 / Sort
<a name=co1></a>
#### Complexity
- **Time:** O(nlogn)
- **Space:** O(1)
<a name=cpp1></a>
#### Code
```cpp
int findKthLargest(vector<int>& nums, int k) {
  sort (nums.begin(),nums.end());
  return nums[nums.size()-k];
}   
```

### Approach-2 / Max-Heap
<a name=l2></a>
#### Logic
- *1.* Insert elements in maxHeap. Max element will be at top
- *2.* Pop max Heap k times.
<a name=co2></a>
#### Complexity
- **Time:** [Rebalancing Max heap O(nlogn)]()
- **Space:** O(n)
<a name=cpp2></a>
#### Code
```cpp
int findKthLargest(vector<int>& nums, int k) {
  priority_queue<int> pq;
  int top = 0;
  for(auto i:nums)
    pq.push(i);

  while (k-- > 0){
    top = pq.top();
    pq.pop();
  }
  return top;
}
```

### Approach-3 / Quick-Select
<a name=qs></a>
#### Quick Select
Quick select Algo works same as [Quick Sort](/DS_Questions/Sorting) & is developed by Tony Hoore(inventor of Quick sort).
```c
Input = {7, 10, 4, 3, 20, 15}, k = 3
kth largest element = 10        //20,15,10
kth largest element = (n - k + 1) smallest element. 
  n = 6, k = 3, n-k+1 = 4
  4th smallest element = 10     //3,4,7,10

Input = {7, 10, 4, 3, 20, 15}, k = 4
4th largest = 3rd smallest = 7      //3,4,7,10,15,20
```
We will find k smallest element.
- Quick Select is similar to QuickSort. The difference is, instead of recurring for both sides(after finding pivot), it recurs only for the part that contains the k-th smallest element.

<a name=l3></a>
#### Logic
```c
- Choose pivot same as Quick sort

  if (index_of_partitioned > k)
    recur in left
  else if (index_of_partitioned < k)
    recur in right
  else
    Found kth smallest element
    return
```
