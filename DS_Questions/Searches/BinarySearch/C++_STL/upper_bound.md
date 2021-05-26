## Upper bound
```c++
ForwardIterator  upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp)
```
- Returns iterator to (last index+1) of number in array.
- **Searching element**
```c++
array  1  1  5  5  8  8  9  9  10  11
index  0  1  2  3  4  5  6  7  8   9

int main() {
  vector<int> a = {1,1,5,5,8,8,9,9,10,11};
  vector<int>::iterator it = upper_bound(a.begin(), a.end(), 8);
  
  cout << it - a.begin();     //6
}
```
- **[Searching pair in vector](/DS_Questions/Questions/Strings/Length_Find/Time_based_Key_value_store.md)**
```c++
vector<pair<string, int>>  {"a",1}, {"b",2}, {"c",3}, {"e",5}, {"g",7}, {"i",9}
index                         0         1       2        3        4       5

//Searching index of "4". it should return <c,3>(ie index - 1)
```
