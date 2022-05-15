**Remove All Anagrams Only keeping 1st**
- [Logic](#l)
- Code
  - [CPP](#c1)
- [Complexity](#co)

### Remove All Anagrams Only keeping 1st
- You are given `vector<string>` containing anagrams.
- Delete all anagrams only keeping 1st anagram.
- Create `vector<string>` from 1st anagram and return
- Example
```c
input = ["abba","baba","bbaa","cd","cd"]
//"abba","baba","bbaa" are anagrams
//"cd","cd" are anagrams

output = ["abba", "cd"] //Remove all keep 1st
```

<a name=l></a>
### Logic
- _1._ Make a copy of input words
```c
input = ["abba","baba","bbaa","cd","cd"]
copy  = ["abba","baba","bbaa","cd","cd"]
```
- _2._ Sort input array
```c
input = ["aabb","aabb","aabb","cd","cd"]
```
- _3._ Create a `map<key=word, value=index>`, ie store only 1st index
```c
um  key   value
    aabb  0
    cd    3
```
- _4._ Store values from above map to set
```c
set= 0 3
```
- _5._ Create output from copy array(created in step-1) using indexes stored in step-4
```c
output = copy[0], copy[1]
         {"abba", "cd"}
```

### Code
<a name=c1></a>
#### CPP
```cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;
using vecS = vector<string>;

vecS fun(vecS& w){
    vecS input = w;                 //1. Make a copy of input words
    vecS out;

    //2. Sort every word             
    for (auto&i:w)
        sort(i.begin(), i.end());

    //3. Store in map<key=word, value=index>
    map<string, int> um;
    for (int i=0;i<w.size();++i){
        auto it = um.find(w[i]);
        if (it == um.end())
            um[w[i]] = i;
    }

    //Get values=indexes from map into set<int>
    set<int> s;
    for (auto&i:um)
        s.insert(i.second);
    
    //Create out from set, using indexes from set above
    for (auto&i : s)
        out.push_back(input[i]);

    return out;
}

int main(){
    vector<string> words = {"abba","baba","bbaa","cd","cd"};
    //vecS words = {"z","z","z","gsw","wsg","gsw","krptu"};
    vecS out = fun(words);
    for (auto&i : out)
        cout << i << " ";
}
```

<a name=co></a>
### Complexity
#### Time O(nlogn)
- copy: O(n)
- sort: O(nlogn)
- store in map: O(n)
#### Space O(n)
- created a copy: O(n)
- created map: O(n)
- created set:O(n)
