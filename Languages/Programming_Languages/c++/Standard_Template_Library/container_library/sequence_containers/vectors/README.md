- [Vector, How vector works](#what)
  - [Arraylist vs Vector](#vs)
- [Insert](#ins)
- [Traverse/Iterate](#trav)
- [Erase/Delete/Remove](#erase)
  - Delete Last: pop_back()
  - [Any Element](#any)
  - [Delete Range](#range)
  - [Erase all](#erase)
- Search
  - [Min Element](#min)
  - [Max Element](#max)
  - [Any](#any)
- [Reverse](#reverse)

<a name=what></a>
## Vector
- Dynamic Allocated Array, Elements are stored in contiguous location.
- Vector keeps some space reserved in advance for storage of some variables. Now when this space is exhausted. It again re-allocates bigger contiguous space, copies the elements to new space, deletes present memory.  
<a name=vs></a>
#### Arraylist vs vector
- Vectors are synchronized by default but ArrayLists are not. Means if multiple threads accesses vectors then no synchronization needed but required in AL.    

<a name=insert></a>
## Insert
- _void push_back(T&& value)_
```c++
  vector<int> v(2,10);      //size=5, Each element value=10
  v.push_back(11);          //10 10 11
```
- *2. void assign(size, val):*  Replaces the contents with count copies of value
```c++
  vector<int> v;
  v.assign(3,10);            //10 10 10  
```
- *3. insert(position, value)*
```c++
  vector<int> v = { 1, 2, 3};
  it = vec.insert(v.begin() + 2, 7);      //1 2 7 3
```

<a name=trav></a>
## Traverse / Iterate
- *By index*
```c++
  for(int i=0;i<v.size();i++)
    cout<<v[i];
```
- *begin(), end()*
```c++
  for(auto i=v.begin();i!=v.end();i++)
    cout<<*i;
```
- *`vector<int>::iterator itr`*
```c++
  vector<int>::iterator itr;
  for(itr=v.begin(); itr!=v.end(); itr++)
    cout<<*itr;
```
- *vector.at(position):* Returns a reference to the element at position n in the vector.
  - This is same operator`[]` but .at() checks the bounds of array while `operator[]` does not. at() throws `out_of_range` exception when index is out of bounds.
```c++
vector<int> v = {1,2,3};
cout<<v.at(2);            //3
cout<<v.at(3);            //terminate called after throwing an instance of 'std::out_of_range' coredumped
```

### Erase/Delete/Remove
<a name=any></a>
#### iterator erase(const_iterator pos)
- Remove element at position
```cpp
  v.erase(v.begin());
```
<a name=range></a>
#### iterator erase(const_iterator first, const_iterator last )
- Remove in range
```cpp
  v.erase(v.begin()+1, v.end()-1);
```
<a name=erase></a>
#### void clear() noexcept
- Erases all elements from the container. After this call, size() returns 0. 
```cpp
  v.clear();
```

### Search
<a name=max></a>
#### Max Element
```cpp
vector<int> a = {4,5,2};
cout << *max_element(a.begin(), a.end());
cout << "Index of max element=" << max_element(a.begin(), a.end()) - a.begin();
```
<a name=min></a>
#### Min Element
```cpp
vector<int> a = {4,2,5};
cout << *min_element(a.begin(), a.end());
cout << "Index of max element=" << min_element(a.begin(), a.end()) - a.begin();
```
<a name=any></a>
#### Any Element
```cpp
vector<string> v = {"test", "self"};
iterator = find(v.begin(), v.end(), "test");
```

<a name=reverse></a>
### `reverse[first, last)`
- Reverses from first to last. Including first and excluding last.
```cpp
  vector<int> v = {1, 2, 3};
  reverse (v.begin(), v.end());
  reverse (v.begin(), v.begin()+3);    //reverse From [0, 2)
```
