- **Software geeks says: I LOVE PROBLEMS and this is AWESOME**

**Word Break**
- [Approach-1. DFS(using Recursion). O(2<sup>n</sup>). TLE](#a1)
  - [Logic](#l)
- [Approach-2. DFS(with storage) = Dynamic Programming](#a2)
  - [Logic](#l1)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
    - [Rust](#rs)
    - [Python](#py)

### [139. Word Break](https://leetcode.com/problems/word-break/)
- Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
- The same word in the dictionary may be reused multiple times in the segmentation. Dictionary does not contain duplicate words.
- **Examples**
```c
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
```

<a name=a1></a>
### Approach-1. DFS(using Recursion). O(2<sup>n</sup>). TLE
<a name=l></a>
#### DFS Logic
```c
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
```
- _1._ Take all substrings, and whenever a substring is found in dictionary, start creating new substring and finding in dictionary.
```c
    c,ca,cats | cats | catsa, catsand, catsando, catsandog(not found)
              |      |
    ----------       -------------------------------------
    |                                                    |
    s,sa,san,sand | sando, sandog(not found)            a,an,and | ando, andog(not found)
                  |                                              |
    --------------                                               -----
    |                                                                 |
    o,og(not found)                                                   o,og(not found)
```

  - *1.* Take Dictionary into a unordered_set for searching in O(1) time.
  - *2.* Find each letter and substring in dictionary recursively.
- **Complexity**
  - **Time:** [Recursion: O(2<sup>n</sup>)](/DS_Questions/README.md) 
  - **Space:** O(n) //n: Length of input string
    - O(n): unordered_set
    - O(n): recursion stack
#### Code
**CPP**
```cpp
class Solution {
    unordered_set<string> us;
    string str;
public:
    bool dfs (int start) {
        //Base case
        if (start == str.size())
            return true;

        for (int i=start+1; i<=str.size(); ++i) {
            // Create substrings (c,ca,cat..)
            string substr = str.substr(start, i-start);

            // Find substring in dictionary
            // if substring is found        && further all substring can be found in dictionary
            if (us.find(substr) != us.end() && dfs (i))
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto&i:wordDict)
            us.insert(i);
        str = s;
        return dfs (0);
    }
};
```

<a name=a2></a>
### Approach-2. DFS(with storage) = Dynamic Programming
<a name=l1></a>
#### Logic
- We will just store results of [Approach-1's logic](#l)
- Notice some subproblems are solved again and again (Eg: o, og) etc.
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
<a name=com></a>
#### Complexity
- **Time:** O(n<sup>2</sup>)
- **Space:** O(n)

#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());

        // dp[i]=true means till this index, substring is present in dictionary
        vector<bool> dp(s.size(), false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
	  // For all substrings str="test"
          for (int j = 0; j < i; j++) {

            // if substring till index=j is present in dictionary
            // then only we will search further substrings
            if (dp[j] == true) {
              //substrings = test, est, st, t
              string substr = s.substr(j, i-j);
              if (us.find(substr) != us.end()) {
                // if substr is found, update found at index=j
    		dp[i] = true;
    		break;
              }
            }
          }
        }
        return dp[s.size()];
    }
};
```
<a name=rs></a>
**Rust**
```rs
use std::collections::HashSet;
//use substring::Substring;
impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let mut hs:HashSet<String> = HashSet::new();
        for word in word_dict {
            hs.insert(word);
        }

        let mut dp:Vec<bool> = vec![false; s.len()+1];
        dp[0] = true;

        for i in 1..=s.len() {
            for j in 0..i {
                if dp[j] == true {
                    //let substr = s.substring(j, i-j);
                    let substr = &s[j..i];
                    if let Some(value) = hs.get(substr) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        dp[s.len()]
    }
}
```
<a name=py></a>
**Python**
```py
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        hs = set()
        for i in range(0,len(wordDict)):
            hs.add(wordDict[i])
        dp = [False] * (len(s) + 1)
        dp[0] = True

        for i in range(0, len(s)+1):
            for j in range(0,i):
                if dp[j]:
                    substr = s[j:i]
                    if substr in hs:
                        dp[i] = True
                        break
        return dp[-1]
```
