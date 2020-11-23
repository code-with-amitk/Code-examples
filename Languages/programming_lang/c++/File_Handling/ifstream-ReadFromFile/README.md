## Code
```c++
#include <iostream>
#include<fstream>
using namespace std;

int main()
{
  char c,fn[10];
  ifstream in("a.txt");                 //This is created in ofstream README.md
  if(in == 0) {
    cout<<"Error! File Does not Exist";
    return 0;
  }
  while(in.eof()==0) {
    in.get(c);
    cout<<c;
  }
}
# ./a.out
Writing to a file in C++.....
```
