**Note**: Google wants ***OPTIMAL SOLUTION***, but you should be aware about all possible solutions.

## [Problem](https://leetcode.com/explore/featured/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3414/)
- Find duplicates in array in O(n) time & O(1) space complexity
- `1 ≤ a[i] ≤ n` (n = size of array).


### Example:
```
Input: [4,3,2,7,8,2,3,1]
Output: [2,3]
```

### Approach-1(Array storing count of elements)

**Original Array**
| elements-> | 4 | 3 | 2 | 7 | 8 | 2 | 3 | 1 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Indexes-> | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |

**Count Array**
| elements-> | 0 | 1 | 2 | 2 | 1 | 0 | 0 | 1 | |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Indexes-> | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |


### Approach-2(unordered_set) Space:O(n)
- Take a hash table & a output vector.
- Insert into:
  - HashTable: if element is not present earlier in hashMap.
  - Output Vector: if element exists in hashtable(it means its duplicate).
- Complexity:
  - Space: O(n) - noOfDuplicates
  - Time: O(1)
  
```
    vector<int> findDuplicates(vector<int>& nums) {
      unordered_set<int> us;
      vector<int> v;

      for(auto i:nums){
        if(us.find(i) != us.end())
          v.push_back(i);
        else
          us.insert(i);
      }
      return v;
    }
```

### Approach-2 Time:O(n), Space:O(1)
- In order to understand it, let's consider how 
