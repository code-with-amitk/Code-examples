[Problem](https://leetcode.com/contest/weekly-contest-197/problems/number-of-substrings-with-only-1s/)

## Question
- Given a binary string s (a string consisting only of '0' and '1's).
- Return the number of CONTINIOUS substrings with all characters 1's.
- Since the answer may be too large, return it modulo 10^9 + 7.

### Example-1
```
Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
index   substring
  1       1,11
  2       1
  4       1,11,111
  5       1,11
  6       1
        ------
          9
```

### A. This is Arithematic Progression
- if 2 continuous `1s` are present (eg: 11). Number of substrings = 2+1 = 3
```
  index   substrings
    0       1,11
    1       1
```
- if 3 continuous `1s` are present (eg: 111). Number of substrings = 3+2+1 = 6
```
  index   substrings
    0       1,11,111
    1       1,11
    2       1
```  
- if 4 continuous `1s` are present (eg: 1111). Number of substrings = 4+3+2+1 = 10
```
  index   substrings
    0       1,11,111,1111
    1       1,11,111
    2       1,11
    3       1
```
- **Again, count[4]=count[3]+1.   count[3]=count[2]+1   count[n]=count[n-1]+1   !! Dynamic Programming !!**

### B. Logic
- Take a dp array of same size as input string. Consider s = "0110111"

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |

- if(s[0] == 0) dp[0]=0   //else 1

| 0 |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |

- Iterate through string
  - if present value in string is 1 `s[i]==1`, `dp[i]=1+dp[i-1]`
  - if present value in string is 0 `s[i]==0`, `dp[i]=0`
  - calculate sum of all elements till present element, Perform Modulus since this sums maybe large
  
i = 1, `dp[1] = 1+dp[0]`
| 0 | 1 |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |

i = 2, `dp[2] = 1+dp[1]`
| 0 | 1 | 2 |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |

i = 3, `dp[3] = 0` because `s[3]=0`
| 0 | 1 | 2 | 0 |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |

i = 4, `dp[4] = 1+dp[3]`
| 0 | 1 | 2 | 0 | 1 |  |  |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |

i = 5, `dp[5] = 1+dp[4]`
| 0 | 1 | 2 | 0 | 1 | 2 |  |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |

i = 6, `dp[6] = 1+dp[5]`
| 0 | 1 | 2 | 0 | 1 | 2 | 3 |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |

```
class Solution {
public:
  int numSub(string s) {
    long int size=s.size(), dp[size], i, tot;

    //if s[0] is 0. dp[0]=0 else dp[0]=1
    dp[0] = (s[0]=='0')?0:1;

    for(int i=0; i<size; i++){  //replace with range_based

      if(s[i] == '1'){
        dp[i] = 1 + dp[i-1];
      }else{    //0
        dp[i] = 0;
      }
      tot = (tot+dp[i])%1000000007;
    }

    return tot;
  }
};
int main(){
  string s = "0110111";   //9 ok
  Solution o;
  o.numSub(s);
}
```
