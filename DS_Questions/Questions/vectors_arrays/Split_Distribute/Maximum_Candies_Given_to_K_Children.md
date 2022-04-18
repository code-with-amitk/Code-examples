**Maximum Candies Allocated to K Children**
- Approach
  - [Logic](#l)

## Maximum Candies Allocated to K Children
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
```
- Total candies = 19, Children = 3. No child will get candies > 6(19/3). Min candies child can get=1
- So, We have a range between which a number will represent candies given to children (1,6). Now we need to search max number between low=1, high=6 which will represent max candies given to children.
