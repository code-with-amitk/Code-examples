## [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
- Given sorted array in ascending order, find two numbers such that they add up to a specific target number.
- Examples
```c
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
```

## 1. Approach-1 (2 for loops)  
- **Complexity:** 
  - Time: O(n<sup>2</sup>)
  - Space: O(1)
```c++
  vec1d twoSum(vec1d& numbers, int target) {
    vec1d out;
    for (auto i=0; i<numbers.size(); ++i){
      for (auto j=i+1; j<numbers.size(); ++j){
        if (numbers[i]+numbers[j] == target){
          out.push_back(i+1);
          out.push_back(j+1);
          break;
        }
      }
    }
    return out;
  }
```

## 2. Approach-2 (Binary Search)
- *Complexity*
  - *Time:* O(nlogn).   logn=binary search. n=Incrementing the start by 1 every time
  - *Space:* O(1)
```c
arr[] = {2,4,5,6,7,8,9,11,15}; int target=12;
  Step-1: start=2, end=15, mid(index=4)=7
  Step-2: target > (start+mid). Move to right. start=8, end=15 ..
  
  Cannot find sum. Move to next element ie start=4
```

## 3. Approach-3 (2 pointer)
- **Complexity**
  - Time: O(n)
  - Space: O(1)
```c++
#include<iostream>
#include<vector>
using vec1d = std::vector<int>;
class Solution {
public:
  vec1d twoSum(vec1d& numbers, int target) {
    vec1d out;
    int i = 0, j = numbers.size()-1;
    if (target > numbers[i]+numbers[j])
      return out;

    while ( i < j ) {
      if (numbers[i]+numbers[j] == target) {
        out.push_back(i+1);
        out.push_back(j+1);
        break;
      }
      if ( numbers[i]+numbers[j] < target )
        ++i;
      if ( target < numbers[i]+numbers[j] )
        --j;
    }
    return out;
  }
};
int main() {
  vec1d v = {2,4,5,6,7,8,9,11,15}; int target=12;
  Solution s;
  vec1d o = s.twoSum(v,target);
  for(auto i:o)
    std::cout<<i<<" ";
}
```
