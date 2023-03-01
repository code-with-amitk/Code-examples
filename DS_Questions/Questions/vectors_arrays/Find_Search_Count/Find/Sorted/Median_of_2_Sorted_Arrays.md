**Median of Two Sorted Arrays**
- [Approach-1. Brute Force. Merge, Find Median. O(m+n)](#a1)

### [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)
- Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
- The overall run time complexity should be O(log (m+n)).
```
Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

<a name=a1></a>
### Approach-1. Brute Force. Merge, Find Median. O(m+n)
- Combine input vectors into 3rd vector.
- if sizeof(created vector) is even, median=sum_of_2_middle_elements/2. Odd=middle_element
#### Complexity
- **Time:** O(m+n)
- **Space:** O(m+n)

#### Code
**CPP**
```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size());
        
         /* OutputIt merge( InputIt1 first1, InputIt1 last1,
                 InputIt2 first2, InputIt2 last2,
                 OutputIt d_first );
        */
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
        
        nums1.clear();        nums2.clear();
        
        if (merged.size() % 2 == 0) {
            // Even number of elements, median is average of middle two
            
            // nth_element find element that should be at nth position in array
            // it does not sorts the array, but find the element
            // Complexity: O(n)
            std::nth_element(merged.begin(), merged.begin() + mid, merged.end());
            int a = merged[mid];
            std::nth_element(merged.begin(), merged.begin() + mid - 1, merged.end());
            int b = merged[mid - 1];
            
            return (double)(a + b) / 2.0;
        } else {
            // Odd number of elements, median is middle element
            std::nth_element(merged.begin(), merged.begin() + mid, merged.end());
            return (double)merged[mid];
        }
    }
};
```
