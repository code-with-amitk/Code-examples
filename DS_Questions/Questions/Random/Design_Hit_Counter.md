**Design Hit Counter**
- [Approach-1, Linear Search](#a1)

### [Self Video(Linear Search)](https://youtu.be/jW9BETuQaqw)

### [Design Hit Counter](https://leetcode.com/problems/design-hit-counter/)
- Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the **past 300 seconds**).
- Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.
```c
Input
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
Output
[null, null, null, null, 3, null, 4, 3]

Explanation
HitCounter hitCounter = new HitCounter();
hitCounter.hit(1);       // hit at timestamp 1.
hitCounter.hit(2);       // hit at timestamp 2.
hitCounter.hit(3);       // hit at timestamp 3.
hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
hitCounter.hit(300);     // hit at timestamp 300.
hitCounter.getHits(300); // get hits at timestamp 300, return 4.
hitCounter.getHits(301); // get hits at timestamp 301, return 3.
```

### Approach-1, Linear Search
#### Logic
- _1._ Save timestamps in `vector<uint32_t>` since `1 <= timestamp <= 2 * 10<sup>9</sup>`
- _2._ When getHits() request comes check from last all timestamps whose difference is less than 300.
```c
vector  |1 2 3 300

getHits(4)    4-3<300, 4-2<300, 4-1<300   count=3

getHits(301)      301-300<300(y)    301-3=298<300(y)    301-2=299<300(y)    301-1=300<300(n)    Count=3
```
#### Code
```cpp
class HitCounter {
    vector<uint32_t> v;
public:
    HitCounter() {}
    
    void hit(int timestamp) {
        v.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int count = 0;
        int size = v.size();
        if (!size)
            return 0;
        while (size && timestamp - v[size-1 ] < 300) {
            count++;
            size--;
        }
        return count;
    }
};
```

#### Complexity
- **Time:** O(n)
- **Space:** O(n)
