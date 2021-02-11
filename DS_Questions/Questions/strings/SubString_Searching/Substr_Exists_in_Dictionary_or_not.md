- **Software geeks says: I LOVE PROBLEMS and this is AWESOME**

## [Word Break leetcode](https://leetcode.com/problems/word-break/)
- Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
- The same word in the dictionary may be reused multiple times in the segmentation. Dictionary does not contain duplicate words.
- **Examples**
```c
Input: s = "test", wordDict = ["t", "e", "st"]
Output: true    //because "havefun" can be segmented as "have fun".

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true    //"applepenapple" can be segmented as "apple pen apple".

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

Input: s = "aaaaaaa", wordDict = ["aaaa", "aaa"]
Output: true

Input: s = "abbc", wordDict = ["a","ab","bc"]
Output: true
```

## Understanding the problem
> s = "test", wordDict = `["t", "e", "st"]`
- *1.* We need to start matching every single character in dictionary
```c
                                  test
                              /   \     \           \
                    (true)t,est   te,st  tes,t    test
                            /     / \ /\    / \ 
                 (true)e,st(true) t e s t   t es
                         / \                / \
                        s   t              e   s

- Which ever branch returns true, that's solution.
This is reursive approach.
why recursion? Because we asking same question on smaller & smaller substrings.
```

## 1. Approach-1
- **Logic**
  - *1.* Take Dictionary into a unordered_set for searching in O(1) time.
  - *2.* Find each letter and substring in dictionary recursively.
- **Complexity**
  - **Time:** [Recursion: O(2<sup>n</sup>)](/DS_Questions/README.md) 
  - **Space:** O(n) //n: Number of words
    - O(n): unordered_set
    - O(n): recursion stack
- **Code**  
```c++
  bool Recursion(string& s, unordered_set<string>& Dict, int pos) {
    if(pos == s.size())
      return true;
        
    for (int i=pos+1; i<=s.size(); ++i){
      if(Dict.find(s.substr(pos, i-pos)) != Dict.end() and Recursion(s,Dict,i))
        return true;
    }
    return false;
  }
    
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> Dict(wordDict.begin(), wordDict.end());
    return Recursion(s, Dict, 0);
  }
```
