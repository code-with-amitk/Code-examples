### Top 3 words in paragraph
- Read paragraph, print top 2 most frequent words in paragraph.
```c
Paragraph.txt
amit hold your values. The thing to protect is your values and character. Keep building your character 
because not skills not speaking but your character decides where you are in your life. Got it amit, now 
keep working on your character keep watch on it.
  
your 6
character 3
on 2  
```

### Approach-1  //Hash Table. unordered_map<String, int>
- **Logic:**
  - *1.* Open file, read each word, fill in unordered_map<Word, count>
  - *2.* Once file reading completes, 
    - search map with highest value, Print Delete. Repeat 3 times.
- **Complexity:** m:words in file
  - **Time** O(m). Reading file,storage in hash-table, Finding top 3 words. O(1).
  - **Space** O(m). Creating hash map.
- **Code:**  
```c++
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include<unordered_map>

using String = std::string;
using Pair = std::pair<String, int>;

static bool comparator(Pair p1, Pair p2){
    return p1.second < p2.second;
}

int main(){
  std::ifstream iFile("Paragraph.txt");

  if (!iFile) {
    std::cout << "File not present\n";
    return 0;
  }

  String strLine, strWord;
  std::unordered_map<String, int> um;   //<Word, count>

  //Open the file
  while (iFile.eof() != 1){

    //Read the line
    std::getline (iFile, strLine);

    //Tokenize the line based on space
    std::stringstream oSS(strLine);
    while(std::getline(oSS, strWord, ' ')){
      um[strWord]++;          //Create <key=String, value=count>
    }
  }
  
//  for (auto [i,j]:um){
//    std::cout <<i<<","<<j << "\n";
//  }

  std::unordered_map<String, int>::iterator it;
  for (int i=0;i<3;++i){
    it = std::max_element(um.begin(), um.end(), comparator);
    std::cout << it->first <<"," << it->second <<"\n";
    um.erase(it);
  }
}  
```
