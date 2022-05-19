[Maximum Consecutive Floors Without Special Floors](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/)
- Approach-1
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
    - [Python](#py)
  - [Complexity](#co)


## Maximum Consecutive Floors Without Special Floors
- Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be special floors, used for relaxation only.
- You are given two integers bottom and top, which denote that Alice has rented all the floors from bottom to top (inclusive). You are also given the integer array special, where special[i] denotes a special floor that Alice has designated for relaxation.
- Return the maximum number of consecutive floors without a special floor.
```c
Example 1:
Input: bottom = 2, top = 9, special = [4,6]
Output: 3
Explanation: The following are the ranges (inclusive) of consecutive floors without a special floor:
- (2, 3) with a total amount of 2 floors.
- (5, 5) with a total amount of 1 floor.
- (7, 9) with a total amount of 3 floors.
Therefore, we return the maximum number which is 3 floors.
  
Example 2:
Input: bottom = 6, top = 8, special = [7,6,8]
Output: 0
Explanation: Every floor rented is a special floor, so we return 0.
```

### Approach-1. Jump from floor to floor
<a name=l></a>
#### Logic
- _1._ Store special floors in set, to make them in ascending order.
- _2._ maxi=0. stores output.
- _3._ current = bottom floor. current is present floor
- _4._ Jump from current to 1st special floor
```c
if special[0] - curr > maxi
  update maxi
```
- _5._ if we jumped from special floor to other special floor. maxi should be stored as 1 less than difference of special floors.
- _6._ if we are on last special floor. and top-last_special_floor > maxi. Update maxi and jump to last floor.

#### Code
<a name=cpp></a>
**CPP**
```c
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        set<int> s;
        for (auto&i :special)
            s.insert(i);

        int maxi = 0, curr = bottom;
        while (curr < top) {
            auto it = s.begin();

            if (s.size()) {
                if (*it - curr > maxi)
                    if (!maxi)
                        maxi = *it - curr;
                    else
                        maxi = *it - curr - 1;
                if (curr == *it && s.size()>1)
                    curr++;
                else
                    curr = *it;
                s.erase(it);
            }
            else {  //No special floors
                if (top - curr > maxi)
                    maxi = top - curr;
                curr = top;
            }
        }
        return maxi;
    }
};
```

<a name=co></a>
#### Complexity
- **Time:** O(nlogn). Storing in set
- **Space:** O(m). size of special array

