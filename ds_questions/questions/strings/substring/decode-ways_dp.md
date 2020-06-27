[Problem](https://leetcode.com/problems/decode-ways/)
[Solution](https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/)

## Task
  - String contains letters from `A` to `Z`
  - determine the total number of ways to decode it.
```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```
### Example-1
```
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
```
### Example-2
```
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

### Logic
  - Consider example `s=226`
  - (Step-1) Take dp table of size+1. ie if input string size=3, take tab of size=4.
    - Dynamic Table
      - Dynamic Table shows number of possible ways to decode the string.
      - Value at `tab[2]` shows number of ways possible with `s[0],s[1]`
      - Value at `tab[3]` shows number of ways possible with `s[0],s[1],s[2]`
    - We will check only `2` elements at a time, in reverse order.
      - ie At index=10, we will check s[8],s[9].
        - if s[8] == 1  //means 1 way exists
        - if s[8]==2 && s[9]<7  //This is valid number and way is considered
  - (Step-2) Make 0th,1st element of tab=1
    - tab[0]=tab[1]=1
    - **Meaning** Atleast 1 way is there. 
      - Example: `99`. 1 way is always there.
      
| input string | 2 | 2 | 6 |
| --- | --- | --- | --- |
| index |        0 | 1 | 2 |
| dp-table     | 1 | 1 | 0 | 0 |

  - (Step-3) Start from i=2
    - i = 2
      - if s[1] > '0', (number of ways = tab[2]) = tab[1]

| input string | 2 | 2 | 6 |
| --- | --- | --- | --- |
| index |        0 | 1 | 2 |
| dp-table     | 1 | 1 | 1 | 

      - if (s[0] == '1') (number of ways = tab[2]) = tab[2]+tab[1]

| input string | 2 | 2 | 6 |
| --- | --- | --- | --- |
| index |        0 | 1 | 2 |
| dp-table     | 1 | 1 | 1 | 2 |

```
class Solution {
public:
    int numDecodings(string s) {
  int size = s.size();

  vector<int> tab(size+1);
  tab[0] = 1, tab[1] = 1;

  //for base condition "0345" should return 0
  if(s[0]=='0')
    return 0;

  for (int i = 2; i <= size; i++)
  {
    tab[i] = 0;

    // If the last digit is not 0, then last digit must add to the number of words
    if (s[i-1] > '0')
      tab[i] = tab[i-1];

    // If second last digit is smaller than 2 and last digit is smaller than 7,
    // then last two s form a valid character
    if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') )
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
