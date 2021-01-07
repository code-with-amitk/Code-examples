### Top 3 words in paragraph
```c
Paragraph.txt
amit hold your values. The thing to protect is your values and character. Keep building your character because not skills not speaking but your character
decides where you are in your life. Got it amit, now keep working on your character keep watch on it.
  
your 6
character 3
on 2  
```

### Approach-1  //Hash Table. unordered_map<String, int>
```c++
#include<fstream>
#include<iostream>
#include<sstream>
#include<unordered_map>
#include<algorithm>
using String = std::string;
using UM = std::unordered_map<String, int>;

static bool comp(std::pair<String, int> i, std::pair<String, int> j){
  return i.second < j.second;
}

int main(){
  std::fstream file("Paragraph.txt");
  UM um;
  if (not file){
    std::cout<<"Cannot find file";
    return 0;
  }
  while (file.eof() != 1){
    std::cout<<"Reading file";
    String strLine, strWord;
    while(std::getline(file, strLine)){
      //std::cout<<strLine<<"\n";

      //Tokenize based on space
      for(const char& i:strLine)  {
        if(i != ' ')
          strWord += i;
        else{
          um[strWord]++;
          strWord.clear();
        }
      }
      um[strWord]++;
    }
    for(const auto i:um)
      std::cout<<i.first<<" "<<i.second<<"\n";
    std::cout<<"\n";

    //Find Max Value in um
    UM::iterator it;
    int i=0;
    while ( i<3 ) {
      it = std::max_element(um.begin(), um.end(), comp);
      std::cout<<it->first<<" "<<it->second<<"\n";
      um.erase(it);
      ++i;
    }
  }
}
$ ./a.out
your 6
character 3
on 2
```

### Approach-2  //Priority Queue
