**Two Sum**
- [Approach-1. 2 for loops. O(n<sup>2</sup>)](#a1)
- [Approach-2. Binary Search](#a2)
- [Approach-3. 2 pointer. O(n)](#a3)
  - [CPP](#cpp)
  - [C](#c)
  - [Java](#j)
  - [Python](#p)
  - [Rust](#r)

### [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
- Given sorted array in ascending order, find two numbers such that they add up to a specific target number.
- Examples
```c
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
```

<a name=a1></a>
### Approach-1 (2 for loops). O(n<sup>2</sup>)
Compare every number with other numbers using 2 for loops and when found 2 numbers, return.
```cpp
  vec1d twoSum(vec1d& numbers, int target) {
    vec1d out;
    for (auto i=0; i<numbers.size(); ++i){
      for (auto j=i+1; j<numbers.size(); ++j){
        if (numbers[i]+numbers[j] == target){
          out.push_back(i+1);
          out.push_back(j+1);
          break;
        }
      }
    }
    return out;
  }
```

<a name=a2></a>
### Approach-2 (Binary Search). O(nlogn)
#### Complexity
- *Time:* O(nlogn).   logn=binary search. n=Incrementing the start by 1 every time
 - *Space:* O(1)
```c
arr[] = {2,4,5,6,7,8,9,11,15}; int target=12;
  Step-1: start=2, end=15, mid(index=4)=7
  Step-2: target > (start+mid). Move to right. start=8, end=15 ..
  
  Cannot find sum. Move to next element ie start=4
```

<a name=a3></a>
### Approach-3 (2 pointer). O(n)
#### Logic
- _1._ Take 2 pointer, one pointing to start, other to end.
- _2._ if sum of `(start + end) > target`, decrement end, else increment start.
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, last = numbers.size()-1;

        vector<int> out;
        while (start < last) {
            int sum = numbers[start] + numbers[last];
            if (sum == target) {
                out.push_back(start+1);
                out.push_back(last+1);
                break;
            } else if (sum > target)
                --last;
            else
                ++start;
        }
        return out;
    }
};
```
<a name=c></a>
**C**
```c
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int start=0, end=numbersSize-1;
    while (start < end) {
        int sum = numbers[start] + numbers[end];
        if (sum > target)
            end--;
        else if (sum < target)
            start++;
        else {  //sum == target
            int* out = (int*) malloc(sizeof(int)*2);
            out[0] = start+1;
            out[1] = end+1;
            *returnSize = 2;        //Set return size
            return out;
        }
    }
    return NULL;
}
```
<a name=j></a>
**Java**
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int start = 0, end = numbers.length-1;
        int[] out = new int[2];
        while (start < end){
            int sum = numbers[start] + numbers[end];
            if (sum > target) 
                end--;
            else if (sum < target)
                start++;
            else {
                out[0] = start+1;
                out[1] = end+1;
                break;
            }
        }
        return out;
    }
}
```
<a name=p></a>
**Python**
```py
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        start = 0
        end = len(numbers)-1
        out = [0,0]
        while start < end:
            sum = numbers[start] + numbers[end]
            if (sum > target):
                end -= 1
            elif (sum < target):
                start += 1
            else:
                out[0]=start+1
                out[1]=end+1
                break
        return out
```
<a name=r></a>
**Rust**
```rs
impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut out:Vec<i32> = Vec::new();
        let mut start:i32 = 0;
        let mut end:i32 = numbers.len() as i32 - 1;
        loop {
            let mut sum = numbers[start as usize] + numbers[end as usize];
            if sum > target {
                end -= 1;
            } else if sum < target {
                start += 1;
            } else {
                out.push(start+1);
                out.push(end+1);
                break;
            }
            if start >= end {
                break;
            }
        }
        out
    }
}
```
