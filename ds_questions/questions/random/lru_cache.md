## LRU Cache?
- **What is Cache?**
  - Cache is used in computers to store the pages which are most frequently(or often asked and used). 
  - But there is limitation that size of cache is not huge as Hard disk, because if it becomes large then searching will take time and cache should be fast.
- **What is LRUCache?** 
  - This is a caching scheme where least recently used Page entry is removed when cache is full and insert a new Page needs to be inserted which is not there in cache.
  - **LRU Example**
```c++
LRUCache: <key=PageNumber> arranged from MostRecent to LeastRecent
- Suppose cache has capacity to store 5 entries/PageNumbers. 
          5           3         2        1        4
  MostRecentlyUsed                           LeastRecentlyUsed
- Now, next key=PageNumber comes in is 1(which is a cache hit), then the cache state will be:
          1           5         3         2         4 
- Next key=PageNumber comes in 6(which is a cache miss), then the cache state will be:
          6           1         5         3         2
  //NOTE: 4=lru removed.
```
  - **How to Implement LRUCache?** Insert/Remove/Search should be O(1)
  
|Operation(should be O(1))|How|Datastrcuture|
|---|---|---|
|Search a key=PageNumber|<ul><li>Before insert/remove a key, that key has to searched in cache</li></ul><ul><li>Because if key is present its made Most recently used</li></ul><ul><li>if key is absent, LRU entry is removed and its made MRU</li></ul>|Hash-Table|
|Insertion (O(1))|Done at head|Doubly Linked-List|
|Removal (O(1))|Done at tail|Doubly LL|


### Logic
- **Data-Structures** 
  - **Doubly LL** container to store cache entries.
    - entry is added at front.
    - entry is removed from back, considering last used.
  - **Hash-table <key, value>** key=page-number, value=address-of-queue-node
- **Operations:**
  - insert(value): value will always be inserted at LL front.
    - case-1: Cannot find entry inside hash-table
      - cache is full and entry not present: Remove last entry
      - cache is empty: In both cases, Add entry at front
- **Complexity**
  - Space: 
```c++
        list=2k+n + Hash=k+n    //Considering n elements
        2k+n=prev+val+next, k+n=key+value
        O(3k+ 2n)
 ```
 - Time:
```c++
        insert: O(1), because finding element in unordered_map=O(1) and pushing at front of list=O(1)
```         

### Code
```c++
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class cache {
  list<int> l;            //Actual cache
  unordered_map<int, list<int>::iterator> um;     //Hash-Table. Insert/Display: O(1)
  int size;               //Size of cache
public:
  cache(int a):size(a){}
  void insert(int);
  void display();
};

/* Function to insert Page into cache
*/
void cache::insert(int val){
  int lru;

  if (um.find(val) == um.end()){          //Cannot find entry in cache

    //Cache full. Remove last entry(Least recently used)
    if (l.size() == size){
      lru = l.back();
      l.pop_back();
      um.erase(lru);
    }else{                                  //entry found in cache, remove
      l.erase(um[val]);
    }

    //Insert value always at front of cache, and store in map
    l.push_front(val);
    um[val] = l.begin();
}

void cache::display(){
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
