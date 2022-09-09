**Reorder Data in Log Files**
- [Approach-1, Sort with Comparator](#a1)

### [Self Video](https://youtu.be/wjb466ecTJA)

### Reorder Data in Log Files
- Array representing logs is given, format: `identifier log`. There are two types of logs in array:
  - _1. Letter-logs_: All words (except the identifier) consist of lowercase English letters.
  - _2. Digit-logs_: All words (except the identifier) consist of digits.
- Reorder these logs so that:
  - The letter-logs come before all digit-logs.
  - The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
  - The digit-logs maintain their relative ordering.
- Return the final order of the logs.
- Example
```c
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Explanation:   1st is always identifier
Letter logs:
  Identifier=Key  Log=Value
    let1          art can
    let2          own kit dig
    let3          art zero
    
Digit Logs:
  Identifier=Key  Log=Value
    dig1          8 1 5 1
    dig2          3 6

Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
  - Letter logs will come 1st, sorted as per value(ie log)
    - if 2 values(ie log) in letterLog are same, these are sorted based on key
  - Digit logs are copied in same order as they appear
```

<a name=a1></a>
### Approach, sort with Comparator
#### Logic
- _1._ Store digitLogs into vector and letterLogs into `vector<pair<key, value>>` seperately.
  - Reach 1st whitespace, if 2nd word is not Alphabet or digit, if digit store in digitLog else in letterLog
- _2._ sort using custom c++ sort
#### Code
**CPP**
```cpp
using vecS = std::vector<std::string>;
using String = std::string;

class Solution {
public:
    vecS reorderLogFiles(vecS& logs) {
        vecS out, digitLogs;
                            //identifier,log
        std::vector<std::pair<String, String>> letterLogs;
        String identifier;

        //Create seperate vector for letter & digit logs
        for (String& s:logs){
            int i=0;

            //Reach 1st space, ie b/w word1 & word2
            while (s[i] != ' ') ++i;

            //if 2nd word is not alphabet, it should be digit insert in digitLogs
            //else insert in letterLogs
            if (!std::isalpha(s[i+1]))
                digitLogs.push_back(s);
            else
                letterLogs.emplace_back(s.substr(0,i), s.substr(i+1));
        }

        //Sort letterLogs using Comparator
        //if 2ndLog.second < 1stLog.second   //good
        //if 2ndLog.second == 1stLog.second &&
        //      2ndLog.first < 1stLog.first //good
        std::sort(letterLogs.begin(), letterLogs.end(), [&](auto&i,auto&j){
           if (i.second < j.second)
                return true;
           if (i.second >  j.second)
                return false;
           if (i.second == j.second && i.first < j.first)
                    return true;
        });

        for (auto&i:letterLogs)
            out.push_back(i.first + " " + i.second);
        for (auto&i:digitLogs)
            out.push_back(i);
        return out;
    }
};
```

#### Complexity
- **Time:** O(nlogn)=Sort
- **Space:** O(2n) = O(n) Taken 2 vectors
