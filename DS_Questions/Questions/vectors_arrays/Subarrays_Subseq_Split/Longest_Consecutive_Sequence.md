- Question
- Approach-1, Brute Force
  - [Logic](#logic1)
  - [Complexity](#complexity1)
  - [Code](#code1)

## [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence)
- Given an unsorted array of integers, return the length of the longest consecutive elements sequence.
- Elements in the subsequence are consecutive integers, the consecutive numbers can be in any order(ie does not need to be ascending or decending).
- Examples
```c
Input: nums = {1, 9, 3, 10, 4, 20, 2}
Output: 4   //The subsequence 1, 3, 4, 2 is the longest.

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Input: nums = [-100, 9, 7, 5, 8, 6, 100]
Output: 6       //5,6,7,8,9
```

### Approach-1, Brute Force
<a name=logic1></a>
#### Logic
- _1._ Take every element and search element+1 in entire array. 
- _2._ Search element+1 in entire array, if found search again ele+1 in entire array, keep count of present_longest_con_seq.
- _3._ Update longest_con_seq with larger value from present_lon_con_seq and longest_con_seq
```c
{1, 9, 3, 10, 4, 20, 2}
                                                  present_Longest_Con_Seq   longest_con_seq
i=0 ele+1 = 2. Search 2 in array. Found 2. O(n)        2                                       //1
    ele+1 = 3. Search 3 in array. Found 3.             3
    ele+1 = 4. Search 4 in array. Found 4.             4
    ele+1 = 5. Search 5 in array. Not Found            4                         4

i=1 ele+1 = 10. Search 10 in array. Found 10. O(n)     2
    ele+1 = 11. Search 11 in array. Not Found.         2                         4

i=2..
```

<a name=complexity1></a>
#### Complexity
- Time: O(n<sup>3</sup>)
- Space: O(1)

<a name=code1></a>
#### Code
```c
using vec = vector<int>;
class Solution {
  bool find_nums_plus_1(vec& v, int j) {
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == j)
        return true;
    }
    return false;
  }
public:
  int longestConsecutive(vec& v) {
    int long_cons_seq = 0;

    for (auto i : v) {
      int curr = i;
      int long_present_seq = 1;

      while (find_nums_plus_1(v, curr + 1)) {               //1
        curr += 1;
        long_present_seq += 1;
      }

      long_cons_seq = max(long_cons_seq, long_present_seq); //3
    }

    return long_cons_seq;
  }
};
```
