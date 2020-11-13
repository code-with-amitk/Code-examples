## (Problem)[https://leetcode.com/problems/add-binary/]
- Given two binary strings, return their sum (also a binary string).
- The input strings are both non-empty and contains only characters 1 or 0.
- **Examples**
```c
Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
```

## Code
```c++
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    uint32_t u32ASize = a.size();
    uint32_t u32BSize = b.size();

    while (u32ASize < u32BSize) {
        a = '0' + a;
        u32ASize++;
    }
    while (u32ASize > u32BSize) {
        b = '0' + b;
        u32BSize++;
    }

    string strResult(u32ASize, '0');
    bool bCarry = false;

    for (int i = u32ASize-1 ; i >= 0; i--) {

        if (a[i]-'0' && b[i]-'0') {       //Both a[i],b[i] are 1
            if (!bCarry)
                strResult[i] = '0';
            else
                strResult[i] = '1';
            bCarry = true;
        }
        else if (a[i]-'0' || b[i]-'0') {    //Any a[i] or b[i] is 1
            if (!bCarry){
                strResult[i] = '1';
                bCarry = false;
            }
            else {
                strResult[i] = '0';
                bCarry = true;
            }
        }
        else {    //Both a[i] & b[i] are 0
            if (!bCarry)
                strResult[i] = '0';
            else
               strResult[i] = '1';
            bCarry = false;
        }
    }
    if (bCarry)
      strResult = '1' + strResult;

    return strResult;
  }
};
int main(){
  string a = "10111", b = "11";     //11010
  //string a = "11", b = "1";       //100
  //string a = "1010", b = "1011";    //10101
  //string a = "0", b="0";            //0
  //string a = "1", b="1";              //10
  //string a = "100", b = "110010";   //110110
  Solution s;
  cout<<s.addBinary(a,b);
  //s.addBinary(a,b);
}
```
