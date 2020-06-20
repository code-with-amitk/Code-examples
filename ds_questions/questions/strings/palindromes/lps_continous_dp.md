
## Problem
  - Given a string find longest palindromic substring present in it. str=`babad`
  - Palindromic Substrings(any substring is fine):
    - bab
    - aba
    
| b | a | b | a | d |
| --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 |     
size = 5      
    
### Logic [Sliding Window]
  1. Take 2-D array of equal size as input string. 5x5 here and initlilize to 0.
  2. Windows
     - Size = 1
      
| 1 | 0 | 0 | 0 | 0 |
| --- | --- | --- | --- | --- |
| 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 1 | 0 |
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
