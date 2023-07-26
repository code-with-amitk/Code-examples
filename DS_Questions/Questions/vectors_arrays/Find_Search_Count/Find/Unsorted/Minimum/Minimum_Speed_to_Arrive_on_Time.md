**Minimum Speed to Arrive on Time**
- [Approach-1. Linear Search. TLE](#a1)
- [Approach-2. Binary Search. O(log(10000000))=7](#a2)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP98](#cpp98)
    - [CPP11](#cpp11)
    - [Python](#py)

### [1870. Minimum Speed to Arrive on Time](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/)
- You are given a floating-point number hour, representing the amount of time you have to reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.
- Each train can only depart at an integer hour, so you may need to wait in between each train ride.
- For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.
- Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.
- Tests are generated such that the answer will not exceed 107 and hour will have at most two digits after the decimal point.
 
```c
Example 1:
Input: dist = [1,3,2], hour = 6
Output: 1
Explanation: At speed 1:
- The first train ride takes 1/1 = 1 hour.
- Since we are already at an integer hour, we depart immediately at the 1 hour mark. The second train takes 3/1 = 3 hours.
- Since we are already at an integer hour, we depart immediately at the 4 hour mark. The third train takes 2/1 = 2 hours.
- You will arrive at exactly the 6 hour mark.

Example 2:
Input: dist = [1,3,2], hour = 2.7
Output: 3
Explanation: At speed 3:
- The first train ride takes 1/3 = 0.33333 hours.
- Since we are not at an integer hour, we wait until the 1 hour mark to depart. The second train ride takes 3/3 = 1 hour.
- Since we are already at an integer hour, we depart immediately at the 2 hour mark. The third train takes 2/3 = 0.66667 hours.
- You will arrive at the 2.66667 hour mark.
```

### Approach-1. Linear Search. TLE
#### [Logic](#l)
#### Code
**CPP**
```cpp
class Solution {
public:
    int round_to_next_int(double val) {
        if (val - int(val))
            return val+1;
        return val;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // Linear Search 
        double speed = 1, calc_time = 0;
        do {
            calc_time = 0;
            for (int i=0;i<dist.size()-1;++i)
				      calc_time += round_to_next_int(((double) dist[i])/speed);
            
            calc_time += ((double)dist.back())/speed;

			      // if I am reaching late, increse speed
            if (calc_time > hour)
                speed++;
        } while (calc_time > hour);
        return speed;
    }
};
```

<a name=a2></a>
### Approach-2. Binary Search. O(logn). n=10<sup>7</sup>. Time=7
<a name=l></a>
#### Logic
- _1._ {Intution} We know time = distance/speed.
  - Divide distance by speed.
  - For all stations(except last) Round to next integer. For last station take decimal as it is.
```c
Expected time to complete = 2.7
        Speed       -----------dist------------      Time
                    1            3        2
Taking speed=1      1/1=1      3/1=3      2/1=2      1+3+2=6        //Taking more time than expected. Increase speed
Taking speed=2      1/2=.5     3/2=1.5    2/2=1
                    rounded=1    2          1      1+2+1=4        //Taking more time than expected. Increase speed
Taking speed=3      1/3=.33      3/3=1    2/3=.67
                    rounded=1      1          .67  1+1+.67=2.67   //Taking less time than expected. This is answer
```
- _2._ Perform binary search between (1, 10<sup>7</sup>) taking these as speeds.

<a name=com></a>
#### Complexity
- **Time:** O(logn)
- **Space:** O(1)
#### Code
<a name=cpp98></a>
**CPP98**
```cpp
class Solution {
public:
    int round_to_next_int(double val) {
        if (val - int(val))
            return val+1;
        return val;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        // Binary Search 
        double min_speed = 1, max_speed = pow(10,7);
        int out = -1;

        while (min_speed <= max_speed) {
            double calc_time = 0;
            int mid_speed = (min_speed + max_speed) / 2;

            for (int i=0;i<dist.size()-1;++i)
                calc_time += round_to_next_int(((double) dist[i])/mid_speed);

            calc_time += ((double)dist.back())/mid_speed;

            if (calc_time > hour) {
                // We are taking more time than required. Incresed speed
                min_speed = mid_speed + 1;
            } else {
                // reduce speed
                out = mid_speed;                
                max_speed = mid_speed - 1;
            }
        }
        // We will get the answer when min_speed >= max_speed.
        return out;
    }
};
```

**Python**
```py
import math
class Solution:
    def __init__(self):
        self.min_speed = 1
        self.max_speed = 10000000
        self.out = -1

    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        # Binary Search

        while self.min_speed <= self.max_speed:
            calc_time = 0.0

	    # // is floor division. 3//2 = 1
	    # / is division.        3/2  = 1.5
            mid_speed = (self.min_speed + self.max_speed) // 2

            for i in range(0, len(dist)-1):
                calc_time += math.ceil(dist[i] / mid_speed)		#math.ceil() to round it up to the next integer.

            # Keep decimal part and add to calc_time
            calc_time += dist[-1] / mid_speed

            if calc_time > hour:
                # We are taking more time than required. Increase speed
                self.min_speed = mid_speed + 1
            else:
                # reduce speed
                self.out = mid_speed
                self.max_speed = mid_speed - 1

        return int(self.out)
```
