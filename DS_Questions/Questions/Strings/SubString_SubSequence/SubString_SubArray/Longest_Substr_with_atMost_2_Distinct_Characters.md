**Longest Substring with At Most Two Distinct Characters**

### Longest Substring with At Most Two Distinct Characters
- Given a string s, return the length of the longest substring that contains at most 2 distinct characters.
```c
Example1
Input: s = "eceba"
Output: 3
All Substring: ec, ece, eceb, ce, ceb, ceba, eb, eba, e, c, e, b, a
Substrings with 2 distinct characters:
ec, ece, ce, eb, ba

Example 2:
Input: s = "ccaabbb"
Output: 5
Substrings with 2 distinct characters:
cca, caa, ccaa, aab, aabb, abbb, aabbb
```

### Approach-1, Hashmap O(n<sup>2</sup>)
#### [Self Video](https://youtu.be/Zs-_FwdeZwA)
#### Logic
- _1._ Take a `hashmap<char, count>` which stores count of characters.
- _2._ if sizeof(hashmap)>2 calculate total count & update maxi variable

#### Code
```cpp
class Solution {
    std::unordered_map<char,int> um;
    int maxi;
    void fun(){
        int count = 0;
        for (auto&i:um)
            count += i.second;
        maxi = std::max(maxi, count);
        um.clear();
    }
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        maxi=1;
        int size = s.size();
        bool bExit = false;
        for (int i=0;i<size;++i){
            for (int j=i;j<size;++j){
                if (j==size-1)
                    bExit=true;
                auto it = um.find(s[j]);
                if (it == um.end()) {
                    um[s[j]]++;
                    if (um.size()>2){
                        um.erase(um.find(s[j]));
                        fun();
                        break;
                    }
                    if(bExit)
                        fun();
                }else{
                    um[s[j]] = ++it->second;
                    if (bExit)
                        fun();
                }
            }
            if (bExit)
                break;
        }
        return maxi;        
    }
};
```
#### Complexity
- **Time:** O(n<sup>2</sup>)
- **Space:** O(n) 
