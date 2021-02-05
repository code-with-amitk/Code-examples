## Timer Code
```c++
#include <iostream>
#include <boost/asio.hpp>


int main(void) {
  uint64_t val = 3000;
  boost::asio::io_service io_service;

  boost::asio::deadline_timer timer(io_service, boost::posix_time::milliseconds(val));

  timer.wait();

std::cout<<"next state";
}

# g++ test.cpp -lboost_system
```
