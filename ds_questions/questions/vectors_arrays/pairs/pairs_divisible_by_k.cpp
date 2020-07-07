[LC Problem : Check If Array Pairs Are Divisible by k](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/)

## Problem
- Given an array of integers arr of even length n and an integer k.
- We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
- Return True If you can find a way to do that or False otherwise.

### Example 1:
```
Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
```
### Example 2:
```
Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
```

## Logic
  1. Let input is  ar = {2,63,3,72,9,11,13,13}  k=5
  2. Create reminder frequency array.
     - Calculate the reminder of ar[i]/k and store the frequency at index.
```
      11/5=1                          freq[1]=1
      2/5=2, 72/5=2                   freq[2]=2
      63/5=3, 3/5=3, 13/5=3, 13/5=3   freq[3]=4
      9/5=4                           freq[4]=1
```
freq[]
| 0 | 1 | 2 | 4 | 1 |
| --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 |

  3. Let's Understand Frequency Array
    - index=0. Even number present at Index=0 means There exists ***pair of numbers*** which are exactly divisible by k.
      - Example: 5,10,15,20 etc.
      - Number of pairs = freq[0]/2
    - index=1, index=4
      - If sum of numbers at index=1,4 is even, then pairs exist.
        - ((freq[1]+freq[4])%2 == 0) it Means exact pairs are present, no extra element. Ex: (1,4) they will give reminder as 1,4
        - pairs = (freq[1]+freq[4])/2
    - index=2,index=3
      - If sum of numbers at index=2,3 is even, then pairs exist.
        - ((freq[2]+freq[3])%2 == 0) it means exact pairs are present, no extra element
        - pairs = (freq[2]+freq[3])/2  
        
  4.         
  
