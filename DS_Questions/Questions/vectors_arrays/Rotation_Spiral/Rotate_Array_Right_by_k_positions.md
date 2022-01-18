**Rotate Array in O(1) Space**
- **Approach-1: Using Stack. Space:O(k), Time:O(n)**
  - [Logic](#l1)
  - [Complexity](#c1)
- **Approach-2: Using 3 reverse. Space:O(1), Time:O(n)**
  - [Logic](#l2)
  - [Complexity](#c2)
  - [Code](#co2)
- **Approach-3: Shift 1 element to right at a time. Space:O(1), Time:O(nk)**
  - [Logic](#l3)
  - [Complexity](#c3)
  - [Code](#co3)

##  [Rotate Array](https://leetcode.com/problems/rotate-array/)
Array is given and number of times it needed to be rotated is given. Return rotated array
```c
Input: arr[] = [1,2,3,4,5,6,7], k = 3
Output: [5, 6, 7, 1, 2, 3, 4]

7 1 2 3 4 5 6   //1st rotation
6 7 1 2 3 4 5   //2nd rotation
5 6 7 1 2 3 4   //3rd Rotation
```
### Approach-1: Time:O(n), Space:O(k)
<a name=l1></a>
#### Logic
If rotation_size(K) > size_of_array(N). Calculate actual_rotation(K) = rotation_size(K) % size_of_array(N)
- Take stack and push last k elements on it
```c
[1,2,3,4,5,6,7], k=3
Push 7,6,5 on stack
|5|
|6|
|7|
```
- Copy 4 elements to right
```c
[1,2,3,1,2,3,4], k=3
Push 7,6,5 on stack
|5|
|6|
|7|
```
- Pop stack and copy on array
```c
[5,6,7,1,2,3,4]
```
<a name=c1></a>
#### Complexity
- Space: O(k). Stack
- Time: O(n)
  - O(k): Creating stack
  - O(n-k): shifting
  - O(k): Poping stack

### Approach-2: Using 3 reverse. Space:O(1)
<a name=l2></a>
#### Logic
If rotation_size(K) > size_of_array(N). Calculate actual_rotation(K) = rotation_size(K) % size_of_array(N)
- _1._ Reverse whole array
```c
[1,2,3,4,5,6,7], k=3
[7,6,5,4,3,2,1]
```
- _2._ Reverse array from 0 to k
```c
[7,6,5,4,3,2,1], k=3
[5,6,7,4,3,2,1]
```
- _3._ Reverse array from k+1 to end
```c
[7,6,5,4,3,2,1]. Reverse from 4 to end
 0 1 2 3 4 5 6
 
[5,6,7,1,2,3,4]
```
<a name=c2></a>
#### Complexity
- Space: O(1)
- Time: O(n). Reverse takes O(n)
<a name=co2></a>
#### Code
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size==1)
            return;
        
        k = k % size;
        if (!k)
            return;
        
        reverse (nums.begin(), nums.end());
        reverse (nums.begin(), nums.begin()+k);
        reverse (nums.begin()+k, nums.end());
    }
};
```

### Approach-3
<a name=l3></a>
#### Logic
- Copy last element and shift all elements right. Copy last to 1st
```c
[1,2,3,4,5,6,7], k=3
i = k = 3
  last=7, [1,2,3,4,5,6,7]
          [1,1,2,3,4,5,6] //copy all elements to right
          [7,1,2,3,4,5,6] //copy last to 1st
i=2          
  last=6, [7,1,2,3,4,5,6] 
          [7,7,1,2,3,4,5] //copy all elements to right
          [6,7,1,2,3,4,5] //copy last to 1st
i=1          
  last=5, [6,7,1,2,3,4,5]
          [6,6,7,1,2,3,4] //copy all elements to right
          [5,6,7,1,2,3,4] //copy last to 1st
```
<a name=c3></a>
#### Complexity
- Space: O(1)
- Time: O(nm)
<a name=co3></a>
#### Code
```c
void RightRotate(vector<int>& v, int k){
  k = k % v.size();
  if (k == 0)    //No rotation needed
    return;

  for (int i=0; i<k; ++i){  
    int last = v[v.size()-1];    
    for(int j = v.size()-1; j > 0; --j){
      v[j] = v[j-1];
    }
    v[0] = last;
  }
}
```
