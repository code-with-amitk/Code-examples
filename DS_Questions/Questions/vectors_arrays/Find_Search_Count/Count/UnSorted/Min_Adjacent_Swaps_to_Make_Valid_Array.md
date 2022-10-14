**Minimum Adjacent Swaps to Make a Valid Array**
- [Approach-1, O(n). Find min,max indexes and swap](#a1)

### [Minimum Adjacent Swaps to Make a Valid Array / Count Swaps to Make a Valid Array](https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/)
- Only Swaps of adjacent elements are allowed
- Make a valid array meets the following conditions:
  - The largest element (any of the largest elements if there are more than 1) is at the rightmost position in the array.
  - The smallest element (any of the smallest elements if there are more than 1) is at the leftmost position in the array.
- Return the minimum swaps required to make valid array.
- Examples
```c
Input: nums = [3,4,5,5,3,1]
               0 1 2 3 4 5
Output: 6
  Indexes of min element: 5
  Indexes of max elements: {2,3}
  Goal: Shift min to index=0(leftmost) and max to index=5(rightmost)

Explanation: Perform the following swaps:
- Swap 1: Swap the 3rd and 4th elements, nums is then [3,4,5,3,5,1].
- Swap 2: Swap the 4th and 5th elements, nums is then [3,4,5,3,1,5].
- Swap 3: Swap the 3rd and 4th elements, nums is then [3,4,5,1,3,5].
- Swap 4: Swap the 2nd and 3rd elements, nums is then [3,4,1,5,3,5].
- Swap 5: Swap the 1st and 2nd elements, nums is then [3,1,4,5,3,5].
- Swap 6: Swap the 0th and 1st elements, nums is then [1,3,4,5,3,5].
It can be shown that 6 swaps is the minimum swaps required to make a valid array.
```

<a name=a1></a>
### Approach-1, O(n). Find min,max indexes and swap
#### Logic
- _1._ Find all indexes of min and max elements.
```c
nums = [3,4,5,5,3,1]
        0 1 2 3 4 5
  
  min_element   max_element_indexes   max_element   max_element_indexes
    1           {5}                   5             {2,3}
```
- _2._ Number of steps
```c
steps += sizeof(arr) - last_index_of_max_element
steps += 1st_index_of_min_element

if (last_index_of_max_element < 1st_index_of_min_element)   //max and min element cross
  steps -= 1;
```
#### Code
```c
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int min = INT_MAX, max = INT_MIN;
        vector<int> min_indexes, max_indexes;
        
        for (int i=0; i< nums.size(); ++i) {  //O(n)
          
            //Find all indexes of max elements
            if (nums[i] > max) {
                max = nums[i];
                max_indexes.clear();
                max_indexes.push_back(i);
            }
            else if (nums[i] == max)
                max_indexes.push_back(i);
            
            //Find all indexes of min elements
            if (nums[i] < min) {
                min = nums[i];
                min_indexes.clear();
                min_indexes.push_back(i);
            }
            else if (nums[i] == min)
                min_indexes.push_back(i);
        }
      
        //Find Steps. O(1)
        int steps = 0;
        if (max_indexes.back() < min_indexes.front())
            steps -= 1;
        steps += nums.size() - 1 - max_indexes.back();
        steps += min_indexes[0];
        
        return steps;
    }
};
```
#### Complexity
- **Time** O(n)
- **Space:** O(n)
