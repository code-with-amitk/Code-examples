**Valid Palindrome**
- [Approach-1. 2 Pointers, One Pass. O(n)](#a1)
  - Code
    - [CPP](#cpp)
    - [Rust](#r)
    - [Python3](#p)
    - [Java](#j)


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
impl Solution {
    pub fn is_palindrome(s: String) -> bool {

        // Convert string to lower case
        // if character is not alphanumeric, replace with ""
        let s = s.to_lowercase().replace(|c:char| !c.is_alphanumeric(), "").into_bytes();

        // if string becomes empty or its len=1, return true
        if s.is_empty() || s.len() == 1 {
            return true;
        }

        // 2 pointers. 
        // Front pointer=0, end pointer=last
        let mut front = 0;
        let mut end = s.len() - 1;

        loop {
            let fc = s.get(front).unwrap();
            let ec = s.get(end).unwrap();

            if fc == ec {
                front += 1;
                end -= 1;
            }
            else {
                return false;
            }
            if front > end {
                break;
            }
        }
        return true;
    }
}
```
<a name=p></a>
**Python**
```py
class Solution:
    def isPalindrome(self, s: str) -> bool:
        front = 0;
        end = len(s)-1;

        while front < end:
            if s[front] == ' ' or s[front].isalnum() == False:
                front += 1;
            elif s[end] == ' ' or s[end].isalnum() == False:
                end -= 1;
            elif s[front].lower() == s[end].lower():
                front += 1;
                end -= 1;
            else:
                return False;
        return True;
```

<a name=j></a>
**Java**
```java

```
