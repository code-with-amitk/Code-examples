## Problem
- Count total number of valid Emails in File.
- File
```c
# cat inputFile.txt
test
@facebook.com amit@.com
a@f.com  amit@facebook.com

Output: 2
  Invalid Emails: 
    - Nothing before @              //@facebook.com
    - Nothing between @ and .       //amit@.com

  Valid Emails:
    - Atleast 1 char before @       //a@f.com
    - Atleast 1 char between @ .    //amit@facebook.com
```

### Approach-1
- **Logic**
  - *1.* Open file, read every line
  - *2.* Tokenize the line using space and get the word
  - *3.* Check above rules on every word
- **Complexity** considering n line m words
  - **Time:** O(nm)
  - **Space:** O(w).    //w: Word having max length
- **Code**
```c++
#include<iostream>
#include<fstream>
#include<sstream>

int main(){
  std::string strLine;
  std::string strWord;
  uint32_t u32Count = 0;

  //Open file
  std::ifstream iFile("a1.txt");
  if (!iFile){
    std::cout<<"File is not present";
    return 0;
  }
  
  //Read file
  while (iFile.eof() != 1){
    //Read Line
    std::getline(iFile, strLine);

    //Tokenize line on spaces, ie get each word
    std::stringstream oSS(strLine);
    while (std::getline(oSS, strWord, ' ')) {
      bool bValid = false;
      //Find position of @
      //Find position of .
      int iPosAtTheRate = 0, iPosDot = 0;
      for (const auto& ch:strWord){
        if (ch == '@'){
          //if two @ in word, invalid email
          if(iPosAtTheRate)
            break;
          iPosAtTheRate = &ch - &strWord[0];
        }

        if (ch == '.'){
          //if two dots in word, invalid email
          if(iPosDot)
            break;
          iPosDot = &ch - &strWord[0];
        }

        //@ should fall before . atleast by 1 place
        if (iPosDot - iPosAtTheRate > 1 && iPosAtTheRate > 0) {
          bValid = true;
          break;
        }
      }

      if(bValid)
        ++u32Count;
    }
  }
  std::cout<<"Email Count:"<<u32Count;
}  
```
