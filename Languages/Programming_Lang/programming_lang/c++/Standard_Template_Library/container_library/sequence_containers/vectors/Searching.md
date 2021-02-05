### 1. Maximum element
```c++
vector<int> a = {0,1,4,5,6,7,2,3};
cout << *max_element(a.begin(), a.end());         //7
cout << "Index of max element=" << max_element(a.begin(), a.end()) - a.begin();    //5
```

### 2. Minimum Element
```c++
vector<int> a = {1,4,5,0,6,7,2,3};
cout << *min_element(a.begin(), a.end());           //0
cout << "Index of max element=" << min_element(a.begin(), a.end()) - a.begin();    //3
```

### 3. Element in vector
```c++
  iterator = find(startIterator, endIterator, ItemToFind);
```
