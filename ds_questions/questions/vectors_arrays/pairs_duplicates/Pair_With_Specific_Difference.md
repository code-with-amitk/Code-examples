## [Problem](https://www.pramp.com/challenge/XdMZJgZoAnFXqwjJwnpZ)
- Given an array arr of distinct integers and a nonnegative integer k, write a function fun() that returns an array of all pairs `[x,y]` in arr, such that x - y = k. If no such pairs exist, return an empty array.
- Note: the order of the pairs in the output array should maintain the order of the y element in the original array.
- Examples:
```c++
Example1:
input:  arr = [0, -1, -2, 2, 1], k = 1
output: [[1, 0], [0, -1], [-1, -2], [2, 1]]

Example2:
input:  arr = [1, 7, 5, 3, 32, 17, 12], k = 17
output: []
```

## Logic
1. Traverse the array and add a key-value pair of `(arr[i] - k, arr[i])` to a hash map. 
2. Once the map is populated, we traverse the array again, find key = `arr[i]`
  - *a.* if key exists, return pair `(arr[i], arr[i] -k)`
  
## Complexity
- **Time = O(n)**
  - O(n) for step-1
  - O(n) for step-2
- **Space**
  - 2O(n). Keeping unordered_map<int,int>

## Code
```c++
std::vector<std::vector<int>> findPairsWithGivenDifference( const std::vector<int>& v, int k) {
  std::vector<int> temp;
  std::vector<std::vector<int> > out;

  std::unordered_map<int,int> um;

  for (int i = 0; i < v.size(); ++i)                  //1
    um.insert(std::make_pair(v[i]-k, v[i]));

  for (int i = 0; i < v.size(); ++i) {                //2
    auto it = um.find(v[i]);
    if (it != um.end()){
      temp.push_back(it->second); temp.push_back(it->first);
      out.push_back(temp);
      temp.clear();
    }
  }
    return out;
}
```
