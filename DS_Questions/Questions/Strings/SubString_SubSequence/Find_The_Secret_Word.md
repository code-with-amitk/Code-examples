## [Guess the word](https://leetcode.com/problems/guess-the-word/)
- You are given an array of words, each size=6(always). Out of these words 1 word is secret which is only known to computer.
- Computer has provided a function `int guess(string)` to which you can pass the word:
  - if word passed is same as secret, guess() will return 6.
  - else guess() will return number of matching characters in passed word.
- You need to guess the word in JUST 10 calls of word guess().
- **Example-1**
```html
wordlist = {"aaaaaa","bbbbbb", "aaaccc", "bbbddd", "eeeeee", "ffffff", "gggggg", "hhhhhh", "iiiiii", "jjjjjj", "kkkkkk"}
Let secret word = "kkkkkk"
guess("aaaaaa") return 0
guess("gggggg") return 0
guess("kkkkkk") return 6    //Answer. You guessed the secret word correctly.
```
- **Example-2:** All are unique words and secret lies after 10th place, it is not possible to guess the word in 10 calls to guess(). This case is allowed and code checker will not mark this case as fail.
```html
wordlist = {"aaaaaa","bbbbbb", "cccccc", "dddddd", "eeeeee", "ffffff", "gggggg", "hhhhhh", "iiiiii", "jjjjjj", "kkkkkk"}
Let secret word = "kkkkkk"
guess("aaaaaa") return 0
guess("gggggg") return 0
guess("kkkkkk") return 6  //11th call to guess(). 

Answer: Either you took too many guesses, or you did not find the secret word.
Expected: Either you took too many guesses, or you did not find the secret word.
```

## Approach  //Elimination
### Logic
- *1.* sort wordlist and create a temporary datastructure maybe doubly linked list.
```html
wordlist = {"aaaaaa","aaaccc","bbbbbb", "bbbddd", "eeeeee", "ffffff", "gggggg", "hhhhhh", "iiiiii", "jjjjjj", "kkkkkk"}

doublyLL = "aaaaaa" <> "aaaccc" <> "bbbbbb" <> "bbbddd" <> "eeeeee" <> "ffffff" <> "gggggg" <> "hhhhhh" <> "iiiiii" <> "jjjjjj" <> "kkkkkk"
```
- *2.* Pass 1st word from LL to guess() function and find how many matching characters this word has with secret.
```html
guess("aaaaaa") returns 0   //because secret was "kkkkkk"

-> 0 means secret word will not have any of characters which is present in "aaaaaa",
so we can remove all words from doublyLL which has any character matching with "aaaaaa"
```
- *3.* Remove all words from doublyLL which has any character matching with "aaaaaaa"
```html
doublyLL = "aaaaaa" <> "aaaccc" <> "bbbbbb" <> "bbbddd" <> "eeeeee" <> "ffffff" <> "gggggg" <> "hhhhhh" <> "iiiiii" <> "jjjjjj" <> "kkkkkk"
Remove "aaaaaa"

doublyLL = "aaaccc" <> "bbbbbb" <> "bbbddd" <> "eeeeee" <> "ffffff" <> "gggggg" <> "hhhhhh" <> "iiiiii" <> "jjjjjj" <> "kkkkkk"
Remove "aaaccc"

doublyLL = "bbbbbb" <> "bbbddd" <> "eeeeee" <> "ffffff" <> "gggggg" <> "hhhhhh" <> "iiiiii" <> "jjjjjj" <> "kkkkkk"

-> All other words in doublyLL does not have any character matching with "aaaaaaa"
```
- *4.* Pass next word from doublyLL to guess() and find matching words, repeat steps-2,3 for rest for words.

### Complexity
- **Time:** O(n<sup>2</sup>)
  - [sort(): O(nlogn)](/Languages/Programming_Languages/c++/Standard_Template_Library/Algorithm-library/sort)
  - 2 while loops: O(n<sup>2</sup>)
    - for loop iterates 6 times, so it will be O(6n<sup>2</sup>)
- **Space:** O(n)
  - Creating doublyLL: O(n)
### Code
```c++
class Solution {
public:
    
    //How many characters match with word passed to guess() function
    int Score(string& strPassedToGuess, string& strWordFromList) {
        int iMatchedCharacters = 0;
        for (int i=0; i<6; ++i) {
            if(strPassedToGuess[i] == strWordFromList[i]) 
                ++iMatchedCharacters;
        }
        return iMatchedCharacters;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int iNoOfMatchingCharacters = 0;
        
        //Sort, Convert to Doubly Linked List                   //1
        sort(wordlist.begin(),wordlist.end());
        list<string> doublyLL(wordlist.begin(), wordlist.end());
        
        //Secret will have matchingCharacters=6.
        //Keep traversing the list until secret is found
        while(iNoOfMatchingCharacters < 6) {

            //At start of doubly LL
            auto it = *doublyLL.begin();
            auto it1 = doublyLL.begin();
            
            //Number of matching characters of word with secret
            iNoOfMatchingCharacters = master.guess(*doublyLL.begin());      //2
            
            while(it1 != doublyLL.end()) {
                
                //Remove all words from doublyLL which have matching
                //characters with recently passed word to guess()
                if(Score(it,*it1) != iNoOfMatchingCharacters) {       //3
                    auto tmp = next(it1);
                    doublyLL.erase(it1); 
                    it1 = tmp;
                }
                else
                    ++it1;
            }
        }
        return;
    }
};
```
