- [Vector, How vector works](#what)
  - [Arraylist vs Vector](#vs)
- [Functions](#fun)
<a name=what></a>
## Vector
- Dynamic Allocated Array, Elements are stored in contiguous location.
- Vector keeps some space reserved in advance for storage of some variables. Now when this space is exhausted. It again re-allocates bigger contiguous space, copies the elements to new space, deletes present memory.  
<a name=vs></a>
#### Arraylist vs vector
- Vectors are synchronized by default but ArrayLists are not. Means if multiple threads accesses vectors then no synchronization needed but required in AL.    

<a name=fun></a>
### Functions
||C++|Rust|Python|
|---|---|---|---|
|Initialize|<ul><li>`vector<int> v(size, init_value)`</li> <li>v.assign(3,10);//10 10 10</li></ul>|
|push_back()|<ul><li>push_back() allocates element somewhere else then insert into vector at back.v.push_back(11)</li> <li>emplace() also inserts at back, it But constructs elements inside the stl only. *Adv:* Does in place insertion, avoids unneccessary copy. v.emplace_back(11)</li></ul>|||
|Insert|vec.insert(v.begin() + 2, 7)|
|Traverse|<ul><li>**for_each** for_each (v.begin(), v.end(),`[&i]`(int element{element += i;});</li> <li>**Iterator** `for(auto i=v.begin();i!=v.end();i++) cout<<*i;`</li></ul>|||
|At position|v.at(2)|
|Delete|<ul><li>**1 element** v.erase(v.begin()+position-1);</li> <li>**Range** `v.erase(v.begin()+position1, v.begin()position2);`</li> <li>**All** v.clear();</li></ul>|||
|Merge|std::merge(it1, v1.end(), it2, v2.end(), v1.begin());|||
|Search|<ul><li>**max element** `*max_element(a.begin(), a.end());`</li> <li>**min element** *min_element(a.begin(), a.end())</li> <li>**Any element** iterator = find(v.begin(), v.end(), "test")</li></ul>|||
|Last Element|v.back()|||
|Reverse|reverse (v.begin(), v.begin()+3)|||
|Convert to heap|<ul><li>**min heap** make_heap(a.begin(), a.end(), greater<int>())</li> <li>**max heap** make_heap(a.begin(), a.end())</li></ul>||||

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
