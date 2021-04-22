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
guess("kkkkkk") return 6  //11th call to guess()
```

### Approach  //Elimination
- **Logic**
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
