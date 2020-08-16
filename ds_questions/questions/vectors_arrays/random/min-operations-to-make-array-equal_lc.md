## [LeetCode](https://leetcode.com/contest/weekly-contest-202/problems/minimum-operations-to-make-array-equal/)

### Problem
- Given a array of length n where arr[i] = (2 * i) + 1 for all valid values of i (i.e. 0 <= i < n).
- In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] (i.e. perform arr[x] -=1 and arr[y] += 1). 
- The goal is to make all the elements of the array equal.
- Given an integer n, the length of the array. Return the minimum number of operations needed to make all the elements of arr equal.

### Examples
```
Input: n = 3
Output: 2
Explanation: arr = [1, 3, 5]
First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].

Input: n = 6
Output: 9
```

### Logic
- No need to take array.
- We know 1st element is always first=1 and last = 2(n-1)/2
- Calculate average of 1st and last element.
  - avg = first+last/2;
  - steps=avg - first;
- Now we have 1st and last elements equal.
- Take next element as first+=2 and penultimate element as last -=2.
- Again calculate averge and increment firt and decrement last
```
int minOperations(int n) {
  if(!n || n==1)
    return 0;

  int first=1, last=2*(n-1)+1;
  int avg=(last+first)/2, steps=0;

  while(last > first){
    steps += avg - first;
    first += 2;
    last -= 2;
  }
  return steps;        
}
```
