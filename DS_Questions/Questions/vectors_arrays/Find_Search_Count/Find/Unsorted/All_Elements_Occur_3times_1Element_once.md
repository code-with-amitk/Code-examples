**All elements appears thrice and one element appears once**
- **Approach-1, unordered_map, Count Frequency. Time:O(n), Space:O(m)**
  - [Logic](#l1)
  - [Complexity](#co1)
  - [Code](#c1)
- **Approach-2, unordered_set, Time:O(n), Space:O(m)**
  - [Logic](#l2)
  - [Complexity](#co2)
  - [Code](#c2)
- **Approach-3, Using Bitwise Operators, Time:O(n), Space:O(1)**
  - [Logic](#l3)
  - [Complexity](#co3)
  - [Code](#c3)

## [Single Number II / All elements appears thrice and one element appears once](https://leetcode.com/problems/single-number-ii/)
- Given an integer array where every element appears 3 times except for one, which appears exactly once. Find the single element and return it.
- In Time:O(n), Space:O(1). Example
```c
Input: nums = [1,2,3,1,2,1,2]
Output: 3
```

### Approach-1, unordered_map. Count Frequency
<a name=l1></a>
#### Logic
- Create a unordered_map containing element and their count and return key having smallest value(will always be 1).
```c
nums = [1,2,3,1,2,1,2]
unordered_map
  key count
  1   3
  2   3
  3   1
```
<a name=co1></a>
#### Complexity
- **Time:** Greater than O(n). Depends on complexity of comparator function.
- **Space:** O(m). m=Unique keys. m=n/3
<a name=c1></a>
#### Code
```cpp
class Solution {
public:
  static bool comp(pair<int,int> i, pair<int, int> j){
    return i.second < j.second;
  }
    
  int singleNumber(vector<int>& nums) {
                 //key, count
    unordered_map<int, int> um;
    for (auto i:nums)
      um[i]++;
        
    //Find key with count=1
    unordered_map<int,int>::iterator it;
    it = min_element(um.begin(), um.end(),comp);
    return it->first;
  }
};
```

### Approach-2, unordered_set
<a name=l2></a>
#### Logic
- _1._ Create unordered_set containing unique elements. Also calculate actual sum while traversing array
```c
nums = [1,2,3,1,2,1,2].   unordered_set ={1,2,3}.   Actual sum=3a + 3b + c
a=1, b=2, c=3
```
- _2._ Answer
```c
3*unique_element_sum - Actual_sum
3(a+b+c) - (3a+3b+c)  = 2c
```
<a name=co2></a>
#### Complexity
- **Time:** O(n)
- **Space:** O(m). m=number of unique elements. m=n/3
<a name=c2></a>
#### Code
```cpp
class Solution {
public:    
  int singleNumber(vector<int>& nums) {
    unordered_set<int> us;
    uint64_t u64ActualSum = 0, u64UniqueSum = 0;
        
    for (auto i:nums){
      u64ActualSum += i;
      if (!us.count(i))
        us.insert(i);
    }
        
    //Unique elements sum
    for (auto i:us)
      u64UniqueSum += i;
        
    return (3*u64UniqueSum - u64ActualSum)/2;
  }
};
```

### Approach-3, Using Bitwise Operators
<a name=l3></a>
#### Logic
```c

```
