## [3sum](https://leetcode.com/problems/3sum/)
- Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
- Examples
```c++
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = []
Output: []

Input: nums = [0]
Output: []
```

## 1. Approach-1    //3 For loops. O(n<sup>3</sup>)
- 3 for loops check every element with each other
```c++
  vector<vector<int>> out;
  for(int i=0; i<nums.size(); ++i)
    for(int j=i+1; j<nums.size(); ++j)
      for(int k=j+1; k<nums.size(); ++k)
        if (nums[i]+nums[j]+nums[k] == 0)
          out.push_back({nums[i],nums[j],nums[k]});
  return out;    
```

## 2. Approach-2  //Sort + 3 pointer search
#### Logic
```c++
Array = {-1,0,1,2,-1,-4}
Step-1: Sort    {-4,-1,-1,0,1,2}    //O(nlogn)
Step-2: Fix 1st element, iterate thru rest of array to find if(Sum of 2 elements == -First_element)
  -4  -1  -1  0  1  2
   a   b            c
Step-3:
  if (-a == (sum=b+c)){    //4 == -1+2
    //Found triplet
  }else{
    if (sum < -a)         //1 < 4
      ++b;
    else
      --c;
  }
  
  -4  -1  -1  0  1  2     -a    sum=b+c
   a   b            c      4      1       (4>1) [Move b to next element ++b]

  -4  -1  -1  0  1  2     -a    sum=b+c
   a       b        c      4      1       (4>1) [++b]

  -4  -1  -1  0  1  2     -a    sum=b+c
   a          b     c      4      2       (4>2) [++b]

  -4  -1  -1  0  1  2     -a    sum=b+c
   a             b  c      4      3       (4>3) [++b]
   
Move a to next element [++a]
  -4  -1  -1  0  1  2     -a    sum=b+c           Results
       a   b        c      1      1       (1==1)  (-1,-1,2)

  -4  -1  -1  0  1  2     -a    sum=b+c        
       a      b     c      1      2       (2>1)   [--c]

  -4  -1  -1  0  1  2     -a    sum=b+c           Results
       a      b  c         1      1       (1==1)  (-1,-1,2) (-1,0,1)
       
Move a to next element [++a]       //if prev-a == present-a. Move to next element
  -4  -1  -1  0  1  2     -a    sum=b+c
              a  b  c      0      3       (3>a) [--c]   

Move a to next element [++a]
  -4  -1  -1  0  1  2   
                 a  bc    No triplets
```

#### Complexity
- **Time:** O(nlogn) + O(n<sup>2</sup>)    //Sort + Two-while
- **Space:** 3k + Function Stack
  - k triplets exist. 3k

#### Code
```c++
#include<iostream>
#include<vector>
#include<algorithm>

using vec =std::vector<int>;
using vec2d =std::vector<vec>;

std::vector<vec> threeSum(vec& nums) {
  vec2d out;

  if(nums.size() < 3)
    return out;

  std::sort(nums.begin(), nums.end());

  auto a = nums.begin();
  while (a < nums.end()) {
    auto b = a+1;
    auto c = nums.end() -1;
    while (b < c) {
      int sum = *b+*c;
      if (sum > -(*a))
        --c;
      else if (sum < -(*a))
        ++b;
      else{       //sum == -(*a)
        out.push_back({(*a), *b, *c});
        ++b;
        
        //if prev_element==present_element. Skip present element
        while(b<c and *(b-1)==*b)
          ++b;
      }
    }
    
    //if next_first_element == present_first_element. Skip it
    while(*a == *(a+1) and a<nums.end())
      ++a;
    ++a;
  }
  return out;
}
int main(){
  vec v = {-1,0,1,2,-1,-4};
  std::vector<vec> out = threeSum(v);
  for(int i=0;i<out.size();++i){
    for(int j=0;j<out[0].size();++j){
      std::cout<<out[i][j]<<" ";
    }
    std::cout<<"\n";
  }
}
```
