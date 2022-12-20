**Valid Palindrome**
- [Approach-1. 2 Pointers, One Pass. O(n)](#a1)
  - Code
    - [CPP](#cpp)
    - [Rust](#r)


### [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
**Alphanumeric characters?** Only Alphabets(a-z, A-Z) and numerals(0-9).
- Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
- Empty string as valid palindrome.
- Examples
```c
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false

Example 3:
Input: ".,"
Output: true

Example 4:
Input: "0P"
Output: false
```

<a name=a1></a>
### Approach-1. 2 Pointers, O(n). One Pass
#### Logic
- _1._ Take 2 pointers(front, back).
- _2._ if characeter is non-alphanumeric or space is found move front, back ptr to 1 position.
- _3._ if characters matches, ++front, --back.
#### Complexity
- **Time:** O(n)
- **Space:** O(1)

#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        // One Pass. Travese string from from front and back
        // if space, nonAlphanumeric character is found skip those
        int front = 0, back = s.size()-1;
        while (front < back) {
            //isalpha() checks whether character is alphabet or not
            if (!isalnum(s[front]) || s[front] == ' ')
                front++;   
            else if (!isalnum(s[back]) || s[back] == ' ')
                back--;
            else if (tolower(s[front]) == tolower(s[back])) {
                front++;
                back--;
            }
            else
                return false;
        }
        return true;
    }
};
```
<a name=r></a>
**Rust**
```rs

```
