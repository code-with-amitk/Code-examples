[Remove Neighbouring Anagrams](https://leetcode.com/contest/weekly-contest-293/problems/find-resultant-array-after-removing-anagrams/)
- [Logic](#l)
- [Code](#c)
- [Complexity](#co)

### Remove Neighbouring Anagrams
- You are given a 0-indexed string array words, where `words[i]` consists of lowercase English letters.
- if `words[i] and words[i+1]` are anagrams, remove `words[i+1]`

<a name=l></a>
#### Logic
- Take 2 words i, i+1. Check if i and i+1 are anagrams. Remove i+1
- Logic to check 2 words are anagrams or not.
  - Insert all charaters from word1 into unordered_multiset
  - iterate through word2 string, if char is found in unordered_multiset, remove char
  - if sizeof unordered_multiset is 0, both are anagrams
- Perform same operation till end.

<a name=c></a>
#### Code
<a name=cpp></a>
**CPP**
```cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
using namespace std;
using vecS = vector<string>;

bool AreAnagrams(string s1, string s2){   //Check s1,s2 are anagrams or not
    unordered_multiset<char> s;
    for(auto&i :s1)
        s.insert(i);

    for(auto&i :s2){
        auto itr = s.find(i);
        if (itr != s.end())
            s.erase(itr);
    }
    return s.size() == 0 ? true : false;
}

vecS remove_neighbour_anagrams(vecS& w){
    int i=0;
    for (int i=0;i<w.size()-1;++i){
    
        //2 words cannot be anagrams if they are of different sizes
        if ((w[i].size() == w[i+1].size()) && AreAnagrams(w[i], w[i+1])){
            w.erase(w.begin()+i+1);
            --i;
        }
    }
    return w;
}

int main(){
    //vector<string> words = {"abba","baba","bbaa","cd","cd"};
    //vecS words = {"z","z","z","gsw","wsg","gsw","krptu"};
    //vecS words = {"a","b","a"};
    vecS words = {"a","az"};
    vecS out = remove_neighbour_anagrams(words);
    for (auto&i : out)
        cout << i << " ";
}
```

<a name=co></a>
#### Complexity
- **Time:** O(n)
  - Checking 2 strings are anagrams or not. O(n)
  - Remove adjacent Anagrams O(n)
- **Space:** O(m). Max length of particular word
