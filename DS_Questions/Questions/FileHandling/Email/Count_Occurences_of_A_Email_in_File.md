## Fb Problem
- Count how many times A Single email address is found in file.
- Example
```txt
[Input]
# cat a.txt
i am going to make it and that's i know soon amit@gmail.com I will prepare as per the role, vivek@gmail.com I know 
i need to stop think amit@gmail.com I will be my
own cheer leader. anil@gmail.com
And I know that's important amit@gmail.com to be motivated

[Output] 3
```

## Complexity
> n=Number of characters in file, m=Characters in Line, w=word length
- **Time:** O(n) Reading in while.
- **Space:** 3O(m) + O(w)
  - 2O(m)  //Reading a line getline
  - O(m)  //Storing in stringstream
  - O(w)  //Storing word

## Code
```c++
#include<iostream>
#include<fstream>
#include<sstream>

int main(){
  std::string strLine;
  std::string strWord;
  uint32_t u32Count = 0;
  std::ifstream iFile("a.txt");                             //ifstream (>>)	For reading from file
  if(not iFile) {
    std::cout << "File Open error" << std::endl;
    return 0;
  }

  while (iFile.eof() == 0) {                              //bool eof(); Returns true if End-of-file reached.
    std::getline(iFile, strLine);                         //getline(istream& is, string& str);  
    std::stringstream oSS(strLine);
    while (std::getline(oSS, strWord, ' ')){              //istream& getline(istream& is, string& str, char delim);
//      if (strWord.find('@') != std::string::npos)       //Find character inside word
        if (strWord == "amit@gmail.com")
          u32Count++;
    }
  }
  std::cout << "Count = " << u32Count << std::endl;
}
```
