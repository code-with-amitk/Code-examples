**Find K Pairs with Smallest Sums**
- [Approach-1. 2 for loops. minHeap. O(n<sup>2</sup>) TLE](#a1)
  - Code
    - [CPP](#cpp)
- [Approach-2. Only look till sum is smaller than stored](#a2)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp1)


### [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)
- you are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
- Define a pair (u, v) which consists of one element from the first array and one element from the second array.
- Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
```c
Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
```

<a name=a1></a>
### Approach-1. 2 for loops. minHeap. O(n<sup>2</sup>) TLE
#### Logic
- minHeap, take all pairs with sum. `<key=sum, value<i,j>>`
#### Complexity
- **Time:** O(n<sup>2</sup>)
#### Code
<a name=cpp></a>
**CPP**
```cpp
using vvI = vector<vector<int>>;
using vI = vector<int>;
using mpair = pair<int, pair<int,int>>;
class Solution {
public:
    vvI kSmallestPairs(vI& nums1, vI& nums2, int k) {
        vvI out;
        priority_queue<mpair, vector<mpair>, greater<mpair>> pq;
        for (auto&i:nums1) {
            for (auto&j:nums2) {
                pq.push({i+j, {i,j}});
            }
        }
        int smaller = pq.size()<k ? pq.size() : k;
        for (int i=0; i<smaller;i++) {
            vI temp;
            mpair m = pq.top(); pq.pop();
            temp.push_back(m.second.first);
            temp.push_back(m.second.second);
            out.push_back(temp);
        }
        return out;
    }
};
```

<a name=a2></a>
### Approach-2. Only look till sum is smaller than stored
<a name=com></a>
#### Complexity
- **Time complexity:** O(mn/k)
- **Space complexity:** O(k)
#### Code
<a name=cpp1></a>
**CPP**
```cpp
// Declare type alias
using vvI = std::vector<std::vector<int>>;
using vI = std::vector<int>;

class Solution {
public:
    vvI kSmallestPairs(vI& nums1, vI& nums2, int k) {
                           //sum    no1, no2
        priority_queue<pair<int,pair<int,int>>> pq;

        for (auto&i:nums1) {
            for (auto&j:nums2) {

                int sum = i+j;

                // Only store k elements in pq
                if (pq.size() < k) {
                    pq.push ({sum, {i,j}});
                }
                else if (sum < pq.top().first) {
                    // if sum of elements < top element.
                    // Remove top and place this element
                    pq.pop();
                    pq.push ({sum, {i,j}});
                }
                else {
                    // if (present sum > top of pq)
                    // break, because after these eleemnts we cannot find 
                    // sum < top of pq
                    break; 
                }
              }
          }

          vvI ans;

        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }      
        return ans;
    }
};
```
