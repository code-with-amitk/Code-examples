**Group Anagrams**
- [Approach-1. Sort+hashmap. O(nmlogm)](#a1)

### [Group Anagram](https://leetcode.com/problems/group-anagrams/)
- Given an array of strings strs, group the anagrams together. You can return the answer in any order.
```c
Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

<a name=a1></a>
### Approach-1. Sort+hashmap
#### Logic
- _1._ copy input strs vector and sort it.
```c
vecS sorted = strs
sort(sorted) 

["eat","tea","tan","ate","nat","bat"]
["aet","aet","ant","aet","ant","abt"]
```
- _2._ Create `hashmap <key=element_from_sorted, value=vector<input_array>>`
```c
| key   value          |                 |            |
| aet, <eat, tea, ate> | ant, <tan, nat> | abt, <bat> |
|                      |                 |            |

out = all values from map
```

#### Complexity
> n: number of words, m: length of each word
- **Time:** O(nmlog(m))
  - O(nmlog(m)): sort
  - O(n): Traverse and create hashmap
- **Space:** 2O(mn)
  - O(mn): Create sorted
  - O(mn): hashmap

#### Code
```cpp
using vecS = vector<string>;
using vecVecS = vector<vector<string>>;

class Solution {
public:
    vecVecS groupAnagrams(vecS& strs) {
        vecVecS out;

        //Sort the incoming string vector
        vecS sorted = strs;
        for (auto&i:sorted){
            sort(i.begin(), i.end());
//            std::cout << i << ", ";
        }

        unordered_map<string, vecS> um;
        for (int i=0;i<sorted.size();++i){
            auto it = um.find(sorted[i]);
            vecS temp;
            if (it == um.end()) {
                temp.push_back(strs[i]);
                um[sorted[i]] = temp;
            }
            else {
                it->second.push_back(strs[i]);
            }
        }

        //Created vecVecS from map above
        for (auto [i,j]:um){
           out.push_back(j);
        }
        return out;
        
    }
};
```
