**Minimum Time Difference**
- [Approach-1. O(nlogn)](#a1)
  - [Logic](#l)
  - [Complexity](#c)
  - Code
    - [CPP](#cpp)

### Minimum Time Difference
- Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
```c
Example 1:
Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
```

<a name=a1></a>
### Approach-1. Sort (nlogn)
<a name=l></a>
#### Logic
