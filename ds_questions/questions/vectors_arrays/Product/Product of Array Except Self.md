### [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self)
- Given an array arr[] construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. 
- Solve in Time:O(n), Space:O(1)
```c
Example-1:
  Input = {1,2,3,4}
  Output = {24,12,8,6}      //24=2*3*4, 12=1*3*4, 8=1*2*4

Example-2:
  Input = {10,3,5,6,2}
  Output = {180,600,360,300,900}    //180=3*5*6*2, 600=10*5*6*2 so on
```
### Approach-1(Brute-force)/Naive: O(n<sup>2</sup>)
- Run 2 nested for() loops, Calculate the product and store in 2nd array

### Approach-2    //Space:3O(n), Time:3O(n)
- **Logic:** 
  - Calculate left and right product arrays.
  - Output array = leftArray*RightArray
- **Complexity**
  - **Time:** 3O(n)
  - **Space:** 3O(n)        
```c
a[]   =     {2, 3, 4, 5}
             0  1  2  3
                                                                                    Time        Space
leftArr  = 1                  a[0]                    a[0]*a[1]   a[0]*a[1]*a[2]    //O(n)      O(n)
RightArr = a[1]*a[2]*a[3]     a[2]*a[3]               a[3]        1                 //O(n)      O(n)
                   
out = leftArr*RightAr                   
out[]    = a[1]*a[2]*a[3]     a[0]*a[2]*a[3]     a[0]*a[1]*a[3]   a[0]*a[1]*a[2]    //O(n)      O(n)
```
- **Code**
```c++
  using vec1d = std::vector<int>;
    vector<int> productExceptSelf(vector<int>& nums) {      //vec1d nums = {1,2,3,4};
        vec1d out(nums.size(), 1);
        vec1d left(nums.size(), 1);
        vec1d right(nums.size(), 1);

        for (int i=0;i<nums.size();++i){
          if (i==0)
            left[i] = 1;
          else
            left[i] = left[i-1]*nums[i-1];
        }

        int j = nums.size()-1;
        while(j>=0){
          if (j == nums.size()-1)
            right[j] = 1;
          else
            right[j] = right[j+1]*nums[j+1];
          --j;
        }

        for (int i=0;i<nums.size();++i)
              out[i] = left[i]*right[i];

        return out;
    }
```

### Approach-3    //Space:3O(n), Time:3O(n)
