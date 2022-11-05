**Number of Ways to Select Buildings**
- [Approach-1, Count 1s, 0s Before and After. Time:O(n), Space:O(n)](#a1)

### [Number of Ways to Select Buildings](https://leetcode.com/problems/number-of-ways-to-select-buildings/description/)
- Given a binary string s which represents the types of buildings along a street where:
  - `s[i] = '0'` denotes that the ith building is an office and
  - `s[i] = '1'` denotes that the ith building is a restaurant.
- As a city official, you would like to select **3 buildings** for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.
```c
Example-1
Input: s = "001101"
Output: 6
Explanation: 
The following sets of indices selected are valid:
- [0,2,4] from "001101" forms "010"
- [0,3,4] from "001101" forms "010"
- [1,2,4] from "001101" forms "010"
- [1,3,4] from "001101" forms "010"
- [2,4,5] from "001101" forms "101"
- [3,4,5] from "001101" forms "101"
No other selection is valid. Thus, there are 6 total ways.
```

<a name=a1></a>
### Approach-1, Count Zero,One's Before After
#### Logic
- _1._ Only 2 types of patterns can be present. "010" or "101". ie The possible sequences of selected buildings is either "101" or "010".
  - "101":
    - If the current building is '0', Then we can count `(One's Before current building)*(One's After current building)`
  - "010":
    - If the current building is '1', Then we can count `(Zero's Before current building)*(Zero's After current building)`
- _2._ we will take 4 arrays where we will calculate One's Before, After and Zero's before after
```c
s = "0 0 1 1 0 1"
     0 1 2 3 4 5
     
     0 0 0 1 2 2     //vector<int> OnesBefore
     3 3 2 1 1 0     //vector<int> OnesAfter
     
     0 1 2 2 2 3     //vector<int> ZerosBefore
     2 1 1 1 0 0     //vector<int> ZerosAfter
```
- _3._ Iterate thru array, check whether `array[i]` is 0 or 1.
  - if 0, then count 1s before and after and multiply
  - if 1, then count 0s before and after and multiply
```c
if (array[i] == '0')
  count += (OnesBefore[i] * OnesAfter[i])
else
  count += (ZerosBefore[i] * ZerosAfter[i])
```

#### Code
```cpp
using ll = long long;
class Solution {
public:
    long long numberOfWays(string s) {
        ll count=0;

        //Calculate OnesAfter, ZerosAfter
        ll OnesAfterCurrent = 0, ZerosAfterCurrent = 0;
        int size = s.size();
        vector<ll> OnesAfter(s.size(), 0);
        vector<ll> ZerosAfter(s.size(), 0);
        for(int i=1;i<size;i++){
            if(s[i]=='1')
                OnesAfter[0]++;
            else
                ZerosAfter[0]++;
        }
        ll ones = OnesAfter[0], zeros = ZerosAfter[0];
        for (int i=1; i<size; ++i) {
            if(s[i] == '1') {
                OnesAfter[i] = --ones;
                ZerosAfter[i] = zeros;
            } else {
                ZerosAfter[i] = --zeros;
                OnesAfter[i] = ones;
            }
        }

        //Calculate OnesBefore, ZerosBefore
        vector<ll> OnesBefore(s.size(), 0);
        vector<ll> ZerosBefore(s.size(), 0);
        for (int i=size-2;i>=0;--i){
            if(s[i]=='1')
                OnesBefore[size-1]++;
            else
                ZerosBefore[size-1]++;
        }
        ones = OnesBefore[size-1], zeros = ZerosBefore[size-1];
        for (int i=size-2;i>=0;--i){
            if(s[i] == '1') {
                OnesBefore[i] = --ones;
                ZerosBefore[i] = zeros;
            } else {
                ZerosBefore[i] = --zeros;
                OnesBefore[i] = ones;
            }
        }

        //Donot consider 1st and last index
        //because pattern cannot be formed from 1st and last.
        for (int i=1; i<size-1; ++i) {
            if (s[i] == '0')
                count += (OnesBefore[i] * OnesAfter[i]);
            else
                count += (ZerosBefore[i] * ZerosAfter[i]);
        }

        return count;
    }
};
```

#### Complexity
- **Time:** O(n)
- **Space:** 4O(n) = O(n)
