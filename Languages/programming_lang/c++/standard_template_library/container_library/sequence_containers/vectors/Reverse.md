### reverse[first, last)
- Reverses from first to last. Including first and excluding last.
```c++
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  
  reverse (arr.begin(), arr.end());       //6, 5, 4, 3, 2, 1
  
            //reverse From [0, 2)
  reverse (arr.begin(), arr.begin()+3);    //3, 2, 1, 4, 5, 6
```
