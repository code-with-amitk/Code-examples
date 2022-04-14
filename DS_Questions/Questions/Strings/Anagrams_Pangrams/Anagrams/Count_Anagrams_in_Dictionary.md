**Count Anagrams in Dictionary**
- Approach
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
  - [Complexity](#co)


### Count Anagrams in Dictionary
- [What is Anagram](..)
- Give a dictionary of words, we need to count anagrams except present word. Dictionary can have meaningful or unmeaningful words.
```c
Input Dictionary: {"rat", "cat", "bus", "art", "tar", "usb"}
Output:
  rat,2     //rat,art,tar are anagrams but we output 2 since present word is not counted
  cat,0     //cat does not have anagram in dictionary
  bus,1     //bus,usb are anagrams
```

### Approch, Sort, map
<a name=l></a>
#### Logic
- _1._ Sort each word and store count in map
```c
input:      {"rat", "cat", "bus", "art", "tar"}
sorted:     {"art", "act", "bsu", "art", "art"}
map:
  art,3 | act,1 | bsu,1
```
- _2._ Iterate thru original Dictionary, sort each word and search in map
```
input:      {"rat", "cat", "bus", "art", "tar"}
word: rat => art, search art in map, if found push count on vector
  <(rat,2)
  
word: cat => act, search act in map, if found push count on vector
  <(rat,2), (cat,0)..
```

#### Code
<a name=cpp></a>
**CPP**
```cpp
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

using vecStr = vector<string>;
vector<pair<string,int>> fun(vecStr& dic) {
    unordered_map<string, int> um;
    vector<pair<string,int>> out;

    //Count anagrams after sort
    for (auto i:dic){
        sort(i.begin(), i.end());
        um[i]++;
        //um will have
        //art:3, act:1, bsu:1
    }

    //Search word inside map after sort
    for (auto i:dic){
        string word = i;
        sort(i.begin(), i.end());
        auto it = um.find(i);
        if (it != um.end()){
            int count = it->second;
            out.push_back({word, count-1});
        }
    }
    return out;
}

int main() {
    //output:
    //rat:2, cat:0, bus:0, art:2, tar:2
    //rat,art,tar are anagrams
    vector<string> dictionary = {"rat", "cat", "bus", "art", "tar"};
    vector<pair<string,int>> out = fun(dictionary);
    for (auto i:out){
        cout << i.first << "," << i.second;
    }
}
```

<a name=co></a>
#### Complexity
- **Time:** `n*mlogm`
  - m: length of longest word in dictionary. mlogm
  - n: length of dictionary.
- **Space:** 2`m*n`
  - n: number of words in dictionary
  - m: max length of word in dictionary
  - `m*n:` storing map
  - `m*n:` storing output.
