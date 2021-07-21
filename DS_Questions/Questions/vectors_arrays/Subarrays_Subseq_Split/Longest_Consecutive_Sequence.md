- [Longest Consecutive Sequence](#ques)
- Approach-1, Brute Force
  - [Logic](#logic1)
  - [Complexity](#complexity1)
  - [Code](#code1)
- Approach-2, Sort
  - [Logic](#logic2)
  - [Complexity](#complexity2)
  - Code
    - [C++](#cpp2)
- Approach-3, HashSet
  - [Logic](#logic3)
  - [Complexity](#complexity3)
  - Code
    - [C++](#cpp3)
    - [Rust](#rust)

<a name=ques></a>
## [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence)
- Given an unsorted array of integers, return the length of the longest consecutive elements sequence, Ignore Duplicates.
- Elements in the subsequence are consecutive integers, the consecutive numbers can be in any order(ie does not need to be ascending or decending).
- Examples
```c
Input: nums = {1, 9, 3, 10, 4, 20, 2}
Output: 4   //The subsequence 1, 3, 4, 2 is the longest.

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Input: nums = [-100, 9, 7, 5, 8, 6, 100]
Output: 6       //5,6,7,8,9
```

### Approach-1, Brute Force
<a name=logic1></a>
#### Logic
- _1._ Take every element and search element+1 in entire array. 
- _2._ Search element+1 in entire array, if found search again ele+1 in entire array, keep count of present_longest_con_seq.
- _3._ Update longest_con_seq with larger value from present_lon_con_seq and longest_con_seq
```c
{1, 9, 3, 10, 4, 20, 2}
                                                  present_Longest_Con_Seq   longest_con_seq
i=0 ele+1 = 2. Search 2 in array. Found 2. O(n)        2                                       //1
    ele+1 = 3. Search 3 in array. Found 3.             3
    ele+1 = 4. Search 4 in array. Found 4.             4
    ele+1 = 5. Search 5 in array. Not Found            4                         4

i=1 ele+1 = 10. Search 10 in array. Found 10. O(n)     2
    ele+1 = 11. Search 11 in array. Not Found.         2                         4

i=2..
```

<a name=complexity1></a>
#### Complexity
- Time: O(n<sup>3</sup>)
- Space: O(1)

<a name=code1></a>
#### Code
```c
using vec = vector<int>;
class Solution {
  bool find_nums_plus_1(vec& v, int j) {
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == j)
        return true;
    }
    return false;
  }
public:
  int longestConsecutive(vec& v) {
    int long_cons_seq = 0;

    for (auto i : v) {
      int curr = i;
      int long_present_seq = 1;

      while (find_nums_plus_1(v, curr + 1)) {               //1
        curr += 1;
        long_present_seq += 1;
      }

      long_cons_seq = max(long_cons_seq, long_present_seq); //3
    }

    return long_cons_seq;
  }
};
```

### Approach-2, Sort the array
<a name=logic2></a>
#### Logic
- _1._ Sort the array
- _2._ Start from index=1. 
  - Check if Prev_elem != present_elem   //Ignore duplicate
    - if present_elem == prev_elem+1
      - increment present_long_cont_seq
    - if present_ele != prev
      - store count into long_con_seq
```c
{1, 9, 3, 1, 10, 4, 20, 2}

1,1,2,3,4,9,10,20                     //1   O(nlogn)
0 1 2 3 4 5 6 6 7

i=1   v[0]==v[1]  //move to next ele
i=2   v[2]!=v[1]                  present_cont_seq
        v[2] = v[1]+1               2
i=3     v[3] = v[2]+1               3
...     
```
<a name=complexity2></a>
#### Complexity
- Time: O(nlogn) + O(n)
- Space: O(1)

#### Code
<a name=cpp2></a>
- **C++**
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        
    if (!v.size() || v.size()==1)
      return v.size();
        
    int long_cons_seq = 1, present_long_cons_seq=1;        
        
    sort (v.begin(), v.end());

    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[i-1]) {
            if (v[i] == v[i-1]+1) {
                present_long_cons_seq++;
            } else {
                long_cons_seq = max(long_cons_seq, present_long_cons_seq);
                present_long_cons_seq = 1;
            }
        }//if
    }//for
    long_cons_seq = max(long_cons_seq, present_long_cons_seq);
    return long_cons_seq;        
    }
};
```

### Approach-3, HashSet
<a name=logic3></a>
#### Logic
- Search continious increasing Sequence in unordered_set in O(1) time. input=3,5,2,1
- We will search 1,2,3 only ie if we found ele+1 in unordered_set then we keep on searching its higher elements, we will not search 3,2,1(ie decreasing seq).
  - _1._ Store all elements in unordered_set`<int>`
  - _2._ Iterate thru unordered_set.
    - if (value+1) is found in set, (value-1) is not found in set. Search for all (value+1).
<a name=complexity3></a>
#### Complexity
- _Time:_ O(n) for creating unordered_set. O(n) for iterating all elements. O(1) for searching (value+1) element.
- _Space:_ O(n), we are storing elements in unordered_set.
#### Code
<a name=cpp3></a>
**C++**
```cpp
class Solution {
public:
  int longestConsecutive(vec& v) {
    unordered_set<int> us;

    if (!v.size() || v.size()==1)
      return v.size();

    for (int i : v)                 //1
      us.insert(i);

    int long_cont_seq = 1;

    for (auto i:us) {
      if (us.find(i+1) != us.end() && us.find(i-1) == us.end()) {        //2
        int curr = i;
        int current_long_cont_seq = 1;

        while (us.find(curr+1) != us.end()) {
          curr += 1;
          current_long_cont_seq += 1;
        }
        long_cont_seq = max(long_cont_seq, current_long_cont_seq);
      }
    }
    return long_cont_seq;
  }
};

//main.cpp
#include"test.cpp"
#include <gtest/gtest.h>

TEST(Collision, case1) {
             //(Expected_Output, function call)
  Solution obj;
  vector<int> input = {-100,9,7,5,8,6,100};  EXPECT_EQ(5, obj.longestConsecutive(input));
  input = {100,4,200,1,3,2};        EXPECT_EQ(4, obj.longestConsecutive(input));
  input = {0,3,7,2,5,8,4,6,0,1};    EXPECT_EQ(9, obj.longestConsecutive(input));
  input = {1, 9, 3, 10, 4, 20, 2};  EXPECT_EQ(4, obj.longestConsecutive(input));
  input = {};                       EXPECT_EQ(0, obj.longestConsecutive(input));
  input = {1};                      EXPECT_EQ(1, obj.longestConsecutive(input));
  input = {1,10};                   EXPECT_EQ(1, obj.longestConsecutive(input));
  input = {0,-1};                   EXPECT_EQ(2, obj.longestConsecutive(input));
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//CMakeLists.txt
cmake_minimum_required(VERSION 2.6)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(runTests main.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# cmake .; make; runTests
```

<a name=rust></a>
**Rust**
```rs
use std::cmp;
use std::collections::HashSet;

struct Solution{}

impl Solution {
    pub fn longest_consecutive(v: Vec<i32>) -> i32 {
        let size:i32 = v.len() as i32;
        if size == 0 || size == 1 {
            return size;
        }

        let hash_set: HashSet<i32> = v.into_iter().collect();

        let mut long_cons_seq = 1; 

        for j in &hash_set {                    //Borrow is done to avoid move
            if hash_set.contains(&(j+1)) &&  !hash_set.contains(&(j-1)){    //value is borrow to avoid copy
                let mut current = *j;
                let mut current_long_cont_seq = 1;

                while hash_set.contains(&(current+1)) {
                    current += 1;
                    current_long_cont_seq += 1;
                }
                long_cons_seq = cmp::max(long_cons_seq, current_long_cont_seq);
            }
        }
        long_cons_seq
    }
}

#[cfg(test)]
mod all_tests {
    use super::*;

    #[test]
    fn test_fn() {
        assert_eq!(5, Solution::longest_consecutive([-100,9,7,5,8,6,100].to_vec()));
        assert_eq!(4, Solution::longest_consecutive([100,4,200,1,3,2].to_vec()));
        assert_eq!(2, Solution::longest_consecutive([0,-1].to_vec()));
    }
}

fn main(){                //For Debugging 
    let v = vec![100,4,200,1,3,2];
    let a = Solution::longest_consecutive(v);
    println!("{}",a);
}

$ cargo run
$ cargo test
```
