**Time based key value store**
- [Approach-1](#a1)

### [Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)
- Create a timebased key-value store class TimeMap, that supports two operations.
- `1. set(string key, string value, int timestamp):` Stores the key and value, along with the given timestamp.
- `2. get(string key, int timestamp):` Returns a value such that set(key, value, ts). ts <= timestamp.
  - If there are multiple such values, it returns the one with the largest timestamp_prev.
  - If there are no values, it returns the empty string ("").
- Example
```c
input:
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]

|foo, bar, 1|foo, bar2, 4|

get(foo,1) => bar     //Value at timestamp<=1 for key=foo is bar
get(foo,3) => bar     //Value at timestamp<=3 for key=foo is bar
get(foo,4) => bar2    //Value at timestamp<=4 for key=foo is bar2
get(foo,3) => bar2
```

<a name=a1></a>
### Approach-1  //map, Linear search, O(nm)
#### Logic
- *1.* Create map having all <value, timestamp> of same key chained together(Seperate Chaining), if more than 1 key to be inserted having different `<value,timestamp>`.
```c
set()
          [value1, 1], [value4, 4], [value10, 10]
            /\
  | key1, vector | key2, vector<value2, 2> | key3, vector<value3, 3> |
```
- *2.* `get(key)`
  - if key has associated chain, Eg: key1, search chain linearly in reverse order ie from timestamp=10 to 1.
  - if key does not have associated chain, send value back. Eg: key3
#### Complexity
  - **Time:** O(nm)
    - n: Total Number of keys
    - m: Number of repeated keys to be inserted.
    - O(n): Creating map. Insertion
    - O(m): For searching in map
  - **Space:** O(nk + nl)
    - k: Max key length
    - l: Max value length
#### Code
```cpp
class TimeMap {
  using ValueTimestamp = pair<string, int>;
  unordered_map<string, vector<ValueTimestamp>> um;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        um[key].push_back(make_pair(value, timestamp));           //1
    }
    string get(string key, int timestamp) {
      vector<ValueTimestamp>& vecChain = um[key];                   //2
      for (auto it = vecChain.rbegin(); it != vecChain.rend(); ++it) {
      if (it->second <= timestamp)
        return it->first;
      }
      return "";
    }
};
int main(){
  TimeMap* o = new TimeMap();
  o->set("key1","value1",1);
  o->set("key2","value2",2);
  o->set("key3","value3",3);
  o->set("key1","value4",4);
  o->set("key1","value10",10);

  cout<<o->get("key1",1)<<"\n";         //value1
  cout<<o->get("key1",4)<<"\n";         //value4
  cout<<o->get("key1",3)<<"\n";         //value1
}  
```

### Approach-2  //map Seperate Chaining, Binary search, O(nlogm)
- **Logic**
  - *1.* Create map having all <value, timestamp> of same key chained together(Seperate Chaining), if more than 1 key to be inserted having different `<value,timestamp>`.
```c
set()
          [value1, 1], [value4, 4], [value10, 10]
            /\
  | key1, vector | key2, vector<value2, 2> | key3, vector<value3, 3> |
```
  - *2.* `get(key)`
    - if key has associated chain, Eg: key1, Perform binary search on chain
    - if key does not have associated chain, send value back. Eg: key3
  - *3.* if timestamp is not found return "", else return prev to present iterator->first. Since [upper_bound()](/DS_Questions/Searches/BinarySearch/C++_STL) return ForwardIterator ie +1 to upper index.
- **Complexity**
  - **Time:** O(nlogm)
    - n: Total Number of keys
    - m: Number of repeated keys to be inserted. logm: Time taken in binary search
    - O(n): Creating map. Insertion
    - O(m): For searching in map
  - **Space:** O(nk + nl)
    - k: Max key length
    - l: Max value length
- **Code**
```c++
class TimeMap {
  using ValueTimestamp = pair<string, int>;
  unordered_map<string, vector<ValueTimestamp>> um;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        um[key].push_back(make_pair(value, timestamp));           //1
    }
    
    string get(string key, int timestamp) {
      vector<ValueTimestamp>& vecChain = um[key];                   //2

      //See upper_bound() from above link.
      //Why comparator is required?
        //Because we need to search only 2nd value in vector<pair> and ignore 1st value.
      auto out = upper_bound(vecChain.begin(),
                             vecChain.end(),
                             ValueTimestamp ("", timestamp),
                             [](const ValueTimestamp& a, const ValueTimestamp& b){ //lambda
                                return a.second < b.second;
                             }
                            );
      return  out == vecChain.begin() ? "" : (--out)->first;        //3
    }
};
int main(){
  TimeMap* o = new TimeMap();
  o->set("key1","value1",1);
  o->set("key2","value2",2);
  o->set("key3","value3",3);
  o->set("key1","value4",4);
  o->set("key1","value10",10);

  cout<<o->get("key1",1)<<"\n";         //value1
  cout<<o->get("key1",4)<<"\n";         //value4
  cout<<o->get("key1",3)<<"\n";         //value1
}  
```
