## Problem
- Given HTML files.
- Read all 3 files and the following:
  - parse email addresses
  - parse URLs
  - Change them.
```c++
Email change example:
  support@test.com  --change to-->  support@fb.com
  
URL change example:  
  test.com  --changed to-->  test.fb.com
  test.org  --changed to-->  test.fb.org
```

- **Logic**
  - *1.* Take a vector of TLD's `vecTLD = {".com",".org",".edu"};` to be parsed from file.
  - *2.* Open input html file in read mode.
  - *3.* Open a temporary file(out) in write mode. 
  - *4.* Read every line from input HTML file, tokenize using space.
    - keep dumping every word read into temporary file(out)
    - {Found Email} if word contains `@`, Modify the word and dump in temporary file(out)
    - {Found URL} if word contains `.com or .org`, Modify the word and dump in temporary file(out)
  - *5.* Rename the file after complete input file is read.
- **Complexity**
  - **Time:** O(n). n is number of words. Reading all words and modifying email, url
  - **Space:** O(n). Creating a temporary file and rename it.
- **Code**
```c++
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_set>

//amit@gmail.com -> amit@fb.com
std::string ModifyEmail(std::string& strWord) {
  std::cout<<"old word="<<strWord<<"\n";
  std::string strNewWord;
  int start=0, end=0, i=0;
  for (auto& ch:strWord) {
    if(ch=='@')
      start = i;
    if(ch=='.')
      end = i;
    ++i;
    if(start !=0 and end != 0){
      strNewWord = strWord.substr(0,start+1);
      strNewWord += "fb";
      strNewWord += strWord.substr(end,strWord.size());
      std::cout<<"newWord="<<strNewWord<<"\n";
      start=end=0;
    }
  }
  return strNewWord;
}

//test.com -> test.fb.com
std::string ModifyURL(std::string& strWord) {
  std::string strNewWord;
  int i=1;
  for(auto ch:strWord){
    if(ch =='.'){
      strNewWord = strWord.substr(0,i);
      strNewWord += "fb";
      strNewWord += strWord.substr(i-1,strWord.size());
      break;
    }
    ++i;
  }
  return strNewWord;
}

int main(){
  std::vector<std::string> vecTLD = {".com",".org",".edu"};
  bool bWritten = false;  
  std::string strLine, strWord, strNewWord;

  //ios::out  =>  allows output (write operations) to a stream
  //ios::in   =>  allows input (read operations) from a stream
  std::fstream file("html-file.html", std::ios::in);
  if (!file) {
    std::cout<<"File does not exist";
    return 0;
  }  
  
  std::fstream out("TemporaryFile.html", std::ios::out);  
  if (!out) {
    std::cout<<"Cannot open out";
    return 0;
  }
  
  while (file.eof() != 1){
    std::getline (file, strLine);   //Read a Line

    std::stringstream ss(strLine);  //Tokenize using space
    while (std::getline(ss, strWord, ' ')) {

      if(strWord.find('@') != std::string::npos){     //Does word have @
        out << ModifyEmail(strWord);
        bWritten = true;
      }
      else{
        for (auto i:vecTLD){
          if(strWord.find(i) != std::string::npos){     //Does word have .com
            out << ModifyURL(strWord);
            bWritten = true;
            break;
          }
        }
      }
      if (not bWritten)
        out << strWord;

      out<<" ";
      bWritten = false;
    }
    out << std::endl;
  }
  out.close();
  file.close();
  if(std::rename("TemporaryFile.html", "html-file.html"))
    std::cout<<"File rename error\n";
}    
```
