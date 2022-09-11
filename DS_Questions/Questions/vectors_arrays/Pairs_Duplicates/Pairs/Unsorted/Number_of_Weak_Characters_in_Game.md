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
- _2._ Now array is sorted on order of:
  - Attacks as ascending, Defence as decending.
  - if there is deviation in above rule, attack order is taken 1st preference.
    - These deviation points are the weakeset players which we want to find.
  - Traverse sorted array from back, and find the deviation points.
```c
leastDefenceVal = 0
count = 0

  [1,5] [4,3] [10,4]
    0     1      2
    
  i  defence    leastDefenceVal=max(val,defence)  if(defence<leastDefenceVal) count++
  2   4                   4                             0
  1   3                   4                             1
  0   5                   5                             1
```

#### Code
```cpp
using vecVecI = vector<vector<int>>;
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        //Sort array based on:
        //  ascending order of attacks (Preferred)
        //  decending order of defence
        //if there is a situation where above rule does not hold {Deviation}
        //  sort on attacks
        sort (properties.begin(), properties.end(), [](auto&a, auto&b){
            if (a[0] == b[0]){
                if (a[1] > b[1])
                    return true;
                else
                    return false;
            }
            else if (a[0] < b[0])
                return true;
            else
                return false;
        });
        
        int weakCharacters = 0, maxDefense = 0;
        
        //Iterate sorted vector from back and find 
        //deviation points
        //Deviation points are the weakest players
        for (int i = properties.size() - 1; i >= 0; i--) {
            maxDefense = max(maxDefense, properties[i][1]);
            if (properties[i][1] < maxDefense)
                weakCharacters++;
        }
        return weakCharacters;
    }
};
```
