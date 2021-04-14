## Example
- 1 commandline option `compression` is created it takes values between range `0 - 256`. if value is out of range it throws exception.

### How it works
- *1.* Create a validator structure/class which stores the value to be validated.
- *2.* Define a `validate()` method. This is templated overloaded method.
  - *Parameters:*
    - 1st,2nd,4th arguments are always fixed.
    - 3rd argument is pointer to Validator structure
  - *Body of validate()*
    - *2a, 2b* are fixed. Mandatory checks
    - *2c.* Converting strValue to type which is stroed by Validator Structure.
    - *2d.* Do the checks, if check fails throw exception else, pass value as boost variable.
### Code
```c++
#include<iostream>
#include<boost/program_options.hpp>
#include<boost/program_options/parsers.hpp>
using namespace std;

namespace po = boost::program_options;

struct RangeValidator{                                                  //1
public:
  RangeValidator(int a):a(a){};
  int a;
};

void validate(boost::any &v,                                            //2
              std::vector<std::string> const &vecValues,
              RangeValidator*,
              long) {

  //Make sure no previous assignments to 'v' was made
  po::validators::check_first_occurrence(v);                            //2a

  //Extract first string from 'values'. if there is more than
  //one string, it's an error, and exception will be thrown.
  const std::string& strValue = po::validators::get_single_string(vecValues); //2b

  int iValue;
  std::istringstream(strValue) >> iValue;                           //2c

  if (iValue > 256 || iValue < 0)                                     //2d
    throw po::validation_error (po::validation_error::invalid_option_value,
                                "compression");
  else
    v = boost::any (RangeValidator(iValue));
}

int main(int ac, char **av){

  try {
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("compression,c",
      po::value<RangeValidator>(),        
      "set compression level");

    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);

    if (vm.count("compression")) {
    cout << vm["compression"].as<RangeValidator>() << "\n";
    }
  }catch(...){
    cout<<"Caught Exception\n";
  }
}

# ./a.out --compression 1000
Caught Exception
```
