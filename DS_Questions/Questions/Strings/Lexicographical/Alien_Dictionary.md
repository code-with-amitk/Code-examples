- [Question](#que)
- [Approach-1, Breadth 1st Search](#apr1)
  - [1. Logic](#logic)
    - Extract information about lexiographical order of letters from input string
      - [1.1 Simple Example](#ex1)
      - [1.1 Complicated Example](#ex2)

<a name=ques></a>
## [Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)
- We are given string of words and these words are lexiographically sorted(as per alien dictionary). Remember this is not English dictionary. Where word `abacus` comes before `algorithm`.
- Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules.
- Example
```c
Input = ["wrt","wrf","er","ett","rftt"]
o/p: wertf
```

<a name=apr1></a>
## Approach-1, BFS
<a name=logic></a>
### 1. Logic
#### Extract information about lexiographical order of letters from input string
<a name=ex1></a>
- **1.1 Simple Example**
- _a._ Lets try finding logical ordering of letters just by seeing the words. Looking at 1st letter of each word, we can find ordering of 1st letters
```c
"wrt","wrf","er","ett","rftt"
[w, e, r]             //Since w appears before e and r. its will be lexiographically ahead in alien dictionary
```
- _b._ Let's remove 1st letters of words and find next lexiographical order.
```c
"rt","rf","r","tt","ftt"
r t f                 //Since r is in 1st word, it will ahead in lexiographical order from other words
```
- _c._ Every word in input string is consumed. We can now predict final lexiographical order.
```c
w, e, r, t, f
```

<a name=ex2></a>
- **1.2 Complicated Example**
```c

```
