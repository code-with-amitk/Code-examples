### [Decode Ways](https://leetcode.com/problems/decode-ways/)
### [Solution](https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/)
- String contains letters from `A` to `Z`. determine the total number of ways to decode it.
```c
'A' -> 1, 'B' -> 2, ..., 'Z' -> 26. 0 is not valid character

Input: "226"
Output: 3       //3 ways possible
2,2,6  -> Valid  BBF
22,6   -> Valid  VF
2,26   -> Valid  BZ
226    -> Invalid

Input: "024"
Output: 0     //1st character should be valid

Input: "21026"
Output: 2         //2 ways possible
2,1,0,2,6 -> Not valid. Since 0 is invalid
21,0,2,6  -> Not valid. Since 0 is invalid
2,10,2,6  -> Valid   BJBF
210,26    -> Not valid. 3 characters cannot be combined
2,10,26   -> Valid   BJZ
```

### Logic (Dynamic Programming)
> Let's conside example `s = 21026`  
- (Step-1) Take dp table of size+1 and init to 0. ie if input string size=5, dpTable size=6.
  - Dp Table shows number of possible ways to decode the string to present index.
    - Value at `dpTable[2]` shows number of ways possible with `s[0],s[1]`
    - Value at `dpTable[3]` shows number of ways possible with `s[0],s[1],s[2]`
```c++
    s   = 2 1 0 2 6     //size=5
dpTable = 0 0 0 0 0 0   //size=6
```
- (Step-2) `dpTable[0] = dpTable[1] = 1`. Means if string has 2 characters, **Minimum** 1 possible way is there.
```c++
  s = 10
  Ways: [10]        //1 possible way
  
  s = 23
  Ways: [2,3] [23]  //Min 1 possible way
```
- (Step-3) Start from `s[2]`.
- (Step-4) i=2 Check word formed using previous+current element ie `s[1]s[2] or s[i-1]s[i]`. 
  - `if (s[i-1] > 0)`, means whatever present element maybe. This is a valid no, Atleast 1 way possible.
```c++
  if (s[i-1] > '0')    //if prev element is greater than 1, prev+present forms a Valid no.
    dp[i] = dp[i-1]

s = "210"     //10 is valid no. Ways=1
2,1,0 -> Invalid
2,10  -> Valid
21,0  -> Invalid
```
- (Step-5) i=2, Check 2 previous elements `s[0]s[1]`
```c++
if ((s[0] is either 1 or 2) and (s[1] < 7))
  //s[0]s[1] is a valid number
```      

### Complexity
- **Time** O(n)
- **Space** O(n+1)

### Code
```c++
class Solution {
public:
  int numDecodings(string s) {
    int size = s.size();

    vector<int> tab(size+1, 0);
    tab[0] = 1, tab[1] = 1;

    //for base condition "0345" should return 0
    if(s[0]=='0')
      return 0;

    for (int i = 2; i <= size; i++) {                 //Step-3

      if (s[i-1] > '0')                               //Step-4
        tab[i] = tab[i-1];

      if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') )    //Step-5
        tab[i] += tab[i-2];
    }
    return tab[size];
  }
};
int main()
{
  //string s = "12";    //ok 2
  //string s = "226";   //ok 3
  string s = "1234";    //ok 3
  //string s = "999";   //ok 1
  //string s = "100";   //ok 0
  cout<<tabDecodingDP(s);
  return 0;
}
```
