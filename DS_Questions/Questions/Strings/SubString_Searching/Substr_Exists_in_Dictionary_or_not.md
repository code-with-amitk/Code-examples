- **Software geeks says: I LOVE PROBLEMS and this is AWESOME**

## [Word Break](https://leetcode.com/problems/word-break/)
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

## 1. Approach-1   //Recursion. O(2<sup>n</sup>)
- **Logic**
  - *1.* Take Dictionary into a unordered_set for searching in O(1) time.
  - *2.* Find each letter and substring in dictionary recursively.
- **Complexity**
  - **Time:** [Recursion: O(2<sup>n</sup>)](/DS_Questions/README.md) 
  - **Space:** O(n) //n: Length of input string
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

## 2. Approach-2    //Dynamic Programming
- **Logic**
  - Notice some subproblems are solved again and again (Eg: t, et, e, s) etc.
  - We will create bool dp array of size=n+1 after solving these subproblems.
    - Each element of boolean DP Array will represent, whether substring to that index is present in Dictionary or not. if present `dp[]=1` else `dp[]=0`.
    - We will return last element of dp array, if complete string is present in Dictionary last element would be 1 else 0.
  - At each step, we partition substring into 2 substrings, if `dp[prev]=1` means substring is present in Dictionary.    
```c
input = test
dp[]  = 0 0 0 0 0   //size=input+1
        0 1 2 3 4
        
dp[0] = 0   //means "" substring is always present in wordDict.        
```
- **Complexity**
  - **Time:** O(n<sup>2</sup>)
  - **Space:** O(n)
- **Code**
```c++
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size());
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] and Dict.find(s.substr(j, i - j)) != Dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }  
```
