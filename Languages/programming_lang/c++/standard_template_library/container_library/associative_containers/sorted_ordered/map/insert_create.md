### Insert

||insert()|emplace() = Inplace insertion|
|---|---|---|
|What|<ul><li>Used for inserting element into stl</li></ul><ul><li>Creates object somewhere else, copies objects into the vector</li></ul>|<ul><li>same</li></ul><ul><li>construct them inside of the vector</li></ul>|
|Preferred||Yes, over insert()|
|Adv||<ul><li>Does in place insertion, avoids unneccessary copy</li></ul>|

- **1. insert()**
```c++
pair<iterator,bool> insert (const value_type& val);
template <class P> pair<iterator,bool> insert (P&& val);

map< char, int > m;
m.insert(make_pair('a', 1));
```
- **2. emplace**
```c++
template <class... Args>
  pair<iterator,bool> emplace (Args&&... args);
  
m.emplace('b', 2);

for (auto i:m)
  cout << i;                    //a 1   b 2
```
