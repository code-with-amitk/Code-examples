## [Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)
- Given an array of positive integers w where `w[i]` describes the weight of ith index (0-indexed).
- Write function pickIndex() which returns element propostional to its probability of happening.
- Example
```c
Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Solution: Constructor will pass vector [1,3]

Output
[null,1,1,1,1,0]
null=Solution
1=returned by pickIndex.  Probability of selecting index=1 is 3/(1+3) = 3/4 = 75%
1=same
1=same
0=returned by pickIndex.  Probability of selecting index=0 is 1/(1+3) = 1/4 = 25%. Only 1 chance out of 4
```

### Approach-1    //PrefixSum, Linear Search
- **Logic:** 
  - *1.* Create prefixSum array
```c
Input   =   [1 2 3 4 5]
prefixSum = [1 3 6 10 15]   //which is sum of all preceding elements till that index
```
  - *2.* Generate a random number in range `[0, lastElementIn_prefixSum_array]` so that we will pick that index
  - *3.* Search nearest number of Random number in prefixSum array and return the index of that element.
- **Complexity:**
  - **Time:** O(n)
  - **Space:** O(n)
- **Code**
```c++
class test {
  vector<int> prefixSum;
public:

  //Create prefixSum array from input array
  test(vector<int> &v) {
    prefixSum.push_back(v[0]);
    
    for (auto i=1; i<v.size(); ++i)
      prefixSum.push_back (v[i] + prefixSum.back());

   //prefixSums.push_back(n + (prefixSums.empty() ? 0 : prefixSums.back()));
  }

  int pickIndex() {
  
    //Generate a random number in the range of [0.....lastElementIn_prefixSum_array]
    float Random =  ((float) rand() / RAND_MAX) * prefixSum.back();
    
    //Search linearly to find index
    for (int i = 0; i < prefixSum.size(); ++i) {
      if (Random < prefixSum[i])
        return i;
    }
     
    //else return last element
    return prefixSum.size() - 1;
  }
};
```

### Approach-2  //PrefixSum, Binary Search
- **Logic:** Same as approach-1, just we will search index using binary search
- **Complexity:**
  - **Time:** O(logn)
  - **Space:** O(n)
- **Code:**
```c++
class test {
  vector<int> prefixSum;
public:

  //Create prefixSum array from input array
  test(vector<int> &v) {
    prefixSum.push_back(v[0]);
    
    for (auto i=1; i<v.size(); ++i)
      prefixSum.push_back (v[i] + prefixSum.back());

   //prefixSums.push_back(n + (prefixSums.empty() ? 0 : prefixSums.back()));
  }

  int pickIndex() {
  
    //Generate a random number in the range of [0.....lastElementIn_prefixSum_array]
    float Random =  ((float) rand() / RAND_MAX) * prefixSum.back();
    
    return upper_bound(begin(prefixSums), end(prefixSums), Random) - begin(prefixSums);
  }
};
```
