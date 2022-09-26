**License Key Formatting**
- [Approach-1. Read characters & recreate](#a1)

### [License Key Formatting](https://leetcode.com/problems/license-key-formatting)
- You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
- We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
- Return the reformatted license key.
- Example 1:
```c
Input: s = "5F3Z-2e-9-w", k = 4
Output: "5F3Z-2E9W"
Explanation: The string s has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
```

<a name=a1></a>
### Approach-1. Read characters & recreate
```cpp
using String = std::string;
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        String out, arr;
        int count = 0;
        
        //1. Parse characters out of string and note length
        //s = "5F3Z-2e-9-w", arr = "5F3Z2e9w"
        for (char &c:s){
            if (c=='-')
                continue;
            arr.push_back(c);
        }
        count = arr.size();

        int rem = count%k, quo = count/k, i=0;
        bool bRem = false;
        
        //2. Prefix number of characters which cannot be divided equally
        while(rem) {
            bRem = true;
            out += std::toupper(arr[i++]);
            rem--;
        }
        if (bRem)
            out.push_back('-');

        //3. Place characters which and "-"
        int temp = quo, temp1;
        while (quo){
            temp1 = k;
            while(temp1) {
                out += std::toupper(arr[i++]);
                temp1--;
            }
            out.push_back('-');
            quo--;
        }
        
        //4. if last character is -, remove it
        if (out.back() == '-')
            out.pop_back();
        return out;   
    }
};
```

### Complexity
- **Time:** O(n)
- **Space:** O(n)
