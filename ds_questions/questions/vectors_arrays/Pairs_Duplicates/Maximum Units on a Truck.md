## [Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/)
- You need to put some amount of boxes onto one truck. each box can have n number of units inside it.
- Input is a 2D Array representing different types of boxes to be placed on truck. Return the maximum total number of units that can be put on the truck.
```c++
Example-1:  boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
  
 TypeOfBox NoOfBoxes	UnitsInsideEachBox
    0	  	  1			    3
    1		    2			    2
    2		    3   			1 
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.    
    
Example-2:    
```

### Approach  //Priority-Queue or MaxHeap
- Create a MaxHeap/Priority-Queue of pair. <key=UnitsInsideEachBox, value=NoOfBoxes>  //O(n)
- Pop top of queue and fill in the boxes as per truckSize   //O(n)
### Complexity
  - **Time:** 2O(n)
  - **Space:** O(n)
### Code    
```c++
class Solution {
public: 
  using vec2d = std::vector<std::vector<int>>;
  using mpair = std::pair<int,int>;
  using PQ = std::priority_queue<mpair>;
    
  int maximumUnits(vec2d& boxTypes, int truckSize) {
    PQ pq;
    int count=0;
    for (int i=0;i<boxTypes.size();++i)
      pq.push({boxTypes[i][1], boxTypes[i][0]});

  while (truckSize>0 and pq.empty()!=1) {
    mpair p = pq.top();   pq.pop();
    int left = truckSize-p.second;

    if (left >= 0) {
      count += p.second*p.first;
      truckSize -= p.second;
    }else{  //negative left
      count += truckSize*p.first;
      break;
    }
  }
  return count;
    }
};
```
