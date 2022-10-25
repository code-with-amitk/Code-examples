**Minimum Health to Beat Game**
- [Approach-1. O(n)](#a1)


### [Minimum Health to Beat Game](https://leetcode.com/problems/minimum-health-to-beat-game/)
- You are playing a game that has n levels numbered from 0 to n - 1. You are given a 0-indexed integer array damage where `damage[i]` is the amount of health you will lose to complete the ith level.
- You are also given an integer armor. You may use your armor ability at most once during the game on any level which will protect you from at most armor damage.
- You must complete the levels in order and your health must be greater than 0 at all times to beat the game.
- Return the minimum health you need to start with to beat the game.
```c
Example1:
Input: damage = [2,7,4,3], armor = 4
Output: 13
Explanation: One optimal way to beat the game starting at 13 health is:
On round 1, take 2 damage. You have 13 - 2 = 11 health.
On round 2, take 7 damage. You have 11 - 7 = 4 health.
On round 3, use your armor to protect you from 4 damage. You have 4 - 0 = 4 health.
On round 4, take 3 damage. You have 4 - 3 = 1 health.
Note that 13 is the minimum health you need to start with to beat the game.

Example2:
Input: damage = [2,5,3,4], armor = 7
Output: 10
Explanation: One optimal way to beat the game starting at 10 health is:
On round 1, take 2 damage. You have 10 - 2 = 8 health.
On round 2, use your armor to protect you from 5 damage. You have 8 - 0 = 8 health.
On round 3, take 3 damage. You have 8 - 3 = 5 health.
On round 4, take 4 damage. You have 5 - 4 = 1 health.
Note that 10 is the minimum health you need to start with to beat the game.
```

<a name=a1></a>
### Approach-1. O(n)
#### Logic
- _1._ Traverse array and find max value ie max_damage and sum all elements.
- _2._ Find damages sum and reduce armour or max_damage
```c
if (max_damage < armor)
  Reduce max_damage from sum
else
  Reduce armor from sum
```
- _3._ Return sum+1, Since question says we energy should be >1

#### Code
```cpp
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long sum=0;
        int max_damage = 0;
        for (int i=0;i<damage.size();++i){
            max_damage = max(max_damage, damage[i]);
            sum += damage[i];
        }
        max_damage >= armor ? sum -= armor : sum -= max_damage;
        return sum+1;
    }
};
```
#### Complexity
- **Time:** O(n)
- **Space:** O(1)
