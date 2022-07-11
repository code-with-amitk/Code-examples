**Minimum Amount of Time to Fill Cups**
- **Approach-1. Sort**
  - [Logic](#l)
  - [Complexity](#co)
  - [Code](#c)

### [Minimum Amount of Time to Fill Cups](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/)
- You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.
- You are given a 0-indexed integer array amount of length 3 where `amount[0], amount[1], and amount[2]` denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.
```c
Example 1:
Input: amount = [1,4,2]
Output: 4
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup and a warm cup.
Second 2: Fill up a warm cup and a hot cup.
Second 3: Fill up a warm cup and a hot cup.
Second 4: Fill up a warm cup.
It can be proven that 4 is the minimum number of seconds needed.

Example 2:
Input: amount = [5,4,4]
Output: 7
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup, and a hot cup.
Second 2: Fill up a cold cup, and a warm cup.
Second 3: Fill up a cold cup, and a warm cup.
Second 4: Fill up a warm cup, and a hot cup.
Second 5: Fill up a cold cup, and a hot cup.
Second 6: Fill up a cold cup, and a warm cup.
Second 7: Fill up a hot cup.

Example 3:
Input: amount = [5,0,0]
Output: 5
Explanation: Every second, we fill up a cold cup.
```

### Approach
<a name=l></a>
#### Logic
- Sort the array and reduce `0th, 1st` element by 1. Increment steps by 1
- Keep doing until all elements are greater than 0
```c
                Steps
[5, 4, 4]
[4, 3, 4]         1
[4, 4, 3]             //sort
[3, 3, 3]         2
[2, 2, 3]         3
[3, 2, 2]             //sort
[2, 1, 2]         4
[2, 2, 1]             //sort
[1, 1, 1]         5
[0, 0, 1]         6
[1, 0, 0]             //sort
[0, -1, 0]        7
```
<a name=co></a>
#### Complexity
- **Time:** O(n) + 3log(3) = O(n)
  - n: This is biggest number out of 3
- **Space:** O(1)

<a name=c></a>
#### Code
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

class Solution {
public:
    int fillCups(vector<int>& v) {
        int steps=0;
        //if any 2 are 0, result is 3rd
        if (!v[0] && !v[1])
            return v[2];
        if (!v[1] && !v[2])
            return v[0];
        if (!v[2] && !v[0])
            return v[1];

        while(v[0]>0 || v[1]>0 || v[2]>0){
            if (v[0] == v[1] && v[1] == v[2]){
            }else{
                sort(v.rbegin(), v.rend());
            }
            v[0]--;
            v[1]--;
            steps++;
        }
        return steps;
    }
};
int main(){
    vector<int> v = {1,4,2};  //4
    //vector<int> v = {5,4,4};  //7
    //vector<int> v = {5,0,0};
    Solution s;
    cout << s.fillCups(v);
}
```
