## [Plus One](https://leetcode.com/problems/plus-one/)
- **Problem**
  - Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
  - The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
  - You may assume the integer does not contain any leading zero, except the number 0 itself.
- **Examples**
```c
Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: digits = [1,2,4,9,9]
Output: [1,2,5,0,0]

Example 3:
Input: digits = [9]
Output: [1,0]
```

### Logic
- Start from rear end using reverse Iterator.
- Keep changing elemnt to 0 until find a number < 9 or 1st digit
  - if (reached 1st digit)
    - Create new vector whose size() = originalSize+1; Fill all zeros, then fill 1 into 1st index.
  - else
    - increment 1 to present node

### Code
```c++
class Solution {
  using vi = vector<int>;
public:

  vi PlusOne(vi& a) {
    vi::reverse_iterator rit = a.rbegin();

    while (*rit == 9) {
      *rit = 0;
      ++rit;
    }

    if(rit == a.rend() and *rit == 0){
      vi c(a.size()+1, 0);            //Create new vector whose size()=originalSize+1. Fill all zeros, then fill 1 into 1st index.
      c[0] = 1;
      return c;
    }
    *rit += 1;
    return a;
  }
};

int main(){
  Solution s;
  vector<int> a = {9,9};
  vector<int> b = s.plusOne(a);
  for (auto i:b)
    cout<<i;
}
```
