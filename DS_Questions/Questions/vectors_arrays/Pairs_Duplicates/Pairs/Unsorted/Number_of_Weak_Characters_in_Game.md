**The Number of Weak Characters in the Game**
- [Approach-1, Sorting with Comparator](#a1)

## The Number of Weak Characters in the Game
- A game that contains multiple characters, and each of the characters has two main properties: attack and defense.
- `Properties[i] = [attacki, defensei]` represents the properties of the ith character in the game.
- A character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.
- Return the number of weak characters.
```c
Example 1:
Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.

Example 2:
Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.

Example 3:
Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
```

<a name=a1></a>
### Approach-1, Sorting with Comparator
#### Logic
- _1._ Sort array in order
  - attack in ascending
  - defence in decending 
  - if clash then attack order is preferred
```c
Input: [1,5]  [10,4]  [4,3]
        0       1       2
Attack  1,10,4
Defence 5,4,3

Sorting
  [1,5]   [10,4]   //Attack ascending ok. Defence decending ok.
    0       1

  [10,4]  [4,3]   //Attack should be ascending
  [4,3]   [10,4]  //Defence should is decending. But in case of clash. Attack takes preference
     1      2

  [1,5] [4,3] [10,4]    //This is correct order
```
- _2._ Traverse sorted array from back, Find least defense value.
```c
  [1,5] [4,3] [10,4]
    0     1      2
    
  i  defense
  2   4
  
```
