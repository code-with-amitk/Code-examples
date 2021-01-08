## [Search a 2D Matrix]
![ImgURL](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)
- Target=3, output=true

## Approach-1  //Linear Search. O(mn)
- Go to every element and check

## Approach-2  //Binary Search
### Logic-2
- *1.* Check last element of row
```c
  if (target < last-element)
    target may-be present in this row, not any where else
```
- *2.* Perform binary search on the row
### Complexity
- **Space:** O(1).
- **Time:** m:No of rows, n:No of cols
  - O(mlogn)
### Code-2
```c++
#include<iostream>
#include<vector>

    using vec2d = std::vector<std::vector<int>>;
    using vec1d = std::vector<int>;
    using itr = std::vector<int>::iterator;
class Solution {
public:

    bool BinarySearch(vec1d v, int start, int end, int target){
        int mid = (start+end)/2;
        if (target == v[mid])
            return true;
        if (start>end)
            return false;

        if (target>v[mid])
            return BinarySearch(v,mid+1,end,target);
        else
            return BinarySearch(v,start,mid-1,target);

        return false;
    }

    bool searchMatrix(vec2d& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i=0;
        while (i<rows){
            if (target < matrix[i][cols-1]){    //if present, target would be in this row
                return BinarySearch(matrix[i], 0, cols, target);
            }else if(target == matrix[i][cols-1]){
                return true;                
            }else{
                ++i;
            }
        }
        return false;
    }
};
int main(){
  Solution s;
  vec2d v = {
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60}
  };
  int target = 13;
  std::cout<<s.searchMatrix(v, target);
}
```
