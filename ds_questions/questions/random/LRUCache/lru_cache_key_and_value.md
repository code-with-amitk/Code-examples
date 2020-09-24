## Cache
- **What is Cache**
  - Cache is used in computers to store the pages which are most frequently used.
- **Limitation of Cache**
  - **1. Cache size is small?** if cache is huge as Hard disk, then it searching will take time and cache would not be fast.
  
## LRUCache
### What?
  - When cache is full, remove least recently used Page entry.
  - When cache is not full, insert a new Page into cache.
  
### LRU Cache Example
```c++
Cache:  {key = UniquePriority,  Value = PageAddress}
```

- **1.** Suppose cache has capacity to store 5 entries `<key, Value>` pair. 

  |Key,Value| 1, 0x10 (MostRecentlyUsed)| 2, 0x20 | 3, 0x30 | 4, 0x40 | 5, 0x50 (LeastRecentlyUsed)|
  |---|---|---|---|---|---|


- **2.** Request for `<key,value> = <6,0x60>` comes in, which is cache miss. Hence LRU is deleted and entry is inserted at head.

  |Key,Value| 6,0x60 MRU | 1, 0x10 | 2, 0x20 | 3, 0x30 | 4, 0x40 LRU|
  |---|---|---|---|---|---|

- **3.** Next, request for `<key,value> = <3,0x30>` comes in, which is cache hit. Hence `<3,0x30>` becomes MRU.

  |Key,Value| 3, 0x30 MRU| 6,0x60 | 1, 0x10 | 2, 0x20 | 4, 0x40 LRU|
  |---|---|---|---|---|---|

### Data Structures to Implement LRUCache? 
> Insert/Remove/Search time complexity = O(1)

|Operation|How|DataStructure|
|---|---|---|
|Search a `<key,value>`|<ul><li>Before insert/remove `<key,value>`, that entry has to searched in cache</li></ul><ul><li>if `<key,value>` is present its made Most recently used.</li></ul><ul><li>if `<key,value>` is absent, LRU entry is removed and new key is made MRU</li></ul>|Hash-Table|
|Insertion (O(1))|Done at head|Doubly Linked-List|
|Removal (O(1))|Done at tail|Doubly LL|

- **How Hash-table<key, value> is used?** `<key=PageNumber, value=address-of-queue-node>`
  
![ImgURL](https://i.ibb.co/FJw3qHX/LRUCache-key-value-pair.png)    

### Logic
- **Doubly LL** container to store cache entries. entry is added at front. entry is removed from back, considering last used.
- **Hash-table <key, Address-of-LL>** when request comes to update cache, it searches key in hash-table if found go to LL. This is O(1) operation.
```c++
Space   //Considering n elements
  List:   <key=8byte, value=8byte> + <prev=8byte, next=8byte> = 4n
  Hash:   <key=8byte, value=8byte> = 2n
  O(6n)
  
Time:
  insert: O(1)
    -> Search/Delete in unordered_map=O(1) 
    -> Insert at front of list=O(1)
```         

### Code
```c++
#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Cache {
public:
  list <pair<int, int>> lst;                              //Actual cache <key,value>
  unordered_map <int, list<pair<int,int>>::iterator> um;  //um<key,address-of-key>
  int cp;
  Cache(int c):cp(c){}
  ~Cache(){}
  virtual void set(int key, int value)=0;   //Set <Key,value> pair in list
  virtual int get()=0;                      //Return 
  virtual void display()=0;
};

class LRUCache : public Cache {
      unordered_map <int, list<pair<int,int>>::iterator>::iterator it;
public:
  LRUCache (int c) : Cache(c) {}

  void set(int key, int val) {
//    cout<<"Capacity="<<cp;
    pair<int, int> lru;

    if (lst.size() < cp) {        //Cache has place, insert at head

      lst.push_front ( make_pair(key, val));
      um [key] = lst.begin();

    } else {                    //Cache full

      if ( (it = um.find (key)) == um.end() ) {  //Cannot find key in cache

        lru = lst.back ();                            //Remove last entry ie lru
        lst.pop_back ();
        um.erase (lru.first);

        lst.push_front (make_pair(key,val));          //Insert new entry at front
        um [key] = lst.begin();

      } else {                                    //Cache is Full and entry is found
        lst.erase(it->second);
        um.erase (key);

        lst.push_front (make_pair(key,val));     //Insert again at front
        um [key] = lst.begin ();
      }

    }
  }

  void display(){
    list<pair<int,int>>::iterator i;
    for (i=lst.begin(); i != lst.end(); ++i)
      cout << i->first <<","<< i->second <<"\n";
      cout<<"\n";
  }

  int get (int key) {                         //Return value correponding to key
    if ( (it = um.find (key)) == um.end() ) {
      return -1;
    } else {
      //return value from key in lru
      return it->second->second;
    }
  }
};      
int main(){
  LRUCache l(4);
  l.set(1,10);                       //set(key,value)
  l.set(2,20);
  l.set(3,30);
  l.set(4,40);
  l.set(5,50);
  l.set(3,300);
  l.display();
}

```
