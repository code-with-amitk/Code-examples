**Search a 2D Matrix**
- Approach-1. Linear Search. O(mn)
- [Approach-2. Linear + Binary Search](#a2)
- [Approach-3. Binary Search](#a3)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
    - [Python](#py)
    - [Rust](#rs)

## [74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)
- Example: Given below matrix search Target=3, output=true

![ImgURL](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

### Approach-1  //Linear Search. O(mn)
- Go to every element and check

<a name=a2></a>
### Approach-2. Linear + Binary Search
#### Logic
- *1.* Check last element of each row in linear search manner.
```c
  if (target < last-element)
    target may-be present in this row, not any where else
```
- *2.* Perform binary search on the row
#### Complexity
- **Space:** O(1).
- **Time:** m:No of rows, n:No of cols
  - O(mn) (if 1 col and all rows)
#### Code
```cpp
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
```

<a name=a3></a>
### Approach-3. Binary Search
#### Logic
- _1._ Treat this as sorted array and perform binary search
```c
rows = matrix.size(), cols = matrix[0].size()
left = 0, right = rows+cols-1
```
- _2._ Perform binary search
```c
while (left < right) {
  mid = (left + right)/2
  row = mid/cols, col = mid%cols;

  if (matrix[row][col] < target)
    left = mid+1;
  else
    right = mid;
}
```

<a name=com></a>
#### Complexity
- **Time:** O(log(mn)). Binary search
- **Space:** O(1)

#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;

        while (left < right){
            int mid = (left + right)/2;
            int row = mid/cols, col = mid%cols;

            if(matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                right = mid;
            else
                left = mid + 1;
        }
        //if this is right most element
        if (matrix [rows-1][cols-1] == target)
            return true;
        return false;
    }
};
```

**Python**
```py
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        left = 0
        right = rows * cols - 1

        while left < right:
            # (Floor Division)15//2=7, 15/2=7.5
            mid = (left+right)//2
            row = mid//cols
            col = mid%cols

            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                right = mid
            else:
                left = mid + 1
        if matrix [rows-1][cols-1] == target:
            return True
        return False
```
<a name=rs></a>
**Rust**
```rs
impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut left = 0;
        let mut right = rows*cols-1;

        while left < right {
            let mut mid = (left+right)/2;
            let row = mid/cols;
            let col = mid%cols;

            if matrix[row][col] == target {
                return true;
            } else if (matrix[row][col] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if matrix [rows-1][cols-1] == target {
            return true;
        }
        false
    }
}
```
