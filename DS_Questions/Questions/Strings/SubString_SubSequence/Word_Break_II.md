**Word Break II**
- [Approach-1, Naive. Greater than O(n<sup>n</sup>)](#a1)
- [Approach-2, Backtracking](#a2)

### Word Break II
- Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. 
- Return **all such possible sentences** in any order.
- Note that the same word in the dictionary may be reused multiple times in the segmentation.
```c
Example 1:
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Example 2:
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "abcdefg", wordDict = ["a", "bc", "d", "ef", "de", "f", "fg", "ab", "abc", "g", "c" , "cd"]
Output = ["a bc d ef g", "ab c d ef g", ...]
```

<a name=a1></a>
### Approach-1, BF (Greater than O(n<sup>n</sup>))
#### Logic
- _1._ Take substring from 1st character and search in dict.
```c
Input: s = "abcdefg", wordDict = ["a", "bc", "d", "ef", "de", "f", "fg", "ab", "abc", "g", "c" , "cd"]
substr = a  //Found in dict
```
- _2._ Search next letter in dict ie b
```c
substr = b  //Found in dict
```
- _3._ As soon all letters are found, Create substring of 2 characters and continue step-2(ie searching)
```c
substring = ab
```
#### Complexity
- **Time:** O(n<sup>n</sup>) n=words.

<a name=a2></a>
### Approach-2, Plain Backtrack
### [Self Video]()
- [Good Video](https://www.youtube.com/watch?v=fNVs1J2KCyo)
#### Logic
- _1._ Insert wordDict into set for O(1) search
```c
input = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
```
- _2._ Take substrings from input word, as soon as a word is found in dictionary
  - Note the position
  - Recursively search for next words in dictionary
- _3._ While falling back from recursive function check
```c
        f(pine)

      f(applepenapple)
  
    f(penapple)
      found=pen
      
      pena    //when fallback from recursive call search these
      penap
      penapp
      
  f(apple)
```
#### Code
```cpp
using vecS = std::vector<std::string>;
using String = std::string;
using UM = std::unordered_map<char, int>;
using US = std::unordered_set<String>;

class Solution {
    US dict;
    vecS val;
    
    void bt(String s, String st, int pos) {
        //Base case
        if (pos == s.size()) {
            val.push_back(st);
            return;
        }

        for (int i=pos;i<s.size();++i){
            //Candidate
            String word = s.substr(pos,i+1-pos);

            if (dict.find(word) != dict.end())
                bt(s, st+" "+word, i+1);        //Backtrack

            //Remove Candidate
            //Automatically done using pos
        }
    }
public:
    vecS wordBreak(string s, vecS& wordDict) {
        //Place Dict into set
        for (auto&i:wordDict)
            dict.insert(i);

        for (int i=0;i<s.size();++i){
            String word = s.substr(0,i+1);
            if (dict.find(word) != dict.end())
                bt(s, word, i+1);
        }
        return val;
    }
};
```
#### Complexity
- **Time:** O(n^2)
- **Space:** O(n). Stacks get destroyed.
