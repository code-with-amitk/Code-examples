**Permutation in String**
- [Approach-1. Find all permutations. Store in `vector<string>`. Compare. O(mn).TLE](#a1)
- [Approach-2. Store s1 in `multiset<char>` and compare. TLE](#a2)

### [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)
- Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
- In other words, return true if one of s1's permutations is the substring of s2.
```c
Example 1:
Input: s1 = "abc", s2 = "eidbaadocdaooo"
Output: true

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

<a name=a1></a>
### Approach-1
- Find all permutations. Store in `vector<string>`.
```c
All permutations of "abc"
abc   bca   cab
acb   bac   cba
```

<a name=a2></a>
### Approach-2. TLE
- Store s1 in `multiset<char>` (Since duplicate chars can be present)

<a name=com></a>
#### Complexity
**Time**
- O(n.mlog(m)).
  - m: Number of chars in s1. Since multiset is balanced BT. searching = mlog(m)
  - n: Number of chars in s2

#### Code
```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        multiset<char> us;
        for (char&i:s1)
            us.insert(i);
        
        for (int i=0;i<s2.size();++i){
            auto it = us.find(s2[i]);
            if (it != us.end()){
                if(check(us, s2, i))
                    return true;
            }
        }
        return false;
    }
    bool check (multiset<char> us, string s2, int i){
        while (i < s2.size()){ 
            auto it = us.find(s2[i]);
            if (it != us.end()){
                us.erase(it);
                if (us.size() == 0)
                    return true;
            }
            else{
                return false;
            }
            ++i;
        }
        return false;
    }
};
```
