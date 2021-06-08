## ofstream writing to file
```c++
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream file;
  file.open ("a.txt");
  file << "Writing to a file in C++....";
  file.close();
}
# ./a.out
# echo a.txt
Writing to a file in C++....
```
