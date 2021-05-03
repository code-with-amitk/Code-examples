## [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
- You are given an integer array and you have to return a new counts array. 
- The counts array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.
- Example:
```c
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```

### Approach-1  //O(n<sup>2</sup>)
- Run 2 for loops and find all elements greater than self

### Approach-2  //Merge Sort
- **Logic**
  - *a.* Sort the array using merge sort, ie using Divide and Conquer
  - *b.* Elements which are smaller than 5(ie 2,1) will jump to left of 5. Note number of jumps and form a new array that's the answer
- **Complexity**
  - **Time:** O(nlogn)
  - **Space:** O(n)
- **Code**
```c++
#include<vector>
#include<iostream>
using namespace std;

using vec = vector<int>;

class Solution {
public:
  void merge(vec& indices, int low, int high,
            int mid, vec& out, vec& nums) {

    // merge [left, mid) and [mid, right)
    int i = low;  // current index for the left array
    int j = mid;   // current index for the right array

    // use temp to temporarily store sorted array
    vec temp;
    while (i < mid && j < high) {

      if (nums[indices[i]] <= nums[indices[j]]) {
        // j - mid numbers jump to the left side of indices[i]
        out[indices[i]] += j - mid;
        temp.push_back(indices[i]);
        i++;
      } else {
        temp.push_back(indices[j]);
        j++;
      }
    }

    // when one of the subarrays is empty
    while (i < mid) {
      // j - mid numbers jump to the left side of indices[i]
      out[indices[i]] += j - mid;
      temp.push_back(indices[i]);
      i++;
    }
    while (j < high) {
      temp.push_back(indices[j]);
      j++;
    }
    // restore from temp
    move(temp.begin(), temp.end(), indices.begin() + low);
  }

  void mergeSort(vec& indices, int low,
                int high, vec& out, vec& nums) {
    if (high - low <= 1)
      return;

    int mid = (low + high) / 2;
    mergeSort (indices, low, mid, out, nums);
    mergeSort (indices, mid, high, out, nums);
    merge (indices, low, high, mid, out, nums);
  }

  vec countSmaller(vec& nums) {
    int n = nums.size();
    vec out(n);
    vec indices(n);  // record the index. we are going to sort this array
    for (int i = 0; i < n; ++i)
      indices[i] = i;

    mergeSort (indices, 0, n, out, nums);
    return out;
  }
};

int main(){
  vec a = {5,2,6,1};
  Solution s;
  vec o = s.countSmaller(a);
  for (auto i:o)
    cout<<i<<" ";
}
```
