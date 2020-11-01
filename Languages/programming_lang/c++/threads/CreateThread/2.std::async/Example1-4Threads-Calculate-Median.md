## Task
- Imagine there is a huge floating number array stored on the disk, which has been partitioned over N different processing nodes.
- Design a software system in C++ to calculate the median value using N multiple processing nodes.

### Code
- 4 nodes are considered as Threads.

```c++
using ld = long double;

std::vector<ld> ldArray= {
1.5,1.6,1.7,1.8,1.9,1.0,1.1,1.2,1.3,1.4,
2.5,2.6,2.7,2.8,2.9,2.0,2.1,2.2,2.3,2.4,
3.5,3.6,3.7,3.8,3.9,3.0,3.1,3.2,3.3,3.4,
4.5,4.6,4.7,4.8,4.9,4.0,4.1,4.2,4.3,4.4
};

void Node1(std::promise<ld>&& prms, uint32_t start, uint32_t end){
  std::sort(ldArray.begin()+start,ldArray.begin()+end);
  ld median = ldArray.at((start+end)/2);
  std::cout<<"Median = "<<median<<std::endl;
  prms.set_value(median);
}

int main(){
  auto startTime = high_resolution_clock::now();
  uint32_t nodes = 4, i = 0;
  uint32_t index = 0;
  ld overAllMedian =0;
  while (i < nodes) {
    std::promise<ld> prms;
    std::future<ld> ftr = prms.get_future();
    std::thread t1(Node1, std::move(prms), index, index+9);
    overAllMedian += static_cast<ld>(ftr.get());
    t1.join();
    index += 10;
    ++i;
  }

  std::cout<<"overAllMedian="<<overAllMedian/nodes<<"\n";
  auto endTime = high_resolution_clock::now();
  auto diff = duration_cast<milliseconds>(endTime - startTime);
  std::cout<<diff.count()/1000<<" seconds";                    //3 seconds
}
```
