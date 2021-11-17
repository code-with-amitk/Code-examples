**[Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)**
- [Approach-1, Breadth 1st Search](#a1)
  - [Logic](#logic)
    - [A. Extract information about lexiographical order of letters from input string](#s1)
      - [A1. Simple Example](#ex1)
      - [1.1 Complicated Example](#ex2)
    - [Step-2: Represent all relations from prev step in graph, specifically DAG](#step2)
  - [Code](#code)

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
### Logic

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
- **A2. Complicated Example:** Considering all rules from Ex-1.1
```c
input = "uvoih", "ufoe", "aaief", "abve", "abvbr"
u -> a                       //1st letters are always Lexiographical ordered                            

"voih", "foe", "aief", "bve", "bvbr"
"voih", "foe", "ief", "bve", "bvbr"
v, f                         //if we found 1st difference in 2 adjacent words, we will ignore all letters after 1st diff.
                             //Consider "test" & "toad" in English, How to find lexiographical order?
                             //1st letters. t,t same. Remove. Left word: "est", "oad".
                             //2nd letter mismatch:
                                //Remove mismatched alphabets. Lexiographical order: t -> e -> o
                                //We cannot predict correct order of alphabets after 1st mismatch in neighbouring words
                                //"st", "ad". We cannot say 's' appears before 'a', which is wrong.
                                //We will park remaning letters to decide order later.
                             //We will Ignore all letters after v and f in 1st and 2nd word.
                             //Means in Adjacent words we need to find first difference between them.
v -> f

"oih", "foe", "ief", "bve", "bvbr"   //For words "ief", "bve" 1st difference was i,b
i -> b

"oih", "foe", "ef", "e", "br"     //words "bve", "bvbr".
b -> v

"oih", "foe", "ef"                //words "e", "br"
e -> b -> r

"oih", "foe", "ef"          //For rest of words, order cannot be decided
e -> b                      //So they will be single nodes in graph
                 i
                 |
                 \/
  u ----> a ---> b  -----> v --> f
                 /\ |
                 |  |----> r
                 e
  o   h   f 

2. As question mentioned there can be multiple orderings, any 1 can be fine.
o  h f   OR
f h o  

//Remove nodes with indegree=0
a ---> b  --> v --> f
       |--> r
o h f u i e

//Remove nodes with indegree=0
b --> v --> f
|--> r
o h f u i e a

//Remove nodes with indegree=0
v --> f
r
o h f u i e a b

//Remove nodes with indegree=0
f
o h f u i e a b v r

//Place remaining nodes in output
o h f u i e a b v r f
```

<a name=code></a>
### Code
#### Logic
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
