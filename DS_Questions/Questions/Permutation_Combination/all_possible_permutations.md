## Problem
- Given integer array, return all possible permutations

### Example
```
Input: [1,2,3]
Output:
  {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,1,2}, {3,2,1}
```

## Code
```
vector<vector<int>> permute(vector<int>& a) {

  vector<vector<int>> v;
  
  sort(a.begin(),a.end());
  
  do{
    v.push_back(a);
  }while(next_permutation(a.begin(),a.end()));
  
  return v;
}
```
