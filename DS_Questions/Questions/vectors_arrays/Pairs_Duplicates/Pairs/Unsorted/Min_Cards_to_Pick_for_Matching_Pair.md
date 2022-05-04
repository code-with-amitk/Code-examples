**Minimum Consecutive Cards to Pick Up**
- **Approach-1**
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
  - [Complexity](#co)


### [Minimum Consecutive Cards to Pick Up](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/)
- You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
- Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.
```c
Example 1:
Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.

Example 2:
Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.
```

### Approach-1
<a name=l></a>
#### Logic
- _1._ Iterate through array, insert every element into `unordered_map<key=value, value=index>`
- _2._ if same key is found and difference of index is smaller than earlier stored difference update value
```c
arr = {3,4,2,3,4,7}
       0 1 2 3 4 5
mini = MAX;

map
  key=value   value=index
  3           0
  4           1
  2           2
                      //key is 3 again, 
    3-0 < mini        //if (present_index-stored_value < mini)
                        //update the difference
  3           3-0=3
```
#### Code
<a name=cpp></a>
**CPP**
```cpp
using vec = vector<int>;
using umI = unordered_map<int,int>;
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int mini = INT_MAX;
        bool bFound = false;
        umI um; 
        for (int i=0;i<cards.size();++i) {
            auto itr = um.find(cards[i]);
            if (itr == um.end()){
                um.insert({cards[i], i});
            }
            else{
                bFound = true;
                //Replace value of map
                int second = itr->second;
                if (i - second < mini) {
                    mini = i-second;
                    itr->second = i;
                }
            }
        }
        return bFound ? mini+1 : -1;     
    }
};
```
<a name=co></a>
#### Complexity
- **Time:** O(n). Traverse array once.
- **Space:** O(n)
  - Creating a unordered_map, it may happen only 1st and last elements are same in that case map size = array size
