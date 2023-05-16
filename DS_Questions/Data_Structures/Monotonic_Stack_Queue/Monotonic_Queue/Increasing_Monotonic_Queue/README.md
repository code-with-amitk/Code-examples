**Increasing Monotonic Queue**
- [What](#w)
- [Code](#c)

### Increasing Monotonic Queue
<a name=w></a>
#### What
- This will store longest incresing [Sub-sequence](DS_Questions/Questions/vectors_arrays/SubSequence_SubArray).
- Example
```c
input = { 1, 3, -1, -3, 5, 3, 6, 7}
Monotonic Increasing Queue = {-3, 3, 6, 7}
```

<a name=c></a>
#### Code
```c
/*
input=  | 1, 3, -1, -3, 5, 3, 6, 7 |
          0  1   2   3  4  5  6  7
  i   monotonic_queue
  0   1
  1   1     3
      front back
      
  2   (3 > -1). Remove 3
      (1 > -1). Remove 1
      
  3   -3
  4   -3     5
      front back
      
  5   (5 > 3). Remove 3
      -3  3
  6   -3  3   6
  7   -3  3   6   7
  
  //Note monotonic Queue contains all increasing Sub-Sequences.
  //Finally Queue keeps longest increasing Sub-Sequence.
*/
deque<int> increasing_monotonic_queue(vector<int>& v) {
    deque<int> q;
    for (auto&i: v) {
        while (!q.empty() && q.back() > arr[i]) 
            q.pop_back();
            
        q.push_back(i);
    }
    return q;
}

int main() {
  vector<int> v =  { 1, 3, -1, -3, 5, 3, 6, 7};
  deque<int> q = increasing_monotonic_queue(v);
  for (int i : q)
      cout << i << " ";           //-3 5 6 7
  return 0;
}
```
