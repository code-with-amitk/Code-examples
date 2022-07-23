**chrono**
- **Clocks**
  - [a. system_clock](#c1)
  - [b. steady_clock](#c2)
  - [c. high_resolution_clock](#c3)
  - [d. utc_clock](#c4)
- [Timepoints](#tp)
- [Durations](#dur)

# chrono
Types defined by chrono: clocks, time points, durations

## 1. clocks
- Consists of: 
  - _a._ starting point(called epoch) and 
  - _b._ tick rate

### Clock Types
<a name=c1></a>
#### a. std::chrono::system_clock (Wall Clock)
- system_clock measures Unix Time (i.e., time since 00:00 1 January 1970)

**Code-1: Display present date & time**
```cpp
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

int main() {
  using namespace std::chrono;
  system_clock::time_point now = system_clock::now();       //now() returns time point representing current time.
  time_t tt = system_clock::to_time_t ( now );            //to_time_t() returns epoch 1970
  std::cout << tt << "\n";                                  //prints epoch since 1970
  std::cout << ctime(&tt);                                  //print into human redable form
}
$ ./a.out 
1656857827
Sun Jul  3 19:47:07 2022
```
**Code-2: Time taken to task completion**
```cpp
#include <iostream>
#include <chrono>
#include <thread>
int main() {

    using namespace std::chrono;
    auto start = std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000) );
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count();
}
$ ./a.out
2.00063
```

<a name=c2></a>
#### b. std::chrono::steady_clock (stopwatch)
```cpp
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int main() {
        auto start = std::chrono::steady_clock::now();              //Start stopwatch
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));   //Run
        auto end = std::chrono::steady_clock::now();                //Stop stopwatch
        std::chrono::duration<double> diff = end - start;
        std::cout << "diff=" << diff.count();
}
$ ./a.out
diff=2.00064
```
##### steady_clock vs system_clock
||steady_clock|system_clock|
|---|---|---|
|What|stopwatch|Wallclock|
|Precision|More|less wrt steady_clock. Because system_clock has to sync with some source to get epoch. if source is faulty clock is faulty|

<a name=c3></a>
#### c. std::chrono::high_resolution_clock
clock with smallest tick period provided by the implementation. It may be an alias of std::chrono::system_clock or std::chrono::steady_clock, or a third, independent clock.
```cpp
#include <iostream>
#include <chrono>
#include <thread>

int main() {
        //record start time
        auto start = std::chrono::high_resolution_clock::now();

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        // record end time
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        std::cout << diff.count() << "\n";
}
$ ./a.out
2.0014
```

<a name=c4></a>
#### d. std::chrono::utc_clock (C++20)
```cpp
#include <iostream>
#include <chrono>
#include <thread>
int main() {
        auto start = std::chrono::utc_clock::now();        // record start time
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));        // do some work
        auto end = std::chrono::utc_clock::now();        // record end time
        std::chrono::duration<double> diff = end - start;
        std::cout << diff.count();
}
```

<a name=tp></a>
### 2. Time points
A time point gives the time value from epoch
```cpp
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

int main()
{
    using namespace std::literals;
    const std::chrono::time_point<std::chrono::system_clock> now =
    std::chrono::system_clock::now();                               //epoch

    const std::time_t tt1 = std::chrono::system_clock::to_time_t(now - 24h);    //timepoint
    std::cout << "24 hours ago time was: "
        << std::put_time(std::localtime(&tt1), "%F %T.\n") << std::flush;
}
$ ./a.out
24 hours ago time was: 2022-07-03 10:15:37
```

<a name=dur></a>
### 3. Durations
- This is span of time, defined as some number of ticks of some time unit.
- For example, "12 seconds" can represented by a duration consisting of 4 ticks of a 3-second time unit.
```cpp
template<class Rep, class Period = std::ratio<1>> class duration;
Rep = count of ticks, tick period
```
