**Unique Morse Code Words**
- [Logic](#l)
- [Complexity](#co)
- [Code](#c)


### [Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/)
- International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:
```c
'a' maps to ".-",
'b' maps to "-...",
'c' maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
```
- For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
Return the number of different transformations among all words we have.
```cpp
Example 1:
  Input: words = ["gin","zen","gig","msg"]
  Output: 2
  Explanation: The transformation of each word is:
  "gin" -> "--...-."
  "zen" -> "--...-."
  "gig" -> "--...--."
  "msg" -> "--...--."
  There are 2 different transformations: "--...-." and "--...--.".

Example 2:
  Input: words = ["a"]
  Output: 1
```

<a name=l></a>
### Logic
- Create hashmap of key as characters and its equivalent representation as value.
- Take a hashset which stores unique moore's represented strings.
- For incoming word, parse characters create string, check if its present in hashset, if not insert and increment count

<a name=co></a>
### Complexity
- **Time:** O(S)
- **Space:** O(S). where S is the sum of the lengths of words in words. We iterate through each character of each word in words.

<a name=c></a>
### Code
```cpp
class Solution {
    unordered_map<char, string> um = {{'a', ".-"},
                                       {'b', "-..."},
                                       {'c',"-.-."},
                                       {'d',"-.."},
                                       {'e',"."},
                                       {'f',"..-."},
                                       {'g',"--."},
                                       {'h',"...."},
                                       {'i',".."},
                                       {'j',".---"},
                                       {'k',"-.-"},
                                       {'l',".-.."},
                                       {'m',"--"},
                                       {'n',"-."},
                                       {'o',"---"},
                                       {'p',".--."},
                                       {'q',"--.-"},
                                       {'r',".-."},
                                       {'s',"..."},
                                       {'t',"-"},
                                       {'u',"..-"},
                                       {'v',"...-"},
                                       {'w',".--"},
                                       {'x',"-..-"},
                                       {'y',"-.--"},
                                       {'z',"--.."}};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> usUnique;

        uint32_t u32Count = 0;
        for (auto word:words) {
          string strCreated;
          for (int i=0;i<word.size();++i) {
            auto itr = um.find(word.at(i));
            strCreated.append(itr->second);
          }
          if (usUnique.find(strCreated) == usUnique.end()){
            usUnique.insert(strCreated);
            u32Count++;
          }
          strCreated.clear();
        }
        return u32Count;
    }
};
```
