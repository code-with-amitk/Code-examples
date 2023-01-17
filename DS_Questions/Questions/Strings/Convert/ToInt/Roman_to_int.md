**Roman to Integer**
- Approach-1
  - [Logic](#l)
  - [Complexity](#co)
  - Code
    - [CPP](#cpp)
    - [C](#c)

### [13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/)
- Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
```c
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```
- For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
- Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
- I can be placed before V (5) and X (10) to make 4 and 9. 
- X can be placed before L (50) and C (100) to make 40 and 90. 
- C can be placed before D (500) and M (1000) to make 400 and 900.
- Given a roman numeral, convert it to an integer.
```c
Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

<a name=a1></a>
### Approach-1
<a name=l></a>
#### Logic
- Store symbol and its int equivalent in hashmap
- Traverse string from left to right.
  - if (nextChar > presentChar) output += (nextCharIntValue - presentCharIntValue)
  - else output += presentCharIntValue
<a name=co></a>
#### Complexity
- **Time:** O(n)
- **Space:** O(1). Everytime allocating only hashmap
#### Code
**CPP**
```cpp
class Solution {
    unordered_map<char, int> umValue;
public:
    void storePlaceValue() {
        umValue['I'] = 1;
        umValue['V'] = 5;
        umValue['X'] = 10;
        umValue['L'] = 50;
        umValue['C'] = 100;
        umValue['D'] = 500;
        umValue['M'] = 1000;
    }
    int romanToInt(string s) {
        storePlaceValue();
        int iNumber = 0;
        for (int i =0; i<s.size(); ++i) {
            int myPlaceValue = umValue.find(s[i])->second;
            int nextNoPlaceValue = 0;
            if (i<s.size()-1)
                nextNoPlaceValue = umValue.find(s[i+1])->second;
            if (myPlaceValue < nextNoPlaceValue) {
                iNumber += nextNoPlaceValue-myPlaceValue;
                ++i;
            } else
                iNumber += myPlaceValue;
        }
        return iNumber;
    }
};
```
<a name=c></a>
**C**
