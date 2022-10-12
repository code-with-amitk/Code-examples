**Top K frequent elements**
- [Approach-1, map and maxHeap](#a1)

### [Top K frequent elements](https://leetcode.com/problems/top-k-frequent-elements/)
- Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
```c
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
```

<a name=a1></a>
### Approach-1, map and maxHeap
#### Logic
- _1._ Count frequency of elements using unordered_map
```c
nums = [1,1,1,2,2,3], map= {key=element, value=count}
      |             |             |             |
map = |key=1,value=3|key=2,value=2|key=3,value=1|
      |             |             |             |
```
- _2._ Store pair in maxHeap as `<count,key>`
```c
maxHeap |3,1|
        /   \
     |2,2|  |1,3|   
```
- _3._ Perform k pop operations on maxHeap and store in `vector out`

#### Code
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1. Store count in unordered_map
                    //key=num, value=count
        unordered_map<int, int> um;
        for (auto&i:nums)
            um[i]++;
        
        //2. Store pair into MaxHeap
        //pair: first=count, second=value
        priority_queue<pair<int,int>> pq;
        for (auto&i:um)
            pq.push({i.second,i.first});

        //3. Pop top k elements
        vector<int> out;
        for (int i=0;i<k;++i){
            pair<int,int> p = pq.top();   pq.pop();
            out.push_back(p.second);
        }
        return out;
    }
};
```
#### Complexity
- **Time:** O(nlogn) + O(nlogn). 
  - O(n): storing in map
  - O(nlogn): Storing in maxHeap, this will involve balancing/rotation of heap=O(logn). if all n elements need to rebalanced the nlogn.
  - O(nlogn): Removing from maxHeap.
- **Space:** 2O(n) = O(n)
