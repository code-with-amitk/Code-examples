- [Question](#que)
- [Approach-1, Breadth 1st Search](#apr1)
  - [1. Logic](#logic)
    - [Step-1: Extract information about lexiographical order of letters from input string](#step1)
      - [1.1 Simple Example](#ex1)
      - [1.1 Complicated Example](#ex2)
    - [Step-2: Represent all relations from prev step in graph, specifically DAG](#step2)
  - [2. Code](#code)

<a name=ques></a>
## [Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)
- We are given string of words and these words are lexiographically sorted(as per alien dictionary). Remember this is not English dictionary. Where word `age` comes before `ago`.
- Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules.
- Example
```c
Input = ["wrt","wrf","er","ett","rftt"]
o/p: wertf
```

<a name=apr1></a>
## Approach-1, BFS, [Topological Sort](/DS_Questions/Data_Structures/Graphs)

<a name=logic></a>
### 1. Logic

<a name=step1></a>
#### Extract information about lexiographical order of letters from input string
- Only find 1st difference between adjacent words.

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
  - Considering all rules from Ex-1.1
```c
input = "uvoih", "ufoe", "aaief", "abve", "abvbr"
u -> a                       //Lexiographical order on 1st iteration

"voih", "foe", "aief", "bve", "bvbr"
v -> f                       //We need to find Ignore all letters after v and f in 1st and 2nd word.
                             //Because in english "agebb" and "agoaa". After e in 1st and o in 2nd all letter are ignored
                             //Means in Adjacent words we need to find first difference between them.
                             //That difference tells us the relative order between two letters.

"oih", "oe", "aief", "bve", "bvbr"  //Just note the 1st difference
o -> a

"ih", "e", "ief", "bve", "bvbr"
i -> e

"h", "ief", "bve", "bvbr"
h -> i

"ef", "bve", "bvbr"
e -> b

"f", "ve", "vbr"
f -> v             //Ignore this since f->v already derived

"e", "br"
b -> r        //Since e->b is already present
```

<a name=step2></a>
#### Represent all relations from prev step in graph, specifically [DAG](/DS_Questions/Data_Structures/Graphs)
- Condering ex-1.2
```c
        u -> a <- o
        
        v -> f
        
        i -> e <- h
             |
             \/
             b -> r
```
- Notice there is no [in-degree(or arrow going)](/DS_Questions/Data_Structures/Graphs) to letters u,v,i,h. So these will be a head in alien dictionary.
```c
Ouput = u,v,i,h
```
- After removing u,v,i,h what's left in DAG?
```c
   a
   
   f
   
   e -> b -> r
```
- Again remove disjoint nodes.
```c
ouput = u,v,i,h,a,f,e
  b -> r
  
output = u,v,i,h,a,f,e,b,r
```

<a name=code></a>
### 2. Code
- _a._ Extract relationship from input string and create a Adjacency list.
- _b._ Identify which letters have no incoming links (ie in-degree=0).
- _c._ 
