**Permutation in String**
- [Approach-1. Find all permutations. Store in `vector<string>`. Compare. O(mn).TLE](#a1)
- [Approach-2. Store s1 in `multiset<char>` and compare. TLE](#a2)
- [Approach-3. Compare Frequencies using Sliding Window](#a3)
  - [Logic](#l)
  - [Complexity](#co)
  - Code
    - [CPP](#cpp)

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

<a name=a3></a>
### Approach-3. Compare Frequencies using Sliding Window
<a name=l></a>
#### Logic
```c
s1 = abc
s2 = bbbca
```
1. Find freq of all characters in s1.
```c
a,1   b,1   c,1
```
2. Then we will be starting with a window of size 1 initially in s2. That means start=0, end=0.
3. Get frequency of the characters in the current window.
```c
b b b c a
|   |
freq = b,3
```
4. Increase the frequency of the character which is just now newly included inside the window
- Now check if the frequency of the characters in the current window, is same as the frequency of characters int s1. But this is only possible if the length of current substring(window) is same as the length of s1. If this is true, then we can directly return true from here.
```c
b b b c a
  |   |
freq = b,2   c,1

b b b c a
    |   |
freq = b,1   c,1   a,1    //match
```
<a name=co></a>
#### Complexity
- **Time:** O(m) + O(n).
  - m: Characters in s1
  - n: Characters in s2
- **Space:** O(m + n)
#### Code
<a name=cpp></a>
**CPP**
https://leetcode.com/problems/permutation-in-string/solutions/1762469/c-sliding-window-optimized-well-explained/
```cpp
class Solution {
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> freqS1(26, 0);
        for(char c: s1) freqS1[c-'a']++;
        
        vector<int> freqS2(26, 0);
        int i=0, j=0;
        
        while(j<s2.size()){
            freqS2[s2[j]-'a']++;
            
            if(j-i+1==s1.size()){
                if(areVectorsEqual(freqS1, freqS2)) return true;
            }
            
            if(j-i+1<s1.size()) j++;
            else{
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};
```
