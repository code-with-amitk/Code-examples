**[Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)**
- [Problem](#p)
- [Approach-1, Recursion, O(n<sup>2</sup>)](#a1)
- [Approach-2, Iteration, O(mn)](#a2)
- **Approach-3, Dynamic Programming**
  - [Logic](#l2)
  - [Logic of Filling values in dp Array](#l21)
  - [Code](#c2)

<a name=p></a>
### Longest Common Subsequence
- Given two strings str1,str2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
- [What is Subsequence](/DS_Questions/Questions/Strings/SubString_SubSequence#s)
```c
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: LCS is "ace" and its length is 3.
           
Example-2: str1 = “AGGTAB”, str2 = “GXTXAYB” 
          Answer = “GTAB” of length 4. 
```

<a name=a1></a>
### Approach-1    //Recursive. O(2<sup>n</sup>)
**Logic** 
- Enumerate all subsequences of both given sequences and find LCS.
- Match every character with other character. 
- PROBLEM: Many subproblems which are solved again and again eg:"se,e". And in bigger string these repeated recurions will be more.
```c
str1=sea, str2=eat
                sea, eat
                /       \
            sea,ea      se,ea
            /           /   \
          se,e        se,e   s,ea
          /           /       \
         s,0        s,0       0,a
```
**Code**
```c++
class Solution {
public:
    int FindLCS(string str1, string str2, int m, int n) {
        s1 = str1;
        s2 = str2;
        return lcs(0, 0);
    }
private:
    string s1, s2;
    int lcs(int m, int n) {
        if (m == 3 || n == 3)
            return 0;

        if (s1[m+1] == s2[n+1])
            return 1 + lcs(m+1, n+1);
        else
            return max(lcs(m, n + 1), lcs(m + 1, n));
    }
};
int main() {
    string s1 = "abc";  string s2 = "acd";
    Solution oSolution;
    cout << "Length of LCS is " << oSolution.FindLCS(s1, s2, 0, 0);     //2
    return 0;
}
```

<a name=a2></a>
### Approach-2, Iteration, Brute Force. O(mn)
#### Logic
- Check every occurance of char from str1 in st2 using 2 for loops
```c
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string lcs(string s1, string s2) {
        int size1 = s1.size(), size2 = s2.size();
        string temp1, temp2;
        if (!size1 || !size2)
            return temp2;
        int k = 0, pos = 0;
        int i = 0;
        for (int i=k; i<size1; ++i) {
            for (int j=pos; j<size2; ++j){

                if (s1[i] == s2[j]){
                    temp1 += s1[i];
                    pos = j+1;
                    if (j == size2-1){
                        if (temp1.size() > temp2.size())
                            temp2 = temp1;
                        temp1.clear();
                        k++;
                        i = k-1;
                        pos = 0;
                    }
                    break;
                }
            }
        }
        if (temp1.size() > temp2.size())
            temp2 = temp1;
        cout << temp2;
        return temp2;
    }
};

int main() {
    string s1 = "aggtab", s2 = "gxtxaybg";
    Solution o;
    string out = o.lcs(s1,s2);
    cout << out;
}
```

<a name=a3></a>
### Approach-3, [Dynamic Programmming](/DS_Questions/Algorithms/Dynamic_Programming) O(mn) //m=strlen(str1), n=strlen(str2)
This question has overlapping subproblem & will be solved using DP.

<a name=l2></a>
#### Logic
- _1._ As in DP, Take 2-D array `dp[s1.size()+1][s2.size()+1]` & init=0. This array represents longest Common Subsequence till that element.
```c
s1="xbdy", s2="abcdef". LCS=bd

dp[5][7]                         //s1.size()+1, s2.size()+1. Represents lcs till that element

       a  b  c  d  e  f   <<s2
    0  1  2  3  4  5  6
 x  1  0  0  0  0  0  0
 b  2  0  0  0  0  0  0
 d  3  0  0  0  0  0  0
 y  4  0  0  0  0  0  0
 s1

dp[2][3] = 1         //Means length of LCS in `s1[0..1]=xb` and `s2[0..2]=abc` ie b is 1
dp[3][4] = 2         //Means length of LCS in `s1[0..2]=xbd` and `s2[0..3]=abcd` ie bd is 2
```
_2._ Start iterting dp array from `[1][1]`. Check 1st character of `s1[0] = x` in s2.
```c++
 dp[1][1]=0         //s1[0]=x, s2[0]=a does not have any LCS
 dp[1][2]=0         //s1[0]=x, s2[0..1]=ab does not have any LCS
 - dp[1][3]=0       //s1[0]=x, s2[0..2]=abc does not have any LCS
 - dp[1][4]=0       //s1[0]=x, s2[0..3]=abcd does not have any LCS
 - dp[1][5]=0       //s1[0]=x, s2[0..4]=abcde does not have any LCS
 - dp[1][6]=0       //s1[0]=x, s2[0..5]=abcdef does not have any LCS 
```
_3._ Check 2 characters of `s1[0..1] = xb` in s2.
```cpp
dp[2][1]=0         //s1[0..1]=xb, s2[0]=a does not have any LCS
dp[2][2]=1         //s1[0..1]=xb, s2[0..1]=ab have LCS=b so dp=1
dp[2][3]=1         //s1[0..1]=xb, s2[0..2]=abc have only LCS=1 hence dp=1
dp[2][4]=1         //s1[0..1]=xb, s2[0..3]=abcd have only LCS=1 hence dp=1
dp[2][5]=1         //s1[0..1]=xb, s2[0..4]=abcde have only LCS=1 hence dp=1
dp[2][6]=1         //s1[0..1]=xb, s2[0..5]=abcdef have only LCS=1 hence dp=1
        a  b  c  d  e  f
    0  1  2  3  4  5  6
 x  1  0  0  0  0  0  0
 b  2  0  1  1  1  1  1
 d  3  0  0  0  0  0  0
 y  4  0  0  0  0  0  0
```
_4._ Check 3 characters of `s1[0..2] = xbd` in s2.
```cpp
dp[3][1]=0         //s1[0..2]=xbd, s2[0]=a does not have any LCS
dp[3][2]=1         //s1[0..2]=xbd, s2[0..1]=ab have LCS = b
dp[3][3]=1         //s1[0..2]=xbd, s2[0..2]=abc have LCS = b
dp[3][4]=2         //s1[0..2]=xbd, s2[0..3]=abcd have LCS = bd
dp[3][5]=2         //s1[0..2]=xbd, s2[0..4]=abcde have LCS = bd
dp[3][6]=2         //s1[0..2]=xbd, s2[0..5]=abcdef have LCS = bd

       a  b  c  d  e  f
    0  1  2  3  4  5  6
 x  1  0  0  0  0  0  0
 b  2  0  1  1  1  1  1
 d  3  0  1  1  2  2  2
 y  4  0  0  0  0  0  0
```
_5._ Check 4 characters of `s1[0..3] = xbdy` in s2.
```c++
dp[4][1]=0         //s1[0..3]=xbdy, s2[0]=a does not have any LCS
dp[4][2]=1         //s1[0..3]=xbdy, s2[0..1]=ab have LCS = b
dp[4][3]=1         //s1[0..3]=xbdy, s2[0..2]=abc have LCS = b
dp[4][4]=2         //s1[0..3]=xbdy, s2[0..3]=abcd have LCS = bd
dp[4][5]=2         //s1[0..3]=xbdy, s2[0..4]=abcde have LCS = bd
dp[4][6]=2         //s1[0..3]=xbdy, s2[0..5]=abcdef have LCS = bd
       a  b  c  d  e  f
    0  1  2  3  4  5  6
 x  1  0  0  0  0  0  0
 b  2  0  1  1  1  1  1
 d  3  0  1  1  2  2  2
 y  4  0  1  1  2  2  2
```
_6._ LCS of complete string=s1 and s2 would be last element `dp[4][6]`. Return `dp[m-1][n-1]`

<a name=l21></a>
#### Logic of Filling values in dp Array
- _1._ if character in s1 and s2 are not same, Calculate LCS using below formula:
```c++
  LCS(str1[0..m], str[0..n]) = max ( LCS(str1[0..m-1], str2[0..n]), LCS(str1[0..m], str2[0..n-1]) )

  if (str1[i] != str2[j])
    dp[4][4] = LCS(xbdy,abcd) = max(above, back) = max(dp[i - 1][j], dp[i][j - 1])
    //above=dp[3][4]=LCS(xbd,abcd)
    //back=dp[4][3]=LCS(xbdy,abc)
```
_2._ if character in s1 and s2 are same, Calculate LCS using below formula:
```c++
  LCS(str1[0..m], str[0..n]) = LCS(str1[0..m-1], str2[0..n-1]) + 1

  if (str1[i] == str2[j])
    dp[3][4] = LCS(xbd,abcd) = LCS(xb, abc) + 1;
```
<a name=c2></a>
#### Code
```c++
 int lcs( string& str1, string& str2, int m, int n ) {
  vector<vector<int> > dp(m+1, vector<int>(n+1,0));               //1
  
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
        
        if (str1[i - 1] == str2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
                        //max of above and back
            dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
  }
```
