### Problem
- Convert `[5,2,0,3,0,1,6,0]` to `[1,2,3,5,6,0,0,0]` in the most efficient way.
 
### Complexity
- 
 
### Code
```c++
using vec = std::vector<int>;

class Solution {
public:
    void moveZeroes(vec& nums) {
        int i=0, j=nums.size()-1;
        while (i<j){
            if (nums[i] == 0 and nums[j] != 0)
                std::swap(nums[i],nums[j]);
            while (nums[i] != 0)
                ++i;
            while (nums[j] == 0)
                --j;
        }

        //Sort from begin to index j
        if(i>0)
        std::sort(nums.begin(), nums.begin()+i);
    }
};
```
