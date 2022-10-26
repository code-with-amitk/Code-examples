**[Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)**
- **Approach-1, Recursive**
  - [Logic](#l1)
  - [Complexity](#co1)
  - [Code](#c1)
- **Approach-2, Search Every dictionary word in string. O(mn)**
  - [Logic](#l2)
  - [Complexity](#c2)
  - [Code](#co2)

### Question
- Given a string s and string of words called dictionary. Delete some letters from input string match formed word in dictionary & return longest word in the dictionary.
- If more than one possible result, return the longest word with the smallest [lexicographical](/DS_Questions/Questions/Strings/Lexicographical) order. If there is no possible result, return the empty string.
```c
Example 1:
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
  
Example 2:
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
```

- This is similar to Finding [Longest Common SubSeqeunce](/DS_Questions/Questions/Strings/SubString_SubSequence/Longest_Common_SubSequence_in_2_strings.md), but word is searhed in string and if lengths are same lexiographical order.

### Approach-1, Recursively create all combinations
<a name=l1></a>
#### Logic
- _1._ Find all words which can be formed by deleting the letter/letters(using recursion), store in unordered_set. Match dictionary words with unordered_set.
- _2._ Use recursive function to create a string by adding/removing characters from the string
```c
string = abpc, dictionary=["ap"]

apc, abc, abp   //Fix a, Delete 1 letter.
bpc, abc, abp   //Fix b, Delete 1 letter.
bpc, apc, abc   //Fix p, Delete 1 letter.
bpc, apc, abc   //Fix c, Delete 1 letter.

ab, ap, ac   //Fix a, Delete 2 letter.
bc, ab, bp   //Fix b, Delete 2 letter.
..
  
a   //Fix a, Delete 3 letter.
...
```
<a name=co1></a>
#### Complexity
- **Time:** Exponential. O(2<sup>n</sup>). generate calls itself 2<sup>n</sup> times. Here, n refers to the length of string s.
- **Space:** O(2<sup>n</sup>). List contains 2<sup>n</sup> strings

<a name=c1></a>
#### Code
```cpp
class Solution {
public:
    void generate (string& s, string str, int i, vector<string>& v){
        if (i == s.size())
            v.push_back(str);
        else {
            generate (s, str+s.at(i), i+1, v);
            generate (s, str, i+1, v);
        }
    }
    string findLongestWord(string s, vector<string>& dic) {
        unordered_set<string> us;
        for (auto i:dic)
            us.insert(i);

        vector<string> vecTemp;
        generate (s, "", 0, vecTemp);
        
        string max_str = "";
        for (string str:vecTemp) {
            if (us.find(str) != us.end())
                if (str.size() > max_str.size() || (str.size() == max_str.size() && str.compare(max_str) < 0))
                    max_str = str;
        }
        return max_str;
    }
};
int main(){
    vector<string> v = {"ale","apple","monkey","plea"};
    string s = "abpcplea";
    Solution o;
    cout << o.findLongestWord (s,v);    //apple
}
```

### Approach-2, Search Every dictionary word in string
<a name=l2></a>
#### Logic
```c
Input: str = "abpcplea", dictionary = ["ale","abl","apple"]
```
_1._ Take `string out` which will store the output word.
_2._ Search every dictionary word inside str. 
  - if complete word is found, store word in `out`.
```c
After searching "ale". out=ale  //because ale is found.
```
_3._ Search `abl` in input str
```c
  if (complete dictionary word is found input string)     //abl is found compeltely in str
    if (present_word.size() == out.size()) {
      if (present_word < out)                 //if new word searched is lexiographically smaller. update out
        out = "abl"
    }
  }
```
- _4._ Search next word="apple" in input string. if word is completely found and its size > stored size. update word
```c
  if("apple" is found completely && ("apple".size() > out.size())
    out = "apple"
```
<a name=c2></a>
#### Complexity
- **Time:** O(mn). m=input_string.size(), n=number of words in dictionary
- **Space:** O(1)

<a name=co2></a>
#### Code
```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& dic) {
        string out;
        
        for(string word: dic){ //Iterate each word in dictionary
            int j=0,k=0;
            
            //Check dictionary word in string completely
            while(j<s.size() && k<word.size()){ 
                if(s[j]==word[k])
                    k++;         
                j++;   
            }
            
            int n=word.size();
            
            if(k==n && (n>out.size() || (out.size()==n && word<out)))
                out=word;
            //save word in out if the three conditions are met: 
                //1. k==n: if every letter of word exists in input string s (and in order of the word)
                //2. n>out.size(): new word is a longer word than saved word(out)
                //3. (out.size()==n && word<out): new word is same size as saved word(out) but is lexicographically smaller
                     //"return the longest word with the smallest lexicographical order."
        }
        return out;     
    }
};
```
