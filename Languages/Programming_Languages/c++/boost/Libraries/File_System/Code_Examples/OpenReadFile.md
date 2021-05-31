## Open in binary mode then Read 
```c++
#include <boost/filesystem/fstream.hpp>
#include <iostream>
using namespace std;

int main() {
  boost::filesystem::ifstream oStream;                //Create input Stream Object

  boost::filesystem::path file = "./test.txt";        //Create path object containing path of file

  oStream.open(file, std::ifstream::binary);          //Open file using path object

  if (!oStream.is_open() && !oStream.good()) {
    cout<<"Cannot open file\n";
  } else {
    cout<<"File is good, opened\n";
  }
  
  oStream.close();
}

# g++ test.cpp -lboost_system
# ./a.out
File is good, opened
```
