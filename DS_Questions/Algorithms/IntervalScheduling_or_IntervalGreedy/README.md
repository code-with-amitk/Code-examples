**Interval Scheduling /Interval Greedy**
- [Use case](#uc)
- [Problem](#p)
- [Step by Step Algorithm](#al)
- Problems
  - [Non-overlapping Intervals](/DS_Questions/Questions/vectors_arrays/Intervals/Non-overlapping_Intervals.md)

### Interval Scheduling /Interval Greedy
<a name=uc></a>
#### Use case
- Finding non-overlapping intervals or maximizing the number of non-overlapping intervals.

<a name=p></a>
#### Problem
- Find non overlapping intervals?
```c
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
  -----------
   ---- ---- ---- 
--|----|----|----|--
  1    2    3    4

O/P (Non overlapping intervals): 3
[1,2],[2,3],[3,4]
```

<a name=al></a>
#### Step-by-Step Algorithm
- _1._ Sort the intervals based on their end times(or start times, depending on the problem).
```c
input intervals =  [[1,2],[2,3],[3,4],[1,3]]
sorted intervals = [[1,2],[2,3],[1,3],[3,4]]
```
- _2._ Take temp as 1st pair
```c
  temp = [1,2].  a1=1, b1=1
```
- _3._ Iterate through the sorted intervals from i=1
```c
  i=1  a2=2, b2=3
  if (b1 > a2)
    - This is overlapping interval
  else
		b1 = b2		//point a to next element, because we need to reach element where b1 > a2
```
