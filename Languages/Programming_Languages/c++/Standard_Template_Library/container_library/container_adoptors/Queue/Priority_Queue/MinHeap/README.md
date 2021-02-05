## minHeap
```c
template<T,  vector<T>,  comparator> pq;
```

- **1. minHeap key=long, value=pair**
```c++
using mpair = pair<long, pair<int,int>>;
priority_queue <mpair, vector<mpair>, greater<mpair>> pq;
```

- **2. minHeap key=int, value=int**
```c++
using mpair = pair<int, int>;
priority_queue <mpair, vector<mpair>, greater<mpair>> pq;
```
