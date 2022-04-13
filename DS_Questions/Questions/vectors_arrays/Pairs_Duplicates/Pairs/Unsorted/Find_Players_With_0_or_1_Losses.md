**Find Players With Zero or One Losses**
- Approach
- [Logic](#l)
- Code
  - [CPP](#cpp)
  - [Rust](#rs)
- [Complexity](#co)

## [Find Players With Zero or One Losses](https://leetcode.com/contest/weekly-contest-287/problems/find-players-with-zero-or-one-losses/)
- You are given an integer array matches where `matches[i] = [winneri, loseri]` indicates that the player winneri defeated player loseri in a match.
- Return a list answer of size 2 where:
  - `answer[0]` is a list of all players that have not lost any matches.
  - `answer[1]` is a list of all players that have lost exactly one match.
- The values in the two lists should be returned in increasing order. You should only consider the players that have played at least one match.
```c
Example 1:

Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
```

### Approach
<a name=l></a>
#### Logic
- Store wins in `set`, since we want ordered output.
- Store losses in `map<loss, count>`. Store count of losses in losses array.
- 0 loss:
  - Check every entry from wins array if it is not present in losses array
- 1 loss:
  - Find all keys from losses array whose count is 1.

#### Code
<a name=cpp></a>
**CPP**
```cpp
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

using vec2d = vector<vector<int>>;
class Solution {
public:
    vec2d findWinners(vec2d& matches) {
        vec2d out;
        set<int> s;
        map<int, int> m;

        for (int i=0; i<matches.size(); ++i) {
            s.insert(matches[i][0]);
            m[matches[i][1]]++;
        }
        //0 loss
        vector<int> vec0Loss;
        for (auto i:s){
            if (m.find(i) == m.end())
                vec0Loss.push_back(i);
        }
        //1 Loss
        vector<int> vec1Loss;
        for (auto i: m){
            if (i.second == 1)
                vec1Loss.push_back(i.first);
        }
        out.push_back(vec0Loss);
        out.push_back(vec1Loss);
        return out;
    }
};
int main(){
    vec2d a = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    Solution s;
    vec2d out = s.findWinners(a);
}
```

<a name=co></a>
#### Complexity
- **Time:** O(n). size of input array
- **Space:** O(n). O(n)=storing wins, O(n)=Storing losses
