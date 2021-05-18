## [Word Ladder](https://leetcode.com/problems/word-ladder/)
- Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
  - Only one letter can be changed at a time.
  - Each transformed word must exist in the word list.
- Example
```c++
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
```
 
### Logic : BFS
1. if endWord is not present in dictionary return
2. Create unordered_set from dictionary so that searching is O(1)
3. Take a queue, push startWord.
4. Do these until queue is not empty
  - *4a.* Pop Queue's front (word = hit)
  - *4b.* Replace each alphabet in word & check in unordered_set
```html  
                i=0 Replace h  ait,bit,cit,dit...
                i=1 Replace i  hat,hbt,hct,...hot //Push on queue, remove from set
                i=2 Replace t  hia, hib,hic..

                if (replaced_word is found in unordered_set){
                        //increment count but only 1 time
                        //Push word on queue
                        //Remove replaced word from unordered_set
                }
```

### COMPLEXITY
- m=word size, n=number of words
- Time:
```c++
        Step-1: O(n) //finding endWord in vector
        Step-2: O(n) //Creating unordered_map
        Step-3: word-size(m)*26*n = O(26mn)
        2O(n) + O(26mn)
```         
- Space:
```c++
        O(mn)   //Creating unordered_set
        O(mn)   //Queue size, considering all words differ by 1 letter
        2O(mn)
```

## Code
```c++
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;
        //beginWord = "hit",
        //endWord = "cog",
        //wordList = ["hot","dot","dog","lot","log","cog"]
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

                //If word is not present in Dictionary, return
                if (find(wordList.begin(), wordList.end(), endWord) ==
                                wordList.end()){
                        return 0;
                }

                //For O(logn) searching
                unordered_set<string> us(wordList.begin(), wordList.end());

                queue<string> q;
                q.push(beginWord);

                int path = 0;
                int height = 1;
                int upbound = 1;

                while (q.empty() != 1){
                        ++path;

                        auto word = q.front();

                        //word=hit
                        //temp
                        for (int i = 0; i < word.size(); i++){

                                for (char j = 'a'; j <= 'z'; j++){

                                        if (word.at(i) == j) continue;

                                        char old = word.at(i);

                                        word.at(i) = j;

                                        if (us.count(word)){
                                                if (word == endWord){
                                                        return ++height;
                                                }

                                                q.push(word);
                                                us.erase(word);
                                        }

                                        word.at(i) = old;
                                }
                        }

                        if (path == upbound){
                                ++height;
                                upbound = q.size() - 1;
                                path = 0;
                        }
                        q.pop();
                }
                return 0;

    }
};
int main(){
//      vector<string> wordList={"hot","dot","dog","lot","log","cog"};  //5
//      vector<string> wordList={"hot","dot","dog","lot","log"};        //0
//      string beginWord = "hit";
//      string endWord = "cog";

        vector<string> wordList={"hot","dot","dog"};    //1
        string beginWord = "hot";
        string endWord = "dot";
        Solution s;
        cout<<s.ladderLength(beginWord,endWord,wordList);
}
```
