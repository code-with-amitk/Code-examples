**Maximum Running Time of N Computers**
- [Approach-1. TLE. sort](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
- Approach-2. Binary Search. But not clear how to use

### [2141. Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers/description/)
- You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.
- Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.
- Note that the batteries cannot be recharged.
- Return the maximum number of minutes you can run all the n computers simultaneously.
```c
Example-1
Input: n = 2, batteries = [3,3,3]
Output: 4
Explanation: 
Initially, insert battery 0 into the first computer and battery 1 into the second computer.
After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
We can run the two computers simultaneously for at most 4 minutes, so we return 4.
```

<a name=a1></a>
### Approach-1. TLE. sort
<a name=l></a>
#### Logic
- _1._ Sort in decending order, bring max charged batteries on front.
```c
computers = 3
batteries = [100, 3, 3, 3]
```
- _2._ Take juice of most charged batteries everytime
```c
        [100, 3, 3, 3]
time=1  [99, 2, 2, 3]
        sort
        [99, 3, 2, 2]
time=2  [98, 2, 1, 2]
        sort
        [98,2,2,1]
time=3  [97,1,1,1]
        sort
        [97,1,1,1]
time=4  [96,0,0,1]
        sort
        [96,1,0,0]
time=5  Cannot charge 3 computers together
```

#### Code
<a name=cpp></a>
**CPP (Maxheap)**
```cpp
using ll = long long;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        std::priority_queue<ll> pq;
        for (auto&i:batteries)
            pq.push(i);

        bool bexit = false;
        long long steps = 0;

        while (!pq.empty()) {
            vector<int> toBePushed;
            int computers = n;

            while (computers > 0) {
                ll top = pq.top();
                if (top>0) {
                    computers--;
                    toBePushed.push_back(top-1);
                }else{
                    bexit = true;
                    break;
                }
                pq.pop();
            }
            if(bexit)
                break;
            steps++;
            for (auto&i: toBePushed)
                pq.push(i);
            toBePushed.clear();
        }
        return steps;
    }
};
```
