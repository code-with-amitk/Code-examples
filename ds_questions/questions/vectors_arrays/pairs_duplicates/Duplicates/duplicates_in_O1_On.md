**Note**: Google wants ***OPTIMAL SOLUTION***, but you should be aware about all possible solutions.

## [Problem](https://leetcode.com/explore/featured/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3414/)
- Find duplicates in array in O(n) time & O(1) space complexity
- `1 ≤ a[i] ≤ n` (n = size of array).


### Example:
```
Input: [4,3,2,7,8,2,3,1]
Output: [2,3]
```

### Approach-1(Array storing count of elements) (Time:O(n) Space:O(n))

**Array(size=8)**
| elements-> | 4 | 3 | 2 | 7 | 8 | 2 | 3 | 1 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Indexes-> | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |

**Count Array**
- Count Array can be 1 greater than input array since `a[i] ≤ n`. Array element can be equal to size.
| elements-> | 0 | 1 | 2 | 2 | 1 | 0 | 0 | 1 | |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Indexes-> | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |


### Approach-2(unordered_set) (Time:O(n), Space:O(n))
- Take a hash table & a output vector.
- Insert into:
  - HashTable: if element is not present earlier in hashMap.
  - Output Vector: if element exists in hashtable(it means its duplicate).
- Complexity:
  - Space: O(n) - noOfDuplicates
  - Time: O(1)
  
```
    vector<int> findDuplicates(vector<int>& nums) {
      unordered_set<int> us;
      vector<int> v;

      for(auto i:nums){
        if(us.find(i) != us.end())
          v.push_back(i);
        else
          us.insert(i);
      }
      return v;
    }
```

### Approach-3(Time:O(n), Space:O(1))
- We will extend Approach-1. In approach-1 we are storing count of occurences in Seperate array
  - Now we will store count of occurences of elements in input array only. `[Since we donot have extra Space]`
- **Logic**  
  - Store count of occurences of elements in Original Array. Increment element by sizeofArray.
    - *Why increment by sizeofArray* Because we need to retrieve original element also. This is Preserving original Element.
  - Traverse array again
    - if `arr[i] > 2*sizeOfArray` it means This element(ie index) occured 2 times.
    - if `arr[i] > 3*sizeOfArray` it means This element(ie index) occured 3 times.
    - so on

- **Understanding**
> sizeOfArray = 8

| elements-> | 4 | 3 | 2 | 7 | 8 | 2 | 3 | 1 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Indexes-> | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |

*`i = 0, a[0]=4, Increment occurence of 4 at index 4`*
`a[4] = a[4]+8`

| elements-> | 4 | 3 | 2 | 7 | 8 | 2 | 3 | 1 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Indexes-> | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |


```
vector<int> findDuplicates(vector<int>& a) {
    int size = a.size();
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
      original_element = a[i]%size;
      a[original_element %s] = a[original_element % s] + s;
    }
    for (int i = 0; i < s; i++){
        if (a[i] > s*2)
        {
            v.push_back(i);
        }
    }
    return v;
}

int main(){
  vector<int> a = {4,3,2,7,8,2,3,1};
  vector<int> b = findDuplicates(a);
  for(auto i:b)
    cout<<i<<" ";
}  
```

