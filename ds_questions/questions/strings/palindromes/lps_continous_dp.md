
## Problem
  - Given a string find longest palindromic substring present in it. s=`babad`
  - Palindromic Substrings(any substring is fine):
    - bab
    - aba

| b | a | b | a | d |
| --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 |

size = 5      

## Overall Logic
  - Take 2-D array (bool `table[5][5]`) of equal size as input string. and initlilize to 0.
  - Value of `table[i][j] = 1` if `str[i ,i+1...j-1, j]` is palindrome
    - if `str[i+1][j-1]` is palindrome and `s[i]==s[j]` then `str[i..to..j]` is palindrome
```    
  if (table[i+1][j-1] == 1 && str[i] == str[j])
    table[i][j] = 1
  else
    table[i][j] = 0
```    
- geeksforgeeks logic is wrong
- [Correct Source](https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/LongestPalindromicSubsequence.java), [Video](https://www.youtube.com/watch?v=_nCsPn7_OgI)
    
## Logic `[Sliding Window]`

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
      - because `s[0] == s[2] &&  a[1][1]=1`    //i=0,j=2 `s[i][j] && a[i+1][j-1]`
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
     
- Complexity O(n<sup>2</sup>)
```c++
int isPalindrome(string s){              //babad
        int size = s.size();

        int a[size][size];

        //str[0][0], str[1][1] .. are always palindromes
        for(int i=0; i <size; i++){
            a[i][i] = 1;
        }

        for(int l = 2; l <= size; l++){

            for(int i = 0; i < size-l + 1; i++){

                int j = i + l - 1;

                if(l == 2 && s[i] == s[j]){
                    a[i][j] = 2;
                }else if(s[i] == s[j]){
                    a[i][j] = a[i + 1][j-1] + 2;
                }else{
                    a[i][j] = max(a[i + 1][j], a[i][j - 1]);
                }
            }
        }

        return a[0][size-1];

}
```
