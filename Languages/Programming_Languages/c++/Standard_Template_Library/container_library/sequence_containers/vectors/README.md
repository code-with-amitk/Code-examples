- [Vector, How vector works](#what)
  - [Arraylist vs Vector](#vs)
- [Insert](#ins)
- [Traverse/Iterate](#trav)
- [Erase/Delete/Remove](#erase)
- 

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
- **1. iterator erase( const_iterator pos );**   //Since C++11
  - Remove element at position
```c++
  v.erase(v.begin());
  for(auto i:v)
    cout<<i<<" ";           //10 10 10 10 11
```

- **2. iterator erase( const_iterator first, const_iterator last );**  //Since C++11
  - Remove in range
```c++
  v.erase(v.begin()+1, v.end()-1);
  for(auto i:v)
    cout<<i<<" ";           //10 11
```

- **3. void clear() noexcept;**  //Since C++11
  - Erases all elements from the container. After this call, size() returns 0
  - Complexity: Linear in the size of the container, i.e., the number of elements.  
  - parameters: None. Return values: None
```c++
  v.clear();
  cout<<v.size();                 //0
```
