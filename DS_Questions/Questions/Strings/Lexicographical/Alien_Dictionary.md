**[Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)**
- [Approach-1, Breadth 1st Search](#a1)
  - [1. Logic](#logic)
    - [A. Extract information about lexiographical order of letters from input string](#s1)
      - [A1. Simple Example](#ex1)
      - [1.1 Complicated Example](#ex2)
    - [Step-2: Represent all relations from prev step in graph, specifically DAG](#step2)
  - [2. Code](#code)

## Alien Dictionary
- Given string of words and these words are lexiographically sorted(as per alien dictionary). Remember this is not English dictionary. Where word `age` comes before `ago`.
- Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. Example
```c
Input = ["wrt","wrf","er","ett","rftt"]
o/p: wertf
```

<a name=a1></a>
## Approach-1, BFS, [Topological Sort](/DS_Questions/Data_Structures/Graphs)

<a name=logic></a>
### 1. Logic

<a name=s1></a>
#### A. Extract information about lexiographical order of letters from input string
- Only find 1st difference between adjacent words.

<a name=ex1></a>
- **A1. Simple Example**
  - _a._ Looking at 1st letter of each word, we can find ordering of 1st letters
```c
"wrt","wrf","er","ett","rftt"
[w, e, r]             //Since w appears before e and r. its will be lexiographically ahead in alien dictionary
```
- _b._ Remove 1st letters of words and find next lexiographical order.
```c
"rt","rf","r","tt","ftt"
r t f                 //Since r is in 1st word, it will ahead in lexiographical order from other words
```
- _c._ Every word in input string is consumed. We can now predict final lexiographical order.
```c
w, e, r, t, f
```

<a name=ex2></a>
- **A2. Complicated Example**
  - Considering all rules from Ex-1.1
```c
input = "uvoih", "ufoe", "aaief", "abve", "abvbr"
u, a                       //Lexiographical order on 1st iteration

"voih", "foe", "aief", "bve", "bvbr"
v, f                         //We will Ignore all letters after v and f in 1st and 2nd word.
                             //Consider "test" & "toad" in English, How to find lexiographical order?
                             //1st letter. t,t same. Remove. Left word: "est", "oad".
                             //2nd letter mismatch: e appears before o. Lexiographical order till now: t,e,o
                             //After 2nd letters, We will park remaning letters to decide order later.
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
- _a._ Extract relationship from input string and create a [Adjacency list](/DS_Questions/Data_Structures/Graphs).
  - Finding all nodes whose [indgree](/DS_Questions/Data_Structures/Graphs) is 0,because these will be placed ahead in alien dictionary. Let's suppose finding for a.
    - Search whether a is present in any of node's adjacency matrix. This means checking all 26 alphabet's adjacency list.
    - This might be ok for dictionary having 26 characters, But what if alien dictionary has 1 million unique characters? This approach will have huge time complexity.
    - _How to do better:_ While building adjacency list, we will Keep count of how many incoming edges each letter has. count=0 means indegree=0.
```c
vector<int> al[26];   //0:a, 1:b, 2:c, 3:d, 4:e, 5:f, 15:o,.. 19:u, 20:v
al[19].push_back(0);  u->a
al[20].push_back(5);  v->f
al[15].push_back(0);  o->a

al[19] | 0 |
al[20] | 5 |
al[15] | 0 |

```
- _b._ Do BFS using Queue
  - Put all letters whose indegree=0 to queue.
  - Pop letter, 
    - place in output string.
    - Check letters connected to this node, whether has indegree=0, if so place on queue.
- _c._ Check all letters are placed on queue or not?
  - if not, this must be cycle, DAG cannot have, even question says return "" if cycle.
