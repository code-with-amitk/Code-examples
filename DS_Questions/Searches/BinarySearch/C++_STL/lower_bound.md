## lower_bound
- Returns Iterator to 1st occurence of number in sorted Array.
```c++
array  1 1 5 5 8 8 9 9 10 11
index  0 1 2 3 4 5 6 7 8  9
               /\

int main() {
  vector<int> a = {1,1,5,5,8,8,9,9,10,11};
  vector<int>::iterator it = lower_bound(a.begin(), a.end(), 8);
  
  cout << it - a.begin();     //4
}
```
