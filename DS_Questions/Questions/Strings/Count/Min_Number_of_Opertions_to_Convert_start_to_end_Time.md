**Minimum Number of Operations to Convert Time**
- Approach
  - [Logic](#l)
  - [Code](#c)
  - [Complexity](#co)

### Minimum Number of Operations to Convert Time
- You are given two strings current and correct representing two 24-hour times.
- 24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
- In one operation you can increase the time current by 1, 5, 15, or 60 minutes. You can perform this operation any number of times.
- Return the minimum number of operations needed to convert current to correct.
- Examples
```c
Example-1:
Input: current = "02:30", correct = "04:35"
Output: 3
Explanation:
We can convert current to correct in 3 operations as follows:
- Add 60 minutes to current. current becomes "03:30".
- Add 60 minutes to current. current becomes "04:30".
- Add 5 minutes to current. current becomes "04:35".
It can be proven that it is not possible to convert current to correct in fewer than 3 operations.

Example-2:
Input: current = "11:00", correct = "11:01"
Output: 1
Explanation: We only have to add one minute to current, so the minimum number of operations needed is 1.
```

### Approach
<a name=l></a>
#### Logic
- _1._ Tokenize start_hours, start_min & end_hours, end_min and store in `vector<int>`
```c
start="02:30", end= "04:35"
vecStart[0] = 2, vecStart[1] = 30
vecEnd[0] = 4, vecEnd[1] = 35
```
- _2._ Calculate total minutes between start and end time.
  - if EndMin > startMin      (start=2:30, End=4:35)
    - minutes = (EndMin - startMin) + (EndHrs - StartHrs)*60
  - if EndMin < startMin      (start=2:30, End=8:13)
    - minutes = (EndMin+60 - startMin) + (EndHrs-1 - StartHrs)*60
- _3._ Calculate steps from minutes.
  - if (minutes > 60)
    - steps = minutes/60. minutes = minutes%60

<a name=c></a>
#### Code
```cpp
#include<sstream>
class Solution {
public:
    int convertTime(string current, string correct) {
        
        string temp;
        int val, minutes, steps=0;
        vector<int> vecStart; 
        vector<int> vecEnd;
        
        //Tokenize current
        stringstream ss(current);
        while (getline(ss, temp, ':')) {
            istringstream(temp) >> dec >> val;
            vecStart.push_back(val);
        }
        
        //Tokenize end
        stringstream ss1(correct);
        while (getline(ss1, temp, ':')) {
            istringstream(temp) >> dec >> val;
            vecEnd.push_back(val);
        }
        
        if (vecEnd[1] > vecStart[1]){
            minutes = vecEnd[1] - vecStart[1];
        }
        else
        {
            minutes = vecEnd[1]+60 - vecStart[1];
            vecEnd[0] -= 1;
        }
        minutes += (vecEnd[0] - vecStart[0])* 60 ;
        
        int k=0, minutes1;
        while (minutes) {
            if (minutes >= 60)
                k = 60;
            else if (minutes >= 15)
                k = 15;
            else if (minutes >= 5)
                k = 5;
            else if (minutes >= 1)
                k = 1;
            minutes1 = minutes;
            minutes %= k;
            steps += minutes1/k;
        }
        return steps;
    }
};
int main(){
    Solution s;
    //s.convertTime("02:30", "04:35");      //3
    //s.convertTime("11:00", "11:01");        //1
    s.convertTime("02:30", "08:13");      //12
}
```

<a name=co></a>
#### Complexity
- **Time:** O(1)
- **Space:** O(1)
  - 2 vectors to store start, end times of fixed sizes.
