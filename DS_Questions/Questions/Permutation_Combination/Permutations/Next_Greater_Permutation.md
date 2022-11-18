## [Next Permutation / Next Greater Permutation](https://leetcode.com/problems/next-permutation/)
- Return lexicographically next greater permutation of numbers.
- If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
- The replacement must be in place and use only constant extra memory.
- Examples
```c
Input: nums = [1,2,3]
Output: [1,3,2]

Input: nums = [1,1,5]
Output: [1,5,1]
```

## Approach-1 //STL next_permutation()
- **Complexity**
  - **Time:** [O(n)](http://www.cplusplus.com/reference/algorithm/next_permutation/)
  - **Space:* O(1)
- **Code**
```c
void nextPermutation(vector<int>& nums) {
  next_permutation(nums.begin(), nums.end());
}
```

## Approach-2
- **Logic**
```c
Example
Input: 1 5 8 4 7 6 5 3 1

Next Greater Permutation of above number would be:  1 5 8 5 7 6 4 3 1
```
  - *1.* Find 1st decreasing element from right
```c
  1 5 8 4 7 6 5 3 1
                  /\
  1 5 8 4 7 6 5 3 1
                /\
  1 5 8 4 7 6 5 3 1
              /\
  1 5 8 4 7 6 5 3 1
            /\
  1 5 8 4 7 6 5 3 1
          /\
  1 5 8 4 7 6 5 3 1   //Found 1st decresing element from right
        /\
```
  - *2.* Now find next greater element from 4 on its right
```c
  1 5 8 4 7 6 5 3 1
        | /\
  1 5 8 4 7 6 5 3 1
        |   /\        
  1 5 8 4 7 6 5 3 1   //5 is next greater element than 4. if we move to 3 its smaller
        |    /\        
```
  - *3.* Swap 4 and 5.
```c
  1 5 8 4 7 6 5 3 1
        |     |        

  1 5 8 5 7 6 4 3 1
        |     |
```
  - *4.* Reverse elements from 5 till end. This is next larger permutation.
```c
  1 5 8 5 7 6 4 3 1
        |     |
        
  1 5 8 5 1 3 4 6 7   //This is next larger permutation
```
- Example2
```c
Input: [3 2 1]   //No decreasing sequence. This means this is largest number and question says:
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

Output: [1 2 3]
```
- **Complexity**
  - **Time:** O(n) = O(n) + O(n)
    - O(n): Considering 1st greater number from back is found after traversing n elements.
    - O(n): Considering to swap elements we need to traverse all elements.
  - **Space:** O(1). No extra space
- **Code**
```c
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        
        int i = nums.size()-2;
        int j = nums.size()-1;

        while (i >=0  && nums[i+1] <= nums[i])
            --i;

        --i;

        if (i>=0){
            
            while(j>=0 && nums[j] <= nums[i])
                j--;

            swap(nums[i],nums[j]);
        }
        if (i+1 != j)
            reverse (nums.begin()+i+1,nums.end());
    }
```
