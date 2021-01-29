**What are Alphanumeric characters?**
- Only Alphabets(a-z, A-Z) and numerals(0-9).

## [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
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

## 1. Approach-1    //Reverse and compare. Time:O(n), Space:O(n)
- **Logic**
  - *1.* Create a new string(called strFiltered) containing only alphanumeric character downcasted to lower case.
  - *2.* store reverse of strFiltered into strReversed
  - *3.* if (strFiltered == strReversed)  return true
- **Complexity**
  - **Time:** O(n)
    - O(n): Creating new string
    - O(n): Reversing new string
    - O(n): Compare
  - **Space:** O(2n) = O(n)
    - Storing 2 new strings of size n
```c++
    bool isPalindrome(string s) {
        string strFiltered, strReversed;
        for (auto ch:s)
            if (isalnum(ch))
                strFiltered += tolower(ch);
        strReversed = strFiltered;
        reverse(strReversed.begin(), strReversed.end());
        if (strFiltered==strReversed)
            return true;
        else
            return false;
    }
```

## 2. Approach-2    //2 Pointer. Time:O(n).Space: O(1)
- **Logic**
  - *1.* Take 2 pointers pointing to start and end, start=0 and end=input.size()-1
  - *2.* if character at start is not alphanumeric
    - increment start
  - *3.* if character at end is not alphanumeric
    - decrement end
  - *4.* Compare start and end.
    - if not equal return false
    - else ++start, --end
- **Complexity**
  - **Time:** O(n)
  - **Space:** [Constant space O(1)](https://github.com/amitkumar50/Code-examples/tree/master/DS_Questions)
- **Logic**
```c++
    bool isPalindrome(string s) {
        int end = s.size()-1;
        int start = 0;

        while (start<end){
            while(start < end and not isalnum(s.at(start)))
              ++start;
            while(start < end and not isalnum(s.at(end)))
              --end;

            if(tolower(s.at(start)) not_eq tolower(s.at(end)))
                return false;
            else{
              ++start;
              --end;
            }
        }
        return true;
    }
```
