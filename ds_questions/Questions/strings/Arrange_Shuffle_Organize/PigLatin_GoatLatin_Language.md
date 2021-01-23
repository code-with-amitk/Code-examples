### Problem
- Convert the sentence to the modified pig-latin/goat-latin language.

### Goat-Latin Language
- If the word starts with a vowel, then append ‘ma’ with the word
- It the word starts with a consonant, then remove that from beginning, and append it at the end, then add ‘ma’ at the end.
- Add one letter ‘a’ to the end of each word per its word index in the sentence, starting with 1

### Logic
- *1.* Extract word from string.
- *2.* For every single word: Perform the process to make it for goat-latin language.

### Complexity
- **Time:** O(n) + O(5) + O(k(k+1)/2)
> Considering total n characters in sentence. m characters/word
  - O(n): Reading compelete sentence
  - O(2): For vowel. Append ma
  - O(3): For consonant. Append ma and 1st character
  - `1+2+3+... k words = k(k+1)/2`
- **Space:** O(n) + 2O(m) + O(5)
  - O(5): unordered_set of vowels
  - 2O(m): Storing 2 word
  - O(n): Storing complete sentence

### Code
```c++
#include<iostream>
#include<string>
#include<unordered_set>

void AppendA(std::string& strWord, int& count){
  int i = 0;
  strWord += "ma";
  while(i++ < count)
    strWord += 'a';
}

void Process(std::string& strParsed, std::string& strWord, int& count){
  std::unordered_set<char> us = {'a','e','i','o','u'};
      //1st Letter is Vowel
      if (us.find(std::tolower(strParsed.at(0))) != us.end())
      {
        strWord = strParsed;
        AppendA(strWord, ++count);
      }
      else    //consonant
      {
        strWord = strParsed.substr(1,strParsed.size());
        strWord += strParsed[0];
        AppendA(strWord, ++count);
      }
}

int main(){
  std::string strInput = "Adam wants to go to the university";
  std::string strOutput, strWord, strParsed;
  int count = 0;

  for (auto& i:strInput){
    if (i == ' '){
      Process(strParsed, strWord, count);
      strOutput += strWord + ' ';
      strWord = "";     strParsed = "";
    }
    else    //Store word in strParsed
    {
      strParsed += i;
    }
  }

  Process(strParsed, strWord, count);
  strOutput += strWord ;

  std::cout<<"Converted string="<<strOutput;
}
```
