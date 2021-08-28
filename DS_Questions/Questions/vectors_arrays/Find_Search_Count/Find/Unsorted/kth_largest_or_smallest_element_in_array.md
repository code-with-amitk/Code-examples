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
3rd=k largest element = 10        //20,15,10
3rd=k largest element = (n - k + 1) smallest element
  n = 6, k = 3, n-k+1 = 4
  4th smallest element = 10     //3,4,7,10

Input = {7, 10, 4, 3, 20, 15}, k = 4
4th largest = 3rd smallest = 7      //3,4,7,10,15,20
```
We will find k smallest element.
- Quick Select is similar to QuickSort. The difference is, instead of recurring for both sides(after finding pivot), it recurs only for the part that contains the kth smallest element, This reduces the expected complexity from O(n log n) to O(n).

<a name=l3></a>
#### Logic
```c
{7, 10, 4, 3, 20, 15}, k = 3          //Step-1. Choose pivot same as Quick sort
 |
 pivot

  if (index_of_partitioned > k)
    recur in left
  else if (index_of_partitioned < k)
    recur in right
  else
    Found kth smallest element
    return
```

<a name=cpp3></a>
#### Code
```cpp
class Solution {
using vec = vector<int>;   

//Standard partition process of QuickSort(). It considers the last element as pivot
//and moves all smaller element to left of it and greater elements to right
int partition(vec& arr, int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}    
              //arr, left, right, k
int kthSmallest(vec& arr, int l, int r, int k) {

    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1) {

        // Partition the array around last element and get position of pivot element in sorted array
        int index = partition(arr, l, r);

        // If position is same as k
        if (index - l == k - 1)
            return arr[index];

        // If position is more, recur for left subarray
        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);

        // Else recur for right subarray
        return kthSmallest(arr, index + 1, r,
                            k - index + l - 1);
    }

    // If k is more than number of elements in array
    return INT_MAX;
}    
public:
    int findKthLargest(vector<int>& a, int k) {
    //4,3,7,10,15,20. 3rd Largest = 4th smallest = 10
    //3rd largest = n - 3 + 1 smallest
    //            = 6 - 3 + 1 = 4th smallest
        return  kthSmallest(a, 0, a.size() - 1, a.size()-k+1);
    }
};

int main() {
    vector<int> a = {7, 10, 4, 3, 20, 15};
    cout << findKthLargest (a, 3);    //10
}
```
