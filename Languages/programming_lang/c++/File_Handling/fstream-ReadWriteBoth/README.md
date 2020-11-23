## Code
- Writes "Hello" to a.txt then read from same file.
```c++
#include <iostream>
#include<fstream>
using namespace std;

int main()
{
  //Write to File
  ofstream fileo("a.txt");
  fileo<<"Hello";
  fileo.close();

  //Read from file
  ifstream fin("a.txt");
  char ch;
  while(fin) {
    fin.get(ch);
    cout<<ch;
  }
  fin.close();
}
# ./a.out
Hello
```
