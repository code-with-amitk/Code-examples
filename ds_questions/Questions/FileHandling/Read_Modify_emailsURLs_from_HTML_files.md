### Problem
- Given 3 HTML files.
- Read the files, parse email, URL from files and change them.
```c++
Email change example:
  support@test.com  --change to-->  support@fb.com
  
URL change example:  
  test.com  --changed to-->  test.fb.com
  test.org  --changed to-->  test.fb.org
```

### Logic
- *1.* Pass html file as command line argument.
- *2.* open input file. Read every line
  - Tokenize using space character and read the word.
  - if `@` is found in word, this is Email modify it as per above rule.
  - if `.com or .org` is found in word, this is URL modify it as per above rule.
- *3.* Keep writing the content to a seperate file.
- *4.* Rename the file after complete input file is read.

### Code
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
  std::fstream file("html-file.html", std::ios::out|std::ios::in);
  std::fstream out("TemporaryFile.html", std::ios::out);
  std::vector<std::string> vecTLD = {".com",".org",".edu"};
  bool bWritten = false;

  if (!file) {
    std::cout<<"File does not exist";
    return 0;
  }
  if (!out) {
    std::cout<<"Cannot open out";
    return 0;
  }
  std::string strLine, strWord, strNewWord;

  while (file.eof() != 1){
    std::getline (file, strLine);   //Read a Line

    std::stringstream ss(strLine);  //Tokenize using space
    while (std::getline(ss, strWord, ' ')) {

      if(strWord.find('@') != std::string::npos){ //Does word have @
        out << ModifyEmail(strWord);
        bWritten = true;
      }
      else{
        for (auto i:vecTLD){
          if(strWord.find(i) != std::string::npos){ //Does word have .com
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
