## Two Options: help and Compression
- *1.* Create object of [class options_description](/Languages/Programming_Languages/c++/boost/Libraries/Program_Options/Library/).
- *2.* [add_options()](/Languages/Programming_Languages/c++/boost/Libraries/Program_Options/Library/) returns a object that defines the [functor operator ()](/Languages/Programming_Languages/c++/Characteristics_of_OOPS/Polymorphism/Static_CompileTime/Operator_Overloading/Functor)
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
  
  desc.add_options()                                            //2
    ("help", "help message")
    ("compression", po::value<int>(), "set compression level");
```
