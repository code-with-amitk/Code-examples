**Maximum Candies Allocated to K Children**
- Approach
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

## [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/)
- You are given array candies. Each element in the array denotes a pile of candies.
- You can split each pile into any number of sub piles, but you cannot merge two piles together.
- You are also given an integer k(represents children). You should allocate piles of candies to k children such that each child gets the equal number of candies.
- Some piles of candies may go unused.
- Return the maximum number of candies each child can get.
```c
Input: 
candies = [5,8,6], k = 3
Output: 5
Explanation: 
  |5|5,3|5,1|
We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.

candies = [5,8,6], k = 4
Output: 4
Explanation:
  |4,1|4,4|4,2|

candies = [5,8,6], k = 5
Output: 3
Explanation:
  |3,2|3,3,2|3,3|

candies = [5,8,6], k = 6
Output: 2
Explanation:
  | 2,2,1 | 2,2,2,2 | 2,2,2 |
```

### Approach
<a name=l></a>
#### Logic
```c
candies = [5,8,6], k = 3
Total candies=19
Children=3
19/3 = 6. No child will get candies greater than 6
```
- So, We have a range between which a number will represent candies given to children (1,6). Now we need to search max number between low=1, high=6 which will represent max candies given to children.
  - Linear Search OR
  - Binary Search

#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long children) {
        long long sum = 0;
        for (auto &i : candies)
            sum += (long long)i;

        //Children are more than candies
        //No division possible
        if(sum<children) 
            return 0;
        
        //Max possible candies that can be given to children
        long long high = sum/children;
        
        //Min possible candies that can be given to children
        long long low = 1;
        
        //count represents number of candies given to children=mid
        long long count = 0, out=0;
        
        //mid represents number children
        long long mid = 0;
        
        //Binary search
        while (high >= low){
            
            count = 0;
            
            mid = (high + low) / 2;
            
            for (auto &i:candies)
                count += i/mid;
            
            //Number of candies given >= number of children
            if (count >= children)
            {
                out = max (out, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return out;
    }
};
```
