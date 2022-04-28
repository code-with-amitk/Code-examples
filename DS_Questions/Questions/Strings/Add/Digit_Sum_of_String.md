**Calculate Digit Sum of a String**
- **Approach-1**
  - [Logic](#l)
  - **Code**
    - [CPP](#c1)
  - [Complexity](#co)

### [Calculate Digit Sum of a String](https://leetcode.com/problems/calculate-digit-sum-of-a-string/)
- You are given a string s consisting of digits and an integer k.
- A round can be completed if the length of s is greater than k. In one round, do the following:
- Divide s into consecutive groups of size k such that the first k characters are in the first group, the next k characters are in the second group, and so on. Note that the size of the last group can be smaller than k.
- Replace each group of s with a string representing the sum of all its digits. For example, "346" is replaced with "13" because 3 + 4 + 6 = 13.
- Merge consecutive groups together to form a new string. If the length of the string is greater than k, repeat from step 1.
- Return s after all rounds have been completed.
```c
Example 1:

Input: s = "11111222223", k = 3
Output: "135"
Explanation: 
- For the first round, we divide s into groups of size 3: "111", "112", "222", and "23".
  ​​​​​Then we calculate the digit sum of each group: 1 + 1 + 1 = 3, 1 + 1 + 2 = 4, 2 + 2 + 2 = 6, and 2 + 3 = 5. 
  So, s becomes "3" + "4" + "6" + "5" = "3465" after the first round.
- For the second round, we divide s into "346" and "5".
  Then we calculate the digit sum of each group: 3 + 4 + 6 = 13, 5 = 5. 
  So, s becomes "13" + "5" = "135" after second round. 
Now, s.length <= k, so we return "135" as the answer.
```

### Approach-1
<a name=l></a>
#### Logic
- Take k characters at a time from string
  - Calculate sum after converting to int
  - Convert back to string, push_back into a temporary string
- Repeat above step for whole string and again.

#### Code
<a name=c1></a>
**CPP**
```cpp
class Solution {
    string sum(string& s, int k){
        int k1 = k;
        int size = s.size();
        while (s.size() > k) {
            int i = 0;
            string temp;
            while (i < s.size()) {
            
                //Group of k characters
                int val=0, no=0;
                
                //Calculating sum of k characters
                while (i<k){
                    if (i == s.size())
                        break;
                    val = (int)s[i++] - 48;
                    no += val;
                }
                
                //Convert back to string and push to temporary string
                stringstream ss;
                ss << no;
                temp += ss.str();
                ss.clear();
                k += k1;
            }
            s = temp;
            temp.clear();
        }
        return s;
    }
public:
    string digitSum(string s, int k) {
        string s1 = s;
        while (s1.size() > k) {
            s1 = sum (s, k);
        }
        return s1;
    }
};
```

<a name=co></a>
#### Complexity
- **Time:** O(n) + O(n/k) + O(n/2k) ..
  - O(n) string traversed at 1st pass. Let n=100, k=3
  - Now string size=100/3=33. Next time need to traverse O(n/k)
  - Then string size=33/3=11. Next time need to traverse O(n/2k)..
- **Space:** O(n) + O(n/k) + O(n/2k) ..
  - Intially for string size=n, we need temporary string of O(n/k)
  - For string size=n/k, we need temporary string of O(n/2k)
