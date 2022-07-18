**Two Sum / Pair with Sum of X**
- [Approach-1, O(n^2), Brute Force](#a1)
- [Approach-2, HashTable](#a2)
- **Multithreaded**
  - [1. lock_guard](#m1)

## [Two Sum](https://leetcode.com/problems/two-sum)
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
```c
Input: nums = [2,11,15,7], target = 9
Output: [0,3] //index

Input: nums = [3,3], target = 6
Output: [0,1]
```

<a name=a1></a>
### Approach-1  //Brute Force, O(n<sup>2</sup>)
#### Logic 
Use 2 for loops iterate over element, find duplicate
```cpp
  for(int i=0; i<v.size(); ++i)
    for(int j=i; j<v.size(); ++j)
      if(v[i] + v[j] == target)
        //Return i,j
```

<a name=a2></a>
### Approch-2, HashTable
#### Logic
*1.* Take hash-tables. key is value of input array and value=index. Check whether target-present_value exist in map. 
  - if it exists pair exists
#### Complexity
Time:O(n), Space:O(n)
#### Code
```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int> out;
        unordered_map<int,int> umm;

        for (int i=0; i<v.size(); ++i) {
            auto it = umm.find(target-v[i]);
            if (it == umm.end())
                umm.insert({v[i], i});
            else {
                out.push_back(it->second);
                out.push_back(i);
                break;
            }
        }
        return out;  
    }
};
int main(){
    Solution s;
    vector<int> v = {2,7,11,15}; int target = 9;
    vector<int> o = s.twoSum(v, target);
    cout << o[0] << "," << o[1] << "\n";
}
```

### Multithreaded
<a name=m1></a>
#### 1. [Using lock_guard](https://leetcode.com/submissions/detail/750056009/)
> [What is lock_guard](/Threads_Processes_IPC/IPC/synchronization/Mutex/README.md#lg)
- Incoming vector is divided into 2 parts. 1st part processed by thread1, other by thread2
```cpp
mutex m;
class Solution {
    vector<int> out;
    unordered_map<int,int> um;
public:
    void find(vector<int>& v, int start, int end, int target){
        lock_guard<mutex> lg(m);                      //if you remove lock_guard, corruption will happen

        for (int i=start; i<end; ++i) {
            auto it = um.find(target-v[i]);
            if (it == um.end())
                um.insert({v[i], i});
            else {
                out.push_back(it->second);
                out.push_back(i);
                break;
            }
        }
    }
    vector<int> twoSum(vector<int>& v, int target) {
        int size = v.size();
        thread t1(&Solution::find, this, ref(v), 0, size/2, target);
        thread t2(&Solution::find, this, ref(v), size/2, size, target);
        t1.join();                                      //Both threads need to be joined before return
        t2.join();                                      //Because if main exits before threads, result will not reflect in out.
        return out;    
    }  
};
```
