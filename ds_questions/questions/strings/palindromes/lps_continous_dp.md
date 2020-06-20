
## Problem
  - Given a string find longest palindromic substring present in it. s=`babad`
  - Palindromic Substrings(any substring is fine):
    - bab
    - aba

| b | a | b | a | d |
| --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 |

size = 5      
    
## Logic `[Sliding Window]`
  - Take 2-D array (bool `a[5][5]`) of equal size as input string. and initlilize to 0.
  - Window Size = 1. Consider 1 character at a time. LPS will be 1.
    - `s[0]` is compared with `s[0]`. if(`s[0]` == `s[0]`) `a[0][0]` = 1
    - `s[1]` is compared with `s[1]`. if(`s[1]` == `s[1]`) `a[1][1]` = 1
    - `s[4]` is compared with `s[4]`. ..
      
| 1 | 0 | 0 | 0 | 0 |
| --- | --- | --- | --- | --- |
| 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 1 |

  - Window Size = 2. Consider 2 characters at a time. `[0.1], [1.2] [2.3] [3.4]` LPS
    - Length of LPS from index 0 to 1 `ba` is 1, hence `a[0][1] = 1`
    - Length of LPS from index 1 to 2 `ab` is 1, hence `a[1][2] = 1`
    - Length of LPS from index 2 to 3 `ba` is 1, hence `a[2][3] = 1`
    - Length of LPS from index 3 to 4 `ad` is 1, hence `a[3][4] = 1`
      
| 1 | 1 | 0 | 0 | 0 |
| --- | --- | --- | --- | --- |
| 0 | 1 | 1 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 0 | 0 | 1 | 1 |
| 0 | 0 | 0 | 0 | 1 |      

  - Window Size = 3. Consider 3 characters at a time. `[0..2], [1..3] [2..4]` LPS
    - Length of LPS from index 0 to 2 `bab` is 3
      - Since `a[0] == a[2]` = 2
      - `a[1][1]=1` hence LPS = `a[0][2] = 2 + 1 = 3`
    - Length of LPS from index 1 to 3 `aba` is 3, hence `a[1][3] = 3`. Same calculation as above.
    - Length of LPS from index 2 to 4 `bas` is 1, hence `a[2][4] = 1`
      
| 1 | 1 | 3 | 0 | 0 |
| --- | --- | --- | --- | --- |
| 0 | 1 | 1 | 3 | 0 |
| 0 | 0 | 1 | 1 | 1 |
| 0 | 0 | 0 | 1 | 1 |
| 0 | 0 | 0 | 0 | 1 |   

  - Window Size = 4. Consider 4 characters at a time. `[0..3], [3..4]` LPS
    - Length of LPS from index 0 to 3 `baba` is 1
      - if `s[0] == s[3]` no. `a[0][3] = 1`
    - Length of LPS from index 1 to 4 `abad` is 1
      - if `s[1] == s[4]` no. `a[1][4] = 1`
      
| 1 | 1 | 3 | 1 | 0 |
| --- | --- | --- | --- | --- |
| 0 | 1 | 1 | 3 | 1 |
| 0 | 0 | 1 | 1 | 1 |
| 0 | 0 | 0 | 1 | 1 |
| 0 | 0 | 0 | 0 | 1 | 
     
```      
/*      longest_palindrome_substring.cpp

Task: Given a string find longest palindrome present in it.
Input string: abeetteec, size=9
Palindromes present: ee, ee, ette, eettee
Output = eettee

******************Logic(Dynamic Programming)*******************
Concept is very simple.
1. Take a 2D boolen array sizexsize, here 9x9. tab[9][9] & intialize to 0. Make tab[i][j] = 1 when substr[i..to..j] is palindrome
2. Take maxlength, startindex variables. Note starting index and maximum length of palindrome string.



- Start with filling diagonal=1, check 2 chars, then 3,4,5..n characters
a. All 1 characters are palindromes.
  tab[1][1] = tab[2][2] ... tab[8][8] = 1

b. Check 2 characters from index 0. if adjacent characters are equal set tab[][]=1
Example:
  if(s[0] == s[1])  tab[0][1]=1; maxlength=2; startindex=0
 
c. Check 3,4.....n characters from index 0.
if character at index[0] == index[3] and inside it is also palindrome ie 1 mark this as 1.
  //Checking 3 characters
  if(s[0] == s[2] && tab[1][1]==1) tab[0][2]=1

Complexity: O(n2)  
***************************************************************
*/


#include<iostream>
#include<string>
using namespace std;

string isPalindrome(string s){
        int n = s.size(), k;

        /*Edge cases
        if(!n)  return "";
        if(n==1)  return s;
        */
  
        bool tab[n][n];
        int maxlength=0;
        int startIndex = 0;

        //Strings of len=1 are always palindrome
        for(int i=0;i<n;i++)
                tab[i][i]=true;

        //Checking strings of size 2
        for(int i=0;i<n-1;i++){
                if(s[i]==s[i+1]){
                        tab[i][i+1]=true;
                        maxlength=2;
                        startIndex = i;
                }
        }

        //Checking substrings of size=3,4,....n
        for(int i=0;i<n-3;i++){
                k=0;
                for(int j=i+2;j<=n-1;j++){

                        if(s[k]==s[j] && tab[k+1][j-1]){
                                maxlength = j-1;
                                startIndex = k;
                                tab[k][j]=true;
                        }
                        k++;
                }
        }
        cout<<"startIndex="<<startIndex<<"\n";
        cout<<"maxlength="<<maxlength<<"\n";
        return s.substr(startIndex, maxlength);
}

int main(){
        string s = "abeetteec";
        cout<<"palindrome="<<isPalindrome(s);
}
/*Output:
# ./a.out 
startIndex=2
maxlength=6
palindrome=eettee
*/
```
