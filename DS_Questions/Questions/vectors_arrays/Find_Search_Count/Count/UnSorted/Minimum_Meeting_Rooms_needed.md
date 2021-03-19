## [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)
- Given an array of meeting time intervals intervals where `intervals[i] = [starti, endi]`, return the minimum number of conference rooms required.
- Examples:
```c
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2   //Minimum 2 conference rooms are required

Input: intervals = [[7,10],[2,4]]
Output: 1
```

### Approach-1  //Min Heap
#### Logic
  - *1.* if only 1 interval is given return 1, min 1 meeting room is needed.
  - *2a.* if more than 1 interval is given, Sort the intervals vector
```c
Example: [[0,30],[15,20],[5,10]]
Sorted:  [[0,30],[5,10],[15,20]]
```
  - *2b.* Traverse vector from start. Create a min Heap with key=EndTime
```c
    [30 0]    //30=key.   
    
count=1. 2 meeting rooms needed.    
```
  - *2c.* if (1st element of incoming vector(5) < top of min Heap(30)), This means element-2(ie meeting) will start before end of Earlier meeting and we need a new room. Increment meeting room count and insert element in min Heap.
```c
  [10, 5]
    \
    [30, 0]  
count=2. 2 meeting rooms needed.
```
  - *2d.* if (1st element of vector(15) > top of min Heap(10)), This means smallest meeting will get over and we will have free room. Delete top and insert new element.
```c
  [20, 15]
    \
    [30, 0]  
count=2. 2 meeting rooms needed.
```
#### Complexity 
>n: Total intervals in input array.
- **Space:** O(n)
  - Min Heap:
    - O(n): Addition to min Heap. Worst case of all elements are same, we keep on adding same as linked list.
- **Time:** O(nlogn)
  - O(nlogn): Sorting of array of n elements.
    - Min Heap:
      - O(n): Addition to min Heap. Worst case of all elements are same, we keep on adding same as linked list.
      - O(n): popping top of min Heap.
#### Code
```c
int minMeetingRooms(vector<vector<int>>& intervals) {
  int count = 1;
  priority_queue<mypair, vector<mypair>,greater<mypair>> pq;    //key=endTime

  if(intervals.size() == 1)
    return count;

  sort(intervals.begin(), intervals.end());

                    //key=endtime,value=starttime
  pq.push(make_pair(intervals[0][1], intervals[0][0]));
  mypair mp;

  for (int i=1;i<intervals.size();++i){

    mp = pq.top();

    if(intervals[i][0] < mp.first)
      ++count;
    else
      pq.pop();

    pq.push(make_pair(intervals[i][1], intervals[i][0]));
  }
  return count;
}

int main(){
  //vector<vector<int>> v = {{0,30},{5,10},{15,20}};
  //vector<vector<int>> v = {{7,10},{2,4}};
  vector<vector<int>> v = {{1,10},{2,7},{3,19},{8,12},{10,20},{11,30}};
  cout<<minMeetingRooms(v);
}
```
