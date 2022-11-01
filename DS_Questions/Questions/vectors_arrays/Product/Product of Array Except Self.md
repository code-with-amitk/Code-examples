**Product of Array Except Self**
- [Approach-1, Brute-Force: Find product of all elements, Divide by number, But uses / operator hence invalid O(n)](#a1)
- [Approach-2](#a2)


### [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self)
- Given an array `arr[]` construct a Product Array `prod[]` (of same size) such that `prod[i]` is equal to the product of all the elements of `arr[]` except `arr[i]`.
- **Should be acheived:**
  - **Space Complexity: O(1)**
  - **Time Complexity: O(n)**
  - **Without Division Operator**
```c
Example-1:
  Input = {1,2,3,4}
  Output = {24,12,8,6}      //24=2*3*4, 12=1*3*4, 8=1*2*4

Example-2:
  Input = {10,3,5,6,2}
  Output = {180,600,360,300,900}    //180=3*5*6*2, 600=10*5*6*2 so on
```

<a name=a1></a>
### Approach-1, Brute-Force: Find product of all elements, Divide by number. O(n)
- **BUT It uses division operator. Hence INVALID**
#### Logic
- Find complete product and replace `nums[i] = product/nums[i]`
```c
[1,2,3,4]
product = 24	//O(n)

[24/1, 24/2, 24/3, 24/4]
```
#### Code
```cpp
class Solution {
public:
using vec1d = std::vector<int>;
    vector<int> productExceptSelf(vector<int>& nums) {
        int64_t all_product = 1;
        int zeroIndex = -1;
        int times = 0;
        bool hasZero = false;
        
        for (int i=0;i<nums.size();++i) {
            if (nums[i]!=0)
                all_product *= nums[i];
            else {
                hasZero = true;
                zeroIndex = i;
                times++;
                if(times==2) {
                    int i=0;
                    while(i<nums.size())                
                        nums[i++]=0;
                    return nums;
                }
            }
        }
        
        if(hasZero){
            for (int i=0;i<nums.size();++i){
                if(zeroIndex == i)
                    nums[i] = all_product;
                else
                    nums[i]=0;
            }
            return nums;
        }
        
        for (int i=0;i<nums.size();++i){
            if (nums[i])
                nums[i] = all_product/nums[i];
        }
        return nums;
    }
};
```

<a name=a2></a>
### Approach-2   //Left and Right Product arrays //Space:O(n), Time:O(n)
~[ImgURL](https://leetcode.com/problems/product-of-array-except-self/Figures/238/diag-1.png)

#### Logic
  - Calculate left and right product arrays.
  - Output array = `leftArray*RightArray` 
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
#### Complexity
- **Time:** 3O(n)
- **Space:** 3O(n)       


### Approach-4    //Space:O(n), Time:2O(n)
- **logic:**
  - *1.* Traverse from left to right, Find Left Product array store in output array (instead of left Array).
  - *2.* Traverse from Right to Left, Store running product in variable and update output array.
```c

in		2		3		4		5
      		0   		1   		2   		3

out		1		1		1		1

Traverse from left to right, Find Left Product array store in output array.   //1
out[0]=1
from 0 to n
out[i] = out[i-1] * in[i-1]

out		1		1*2		2*3		6*4
		1		  2		 6		 24
		
Traverse from Right to Left.              //2
 - Store running product in variable
int var = 1;
from n to 0
out[i] = out[i]*var
var = var*in[i]

in		2		      3		     4		      5
out		1		      2   	     6  	     24

 							       	     24*1 //out*var
								     var=5
						   6*5 //out*var
						   var=5*4
						   
				      2*20  //out*var          
    				     var=20*3
		1*60  //out*var
		
		60		20		30		24
```
- **Code**
```c
class Solution {
public:
using vec1d = std::vector<int>;
    vector<int> productExceptSelf(vector<int>& nums) {
        vec1d out(nums.size(), 1);

        for (int i=0;i<nums.size();++i){
          if (i==0)
            out[i] = 1;
          else
            out[i] = out[i-1]*nums[i-1];
        }

        int var = 1;
        int j = nums.size()-1;
        while(j>=0){

            out[j] *= var;
            var *= nums[j];
          --j;
        }

        return out;
    }
};
```
