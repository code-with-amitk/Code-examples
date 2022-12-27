**3Sum**
- [Approach-1, 3 for loops. O(n<sup>3</sup>)](#a1)
- [Approach-2, Sort+3 Pointers. O(n<sup>2</sup>)](#a2)
  - [Logic](#l)
  - [Complexity](#com)
  - [CPP](#cpp)


### [3sum](https://leetcode.com/problems/3sum/)
- Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
```c
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = []
Output: []

Input: nums = [0]
Output: []
```

<a name=a1></a>
### Approach-1    //3 For loops. O(n<sup>3</sup>)
- 3 for loops check every element with each other
```c++
  vector<vector<int>> out;
  for(int i=0; i<nums.size(); ++i)
    for(int j=i+1; j<nums.size(); ++j)
      for(int k=j+1; k<nums.size(); ++k)
        if (nums[i]+nums[j]+nums[k] == 0)
          out.push_back({nums[i],nums[j],nums[k]});
  return out;    
```

### Approach-2  //Sort + 3 pointer search. O(n<sup>2</sup>)
<a name=l></a>
#### Logic
```cpp
Array = {-1,0,1,2,-1,-4}
Step-1: Sort    {-4,-1,-1,0,1,2}    //O(nlogn)
Step-2: Fix 1st element, iterate thru rest of array to find if(Sum of 2 elements == -First_element)
  -4  -1  -1  0  1  2
   a   b            c
Step-3:
  if (-a == (b+c)){    //4 == -1+2
    //Found triplet
  }else{
    if (sum < -a)         //1 < 4
      ++b;
    else
      --c;
  }
```
- Insert triplets into `unordered_set<string>` to ensure duplicate triplets are not returned.

<a name=com></a>
#### Complexity
- **Time:** O(nlogn) + O(n<sup>2</sup>)    //Sort + Two-while
- **Space:** 3k + Function Stack
  - k triplets exist. 3k

#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<string> us;
        // Sort: O(nlogn)
        sort (nums.begin(), nums.end());

        // Fix 1st element and search 2 elements
        // whose sum = -first_element
        // O(n2). Outer for, inner while
        for (int i=0;i<nums.size()-1;++i) {
            int first_element = nums[i];
            int start = i+1, end = nums.size()-1;

            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum == -first_element) {
                    // Found Triplet, Insert in set
                    // Convert set to vector later
                    stringstream ss;
                    ss << first_element << "," << nums[start] << "," << nums[end];
                    us.insert(ss.str());

                    // Donot break, Search other triplets from this 1st element
                    // {-2,0,1,1,2}. => {-2,0,2} {-2,1,1}
                    // if we break will loose 2nd triplet
                    //break;
                    ++start;

                    // Skip all elements, where prev_element == present_element
                    while (start<end && nums[start] == nums[start-1])
                        ++start;
                }
                else if (sum < -first_element) 
                    start++;
                else
                    end--;
            }
            // Skip all same elements
            // This condition is helpful when input is like:
            // [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ...]
            while (start < end && nums[start] == nums[start+1])
                start++;
        }

        // Create vector from hashset to return output
        vector<vector<int>> out;
        for (auto i:us){
            string str;
            stringstream ss(i);
            vector<int> temp_vec;
            while (getline(ss, str, ',')) {
                int val;
                istringstream(str) >> dec >> val;
                temp_vec.push_back(val);
            }
            out.push_back(temp_vec);
        }
        return out;
    }
};
```
