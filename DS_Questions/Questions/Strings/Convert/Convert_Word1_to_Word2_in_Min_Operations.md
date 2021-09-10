**Minimum number of operations required to convert word1 to word2 / Edit Distance**
- **[Approach-1 / Brute Force](#a1)**
- **Approach-2 / Dynamic Programming**
  - [Logic](#l)
  - [Complexity](#c)
  - [Code](#cpp)

## [Edit Distance](https://leetcode.com/problems/edit-distance/)
- Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
- You have the following three operations permitted on a word:
  - Insert a character
  - Delete a character
  - Replace a character
- Example
```c
Input: word1 = "horse", word2 = "ros"
Output: 3
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

<a name=a1></a>
### Approach-1 / Brute Force
- Check for all possible sequences from word1 to word2 and choose the shortest one in-between. 
- **Complexity:** exponential. 
  - It overkill since we donot want all possible edit sequences but just the shortest one.

### Approach-2 / DP
<a name=l></a>
#### Logic
```c
word1 = horse
word2 = ros
```
- _1._ We will create a 2-D array which will represent edit distance of each character of word1 to/from word2.
```c
 5 e
 4 s
 3 r
 2 o
 1 h
   x  r   o   s
      1   2   3
```
- _2._ Distance b/w `h` and `r` = 1.
```c
1 replacement needed to convert h to r
h =>  r(Replace h)
r

 5 e
 4 s
 3 r
 2 o
 1 h  1
   x  r   o   s
      1   2   3
```
- _3._ Distance b/w `h` and `ro` is 2.
```c
1 replacement, 1 add  needed to convert h to ro
h   =>  r(Replace)  =>  ro(Add o)   
ro  

 5 e
 4 s
 3 r
 2 o
 1 h  1   2
   x  r   o   s
      1   2   3
```

- _4._ Distance b/w `h` and `ros` is 3
```c
1 replacement, 2 adds needed to convert h to ros
h   =>  r(Replace)  =>  ro(Add o)   =>  ros(Add s)
ros

 5 e
 4 s
 3 r
 2 o
 1 h  1   2   3
   x  r   o   s
      1   2   3
```
- _5._ Distance b/w `ho` and `r` is 2
```c
1 replacement, 2 adds needed to convert h to ros
ho
r =>  h(Replace h)  =>  ho(Add o)

 5 e
 4 s
 3 r
 2 o  2
 1 h  1   2   3
   x  r   o   s
      1   2   3
```
- _6._ So on we will be creating whole dp array. We can devise next next number using prev number 
```c
Since only 1 character is added to word1 or word2, Edit distance can be:

If (last character is the same, i.e. word1[i] = word2[j])
  d[i][j] = 1 + min(d[i−1][j], d[i][j−1], d[i−1][j−1]−1) =  1 + min(prev_row_ele, prev_col_elem, prev_diag_ele -1)

else //we have to take into account the replacement of the last character during the conversion.
  D[i][j] = 1 + min(D[i−1][j], D[i][j−1], D[i−1][j−1])

 5 e
 4 s
 3 r
 2 o  2   1   
 1 h  1   2   3
   x  r   o   s
      1   2   3
```
<a name=c></a>
#### Complexity
- **Time:** O(mn). 2 for loops
- **Space:** O(mn). 2d vector

<a name=cpp></a>
#### Code
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // if one of the strings is empty
        if (n * m == 0)
            return n + m;

        // Take dp array
        vector<vector<int>> d(n+1, vector<int>(m+1,0));

        // init boundaries
        for (int i = 0; i < n + 1; i++) {
            d[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            d[0][j] = j;
        }

        // DP compute 
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = d[i - 1][j] + 1;
                int down = d[i][j - 1] + 1;
                int left_down = d[i - 1][j - 1];
                if (word1[i-1] != word2[j - 1])
                    left_down += 1;
                d[i][j] = min(left, min(down, left_down));

            }
        }
        return d[n][m];        
    }
};
```
