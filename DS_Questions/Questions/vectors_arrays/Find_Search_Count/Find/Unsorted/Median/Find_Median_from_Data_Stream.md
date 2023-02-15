**Find Median from Data Stream**
- [Approach-1. `vector<int>`, push_back(), sort. O(nlogn). TLE](#a1)
- [Approach-2. `vector<int>`. binary search position. insert. O(n). TLE](#a2)
- [Approach-3. `multiset<int>`. O(logn) + O(n/2) = O(n/2). Works](#a3)
- [Approach-4. maxHeap, minHeap. O(logn). Works](#a4)

### [295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/description/)
- The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
```c
For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:
```
- MedianFinder() initializes the MedianFinder object.
- void addNum(int num) adds the integer num from the data stream to the data structure.
- double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
```c
Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
```

**Note: Median is always calculated from sorted array**

<a name=a1></a>
### Approach-1. `vector<int>`, push_back(). sort(). O(nlogn). TLE
#### Logic
- _1._ Take a `vector<int>`
- _2._ add(): insert element at back & sort()
- _3._ findMedian():
```c
    if (odd number of elements in vector)
        return vector[mid]
    else
        return (vector[mid] +vector[mid-1])/2
```
#### Complexity
- **Time:** findMedian()=O(nlogn)
#### Code
```cpp
class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size%2)   //Odd number of entries
            return (double)nums[size/2];
        else        //Even entries
            return (double)(nums[size/2] + nums[size/2-1])/2;
    }
};
```

<a name=a2></a>
### Approach-2. `vector<int>`. binary search position. insert. TLE. O(logn + n/2)
#### Logic
- _1._ add() 
  - Search the position where new element need to be added. O(logn)
  - After element is searched, insert new element. This can take O(n) since elements need to be shifted
- _2._ findMedian() O(1)
#### Complexity
- **Time:** O(logn) + O(n) = O(n)
  - Binary Search takes O(logn) time to find correct insertion position.
  - Insertion can take up to O(n) time since elements have to be shifted inside the container to make room for the new element.
- **Space:** O(n)
#### Code
```cpp
class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() { }
    void addNum(int num) {
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
    }
    
    double findMedian() {
        int size = nums.size();
        if (size%2)   //Odd number of entries
            return (double)nums[size/2];
        else        //Even entries
            return (double)(nums[size/2] + nums[size/2-1])/2;
    }
};
```

<a name=a3></a>
### Approach-3. `multiset<int>`. O(logn) + O(n/2) = O(n/2). Works
#### Logic
- _1._ Take a `multiset<int> m`
- _2._ m.insert(ele). 
  - set is internally [Self Balanced RB Tree](/Languages/Programming_Languages/c++/Standard_Template_Library/container_library/associative_containers/).
  - insert(): O(logn)
- _3._ findMedian():
  - Move to middle of set(). [std::advance() has linear time complexity](https://en.cppreference.com/w/cpp/iterator/advance) O(n/2)
  - if set has odd elements. return middle
  - if even elements. return (middle + middle-1)/2
#### Complexity
- **Time:** O(logn) + O(n/2) = O(n/2)
- **Space:** O(n)
#### Code
**CPP**
```cpp
class MedianFinder {
    multiset<int> nums;
public:
    MedianFinder() { }
    void addNum(int num) {
        nums.insert(num);
    }
    
    double findMedian() {
        std::set<int>::iterator it = nums.begin();
        std::advance(it, nums.size() / 2);
        if (nums.size()%2)        //Odd element
            return (double)*it;
        std::set<int>::iterator itp = prev(it, 1);
        return (double)(*it+*itp)/2;
    }
};
```

<a name=a4></a>
### Approach-4. maxHeap, minHeap. O(logn). Works
#### Logic
```c
input = [4, 5, 2, 7, 1, 8, 3, 6]

if array if sorted: 1,2,3,4,5,6,7,8
    max_heap            min_heap
    /   4  \            /  5  \
   / 2  1 3 \          / 8 6 7 \
   ----------          ---------
```
- _1._ Take 2 heaps. max_heap, min_heap.
  - max_heap will store lower half elements
  - min_heap will store upper half elements
  - Then median =
```c
    if (max_heap.size() == min_heap.size())
        median = (max_heap.top() + min_heap.top() )/2
    else
        median = max_heap.top()
```
- _2._ Rules of adding into heaps
