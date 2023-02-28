- [Vector, How vector works](#what)
  - [Arraylist vs Vector](#vs)
- [Initialize](#ini)
- Insert
  - [At end: `push_back(), emplace_back()`](#emp)
  - [At any place `insert(position, value)`](#any)
- [Traverse/Iterate](#trav)
- [Erase/Delete/Remove](#e)
  - Delete Last: pop_back()
  - [1 Element](#one)
  - [Delete Range](#r)
  - [Erase all](#erase)
- [Merge](#merge)
- Search/Print
  - [Min Element](#min)
  - [Max Element](#max)
  - [Any](#any)
  - [Last](#last)
  - [lower_bound (uses binary search)](#lb)
- [Reverse](#reverse)
- [Convert to min_heap, max_heap](#conv)

<a name=what></a>
## Vector
- Dynamic Allocated Array, Elements are stored in contiguous location.
- Vector keeps some space reserved in advance for storage of some variables. Now when this space is exhausted. It again re-allocates bigger contiguous space, copies the elements to new space, deletes present memory.  
<a name=vs></a>
#### Arraylist vs vector
- Vectors are synchronized by default but ArrayLists are not. Means if multiple threads accesses vectors then no synchronization needed but required in AL.    

<a name=ini></a>
## Initialize
```c
vector<int> v(size, init_value);
vector<int> v(4, 10);           //vector of 4 ints, initialized to 10
```

## Insert
<a name=emp></a>
#### Insert At end `[push_back(), emplace_back()]`
- _void push_back(T&& value), void emplace_back(T&& value)_
  - push_back() allocates element somewhere else then insert into vector at back.
  -  emplace() also inserts at back, it But constructs elements inside the stl only. *Adv:* Does in place insertion, avoids unneccessary copy
```c++
  vector<int> v(2,10);      //size=5, Each element value=10
  v.push_back(11);          //10 10 11
  
  v.emplace_back(11);       //10 10 11
```
<a name=any></a>
#### Insert At any place `insert(position, value)`
```cpp
  vector<int> v = { 1, 2, 3};
  it = vec.insert(v.begin() + 2, 7);      //1 2 7 3
```
- *void assign(size, val):*  Replaces the contents with count copies of value
```c++
  vector<int> v;
  v.assign(3,10);            //10 10 10  
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

<a name=e></a>
## Erase/Delete/Remove
<a name=one></a>
#### Delete 1 element
```cpp
  //iterator erase(const_iterator pos)
  v.erase(v.begin()+position-1);
```
<a name=r></a>
#### Delete range
```cpp
  //iterator erase(const_iterator first, const_iterator last )
  v.erase(v.begin()+position1-1, v.begin()position2-1);
```
<a name=erase></a>
#### Delete all
- Erases all elements from the container. After this call, size() returns 0. 
```cpp
//void clear() noexcept
  v.clear();
```

<a name=merge></a>
## Merge
```cpp
  using itr = std::vector<int>::iterator;
  std::vector<int> v1 = {1, 3, 5, 7};
  std::vector<int> v2 = {2, 4, 6, 8};

  itr it1 = v1.begin();
  itr it2 = v2.begin();
  
  /* OutputIt merge( InputIt1 first1, InputIt1 last1,
                 InputIt2 first2, InputIt2 last2,
                 OutputIt d_first );
  */
  std::merge(it1, v1.end(), it2, v2.end(), v1.begin());
```

## Search
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
<a name=last></a>
#### last element
```cpp
cout << v.back();
```

<a name=lb></a>
#### lower_bound
## lower_bound (this uses binary_search)
- Returns Iterator to 1st occurence of number in sorted Array.
- if number does not exist, returns number just greater than searched value.
```c++
//ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val);

array  1 1 5 5 8 8 9 9 10 11
index  0 1 2 3 4 5 6 7 8  9

int main() {
  vector<int> a = {1,1,5,5,8,8,9,9,10,11};
  vector<int>::iterator it = lower_bound(a.begin(), a.end(), 8);     //Search 8
  cout << "index:" << it - a.begin();     //4
  
  vector<int>::iterator it = lower_bound(a.begin(), a.end(), 4);     //Search 4
  cout << *it;                            //5
  cout << "index:" << it - a.begin();     //2
}
```


<a name=reverse></a>
### `reverse[first, last)`
- Reverses from first to last. Including first and excluding last.
```cpp
  vector<int> v = {1, 2, 3};
  reverse (v.begin(), v.end());
  reverse (v.begin(), v.begin()+3);    //reverse From [0, 2)
```

<a name=conv></a>
## Convert to min_heap, max_heap
```cpp
  vector<int> a = {2,3,4,1};
  make_heap(a.begin(), a.end(), greater<int>());    //To min_Heap
  make_heap(a.begin(), a.end());                    //To max_heap
```
