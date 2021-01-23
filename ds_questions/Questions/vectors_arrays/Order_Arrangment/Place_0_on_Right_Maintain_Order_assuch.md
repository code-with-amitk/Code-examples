### [Move Zeros](https://leetcode.com/problems/move-zeroes/)
- Given an array nums, Move all 0's to the end of it while maintaining the relative order of the non-zero elements.
- Example
```c++
  Input: [0,1,0,12,3]
  Output: [1,12,3,0,0]
```

### Logic (2 pointer approach, Both starting from start)
- **Example-1:**
```c++

   0  1  0  12  3
   i  j           //1. swap element when num[i]==0 and num[j]!=0.
   
   1  0  0  12  3
      i  j       //2. Increment j till it points to non-zero element

   1  0  0  12  3
      i     j    //swap and increment i,j

   1  12  0  0  3
          i     j   //swap

    1  12  3  0  0
```
- **Example-2:**
```c++
    4  2  4  0  0  3  0  5  1  0
    i  j                            //Increment i and j till i points to 1st zero element
    
    4  2  4  0  0  3  0  5  1  0    
             i  j                   //Perform steps as mentioned in example-1
```
- **Logic:**
  - *1.* Take pointer i and pointer j, pointing to 1st and 2nd element of array.
  - *2.* Increment i till it points to 1st 0 element of array
  - *3.* Increment j till it points to 1st non-zero element of array
    - Once `num[i]==0 and num[j]!=0` swap both elements.

### Complexity
- **Time:** O(n+m)
  - O(n): Total number of elements
  - O(m): Non-zero elements
- **Space:** O(1) //No extra space

### Code
```c++
class Solution {
public:
    void moveZeroes(vec& nums) {
        int i = 0, j = 1;                 //1
        int size = nums.size();

        while (j < size){
          if(nums[i] == 0 and nums[j] != 0){
            std::swap (nums[i], nums[j]);
            ++i; ++j;
          }

          while(i<size and nums[i] != 0){
            ++i;
            ++j;
          }

          while(j<size and nums[j] == 0)
            ++j;

          if(j==size or i==size)
            break;
        }

    }
};
```
