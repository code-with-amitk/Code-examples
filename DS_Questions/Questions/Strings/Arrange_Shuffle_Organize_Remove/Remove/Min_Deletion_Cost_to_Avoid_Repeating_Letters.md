**Minimum Deletion Cost to Avoid Repeating Letters / Minimum Time to Make Rope Colorful**
- Approach
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
    - [Rust](#rs)

### Minimum Deletion Cost to Avoid Repeating Letters
- Given a string s and an array of integers cost where `cost[i]` is the cost of deleting the character i in s.
- Return the minimum cost of deletions such that there are no two identical letters next to each other.
- After deleting a character, the costs of deleting other characters will not change.
```c
Example 1:
Input: s = "abaac", cost = [1,2,3,4,5]
Output: 3
Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical letters next to each other).

Example 2:
Input: s = "abc", cost = [1,2,3]
Output: 0
Explanation: You don't need to delete any character because there are no identical letters next to each other.
```

### Minimum Time to Make Rope Colorful
- Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where `colors[i]` is the color of the ith balloon.
- Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
- Return the minimum time Bob needs to make the rope colorful.
<img src=https://assets.leetcode.com/uploads/2021/12/13/ballon1.jpg width=300 />
```c
Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
```

### Approach-1
#### Logic
- Traverse thru colors/string and check if next letter is same as present? if it is,
  - Add min of two costs to total cost
  - Change smaller cost to bigger cost, to avoid repetative calculations.
#### Code
**CPP**
```cpp
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int N = cost.size(), sum=0;
        
    for(int i=0;i<N;++i)
    {
        if(s[i]==s[i+1])
        {
            if(cost[i]<cost[i+1])
            {
                sum += cost[i];
                cost[i] = cost[i+1];
            }
            else
            {
                sum += cost[i+1];
                cost[i+1] = cost[i];
            }
        }
    }
    
    return sum;
    }
};
```
**Rust**
```rs
impl Solution {
    pub fn min_cost(colors: String, mut needed_time: Vec<i32>) -> i32 {
        let size = needed_time.len();
        let mut sum = 0;
        let mut i = 0;
        let c = colors.as_bytes();
        
        while i < size-1 {
        
            if c[i] == c[i+1] {
                if needed_time[i] < needed_time[i+1] {
                    sum += needed_time[i];
                    needed_time[i] = needed_time[i+1];
                }
                else {
                    sum += needed_time[i+1];
                    needed_time[i+1] = needed_time[i];
                }
            }
            i += 1;
        }
        sum
    }
}
```

<a name=co></a>
#### Complexity
- **Time:** O(n)
- **Space:** O(1)
