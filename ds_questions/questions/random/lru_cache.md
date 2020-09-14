## LRU Cache?
- **What** Remove least recently used entry when cache is full and insert a new entry which is not there in cache.
- **Example**
```c++
- Suppose cache has capacity to store 5 keys (arranged from most recently used key to least recently used keys):
5 3 2 1 4
- Now, next key comes in is 1(which is a cache hit), then the cache state will be:
1 5 3 2 4
- Now, If the next key comes in 6(which is a cache miss), then the cache state will be:
6 1 5 3 2
//NOTE: 4 has been discarded because it was the least recently used key and since the capacity of cache is 5, it could not be retained in the cache any longer.
```

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
