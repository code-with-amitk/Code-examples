### Print

```c++
  #include<queue>
  
  std::priority_queue<std::pair<double, std::string>> maxHeap;
  maxHeap.push(make_pair(double, string));

  while(maxHeap.empty() != 1) {
    std::pair<double, std::string> p = maxHeap.top();
    std::cout<<p.second<<","<<p.first<<"\n";
    maxHeap.pop();
  }
  
```
