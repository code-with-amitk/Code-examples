**Delete and Earn**
- [Approach-1, Dynamic Programming](#a1)
  - [Why this is DP Problem?](#w)
  - [Logic](#l1)

## [Delete & Earn](https://leetcode.com/problems/delete-and-earn/)
- Given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
- Pick any `nums[i]` and delete it to earn `nums[i]` points. Afterwards, you must delete every `nums[i] - 1` and `nums[i] + 1` element.
- Return the maximum number of points you can earn by applying the above operation some number of times.
- Examples
```c
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
  - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2]
  - Delete 2 to earn 2 points. nums = []
You earn a total of 6 points.

Example 2:
Input: nums = [2,2,3,3,3,4]
Output: 9
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].

Example 3:
Input nums = [5, 5, 5, 6, 6, 6, 6, 7, 7]
Output: 29
- Delete a 5 to earn 5 points. All 6's are also deleted. nums = [5,5,7,7].
- Delete a 5 again to earn 5 points. nums = [5,7,7].
- Delete a 5 once more to earn 5 points. nums = [7,7].
- Delete both 7 to earn 14 points
```

<a name=a1></a>
## Approach-1, Dynamic Programming

<a name=w></a>
#### [Why this is DP Problem?](/DS_Questions/Algorithms/Dynamic_Programming/README.md#i)
  - _1. Keyword:_ Maximum
  - _2. Optimal Substructure?_ Yes, Does smaller solution cumulate to give bigger solution? Yes gain is calculated by careful selection of element.
  - _3. Greedy solution does not fit:_ Take example:`[5, 5, 5, 6, 6, 6, 6, 7, 7]`if we greedily choose 6. Gain would be 24, but 5's and 7's gain becomes 29

<a name=l1></a>
### Logic = [DP Template](/DS_Questions/Algorithms/Dynamic_Programming/README.md#tem)
- _1._ Create a hash map of number and times its occuring. Number of times is the gain.
```c
  key   Value=Gain
  5     15
  6     24
  7     14
```
- _2. State_ = Gain on choosing particular number.
- _3._ Define a function to return gain
```c
int gain(int i) {
}
```
- _4. Recoccurance Relation:_ Deriving gain from selection of prev, next available numbers.
