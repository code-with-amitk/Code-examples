## [Adding elements of an array until every element becomes greater than or equal to k](https://www.geeksforgeeks.org/adding-elements-array-every-element-becomes-greater-k/)
- Given a list of N unsorted elements, we need to find minimum number of steps in which the elements of the list can be added to make all the elements greater than or equal to K. We are allowed to add two elements together and make them one.
- Example:
```c
Input: arr[] = {1 10 12 9 2 3},   K = 6
Output: 2
Step-1: {3 10 12 9 3}   //1+2
Step-1: {6 10 12 9}   //3+3
```

### 1. Approach-1   //Brute Force. O(n<sup>2</sup>)
- **Logic**
  - *1.* sort the input array. `{1 2 3 9 10 12}`
  - *2.* Keep adding elements in for loop until find sum>=k.
```c
{3 3 9 10 12}
{6 9 10 12}
```
- **Complexity**
  - **Space:** O(n)
  - **Time:** O(nlogn) + O(n<sup>2</sup>)
    - O(nlogn): sorting
    - O(n<sup>2</sup>): Searching in sorted array. Because we need 2 for() loops to check and add elements.

### 2. Approach-2   //minHeap.  O(n)
- **Logic**
  - *1.* Push all elements which are smaller than k into minHeap `{1 2 3}`
  - *2.* Pop top, keep adding top to prev top until top>=k. Then make top=0. count the steps.
- **Complexity**
  - **Space:** O(n). Heap Created. Considering all elements are smaller than k.
  - **Time:** O(n)
    - Traversal of input array to create minHeap. O(n)
    - Iterating thru minHeap, adding top and finding count. O(n). Since minHeap size=n. top will be O(1)
- **Code**
```c++
int fun(std::vector<int>& v, int k){

  //minHeap to store all elements smaller than k  {1 2 3}
  std::priority_queue<int, std::vector<int>, std::greater<int>> MinHeap;
  
  int MinTotal = 0;
  
  for(auto i:v){
    if(i<k){
      MinHeap.push(i);
      MinTotal += i;
    }
  }
  
  //if total of minimum elements < k. return 0
  if(MinTotal<k)
    return 0;

  int MinHeapSize = minHeap.size();
  int count = 0, top=0;
  
  while(MinHeap.empty() != 1){
  
    //Increment count only after adding 2 elements from heap
    if(top!=0)
      ++count;
    top += MinHeap.top(); MinHeap.pop();
    if (top >= k)
      top=0;
  }

  //if some element was left on Heap and (numberofelements in array>minHeapSize). increment count by 1
  if(top!=0 and MinHeapSize < v.size())
    ++count;

  return count;
}

int main(){
  std::vector<int> a = {1,10,12,9,2,3}; int k=6;
  std::cout<<fun(a,k);
}
```
