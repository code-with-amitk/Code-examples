**Minimum Deletions to Make Character Frequencies Unique**
- [Approach-1. Delete Duplicates from unordered_set. O(26`*`m)](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)


### 1647. Minimum Deletions to Make Character Frequencies Unique
- A string s is called good if there are no two different characters in s that have the same frequency.
- Given a string s, return the minimum number of characters you need to delete to make s good.
- The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
```c
Example 1:
Input: s = "aab"
Output: 0
Explanation: s is already good.

Example 2:
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

Example 3:
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
```

<a name=a1></a>
### Approach-1. Delete Duplicates from unordered_set. O(26`*`m)
<a name=l></a>
#### Logic
1. Count frequency of characters using unordered_map
```c
input = "abbccdddeeffffggg"
unodered_map<char,int>
    |a,1|b,2|c,2|d,3|e,2|f,4|g,3|
```
2. Insert frequencies into `unordered_set<int>`, decrement the freq by 1 everytime until freq becomes=0 or unique in set.
```c
  if (freq is already present in set){
    decrement freq by 1 then check again
    keep on decrementing until freq=0
    donot insert 0 into set   //0 means we have removed the element
  }
  
unordered_set<int> us;
  freq=1. insert    |1|
  freq=2. insert    |1,2|                   Steps
  freq=2. 
      freq=2 is already present. --2           
      freq=1. 1 already present. --1          1
      freq=0. Donot insert 0                  2
  freq=3. insert    |1,2,3|
  freq=2. insert    |1,2,3|
      freq=2 is already present. --2           
      freq=1. 1 already present. --1          3
      freq=0. Donot insert 0                  4
..
```
<a name=com></a>
#### Complexity
- **Time:** O(26`*`m). m: number of times each character is present in array
  - O(n): Counting elements using unordered_map
  - O(26`*`m): if 26 letters are present and each happened m times
```c
  aaaabbbbcccc ..
  m,m,m,m....26 times
```
- **Space:** O(m+26)
  - O(26): 26 characters occured m times. unordered_map
  - O(m): unordered_set containing m,m-1,m-2..1
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
    unordered_map<char,int> um;
public:
    int minDeletions(string s) {
        // Count number os occurences of word
        for(auto i:s)
            um[i]++;

        int count = 0;
        // Get count into unordered_set<int>
        unordered_set<int> usSeenFrequency;
        for(auto i:um){
            // if element not found in seen sSeenFrequency
            auto it = usSeenFrequency.find(i.second);
            if (it == usSeenFrequency.end())
                usSeenFrequency.insert(i.second);
            else {
                // if freq is already present in set
                // decrement and insert, until you does not find
                // matching freq
                int val = i.second;
                while (it !=usSeenFrequency.end()) {
                    ++count;
                    it = usSeenFrequency.find(--val);
                }
                if (val)
                    usSeenFrequency.insert(val);
            }
        }
        return count;
    }
};
```
