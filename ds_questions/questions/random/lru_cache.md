## Cache
### What is Cache
  - Cache is used in computers to store the pages which are most frequently used.
### Limitation of Cache
  - **1. Cache size is small?** if cache is huge as Hard disk, then it searching will take time and cache would not be fast.
### LRUCache?  
  - **What?** 
    - When cache is full, remove least recently used Page entry.
    - When cache is not full, insert a new Page into cache.
  - **Example**
```c++
<key=PageNumber> arranged from MostRecent to LeastRecent
- Suppose cache has capacity to store 5 entries/PageNumbers. 
          5           3         2        1          4
  MostRecentlyUsed                           LeastRecentlyUsed
- Now, next key=PageNumber comes in is 1(which is a cache hit), then the cache state will be:
          1           5         3         2         4 
- Next key=PageNumber comes in 6(which is a cache miss), then the cache state will be:
          6           1         5         3         2
  //NOTE: 4=lru removed.
```
- **Data Structures to Implement LRUCache?** Insert/Remove/Search
  
|Operation(should be O(1))|How|DataStructure|
|---|---|---|
|Search a key=PageNumber|<ul><li>Before insert/remove a key, that key has to searched in cache</li></ul><ul><li>Because if key is present its made Most recently used(nothing deleted from cache)</li></ul><ul><li>if key is absent, LRU entry is removed and new key is made MRU</li></ul>|Hash-Table|
|Insertion (O(1))|Done at head|Doubly Linked-List|
|Removal (O(1))|Done at tail|Doubly LL|

- **How Hash-table<key, value> is used?** `<key=PageNumber, value=address-of-queue-node>`
  
![ImgURL](https://i.ibb.co/1n22bjF/LRUCache-Hash-Doubly-LL.png)    

### Logic
- **Doubly LL** container to store cache entries. entry is added at front. entry is removed from back, considering last used.
- **Hash-table <key, value>** 
- **Complexity**
```c++
Space
  list=2k+n + Hash=k+n    //Considering n elements
  2k+n=prev+val+next, k+n=key+value
  O(3k+ 2n)
  
Time:
  insert: O(1), because finding element in unordered_map=O(1) and pushing at front of list=O(1)
```         

### Code
```c++
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class cache {
  list<int> l;                                       //Actual cache
  unordered_map < int, list<int>::iterator > um;     //Hash-Table. <key=PageNumber, value=AddressOfPage>
  int size;                                          //Size of cache
public:
  cache (int a) : size (a) {}
  void insert ( int );
  void display ();
};

// Function to insert Page into cache
void cache::insert (int val) {
  int lru;
  
  if ( l.size() < size ) {    //Cache has place. Insert at head
    l.push_front (val);
    um [val] = l.begin();
  } else {                //Cache is Full
    if ( um.find (val) == um.end() ) {  //Cannot find entry
      lru = l.back ();    //Remove lru
      l.pop_back ();
      um.erase (lru);

      l.push_front (val);   //Insert at front
      um [val] = l.begin();
    } else {            //Cache is Full and entry is found
      l.remove (val);   //Remove entry from mid
      um.erase (val);

      l.push_front (val);     //Insert again at front
      um[val] = l.begin ();
    }
  }
  
}

void cache::display () {
  for (auto i = l.begin(); i != l.end(); i++)
    cout << (*i) << " ";
  cout << endl;
}

int main(){
  cache obj(3);
  obj.insert(1);
  obj.insert(2);
  obj.insert(3);
  obj.insert(4);
  obj.insert(5);
  obj.display();
  return 0;
}

/*
# g++ lru-cache.cpp 
# ./a.out 
5 4 3 
*/
```
