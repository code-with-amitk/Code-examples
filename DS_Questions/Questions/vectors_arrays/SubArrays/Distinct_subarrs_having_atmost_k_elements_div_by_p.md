**K Divisible Elements Subarrays / Distinct subarrays having atmost k elements divisible by p**


### [K Divisible Elements Subarrays](https://leetcode.com/problems/k-divisible-elements-subarrays/)
- Given an integer array nums and two integers k and p, return the number of distinct subarrays which have at most k elements divisible by p.
```c
Example 1:
Input: nums = [2,3,3,2,2], k = 2, p = 2
Output: 11
Explanation:
The 11 distinct subarrays which have atmost k = 2 elements(atleast=0) & divisible by 2 are:
[2]       //1 element div by 2. atmost 2 elements div by 2
[2,3]     //1 element div by 2
[2,3,3]   //1 element div by 2
[2,3,3,2] //2 elements div by 2
[3]       //0 element div by 2
[3,3]     //0 element div by 2
[3,3,2]   //1 element div by 2
[3,3,2,2] //2 element div by 2
[3,2]     //1 element div by 2
[3,2,2]   //2 elements div by 2
[2,2]     //2 element div by 2

[2,3,3,2,2]   //Not counted.  //Has 3 elements div by 2
Note that the subarrays [2] and [3] occur more than once in nums, but they should each be counted only once.

Example 2:
Input: nums = [1,2,3,4], k = 4, p = 1
Output: 10
Explanation:
All element of nums are divisible by p = 1.
Also, every subarray of nums will have at most 4 elements that are divisible by 1.
Since all subarrays are distinct, the total number of subarrays satisfying all the constraints is 10.
```
