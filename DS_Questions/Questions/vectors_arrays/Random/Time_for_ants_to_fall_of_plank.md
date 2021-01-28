## [Problem](https://leetcode.com/contest/weekly-contest-196/problems/last-moment-before-all-ants-fall-out-of-a-plank/)

## Logic
- We need to find maximum distance travelled by ant placed leftmost on plank(travelling right) & rightmost ant(travelling left)
- Collision of ants does not matter because its just exchange of ants but and movement of 1+ position.

## Code
```
Complexity: O(n)

class Solution {
public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int leftMax=0, rightMin=0;

    if(left.size())
      leftMax = *max_element(left.begin(), left.end());

    if(right.size())
      rightMin = *min_element(right.begin(), right.end());

    if(right.empty())
      return leftMax;
    if(left.empty())
      return n-rightMin;

    return (leftMax > n-rightMin)?leftMax:(n-rightMin);
  }
};
```
