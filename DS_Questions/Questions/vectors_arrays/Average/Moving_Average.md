## [Moving Average](https://leetcode.com/problems/moving-average-from-data-stream/)
- Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
- **What is moving average?**
  - A simple moving average is formed by computing the average over a specific number of periods, ie using window.
```c
Numbers: 11, 12, 13, 14, 15, 16, 17
Average of 1st 5-days: (11 + 12 + 13 + 14 + 15) / 5 = 13    //Window-1
Window moved by 1: (12 + 13 + 14 + 15 + 16) / 5 = 14
Window moved by 1: (13 + 14 + 15 + 16 + 17) / 5 = 15
```

- Implement the MovingAverage class:
```c
  MovingAverage(int size) Initializes the object with the size of the window size.
  double next(int val) Returns the moving average of the last size values of the stream.
  
Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]

Output: [null, 1.0, 5.5, 4.66667, 6.0]
Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
```

### Approach-1    //Vector
- **Logic**
  - *1.* Take a vector or doubles. Keep inserting elements at end
```c
if (number of elements < Window size)
  calculate average and return
else if (number of elements > Window size)
  Calculate averge over window and return
```
- **Complexity** m: Window size
  - **Time:** O(m). Will traverse m elements
  - **Space:** O(mxk). k times function to return 
- **Code**
```c++
class MovingAverage {
    int WindowSize;
    vector<double> vecElements;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        WindowSize = size;
    }
    
    double next(int val) {
        double dMovingAverage = 0.0;
        
        //Added Element
        vecElements.push_back(val);
        
        //Find Moving Average
        if(vecElements.size() <= WindowSize){
            //Find average of all
            for (auto i:vecElements)
                dMovingAverage += i;
            return dMovingAverage / vecElements.size();
        }else{
            //Find average from window
            int skip = vecElements.size() - WindowSize;
            for (int i = skip; i<vecElements.size(); ++i){
                dMovingAverage += vecElements[i];
            }
            return dMovingAverage / WindowSize;
        }
        return dMovingAverage;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```
