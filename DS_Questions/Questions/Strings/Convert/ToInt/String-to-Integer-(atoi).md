## [Problem](https://leetcode.com/problems/string-to-integer-atoi/)
- Implement atoi which converts a string to an integer
- Examples
```c++
Example-1
Input: str = "42"
Output: 42

Example 2:
Input: str = "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign. Then take as many numerical digits as possible, which gets 42.

Example 3:
Input: str = "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:
Input: str = "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical digit or a +/- sign. Therefore no valid conversion could be performed.
```

## [Self Youtube Video](https://youtu.be/ao4t993rU5U)

### Logic
- Check conditions for return 0.
  - *1.* Skip all preceding whitespaces.
  - *2.* If string has only whitespaces. return 0
  - *3.* if string starts from character other than '+' or '-'
```c  
        //isdigit(char) returns
        //  true=1 when char is digit eg '4'
        //  false=0 when char is not digit eg 'a'
```
  - *4.* Create a temporary string containing '+' or '-' and all numerals
  - *5.* Convert string to double. Because double has 8 byte precision wrt 4 byte float. if converted string is not > INT_MAX or < INT_MIN
  - *6.* convert to int and return

### Code
```c++
#include<iostream>
#include<climits>
using namespace std;
class Solution {
public:
  int myAtoi(string s) {
        int i = 0;

        while (s[i] == ' ')   //1
          i++;

        if (i == s.length())  //2
          return 0;

        if ((s[i] not_eq '-') and   //3
            (s[i] not_eq '+') and
            (not isdigit(s[i])))
            return 0;
        //Fill 1st character into Temporary String
        string str;
        if (s[i] == '-'){         //4
          str = "-";
        }else{
          if (isdigit(s[i]))          //if 1st character is digit eg '4'
            str = ""+string(1,s[i]);    //string(size,char c)
          else
            str = "";
        }
        i++;

        //Fill all digits into string
        while (i < s.length() && isdigit(s[i])) {   //4
            str += string(1, s[i++]);
        }

        try{
            if (stod(str) > INT_MAX)    //5
              return INT_MAX;
            if (stod(str) < INT_MIN)
              return INT_MIN;
            return stoi(str);           //6
        }
        catch(const std::exception&){
            return 0;
        }
    }
};

int main() {
  //string s = "-42gml";    //-42
  //string s = "42";
  //string s = "4193 with words";
  //string s = "words and 987";
  string s = "-91283472332";
  //string s = "   -42";
  //string s = "-+12";
  //string s = "21474836460";   //2147483647
  Solution o;
  cout<<o.myAtoi(s);
}
```
