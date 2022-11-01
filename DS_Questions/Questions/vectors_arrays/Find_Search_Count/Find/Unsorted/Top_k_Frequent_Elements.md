**Top K frequent elements**
- [Approach-1, (unordered_map(O(n)) + maxHeap(O(nlogn)) => O(nlogn)](#a1)
- [Approach-2, (unordered_map(O(n)) + Bucket sort(O(n)) => O(n)](#a2)

### [Self Video, Both Approaches](https://youtu.be/LWCU01gFTIs)

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
### Approach-1, map and maxHeap, O(nlogn)
#### Logic
- _1._ Count frequency of elements using unordered_map
```c
nums = [1,1,1,2,2,3], map= {key=element, value=count}
      |             |             |             |
map = |ele=1,count=3|ele=2,count=2|ele=3,count=1|
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

<a name=a2></a>
### Approach-2, unordered_map + Bucket sort, O(n)
#### Logic
- _1._ Take `unordered_map` and count the frequency of numbers.
```c
nums.size()=10
nums = [1,10,12,10,15,1,3,6,50,60], map= {key=element, value=count}
      |             |              |              |              |             |             |              |              |
map = |ele=1,count=2|ele=10,count=2|ele=12,count=1|ele=15,count=1|ele=3,count=1|ele=6,count=1|ele=50,count=1|ele=60,count=1|
      |             |              |              |              |             |             |              |              |
```
- _2._ Take a bucket(2d vector) of size=nums.size()+1. For 10 elements take bucket of size=11.
```c
|   |   |   |   |   |   |   |   |   |   |   |
  0   1   2   3   4   5   6   7   8   9   10
bucket=2d vector
```
- _3._ Insert `vec[count].push_back(ele)`
```c
|   |   |1  |   |   |   |   |   |   |   |   |     //count=index=2. Insert ele=1
  0   1   2   3   4   5   6   7   8   9   10

|   |    |1,10  |   |   |   |   |   |   |   |   |     //count=index=2. Insert ele=10
  0   1   2   3   4   5   6   7   8   9   10

|   |  12  |1,10  |   |   |   |   |   |   |   |   |     //count=index=1. Insert ele=12
  0   1      2     3   4   5   6   7   8   9   10

|   |  12,15  |1,10  |   |   |   |   |   |   |   |   |     //count=index=1. Insert ele=15
  0   1         2      3   4   5   6   7   8   9   10
  
|   |   12,15,3  |1,10  |   |   |   |   |   |   |   |   |     //count=index=1. Insert ele=3
  0   1           2      3   4   5   6   7   8   9   10
  
|   |  12,15,3,6  |1,10  |   |   |   |   |   |   |   |   |     //count=index=1. Insert ele=6
  0   1             2      3   4   5   6   7   8   9   10
  
|   |  12,15,3,6,50  |1,10  |   |   |   |   |   |   |   |   |     //count=index=1. Insert ele=50
  0   1                2      3   4   5   6   7   8   9   10
  
|   |  12,15,3,6,50,60  |1,10 |   |   |   |   |   |   |   |   |     //count=index=1. Insert ele=60
  0   1                   2     3   4   5   6   7   8   9   10

//This shows:
12,15,3,6,50,60 occurs 1 time
1,10 occurs 2 times
```
- _4._ Now traverse bucket from back, pop elements, once elements popped == k return.
```c
|   |  12,15,3,6,50,60  |10   |   |   |   |   |   |   |   |   |     //pop 1. out=|1|
  0   1                   2     3   4   5   6   7   8   9   10

|   |  12,15,3,6,50,60  |     |   |   |   |   |   |   |   |   |     //pop 10. out=|1,10|
  0   1                   2     3   4   5   6   7   8   9   10
out.size()==2. return
```
#### Code
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> out;
        
        //1. Store count in unordered_map
                    //key=num, value=count
        unordered_map<int, int> um;
        for (auto&i:nums)
            um[i]++;
     
        //2. Create bucket, where count is index and value is element
        vector<vector<int>> bucket(nums.size()+1);
        for (auto&i:um){
            bucket[i.second].push_back(i.first);    
        }
        
        //3. Traverse bucket from back and return once k elements are found 
        int count=0;
        for (int i=bucket.size()-1; i>=0; --i){
            while (bucket[i].size()){
                out.push_back(bucket[i].back());
                bucket[i].pop_back();
                count++;
            }
            if (count==k)
                break;
        }
        return out;
    }
};
```
#### Complexity
- **Time:** 
  - O(n): Insertion into unordered_map
  - O(m): m<n. Creation of bucket
  - O(n): Iterate bucket from end to generate output
- **Space:**
  - O(n): for unordered_map
  - O(n): 
