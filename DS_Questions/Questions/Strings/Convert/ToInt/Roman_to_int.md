**Roman to Integer**
- [Approach-1, Left to Right. O(n)](#a1)
  - [Logic](#l)
  - [Complexity](#co)
  - Code
    - [CPP](#cpp)
    - [C](#c)
- [Approach-2, Right to left. O(n)](#a2)
  - [Logic](#l2)
  - [Complexity](#co2)
  - Code
    - [CPP](#cpp2)
    - [Rust](#r)

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
### Approach-1,Left to Right. O(n)
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
```c
char cArr[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int iArr[7] = {1,5,10,50,100,500,1000};
int GetValue(char c) {
    int i=0;
    while (c != cArr[i]) {
        ++i;
    }
    return iArr[i];
}
int romanToInt(char * s){
    int iNumber = 0, i = 0;
    while (s[i] != '\0') {
        int presentIndexValue = GetValue(s[i]);
        int nextIndexValue = 0;
        if (s[i+1] != '\0')
            nextIndexValue = GetValue(s[i+1]);
        if (presentIndexValue < nextIndexValue) {
            iNumber += (nextIndexValue-presentIndexValue);
            ++i;
        } else
            iNumber += presentIndexValue;
        ++i;
    }
    return iNumber;
}
```

<a name=a2></a>
### Approach-2, Right to Left. O(n)
<a name=l2></a>
#### Logic
- Store char and corresponding value in HashMap.
- Traverse from right to left.
- if (presentValue < prevValue)
  - out -= presentValue  
- else
  - out += presentValue
<a name=co2></a>
#### Complexity
- **Time:** O(n)
- **Space:** O(1). Everytime same hashmap is allocated
#### Code
<a name=cpp2></a>
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
        int iSum = 0, iprevValue = 0;
        for (int i=s.size()-1; i>=0; --i) {
            int iPresentValue = umValue.find(s[i])->second;
            iPresentValue < iprevValue ?
            iSum -= iPresentValue :
            iSum += iPresentValue;
            
            iprevValue = iPresentValue;
        }
        return iSum;
    }
};
```
**Rust**
```rs
use std::collections::HashMap;
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut hm = HashMap::new();
        hm.insert('I', 1);
        hm.insert('V', 5);
        hm.insert('X', 10);
        hm.insert('L', 50);
        hm.insert('C', 100);
        hm.insert('D', 500);
        hm.insert('M', 1000);

        let mut prev_value = 0;
        let mut sum = 0;

        /// Traverse from back, reverse iterate
        for i in s.chars().rev() {
            /// get() return Option<&value>
            if let Some(present_value) = hm.get(&i) {
                if *present_value < prev_value {
                    sum -= *present_value;
                } else {
                    sum += *present_value;
                }
                prev_value = *present_value;
            } else {
                /// Bad case, Will never happen
                break;
            }
        }
        sum
    }
}
```
**Java**
```java
class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> hash_map = new HashMap<Character, Integer>();
        hash_map.put('I', 1);
        hash_map.put('V', 5);
        hash_map.put('X', 10);
        hash_map.put('L', 50);
        hash_map.put('C', 100);
        hash_map.put('D', 500);
        hash_map.put('M', 1000);

        int prev_value = 0, sum = 0;
        // Reverse iterate String
        for (int i=s.length()-1; i>=0; --i) {
            int present_value = hash_map.get(s.charAt(i));
            if (present_value < prev_value)
                sum -= present_value;
            else
                sum += present_value;
            prev_value = present_value;
        }
        return sum;
    }
}
```
<a name=p></a>
**Python**
```py
```
