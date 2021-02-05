## [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)
- Given two sorted arrays nums1 and nums2. Merge nums2 into nums1 as one sorted array. 
- The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
- **Examples**
```c
Input: 
nums1 = [1,2,3,0,0,0], m = 3      //Take 3 elements from start [1,2,3]
nums2 = [2,5,6], n = 3      
Output: [1,2,2,3,5,6]   total=6

Input
num1 = [-1,0,0,3,3,3,0,0,0], m = 6  //Take 6 elements from start [-1,0,0,3,3,3]
num2 = [1,2,2], n = 3
output: [-1 0 0 1 2 2 3 3 3]  total=9
```
## 1. Approach-1    //Merge nums2 at end of nums1 and sort
- **Complexity**
  - **Time:** O((n+m)log(n+m)). Copy:O(m), Merge:O((n+m)log(n+m))
  - **Space:** O(n+m). Builtin sorting algos use extra space
- **Code**
```c++
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //copy (InputIterator first, InputIterator last, OutputIterator result); 
        //copy nums2[0,n] into nums1 from m 
        copy(nums2.begin(), nums2.begin()+n, nums1.begin()+m);
        sort(nums1.begin(), nums1.end());
    }
```

## 2. Approach-2    //2 pointer approach. Time:O(m+n), Space:O(m+n)
```c
num1 = [-1,0,0,3,3,3,0,0,0], m = 6    
num2 = [1,2,2], n = 3
```
- **Logic**
  - *1.* Take seperate vector(out) of size(m+n) where merged elements would be placed
  - *2.* Take 2 pointers nums1(pointer i), nums2(pointer j) to iterate thru array.
```c
num1 = [-1 0 0 3 3 3 0 0 0]
         i
num2 = [1 2 2]
        j
```  
  - *3.* `if (nums1[i] < num2[j])` place `nums[i]` into out and ++i. Similar for j.
  - *4.* if (i==m and j<n) merge all elements of nums2 to out. Same for nums1.
  - *5* Copy out to nums1.
- **Complexity**
  - **Time:** O(m+n)
  - **Space:** O(m+n). Output vector
- **Code**
```c++
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int> out(m+n);
        
        while (i<m and j<n){
            if(nums1[i]<nums2[j])
                out.push_back(nums1[i++]);
            else
                out.push_back(nums2[j++]);
            
            if (i<m and j<n and nums1[i]==nums2[j]){
                out.push_back(nums1[i++]);
                out.push_back(nums2[j++]);
            }   
        }
        while(i<m)
            out.push_back(nums1[i++]);
        while(j<n)
            out.push_back(nums2[j++]);
        nums1 = out;
    }
```

## 3. Approach-3 //3 Pointer Approach. Time:O(m+n). Space:O(1)
```c
  nums1 = [1,2,3,0,0,0] int m = 3
  nums2 = [2,5,6] int n = 3;
```
- **Logic**
  - *1.* Take copy 1st m elements of nums1 to nums1Copy
```c
  nums1 = [1,2,3,0,0,0]
           k
  
  nums2 = [2,5,6]
           i
           
  nums1Copy = [1,2,3]
              j
```  
  - *2.* Compare element of num1Copy(pointer i), num2(pointer j) and merge into nums1(pointer k).
- **Complexity**
  - **Time:** O(m+n)
    - Copy to nums1Copy: O(m)
    - Merge using linear traversal: O(m+n)
  - **Space:** [O(1)](https://github.com/amitkumar50/Code-examples/tree/master/DS_Questions). Every time we will take nums1Copy of size=m
```c
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0, j=0, k=0;
    vector<int> nums1Copy(m);
    copy(nums1.begin(), nums1.begin()+m, nums1Copy.begin());

    while (i<m and j<n){
      if(nums1Copy[i]<nums2[j])
        nums1[k++]=nums1Copy[i++];
      else
        nums1[k++]=nums2[j++];

      if(nums1Copy[i]==nums2[j]){
        nums1[k++] = nums1Copy[i++];
        nums1[k++] = nums2[j++];
      }
    }
    while(j<n)
      nums1[k++] = nums2[j++];
    while(i<m)
      nums1[k++] = nums1Copy[i++];
  }
```
