- [Question](#ques)
- [Approach-1](#apr1)

<a name=ques></a>
## [Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)
- Alien language also use english lowercase letters, but in a different order.
- Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.
- Examples:
```c
Example 1:
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 2:
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅',
```

<a name=apr1></a>
## Approach-1
- Check each character of words in input array whether in lexicographical order or not by going to each character of input array.
- **Logic**
  - *1.* Create a array containing positions of characters as per order
  - *2.* Take 1st 2 words to check whether all characters are in lexiographical order(as per new dictionary) by Iterating till smaller word's length(word1's len=4)
  - _3._ if length of word1>word2 return false
```c
order = "worldabcefghijkmnpqstuvxyz"
words = {"word","world","row"}

value 5	 6  7  4                         3           1           2                   0                //Step-1
index 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
      a  b  c  d  e  f  g  h  i  j   k   l   m   n   o   p   q   r   s   t   u   v   w   x   y   z

word1 = "word"	//len=4
word2 = "world" //len=5

if (characters at position match)                           //Step-2
  do nothing
else	//character do not match	i=3. d,l
  if(Check whether 2 characters are in lexiographical order as per dictionary?)
    //PlaceValue of d=4, PlaceValue of l=3. this is not.
	//return false			
   break
```
- **Complexity**
  - *Time:* O(n). n=Total count of characters in words.
  - *Space:* O(1). Size of created index array is always contant ie 26.
- **Code**
```c
bool isAlienSorted(std::vector<std::string>& words, std::string order) {
  int* index = new int[26];
  for (int i = 0; i < order.size(); ++i)
    index[order.at(i) - 'a'] = i;
  int temp = 0;

  for (int i = 0; i < words.size() - 1; ++i) {
    std::string strWord1 = words[i];
    std::string strWord2 = words[i+1];
    temp=1;

    //Compare word1, word2
    for (int k = 0; k < std::min(strWord1.size(), strWord2.size()); ++k) {

      //Continue matching each character of word1,word2 until mismatch
      //Eg: word1 = "word", word2 = "world"
      //k=0,1,2 will not go inside if
      //k=3. Go inside if
      if (strWord1.at(k) != strWord2.at(k)) {

        //word1.at(3)=d, word2.at(3)=l
        //index[d-a]=4 > index[l-a]=3
        //Found 2 words which are not placed lexicographicaly as per given order
        if (index[strWord1.at(k) - 'a'] > index[strWord2.at(k) - 'a'])
          return false;

        temp = 0;
        break;
       }
     }

     // After comparing all characters, if still word1>word2. return false
     if (temp and strWord1.size() > strWord2.size())
      return false;
   }
   return true;
}
```
