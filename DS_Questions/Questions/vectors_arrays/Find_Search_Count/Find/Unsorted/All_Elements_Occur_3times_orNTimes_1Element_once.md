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
- **Approach-4. Sort. Time:O(nlogn). Space:O(1)**
- **Approach-5, Using Bitwise Operators, Time:O(n), Space:O(1)**
  - [Logic](#l3)
  - [Complexity](#co3)
  - Code
    - [CPP98](#cpp5)
    - [CPP11](#cpp11)
    - [Python](#py)

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

#### Code
<a name=cpp5></a>
**CPP98**
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int size = 33;
        std::vector<int> bitarray(size, 0);

        // Find bits in 32 bit integer
        // nums = {6,6,6,3}
        // bitarray = {0,4,1,3,0,0,0,0,..}
        for (const auto&num : nums) {
            int k = abs(num);
            
            uint64_t j = 0, a = 1;
            while (j++ < size) {
                int val = k & a;
                if (val)
                    bitarray[j]++;
                a <<= 1;
            }
        }
      
        // bitarray%3
        for (auto&i : bitarray)
            i %= 3;

        // Find number
        uint64_t u64Out = 0;
        for (int i=1;i<size;++i) {
            if (bitarray[i])
                u64Out += pow(2, i-1);
        }

        ////////Handling -ve Number {1,1,-2,1}/////////
        //We have taken abs of all numbers before. {1,1,-2,1} => {1,1,2,1}
        //With above logic answer=2.
        //Check back again in input array, that 2 exists? if not answer=-2
        int count = 0;
        for (auto num:nums) {
            if (num == u64Out)
                count++;
        }
        return count==1 ? u64Out : -u64Out;
    }
};
```
<a name=cpp11></a>
**CPP11**
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int size = 33;
        std::vector<int> bitarray(size, 0);

        // Find bits in 32-bit integer
		// lambda function
		// for_each (InputIterator start_iter, InputIterator last_iter, Function fnc)
		// Lambda captures the bitarray vector and size variable by reference (&) from env
        std::for_each(nums.begin(), nums.end(), [&bitarray, size](const auto& num) {
            const int k = std::abs(num);
            uint64_t j = 0, a = 1;
            while (j++ < size) {
                const int val = k & a;
                if (val)
                    bitarray[j]++;
                a <<= 1;
            }
        });

        // bitarray % 3
        for (auto& i : bitarray)
            i %= 3;

        // Find number
        uint64_t u64Out = 0;
        for (int i = 1; i < size; ++i) {
            if (bitarray[i])
                u64Out += std::pow(2, i - 1);
        }

        // // Handling negative numbers
        return std::count(nums.begin(), nums.end(), u64Out)==1 ? u64Out : -u64Out;
    }
};
```
<a name=py></a>
**Python**
```py
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        size = 33
        bitarray = [0] * size

        # Find bits in a 32-bit integer
        for num in nums:
            k = abs(num)
            j = 0
            a = 1
            while j < size:
                if k&a:
                    bitarray[j] += 1
                a <<= 1
                j += 1

        # bitarray % 3
        for i in range(len(bitarray)):
            bitarray[i] %= 3

        # Find number
        u64Out = 0
        for i in range(1, size):
            if bitarray[i]:
                u64Out += 2 ** (i - 1)

        # Handling negative numbers {1,1,-2,1}
        # We have taken the absolute value of all numbers before: {1,1,2,1}
        # With the above logic, the answer would be 2
        # Check back again in the input array if 2 exists, if not, answer = -2
        count = 0
        for num in nums:
            if num == u64Out:
                count += 1

        return u64Out if count == 1 else -u64Out
```
