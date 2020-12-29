### [Question](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/)
  - Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
  
#### Example-1
```
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
```

#### Example-2
```
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
```

### Logic
  1. Count number of times element is repeated in array   //unordered_map<key=element, value=count_in_array>  //O(n)
  2. Create vector containing only values from map    //O(m)
  3. Convert vector into min_heap   //O(logn)
  4. Decrement top of min_heap until k>0    //O(1)
  
### Complexity
  O(nlogn)
```
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int,int> um;  //<value,count>
    unordered_map<int,int>::iterator it;
    vector<int> v;

    //1. create unordered_map <key=element, value=count>
    for (auto i:arr)
        um[i] = um[i]+1;

    //2. Fill second element into vector
    for (auto i: um)
        v.push_back(i.second);

    //3. Create min_heap from vector
    make_heap(begin(v), end(v), greater<int>());

    //4. Decrement top of min_heap until k>0
    while(k>0){
        k -= v.front();
        pop_heap(begin(v), end(v), greater<int>());
        if (k >= 0)
            v.pop_back();
    }
      for(auto i:um)
        cout<<i.first<<","<<i.second<<endl;
      return v.size();
    }
};
int main(){
  Solution s;
  vector<int> a={5,5,4};
  cout<<s.findLeastNumOfUniqueInts(a,1);
//  vector<int> a={4,3,1,1,3,3,2};
//  cout<<s.findLeastNumOfUniqueInts(a,3);
}
```
