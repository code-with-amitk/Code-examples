### Problem
- Given a file with multiple columns, print the first and the third column out and find a new value based on the values of those two columns.
- Example
```c
[Input]
# cat MultipleColumn.txt
Coloumn1 Coloumn2 Coloumn3
1 2 3
4 5 6
9.9 8.9 4.5
10 11 12
13 14 15 16      17 18

[Output]
Coloumn1  Coloumn3
1  3
4  6
9.9  4.5
10  12
13  15
```

### Logic
- Open the file
- Ignore 1st line since its header only
- Read everyline, parse 1st and 3rd string. Convert to integer(using stringstream). Calculate cumulative Value.
- Repeat until end of file.

### Complexity
- **Time:** O(n). //n=number of characters in file
- **Space:** O(m). //m= max length of 1 line

### Code
```c++
#include<iostream>
#include<fstream>
#include<sstream>

using ifStr = std::ifstream;
using ss = std::stringstream;
using is = std::istringstream;

int main(){
  std::string strLine, strWord;
  int iFirstColoumn = 0, i = 0, iThirdColoumn = 0;
  int iCumulativeOutput = 0;

  ifStr f("MultipleColumn.txt");
  if (not f){
    std::cout<<"File opening error\n";
    return 0;
  }

  std::getline (f, strLine);  //Ignore the 1st line

  while(f.eof() == 0){
    std::getline (f, strLine);    //Read 2nd line onwards
    ss oSS(strLine);              //Tokenize for ' '
    while (std::getline (oSS, strWord, ' ')) {
      if (i==0){
        std::cout << strWord << " ";
        is(strWord) >> iFirstColoumn;
      }
      if (i==2){
        std::cout << strWord << " ";
        is(strWord) >> iThirdColoumn;
        break;
      }
      ++i;
    }//while (std::getline (oSS, strWord, ' ')
    i = 0;
    oSS.clear(); oSS.str("");
    std::cout << std::endl;
    iCumulativeOutput = iFirstColoumn*2 + iThirdColoumn/2;
  }//while(f.eof == 0){

  std::cout << "CumulativeOutput="<<iCumulativeOutput<<"\n";
}
```
