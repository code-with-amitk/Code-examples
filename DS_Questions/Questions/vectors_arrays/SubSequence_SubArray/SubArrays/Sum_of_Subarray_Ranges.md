**Sum of Subarray Ranges**
- [Approach-1, Naive, 2 pointers, 3 loops. O(n<sup>3</sup>). TLE](#a1)
- [Approach-2, 2 for loops. O(n<sup>2</sup>)](#a2)
- [Approach-3, Monotonic Stack. O(n)](#a3)

### [2104. Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)
- You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
- Return the sum of all subarray ranges of nums. A subarray is a contiguous non-empty sequence of elements within an array.
- **This is to be achieved in O(n) time complexity**
```c
Example-1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
            largest-smallest
[1]         //0
[1,2]       //1
[1,2,3]     //2
[2]         //0
[2,3]       //1
[3]         //0
```

<a name=a1></a>
### Approach-1, Naive, 2 pointers, 3 loops. O(n<sup>3</sup>). TLE
#### [Logic. Find All Subarrys](/DS_Questions/Questions/Strings/SubString_SubSequence/SubString_SubArray/Find_All_SubSeq.md)
#### Code
```cpp
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int b = 0;
        for (int i=0; i<nums.size(); ++i) {
            long long maxi = INT_MIN, mini = INT_MAX;
            b = i+1;
            while (b <= nums.size()) {
                for (int j=i; j<b; ++j) {
                    maxi = nums[j] > maxi ? nums[j] : maxi;
                    mini = nums[j] < mini ? nums[j] : mini;
                }
                sum += (maxi-mini);
                b++;
            }
        }
        return sum;
    }
};
```
#### [Complexity](/DS_Questions/Questions/Strings/SubString_SubSequence/SubString_SubArray/Find_All_SubSeq.md)

<a name=a2></a>
### Approach-2 for loops O(n<sup>2</sup>)
#### Logic
- _1._ Take min, max values as 1st value in subarray, then compare all other values and find min, max.
- _2._ Iterate 
```c
  1  2  3  4         min            max         sum += max-min          subarray
  .
  *                   1              1           0                       [1]
     *                1              2           0+1=1                   [1,2]
         *            1              3           1+2=3                   [1,2,3]
            *         1              4           3+3=6                   [1,2,3,4]

     .                
     *                2              2           6                       [2]
         *            2              3           6+1=7                   [2,3]
            *         2              4           7+2=9                   [2,3,4]

         .
         *            3              3           9                       [3]
            *         3              4           9+1=10                  [3,4]
            
            .
            *         4              4           10

```
#### Code
```cpp
using ll = long long;

class Solution {
public:
    ll subArrayRanges(vector<int>& nums) {
        ll sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            ll maxi = nums[i], mini = nums[i];                         //1
                for (int j=i; j<nums.size(); ++j) {
                    maxi = nums[j] > maxi ? nums[j] : maxi;
                    mini = nums[j] < mini ? nums[j] : mini;
                    sum += (maxi-mini);
                }
            }
        return sum;
    }
};
```
#### Complexity
- **Time:** O(n<sup>2</sup>)
- **Space:** O(1).

<a name=a3></a>
### Approach-3, Monotonic Stack. Time:O(n), Space:O(n)
#### Logic
#### Code
```cpp
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //nums = {3,1,2,4}
        int size=nums.size();
        long long sum=0;

        //NOTE: STACK contains indexes not elements
        stack<int>st;

        //Distance of nearset lowest element on left from current elemnt
        vector<int> dnll(size, -1);
        //Leftmost element does not have lower element than it.
        dnll[0] = 1;
        //Start from element at index=0
        st.push(0);

        //Distance of nearset lowest element on right from current elemnt
        vector<int> dnlr(size, size);

        //Distance of nearset Highest element on left from current elemnt
        vector<int> dnhl(size, -1);

        //Distance of nearset Highest element on right from current elemnt
        vector<int> dnhr(size, size);

        /// Distance of nearset lowest element on left from current element
        /// nums = {3,1,2,4}
        /// dnll  = {1,2,1,1}.
        /// dnll[0] = 1. nums[0]=3 is leftmost and does not have element
        /// dnll[1] = 2. nums[1]=1 does not have lower element than self on left
        /// dnll[2] = 1. nums[2]=2 has nearst lowest element on left at distance=1
        /// dnll[3] = 1. nums[3]=4 has nearst lowest element on left at distance=1
        for(int i=1; i<size; ++i) {
            if (nums[i] > nums[st.top()]) {
                //Present element > prev element
                //Simply push
            } else {
                //Present element <= stack top
                //Pop all elements, until stack.top < present
                while (!st.empty() && nums[i] < nums[st.top()])
                    st.pop();
            }
            if(st.empty()) {
                // Stack is empty means
                // There is no element smaller than me on left
                dnll[i] = i+1;
            } else {
                // Stack is not empty
                // stack.top() is nearest smaller than me on left in arr
                // nearest smaller than me on left = my_index - stack.top()
                dnll[i] = i - st.top(); // distance = i-st.top()
            }

            st.push(i);
        }

        st = stack<int>();

        /// nums = {3,1,2,4}
        /// dnlr  = {3,1,1,1}. Distance of Nearset lowest element on right
        st.push (size-1);
        // distance = 1, right not found, this is distance multiplied with num, so it can't be zero
        dnlr[size-1] = 1;
        for(int i = size-2; i>=0; --i) {
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();

            if(st.empty())
                dnlr[i] = size-i; // distance
            else
                dnlr[i] = st.top()-i;

            st.push(i);
        }

        st = stack<int>();
        /// nums = {3,1,2,4};
        /// dnhl = {1,1,2,4}
        /// dnhl[0]=1 since nums[0]=3 leftmost does not have nearst highest on left
        /// dnhl[1]=1 nums[1]=1 has nearst highest on left=3, hence distance=1
        /// dnhl[2]=2 nums[2]=2 has nearest highest on left as 3 hence distance=2
        /// dnhl[3]=4 nums[3]=4 does not any nearest highest on left hence distance=4(ie out of array index)
        st.push(0);
        dnhl[0] = 1;
         for(int i=1 ; i<size ; ++i) {
            if (nums[i] < nums[st.top()]) {
                //Present element < prev
                //Simply push
            } else {
                // Present element > stack top
                // Remove all elements from stack until stack.top() > me
                while(!st.empty() && nums[i] >= nums[st.top()])
                    st.pop();
            }
            if (st.empty()) {
                //There is no element Greater than me on left
                dnhl[i] = i+1;
            } else {
                //Stack is not empty
                // stack.top() is > present element
                dnhl[i] = i - st.top();
            }
            st.push(i);
         }

         st = stack<int>();

        /// Distance of next highest element on right
        /// nums = {3,1,2,4};
        /// dnhr =  {3,1,1,1}
        /// dnhr[3]=1 nums[3]=4 rightmost does not have nearst highest on right
        /// dnhr[2]=1 nums[2]=2 has nearst highest on right=4, hence distance=1
        /// dnhr[1]=1 nums[1]=1 has nearest highest on right=2 hence distance=1
        /// dnhr[0]=3 nums[0]=3 has nearest highest on right=4 hence distance=3
        st.push(size-1);
        dnhr[size-1] = 1;
         for(int i=size-2; i>=0; --i) {
            if (nums[i] < nums[st.top()]) {
                // Present element < st.top()
                // Simply push
            } else {
                // Present element > top of stack. ie nums[i] > nums[i+1]
                // Pop the stack until element < present is found on right
                while(!st.empty() && nums[i] > nums[st.top()])
                    st.pop();
            }
            if (st.empty()) {
                // There is not element on right on me > me
                dnhr[i] = size - i;
            } else {
                // 1 element is found on my right which is > then me
                // And nearest highest element on my right is at st.top()
                dnhr[i] = st.top() - i;
            }
            st.push(i);
         }

        long long out = 0;
        for (int i=0; i<size; ++i) {
            //num_of_subarr_in_which_ele_is_max = nhl[i]*nhr[i]
            //num_of_subarr_in_which_ele_is_min = nll[i]*nlr[i]
            long long num_of_subarr_in_which_ele_is_max = (dnhl[i]*dnhr[i]) % 1000000007;
            long long num_of_subarr_in_which_ele_is_min = (dnll[i]*dnlr[i]) % 1000000007;
            long long temp = (num_of_subarr_in_which_ele_is_max - 
                              num_of_subarr_in_which_ele_is_min) % 1000000007;
            out += (nums[i]*temp) % 1000000007;
            //out = out % 1000000007;
        }
        return out;
    }
};
```
