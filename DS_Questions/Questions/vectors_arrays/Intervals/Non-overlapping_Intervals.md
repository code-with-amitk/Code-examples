**Non-overlapping Intervals**
- [Approach-1. Interval Scheduling algorithm](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - CPP
      - [CPP98](#cpp)
      - [CPP11](#cpp11)
    - [Python](#py)

### [Self Video](https://youtu.be/xSnNzrYM1y8)

### [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/)
- Given an array of intervals intervals where `intervals[i] = [starti, endi]`, return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
- consider intervals on number line
```c
Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
```

<a name=a1></a>
### Approach-1
<a name=l></a>
#### Logic
- [Interval Scheduling Algorithm](/DS_Questions/Algorithms/IntervalScheduling_or_IntervalGreedy)

<a name=com></a>
#### Complexity
- **Time:** O(nlogn). sort
- **Space:** O(1)
#### Code
<a name=cpp></a>
**CPP98**
```cpp
bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int out = 0;

		if (!intervals.size()) 
            		return 0;

		/*	Sort on endi
			[[1,2],[2,3],[3,4],[1,3]]
			becomes
			[[1,2],[1,3],[2,3],[3,4]]
		*/
		sort(intervals.begin(),intervals.end(),comp);

		// Take endi of 1st interval
		int b1 = intervals[0][1];

		/*	if (present_endi > next_starti)
				- out++. This is overlapping interval
			else
				- point a to next element, because we need to reach element 
				- where present_endi > next_starti
		*/
		for(int i=1;i<intervals.size();++i) {
      			int a2 = intervals[i][0], b2 = intervals[i][1];
			if(b1 > a2)
				out++;
      			else
        			b1 = b2;
		}
		return out;
	}
};
```
<a name=cpp11></a>
**CPP11(Advanced)**
```cpp
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       		int out = 0;

        	if (!intervals.size())
			return 0;

    		/*	Sort on endi
    			[[1,2],[2,3],[3,4],[1,3]]
    			becomes
    			[[1,2],[1,3],[2,3],[3,4]]
    		*/                                            //[] lambda not taking any outside param
		std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            		return a[1] < b[1];
        	});

        	int b1 = intervals[0][1];
    		/*	if (present_endi > next_starti)
    				- out++. This is overlapping interval
    			else
    				- point a to next element, because we need to reach element 
    				- where present_endi > next_starti
    		*/                                                  //& = lambda taking all outside param
		std::for_each(intervals.begin()+1, intervals.end(), [&](const vector<int>& v) {
			int a2 = v[0], b2 = v[1];
			if (b1>a2)
				out++;
			else
				b1 = b2;
		});
        return out;
    }
};
```

<a name=py></a>
**Python**
```py
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        out = 0
        """
            Sort on endi
			[[1,2],[2,3],[3,4],[1,3]]
			becomes
			[[1,2],[1,3],[2,3],[3,4]]
		""" 
        def custom_comparator(s):
            return s[1]
        intervals = sorted(intervals, key=custom_comparator)

        b1 = intervals[0][1]

        for (a2,b2) in intervals:
            if b1 > a2:
                out += 1
            else:
                b1 = b2
        
        return out-1
```
