## Open in binary mode then Read 
```c++
#include <boost/filesystem/fstream.hpp>
#include <iostream>
using namespace std;

int main() {
  boost::filesystem::ifstream oStream;  //input Stream Object

  boost::filesystem::path file = "./test.txt";

  oStream.open(file, std::ifstream::binary);

  if (!oStream.is_open() && !oStream.good()) {
    cout<<"Cannot open file\n";
  } else {
    cout<<"File is good, opened\n";
  }
}

# g++ test.cpp -lboost_system
# ./a.out
File is good, opened
```
