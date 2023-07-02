**Fair Distribution of Cookies**
- [Approach-1. Backtracking](#bt)


### [2305. Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies/description/)
- You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.
- The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.
- Return the minimum unfairness of all distributions.
- Example 1:
```c
Input: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
```
<a name=a1></a>
### Approach-1. Backtracking
#### Code
**CPP**
```c
#include<cstring>
using vI = vector<int>;
class Solution {
    int k;
    vI candidate, cookies;
public:
    void bt(int start, int& out) {
        //Base case 
        if (start >= cookies.size()) {
            int maxi = INT_MIN;
            for (const auto&i:candidate)
                maxi = max(maxi, i);
            out = min(out, maxi);
            return;
        }

        for (auto i=0;i<k;++i) {
            candidate[i] += cookies[start];
            bt (start+1, out);
            candidate[i] -= cookies[start];
        }
    }
    int distributeCookies(vI& cookies1, int k1) {
        // Store cookies in object, donot pass in functions
        cookies.resize(cookies1.size());
        cookies = cookies1;

        // Create candidate array and init=0
        k = k1;
        candidate.resize(k);
        std::fill(candidate.begin(), candidate.end(), 0);

        int out = INT_MAX;
        
        // Start backtrack with index=0
        bt(0, out);
        return out;
    }
};
```
