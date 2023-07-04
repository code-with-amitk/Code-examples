**All elements appears thrice(or n times) and one element appears once**
- **Approach-1, unordered_map, Count Frequency. Time:O(n), Space:O(m)**
  - [Logic](#l1)
  - [Complexity](#co1)
  - [Code](#c1)
- **Approach-2, unordered_set, Time:O(n), Space:O(m)**
  - [Logic](#l2)
  - [Complexity](#co2)
  - [Code](#c2)
- **Approach-3. minHeap. Time:O(n). Space:O(n)**
- **APproach-4. Sort. Time:O(nlogn). Space:O(1)**
- **Approach-5, Using Bitwise Operators, Time:O(n), Space:O(1)**
  - [Logic](#l3)
  - [Complexity](#co3)
  - [Code](#c3)

## [Single Number II / All elements appears 3 times(or n times) and 1 element appears once](https://leetcode.com/problems/single-number-ii/)
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
- _1._ Sum all the bits in same positions for all the elements in `int bitset[32]`
```c
input = {6, 6, 6, 3}   

6 -> 00000000 00000000 00000000 00000 110
6 -> 00000000 00000000 00000000 00000 110
6 -> 00000000 00000000 00000000 00000 110
3 -> 00000000 00000000 00000000 00000 011
  ________________________________________+
        0       0         0     00000 341
```
- _2._ Take modulus by 3. We can mod by n which means elements repeating n times.
```c
0mod3 3mod3  4mod3 1mod3
_________________________
0       0     1     1         =>   3  appearing once.
```
<a name=co3></a>
#### Complexity
- **Time** O(n)
- **Space:** O(1). We are taking bitset of size 32 all times.
<a name=c3></a>
#### Code Logic
- _1._ Check every bit of every number present in incoming vector.
```
input = {3,4}
j = 1;
for (int i=0;i<32; ++i){    //For 32 bits
  int sum = 0;
  for (int j=0; j<input.size(); ++j) {
    sum = j<<1 | number
  }
}
```
- _2._ Calculate mod
- _3._ Then check for -ve numbers as well.

**Code**
```cpp
int fun(vector<int>& v) {
  uint64_t iOut = 0;
  
  //For calculating all bits in 32 bit integer
  for (int i = 0; i < 32 ;i++) {
    int iTempSum = 0;
    
    //Going thru every 
    for(int j=0; j < v.size(); j++) {
      int k = abs(v[j]);
      iTempSum += ( k& (1<<i) ) !=0 ? 1 : 0;  
    } 
    iTempSum %= 3; 
    iOut += pow(2,i) * iTempSum;
  }//for
  
  ////////Handling -ve Number/////////
  //Case-1 {1,1,-2,1} => {1,1,2,1}
  //Case-2 {1,1,2,2,2,1,-2} => {1,1,2,2,2,1,2}
  //We have taken abs of all numbers before. 
  //With above logic answer=2 for Case-1, Case-2 both
  //Check back again in input array, that 2 exists? if not answer=-2
  int count = 0;
  for (auto i:v) {
    if (i == iOut)
      count++;
  }
  return count==1 ? iOut : -iOut;
}  
```
