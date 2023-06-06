**Can Make Arithmetic Progression From Sequence**
- [Approach-1. sort O(nlogn)](#a1)
- [Approach-2. Without sort. Time:O(n),Space:O(n)](#a2)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

### Can Make Arithmetic Progression From Sequence
- A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
- Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
```c
Example 1:
Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
```

<a name=a1></a>
### Approach-1. sort O(nlogn)
#### Logic
- sort, and check is difference of consecutive elements same or not
```c
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() == 2)
          return true;
        
        sort(arr.begin(), arr.end());
        int diff = arr[0] - arr[1];
        for (auto i = arr.begin(); i != arr.end()-1; ++i) {
          auto next = i+1;
            if (*i-*next != diff)
              return false;
        }
        return true;
    }
};
```

<a name=a2></a>
### Approach-2. Without Sort. Time: O(n), Space:O(n)
#### Logic
- _1._ Iterate through array and:
  - _a._ Find min, max elements
  - _b._ Fill all elements in `unordered_set<int>`
```c
arr = [2,4,6,10,8]
min=2, max=10
```
- _2._ Calculate Difference of Arithematic Progression.
```c
diff = (max - min) / (size(arr) - 1)  = (10-2)/(5-1) = 8/4 = 2
// All elements differ from each other by 2
```
- _3._ if size of unordered_set == 1. It means all elements are same, its valid AP.
- _4._ Now traverse unordered_set. 
  - if (present_element < max)
    - Search (present_element+diff) in unordered_set. if not found not valid AP
  - if (present_element == max)
    - Search (present_element-diff) in unordered_set. if not found not valid AP
#### Code
**CPP**
```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
      if (arr.size() == 2)
        return true;

        unordered_set<int> us;
        // find min and max. Store elements in set
        int min = INT_MAX, max = INT_MIN;
        for (auto&i:arr) {
          min = i < min ? i : min;
          max = i > max ? i : max;
          us.insert(i);
        }

        // All elements are same
        if (us.size() == 1)
          return true;

        // This is the difference of AP
        int diff = (max - min) / (arr.size()-1);

        // Difference is not integer
        if (diff == 0)
          return false;

        // Iterate thru array and find element in set
        for (auto &i:arr) {
            int find = 0;
            // i+diff should be present in unordered_set
            if (i < max)
              find = i+diff;
            else    //Max element
              find = i-diff;
            
            if (us.find(find) == us.end())
              return false;

        }
        return true;
    }
};
```
