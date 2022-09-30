**Longest Substring Without Repeating Characters**
- [Approach-1, Naive O(n<sup>2</sup>)](#a1)
- [Approach-2, Sliding Window O(nm)](#a2)

### [Self Video](https://youtu.be/_CBE8M-P1rs)

### [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- Given a string s, find the length of the longest substring without repeating characters. Substring is always continious.
- Examples
```c
Input: s = "abcabcbb"
  subsequences(without repeating chars):  
    a, ab, abc
    b, bc, bca
    c, ca, cab
    a, ab, abc
    b, bc,
    c, cb
    b
Output: 3                   //The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1                   //The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3                   //The answer is "wke", with the length of 3. Note "pwke" is not contigious substring.

Input: s = "abac"
Output: 3                   //bac

Input: s = "abcdeafed"
Output: 6                   //bcdeaf
```

<a name=a1></a>
### Approach-1 //Naive O(n<sup>2</sup>)
- Fix 1 char then check all rest of string for particular character repetition. 2 for loops.
```c
for()
  for()
```

### Approach-2  //Sliding Window(using 2 pointers) unordered_map    //O(n)
#### Logic
```c
input:    a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
          |
         left
```
- *1.* Take `unordered_map<char, index_of_char>` storing key=char, value=index_of_char
- _2._ Iterate thru string, keep on incrementing i
  - if char is not found in map 
    - insert in map.
  - else      //char is found
    - Delete all characters between left and i
    - move left to i
```c
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
          |
         left
         
         i   unordered_map<char, index>   left    out=i-left
         0    |a,0|                        0       0           //<a,0> not in map insert
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
          |
        left,i
         
         1     |a,0|b,1|                    0       1
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
          |  |
        left i
        
         2      |a,0|b,1|c,2|               0       2
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
          |     |
        left    i
        
         3      |a,0|b,1|c,2|d,3|           0       3
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
          |        |
        left       i
        
         4      |a,0|b,1|c,2|d,3|e,4|       0       4
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
          |           |
        left          i

         5    //key=a found
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
          |              |
        left             i
              //Delete all entries in map from left to it->second+1
              |b,1|c,2|d,3|e,4|
                        
              //insert new key,value(a,5) in map
              |b,1|c,2|d,3|e,4|a,5|     
              
              //increment left by it->second+1  
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8     left=1    out=5-1=4
             |           |
            left         i    

              
          6   |b,1|c,2|d,3|e,4|a,5|f,6|   1       6-1=5
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
             |              |
            left            i    
          
          7   //key=e found
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8
             |                 |
            left               i    
              //Delete all entries in map from left to it->second
              //ie delete from char=b to char=e
              |b,1|c,2|d,3|e,4|a,5|f,6| //original
              |a,5|f,6|
              
              //insert new key,value<e,7> in map
              |a,5|f,6|e,7|
              
         7    //increment left by it->second+1
          a  b  c  d  e  a  f  e  d
          0  1  2  3  4  5  6  7  8   left=5    out=7-5=2
                         |     |
                       left    i
            
         8     a  b  c  d  e  a  f  e  d
               0  1  2  3  4  5  6  7  8   left=5    out=8-5=3
                              |        |
                            left       i
               |a,5|f,6|e,7|d,8|

return out+1;
```
#### Complexity
- **Time:** O(nm). 
  - n=Lenght of string to traverse
  - m=maximum characters to be removed when a repeating char is found.
- **Space:** O(n) for unordered_map
#### Code
```cpp
int lengthOfLongestSubstring(String s) {
        int out = 0, left=0;
        std::unordered_map<char, int> um;
        
        for (int i=0;i<s.size();++i) {
            auto it = um.find(s[i]);
            if (it != um.end()) {
                int temp = it->second;
                for (int j=left;j<it->second;++j)    //Delete all chars from left till
                    um.erase(s[j]);
                left = temp+1;
            }
            um[s[i]]=i;
            out = std::max(out, i-left);
        }
        return out+1;
}
```
