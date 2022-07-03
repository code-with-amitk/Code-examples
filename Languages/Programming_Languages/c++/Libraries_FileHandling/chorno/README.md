**chrono**

# chrono
Types defined by chrono: clocks, time points, durations

## 1. clocks
- Consists of: 
  - _a._ starting point(called epoch) and 
  - _b._ tick rate

### Clock Types
#### 1. std::chrono::system_clock (Wall Clock)
- system_clock measures Unix Time (i.e., time since 00:00 1 January 1970)
- Code: Display present date & time
```cpp
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

int main() {
  using namespace std::chrono;
  system_clock::time_point now = system_clock::now();       //now() returns time point representing current time.
  time_t tt = system_clock::to_time_t ( today );            //to_time_t() returns epoch 1970
  std::cout << tt << "\n";                                  //prints epoch since 1970
  std::cout << ctime(&tt);                                  //print into human redable form
}
$ ./a.out 
1656857827
Sun Jul  3 19:47:07 2022
```

### 2. Time points

### 3. Durations
