## Two Options: help and Compression
```c++
#include<iostream>
#include<boost/program_options.hpp>
#include<boost/program_options/parsers.hpp>
using namespace std;

namespace po = boost::program_options;

int main(int ac, char **av){

  int opt;
  std::string strInput;

  po::options_description desc("Allowed options");              //1
  
  desc.add_options()
    ("help", "help message")
    ("compression", po::value<int>(), "set compression level");
```
