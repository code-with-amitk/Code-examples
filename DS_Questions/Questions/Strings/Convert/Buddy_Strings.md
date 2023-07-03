**Buddy Strings**
- Approach-1. Iterate
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)

### Buddy Strings
- Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
- Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at `s[i] and s[j]`.
- For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
```c
Example 1:
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Example 2:
Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

Example 3:
Input: s = "aaaa", goal = "aaaa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aaaa", which is equal to goal.

Example 4:
Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Example 5:
Input: s = "abab", goal = "abab"
Output: true
Explanation: The only letters you can swap are s[0] = 'a' and s[2] = 'a', which results in s == goal.

Example 6:
Input: s = "a", goal = "a"
Output: false
Explanation: no swaps

Example 7:
Input: s = "abcdef", goal = "aecdbf"
Output: true
Explanation: swap s[1] and s[4] to make s==goal
```

### Approach-1. Iterate
<a name=l></a>
### Logic
- _1._ Note all conditions in question
```c
False conditions:
  a. len(s) != len(goal)
  b. len(s) < 2
```
- _2._ if len(s) == len(goal)
```c
True conditions
  - All characters of s are same(swap any 2 characters).  //Example-3
  - if 2 or more characters same. swap 2 chars            //Example-5
```
<a name=com></a>
#### Complexity
- **Time:** O(n)
- **Space:** O(n). Hashmap created

#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        bool bFirstdiff = false, bSecdiff = false;
        int iFirstDiff=0, iSecDiff=0;

        if (s.size() != goal.size() || s.size()<2)
            return false;
        if (s==goal) {
            unordered_map<char,int> um;
            for(auto&i:s)
                um[i]++;
            if (um.size() == 1)
                return true;
            for (auto&i:um) {
                if (i.second >= 2)
                    return true;
            }
            return false;
        }

        // if s.size() == goal.size(). Iterate s and goal, find 1st and 2nd difference
        for (int i=0;i<s.size(); ++i){
            if (s[i] != goal[i]){
                if (!bFirstdiff) {
                    iFirstDiff = i;
                    bFirstdiff = true;
                }
                else if (!bSecdiff) {
                    iSecDiff = i;
                    bSecdiff = true;
                }
            }
        }
        if (iFirstDiff == iSecDiff)
            return false;
        swap (s[iFirstDiff], s[iSecDiff]);
        if (s == goal)
            return true;
        return false;
    }
};
```
