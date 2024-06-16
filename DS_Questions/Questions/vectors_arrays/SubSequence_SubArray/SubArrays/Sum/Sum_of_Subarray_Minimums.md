**Sum of Subarray Minimums**
- [Approach-1, Naive, 2 pointers, 3 loops. O(n<sup>3</sup>). TLE](#a1)
- [Approach-2, Naive, 2 loops. O(n<sup>2</sup>). TLE](#a2)
- [Approach-3, Monotonic Stack. O(n)](#a3)

### [907. Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/description/)
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10<sup>9</sup> + 7
```c
Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
  All Subarrays: [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
  Mins of subarrs:3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
```

<a name=a1></a>
### Approach-1, Naive, 2 pointers, 3 loops. O(n<sup>3</sup>). TLE
#### [Logic](/DS_Questions/Questions/Strings/SubString_SubSequence/SubString_SubArray/Find_All_SubSeq.md)
#### Code
```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        //Find All subarrays, 2 pointer approach
        /*
        3 1 2 4
        j b
            b
              b
        */
        long long sum = 0;
        int b = 0;
        for (int i=0; i<nums.size(); ++i) {
            long long mini = INT_MAX;
            b = i+1;
            while (b <= nums.size()) {
                for (int j=i; j<b; ++j) {
                    mini = nums[j] < mini ? nums[j] : mini;
                }
                sum = sum%1000000007;
                sum += mini;
                b++;
            }
        }
        return sum;
    }
};
```

<a name=a2></a>
### Approach-2, 2 for loops. O(n<sup>2</sup>)
#### Logic
1. Take min value as 1st value in subarray, then compare all other values and find min.
#### Code
```cpp
using ll = long;
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        ll sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            ll mini = nums[i];
             for (int j=i; j<nums.size(); ++j) {
                mini = nums[j] < mini ? nums[j] : mini;
                sum = sum%1000000007;
                sum += mini;
            }
        }
        return sum;
    }
};
```

<a name=a3></a>
### Approach-3, Monotonic Stack. O(n)
[What is Monotonic Stack](/DS_Questions/Data_Structures/Stacks/)
#### Logic
- _1._ The goal of this approach is to create 2 arrays. And **only to create these 2 arrays we will use monotonic stack**.
  - _1a._ nll array: where each element represents Distance of nearest lesser element than me on left
```c
Finding nll = Distance of nearest lesser element than me on left
input arr = {5, 6, 3, 10, 8, 4, 8, 9, 11}
             0  1  2   3  4  5  6  7   8

Start from index=0 ----------> 8
      nll =  1  1  3   1  2  3  1  1   1
          //element   nll   Why
            5         1     5 is leftmost element, nll=0 means index=0 is lesser than 5 which is not correct
            6         1     5 is nearest lesser to 6 on left
            3         3     There is no nearset lesser element than 3 on left. 
            10        1     3 is nearest lesser to 10 on left
            8         2     3 is nearest lesser to 8 on left, which is at distance of 2
            4         3     3 is nearest lesser to 8 on left, which is at distance of 3
            8         1     4 is nearest lesser to 8 on left, which is at distance of 1
            9         1     8 is nearest lesser to 9 on left, which is at distance of 1
            11        1     9 is nearest lesser to 11 on left, which is at distance of 1
```
- _1b._ nlr array: where each element represents Distance of nearest lesser element than me on right
```c
Finding nlr=Distance of nearest lesser element than me on right
input arr = {5, 6, 3, 10, 8, 4, 8, 9, 11}
             0  1  2   3  4  5  6  7   8
             
             0 <------------------ Start from index=8              
      nlr =  2  1  7  1   1  4  3  2   1
          //element   nlr   Why
            11        1     11 is rightmost element, nlr=0 means index=8 is lesser than 11 which is not correct
            9         2     No nearest lesser than 9 on right
            8         3     No nearest lesser than 8 on right
            4         4     No nearest lesser than 4 on right
            8         1     4 is nearest lesser than 8 on right
            10        1     8 is nearest lesser than 10 on right
            3         7     No nearest lesser than 3 on right
            6         1     3 is nearest lesser than 6 on right
            5         2     3 is nearest lesser than 5 on right
```
- _2._ Creating nll=Distance of nearest lesser element than me on left using monotonic stack
  - **Note: Monotonic stack only contains indexes of elements** 
```c
input arr = {5, 6, 3, 10, 8, 4, 8, 9, 11}
             0  1  2   3  4  5  6  7   8
             
Step-1: Make nll[0]=1, Since 5 is leftmost element and there does not exists any element which is less than 5 on left   
      nll =  1
      
i     nll            Monotonic Stack
0     {1}                  |   |
                           | 0 |
                           
1   //Is A[1]=6 > A[st.top()=0]=5   //if present element is Greater prev (ie stack top)
      Yes. Insert index on stack
                            | 1 |   //This means element at index=stack.top() is nearest lesser than me, Hence nearest lesser on left is distance=1
                            | 0 |   //Make nll[i] = 1
      {1, 1}
      
2   //Is A[2]=3 > A[st.top()=1]=6
      No. Pop stack until found st.top() < ele
      
                            |   |   //if stack is empty I'm the least element from left
                                    //nll[i] = current_index+1
      {1, 1, 3}
                            | 2 |   //Push present index stack

3     //Is A[3] > A[st.top()=2]
        Yes. Insert index on stack
                             | 3 |   //This means element at index=stack.top()=2 is nearest lesser than me, Hence nearest lesser on left is distance=1
                             | 2 |   //Make nll[i] = 1
        {1, 1, 3, 1}
        
4     //Is A[4]=8 > A[st.top()=3]=10
        No. Pop stack until found st.top() < ele
                             | 2 |   //A[2]=3 < ele=8. Distance = Present_index - index_at_top = 4 - 2 = 2. Insert in nll[i] = 2
        {1, 1, 3, 1, 2}
                             | 4 |    //Push present index on stack
                             | 2 |

5     //Is A[5]=4 > A[st.top()=4]=8
        No. Pop stack until found st.top() < ele
                             | 2 |   //A[2]=3 < ele=4. Distance = Present_index(5) - index_at_top(2) = 5 - 2 = 3. Insert in nll[i] = 3
        {1, 1, 3, 1, 2, 3}
                             | 5 |    //Push present index on stack
                             | 2 |
                             
6     //Is A[6] > A[st.top()=5]
        Yes. Insert index on stack
                             | 6 |
                             | 5 |   //This means element at index=stack.top()=5 is nearest lesser than me, Hence nearest lesser on left is distance=1
                             | 2 |   //Make nll[i] = 1
        {1, 1, 3, 1, 2, 3, 1}

7     //Is A[7] > A[st.top()=6]
        Yes. Insert index on stack
                             | 7 |
                             | 6 |   //This means element at index=stack.top()=6 is nearest lesser than me, Hence nearest lesser on left is distance=1
                             | 5 |   
                             | 2 |   //Make nll[i] = 1
        {1, 1, 3, 1, 2, 3, 1, 1}


8     //Is A[8] > A[st.top()=7]
        Yes. Insert index on stack
                             | 8 |
                             | 7 |   //This means element at index=stack.top()=7 is nearest lesser than me, Hence nearest lesser on left is distance=1
                             | 6 |
                             | 5 |   
                             | 2 |   //Make nll[i] = 1
        {1, 1, 3, 1, 2, 3, 1, 1, 1}
```
- _3._ Similarly nlr array created by starting from right side
```c
arr = {5, 6, 3, 10, 8, 4, 8, 9, 11}
       0  1  2   3  4  5  6  7   8
nll = {1, 1, 3,  1, 2, 3, 1, 1,  1}
nlr = {2, 1, 7,  1, 1, 4, 3, 2,  1}
```
- _4._ **Formula. Number of subarrays in which element i is minimum = `nll[i]*nlr[i]`**
```c
Example:
1. Number of subarrays in which arr[7]=9 is minimum = nll[7]*nlr[7]  = 1*2 = 2
  {9}
  {9,11}
  
2. Number of subarrays in which arr[5]=4 is minimum = nll[5]*nlr[5]  = 3*4 = 12
  {10,8,4}
  {10,8,4,8}
  {10,8,4,8,9}
  {10,8,4,8,9,11}
  {8,4}
  {8,4,8}
  {8,4,8,9}
  {8,4,8,9,11}
  {4}
  {4,8}
  {4,8,9}
  {4,8,9,11}
```
- _5._ Since we need sum of minimums. Hence contribution of `arr[i]` in total sum is `arr[i]*nll[i]*nlr[i]`
#### Code
```cpp
using ll = long;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int size = arr.size();
        vector<int> nll(size);  //Nearst less element on Left
        vector<int> nlr(size);  //Nearst less element on right

        // Filling array nll
        // Distance of nearest lesser element than me on left
        //
        // Monotonic Stack.
        // Note: STACK ONLY STORES INDEXES (not elements)
        stack<int> st;

        // Push index=0 on stack
        st.push(0);

        // Since arr[0] is leftmost element and there does not exists any element which is less than arr[0] on left
        nll[0] = 1;

        for(int i=1; i<size; ++i) {

            if (arr[i] > arr[st.top()]) {
                //Present element > prev
                //  Simply push
            } else {
                // Present element <= stack top
                // Pop all elements, until stack.top() < present
                while(!st.empty() && arr[i] < arr[st.top()])
                    st.pop();
            }

            // Fill nll array

            if(st.empty()) {
                // Stack is empty means
                // There is no element smaller than me on left
                nll[i] = i+1;
            } else {
                // Stack is not empty
                // stack.top() is nearest smaller than me on left in arr
                // nearest smaller than me on left = my_index - stack.top()
                nll[i] = i - st.top(); // distance = i-st.top()
            }
                // Insert present index
                st.push(i);
        }
        
        while(st.size())
            st.pop();

        // Fill nlr array
        
        st.push(size-1);
        nlr[size-1] = 1; // distance = 1, right not found, this is distance multiplied with num, so it can't be zero
        for(int i=size-2; i>=0; i--)
        {
            while(!st.empty() && arr[i] <= arr[st.top()])
                st.pop();

            if(st.empty())
                nlr[i] = size-i; // distance
            else
                nlr[i] = st.top()-i;

            st.push(i);
        }

        long long out = 0, temp = 0;
        for (int i=0; i<size; i++) {
            temp = (nll[i] * nlr[i]) % 1000000007;
            out += (temp * arr[i]) % 1000000007;
            out = out % 1000000007;
        }
        return out;
    }
};
```
