**K Closest Points to Origin**
- [Approach-1, sort, O(nlogn)](#a1)
- [Approach-2, minHeap, O(klogn)](#a2)

### [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)
- We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
- You may return the answer in any order.
- Examples
```c
Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).   //ans
```

<a name=a1></a>
### 1. Approach-1    //sort. Time:O(nlogn), Space:O(n)
- **Logic**
  - *1.* Traverse the 2d vector linearly, find distance of each point from origin and store in temporary array(temp). //O(n)
  - *2.* sort the temporary array in ascending order. //O(nlogn)
  - *3.* Find 1st k entries from array and return corresponding points. //O(k)
  
<a name=a2></a>
### 2. Approach-2    //minHeap. Time:O(klogn), Space:O(n)
#### Logic
  - *1.* Traverse the array, find distance of every point from origin. sqrt(a^2+b^2) and store in minHeap.
    - sqrt() would be double. And we know double float/double are intrinsically inaccurate. We will store (a^2+b^2)
    - minHeap will store smallest keys on top.
```c
double:8bytes, float:4bytes
  double b = 1.2 - 1.0;
  std::cout.precision(17);
  std::cout<<(double)b<<"\n";       //0.19999999999999996 (should be .2)
  
  minHeap
    key(a^2+b^2)   value(a,b)
    1+9=10          1,3
    4+4=8           -2,2
```
  - *2.* Pop k elements from minHeap.
#### Code
```c++
    using mpair = pair<long, pair<int,int>>;
    using vecVecI = vector<vector<int>>;
    vecVecI kClosest(vecVecI& points, int K) {
        if(points.size() == K)
            return points;

        vecVecI out;
        priority_queue <mpair, vector<mpair>, greater<mpair>> pq; //minHeap

        //Insert (a^2+b^2, point) into minHeap. O(logn)
        for (int i=0;i<points.size();++i) {
            long square = points[i][0]*points[i][0] + points[i][1]*points[i][1];            
            pair<int,int> point = {points[i][0], points[i][1]};
            pq.push({square,point});
        }

        //Pop k elements from minHeap. O(klogn)
        for (int i=0;i<k;++i) {
          mpair m = pq.top(); pq.pop();
          pair<int,int> p = m.second;
          vector<int> out1;
          out1.push_back(p.first);
          out1.push_back(p.second);
          out.push_back(out1);
          out1.clear();
        }
      return out;
    }
```
#### Complexity
- **Time:** O(klogn)
  - O(logn): [Insert element into minHeap complexity = O(logn)](/DS_Questions/Data_Structures/Queue/Priority_Queue/)
  - O(klogn): Remove k element into minHeap. [Removing 1 element O(logn)](/DS_Questions/Data_Structures/Queue/Priority_Queue/)
  - Traversing array once
- **Space:** O(3n)=O(n) Creating minHeap
