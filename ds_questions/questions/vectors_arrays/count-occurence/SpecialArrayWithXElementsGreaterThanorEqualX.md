## [Problem](https://leetcode.com/contest/weekly-contest-209/problems/special-array-with-x-elements-greater-than-or-equal-x/)
- You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
- Notice that x does not have to be an element in nums.
- Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.
- Examples
```c
Example-1
Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.

Example-2
Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.

Example-3
Input: nums = [3,6,7,7,0]
Output: -1
```

### Logic
- Consider this array = [0,4,3,0,4]
- Create unordered_map having count of elements in array
```c
    |key|value|
    |0  |2    |
    |3  |1    |
    |4  |2    |
```    
- Start from i=0,1,2,3,4.. Till Max element in array here=4
```c
  i       count
  0       key=0, count=2. break
  1       key=0, count=0
              3,       1
              4,       3. break
  2       key=3, count=1
              4,       3  break
  3       key=3, count=1
              4       =3  Found element
```

### Code
```c
#include<unordered_map>
#include<vector>

using namespace std;
class Solution {
  using _RESULT = int;

  _RESULT maxElement=0;
  unordered_map<int,int> um;

  void countElements(vector<int>& a){
    for(auto i:a){
      if (i>maxElement)
        maxElement = i;
      um[i]++;
    }
  }
  _RESULT findSpecial() {
    uint32_t temp;
    for (int i=0;i<=maxElement;i++){
      temp = 0;

      for (auto j:um){
        if (j.first >= i){
          temp += j.second;
        }

        if (temp > i)
          break;
      }

      if (temp == i)
        return i;
    }
    return -1;
  }

public:
  _RESULT specialArray(vector<int>& a) {
    countElements(a);
    return findSpecial();
  }
};

int main(){
  Solution s;
  cout<<s.specialArray(a);
}
```
