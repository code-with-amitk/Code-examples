**Delete and Earn / Delete and profit / Delete and gains / Maximum Gains**
- [Approach-1, Dynamic Programming(Top Down)](#a1)
  - [Why this is DP Problem?](#w)
  - [Logic](#l1)
  - Code
    - [CPP](#cpp)
    - [Rust](#rs)
  - [Complexity](#co)


## [Delete & Earn](https://leetcode.com/problems/delete-and-earn/)
- Given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
- Pick any `nums[i]` and delete it to earn `nums[i]` points. Afterwards, you must delete every `nums[i] - 1` and `nums[i] + 1` element.
- Return the maximum number of points you can earn by applying the above operation some number of times.
- Examples
```c
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
  - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2]
  - Delete 2 to earn 2 points. nums = []
You earn a total of 6 points.

Example 2:
Input: nums = [2,2,3,3,3,4]
Output: 9
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].

Example 3:
Input nums = [5, 5, 5, 6, 6, 6, 6, 7, 7, 10, 10, 10, 10]
Output: 29
- Delete a 5 to earn 5 points. All 6's are also deleted. nums = [5,5,7,7].
- Delete a 5 again to earn 5 points. nums = [5,7,7].
- Delete a 5 once more to earn 5 points. nums = [7,7].
- Delete both 7 to earn 14 points
```

<a name=a1></a>
## Approach-1, Dynamic Programming(Top Down)

<a name=w></a>
#### [Why this is DP Problem?](/DS_Questions/Algorithms/Dynamic_Programming/README.md#i)
  - _1. Keyword:_ Maximum
  - _2. Optimal Substructure?_ Yes, Does smaller solution cumulate to give bigger solution? Yes gain is calculated by careful selection of element.
  - _3. Greedy solution does not fit:_ Take example:`[5, 5, 5, 6, 6, 6, 6, 7, 7, 10, 10, 10, 10]`if we greedily choose 6. Gain would be 24, but 5's and 7's gain becomes 29

<a name=l1></a>
### Logic = [DP Template](/DS_Questions/Algorithms/Dynamic_Programming/README.md#tem)
- _1._ Create a hash map of number and times its occuring. Number of times is the gain. Also note max number.
```c
Hashmap
  key   Value=Gain
  5     15
  6     24
  7     14
  10    40

max_number = 10
```
- _2. State_ = Gain on choosing particular number.
- _3._ Define a function to return gain from number=i
```c
int gain(int i) {
}
```
- _4. Recoccurance Relation:_ can we derive gain from present number from prev gain?
```c
//Taking present number's gain
gain = gain(i) + gain(i-2);      //Because we cannot get points for i-1, But all points upto i-2 add up

//if we donot take present number's gain
gain = gain(i-1)                //we donot consider gain(i+1) since this will be calculated as we move to i+1

gain(i) = max(gain(i) + gain(i-2), gain(i-1))
```
- _5._ Base cases: We need to think logically.
```c
i=0, gain=0     //There is no gain in selecting 0
i=1, gain=number of time 1 is found
```
- _6._ Memoize the gains returned in step-4.
```c
unordered_map <number, gain>
```

### Code
#### CPP
```cpp
class Solution {
                 //num, gain
    unordered_map<int, int> umGains;
public:
    int fill(int num, unordered_map<int,int>& um){
        
        //Base cases
        if (!num)
            return 0;
        if (num == 1)
            return um[num];
        
        if (umGains.find(num) != umGains.end())
            return umGains[num];
        
        //Apply recurrance relation
        umGains[num] = max(fill(num-1, um), (fill(num-2, um) + um[num]));
        return umGains[num];
    }
    
    //[5, 5, 5, 6, 6, 6, 6, 7, 7, 10, 10, 10, 10]
    int deleteAndEarn(vector<int>& nums) {
        
        int max_number = 0;
        
        //HashMap <key=number, value=No_of_times>
        //5:15, 6:24, 7:14, 10:40
        //max_number = 10
        unordered_map<int,int> um;
        for (auto itr:nums) {
            um[itr] += itr;
            max_number = max(max_number, itr);
        }
        
        return fill(max_number, um);
    }
};
```

<a name=rs></a>
#### Rust
```rs
use std::collections::HashMap;
use std::cmp::max;
pub struct Solution1{
    pub um_gains: HashMap<i32, i32>,
    pub um: HashMap<i32, i32>,
}
impl Solution1 {
    pub fn new() -> Self {
        Self {
            um_gains: HashMap::new(),
            um: HashMap::new()
        }
    }
}
pub struct Solution{}
impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let mut max_number: i32 = 0;
        let mut s = Solution1::new();
        
        //HashMap <key=number, value=No_of_times>
        let mut um = s.um;
        for i in nums.iter() {
            um.entry(*i).and_modify(|e|{*e+=*i}).or_insert(*i);
            max_number = max(max_number, *i);
        }

        println!("um={:?}",um);
        println!("max_no={:?}",max_number);
        return Self::fill (max_number, &mut um, &mut s.um_gains);
        
    }
    pub fn fill(num:i32, um:&mut HashMap<i32, i32>, um_gains:&mut HashMap<i32, i32>) -> i32 {
        //Base cases
        if num == 0 {
            return 0;
        }
        if num == 1 {
            let a = um.get(&num);
            if a != None {
                return *a.unwrap();
            }
            return 0;
        }

        if um_gains.get(&num) != None {
            return um_gains[&num];
        }
        else{
            let a = Self::fill(num-1, um, um_gains);
            let b = Self::fill(num-2, um, um_gains);
            let c = um.get(&num);
            let mut d = 0;
            if c != None {
                d = *c.unwrap();
            }
            um_gains.insert(num, max(a, b+d));
        }
        return um_gains[&num];
    }
}

fn main() {
    let nums = vec![2,2,3,3,3,4];
    let out = Solution::delete_and_earn(nums);
    println!("Hello, world! {}", out);
}
```
<a name=co></a>
### Complexity
#### Time = O(n)
- O(n): Creating `unordered_map um`. Supposing all numbers are unique.
- O(n): Finding gains `unordered_map umGains`
#### Space = O(n)
- 2O(n): `unordered_map um`
- 2O(n): `unordered_map umGains`
