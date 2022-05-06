//4 threads are created assuming as 4 nodes.
//A common vector<long double> is shared and threads take 10 entries, 
//Threads Calculates/Displays median and sends median back. Main thread calculates overall median.

#include<iostream>
#include <unistd.h>
#include<thread>
#include<vector>
#include<future>
#include<chrono>
#include<algorithm>
#include<mutex>
#include <boost/asio.hpp>
using namespace std::chrono;

using ld = long double;
boost::asio::io_service io_service;

std::vector<ld> ldArray= {
1.5,1.6,1.7,1.8,1.9,1.0,1.1,1.2,1.3,1.4,
2.5,2.6,2.7,2.8,2.9,2.0,2.1,2.2,2.3,2.4,
3.5,3.6,3.7,3.8,3.9,3.0,3.1,3.2,3.3,3.4,
4.5,4.6,4.7,4.8,4.9,4.0,4.1,4.2,4.3,4.4
};

void Node(std::promise<ld>&& prms, uint32_t start, uint32_t end){
  std::sort(ldArray.begin()+start,ldArray.begin()+end);

  srand(time(NULL));

  //std::cout<<"rand="<<(rand()%1000)<<"\n";

  //Median Calculation Delay
  boost::asio::deadline_timer timer(io_service, boost::posix_time::milliseconds(rand()%10000));

  ld median = ldArray.at((start+end)/2);
  std::cout << "This Node Median:" << median << std::endl;

  prms.set_value(median);
}

int main(){
  auto startTime = high_resolution_clock::now();
  uint32_t u32Nodes = 4, i = 0;
  uint32_t u32Index = 0;
  ld ldOverAllMedian =0;
  while (i < u32Nodes) {

    std::promise<ld> prms;
    std::future<ld> ftr = prms.get_future();
    std::thread t1(Node, std::move(prms), u32Index, u32Index+9);

    //Median Tranmission Delay
    srand(time(NULL));
    boost::asio::deadline_timer timer(io_service, boost::posix_time::milliseconds(rand()%10000));

    ldOverAllMedian += static_cast<ld>(ftr.get());
    t1.join();
    u32Index += 10;
    ++i;
  }
  std::cout << "OverAll Median : " << (ldOverAllMedian/u32Nodes) << std::endl;
  auto endTime = high_resolution_clock::now();
  auto diff = duration_cast<milliseconds>(endTime - startTime);
  std::cout << "Over Time Taken : " << diff.count()
            <<" milliseconds" << std::endl;
}

/*
$ g++ main-future1.cpp -lpthread -lboost_system
$ ./a.out
This Node Median:1.5
This Node Median:2.5
This Node Median:3.5
This Node Median:4.5
OverAll Median : 3
Over Time Taken : 12 milliseconds
*/
