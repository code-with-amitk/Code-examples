[Underground System](https://leetcode.com/problems/design-underground-system/)
- Approach, HashMap
  - [Logic](#logic)
  - [Complexity](#comp)
  - [Code](#code)

### Underground System
- An underground railway system is keeping track of customer travel times between different stations. They are using this data to calculate the average time it takes to travel from one station to another.
- Implement the UndergroundSystem class:
```c
void checkIn(int id, string stationName, int t)
  A customer with a card ID equal to id, checks in at the station stationName at time t.
  A customer can only be checked into one place at a time.
void checkOut(int id, string stationName, int t)
  A customer with a card ID equal to id, checks out from the station stationName at time t.
double getAverageTime(string startStation, string endStation)
  Returns the average time it takes to travel from startStation to endStation.
  The average time is computed from all the previous traveling times from startStation to endStation that happened directly, 
  meaning a check in at startStation followed by a check out from endStation.
```

### Approach, HashMap

<a name=logic></a>
#### Logic
- let's consider we have 3 stations(A,B,C) and 4 customer-id's(1,2,3,4). Customer-id(1,2,3,4) checksin at station-A at time(10,20,30,40) and checkouts at station-B,C.
```c
    A         B         C
    /\        |         |
    |1,10     |1,50     |3,70
    |2,20     |2,60     |4,80
    |3,30     \/        \/
    |4,40
```
We will maintain 2 hashmaps to get the average time of travel between 2 stations.
- checkInMap HashMap to be populated at checkIn() method.
```c
                //id    stationName,checkInTime
    unordered_map<int, pair<string,int>> checkInData;
    
| 1,<A,10> | 2,<B,20> | 3,<C,30> | 4,<D,40> |
```
- checkOutMap HashMap about journey to be populated at checkout()
```c
                //ss->es    TotalTime,NoOfTrips
    unordered_map<string, pair<double,double>> checkOutMap;
    
checkout (id=1, es=B, t=50) {
  //Find start station for id=1. ss=A. key becomes startStation_endStation = A_B
  it's always certain that we will find the key(customer_id which checkedin), so we can directly goto value in Map
  
  goto value of key=ss_es
  TotalTime += checkoutTime - startTime   //Keep adding total times
  NoOfTrips += 1;                         //Total trips from startStation to EndStation
  
  //Also delete id from checkInMap since its not needed now and reduces space complexity
}
```
- Using these 2 hashMaps we will find average
```c
  getAverage(startStation, endStation)
    Find key (ss_es) in checkout Map
    Return value.first/value.second;
```

<a name=comp></a>
#### Complexity
- **Time** O(1)
- **Space** O(P+S<sup>2</sup>)
  - S:number of stations
  - P:no of passengers

<a name=code></a>
#### Code
```cpp
/////underground.cpp
class UndergroundSystem {
                //id    stationName,checkInTime
    unordered_map<int, pair<string,int>> checkInMap;

                //ss->es    TotalTime,NoOfTrips
    unordered_map<string, pair<double,double>> checkOutMap;
public:
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = { stationName,t };
    }

    void checkOut(int id, string stationName, int t) {
        auto itr = checkInMap[id];
        string ss_es = itr.first + "_" + stationName;
        checkOutMap[ss_es].first += t - itr.second;         //TotalTime
        checkOutMap[ss_es].second += 1;                     //TotalTrips from ss to es
        checkInMap.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string ss_es = startStation + "_" + endStation;
        auto itr = checkOutMap[ss_es];
        return (double)itr.first / itr.second;
    }
};

/////main.cpp
#include"underground.cpp"
#include <gtest/gtest.h>

TEST(Random, case1) {
             //(Expected_Output, function call)
    UndergroundSystem o;
    o.checkIn(45, "Leyton", 3);
    o.checkIn(32, "Paradise", 8);
    o.checkIn(27, "Leyton", 10);
    o.checkOut(45, "Waterloo", 15);
    o.checkOut(27, "Waterloo", 20);
    o.checkOut(32, "Cambridge", 22);
    EXPECT_EQ(14.0, o.getAverageTime("Paradise", "Cambridge"));
    EXPECT_EQ(11.0, o.getAverageTime("Leyton", "Waterloo"));
    o.checkIn(10, "Leyton", 24);
    EXPECT_EQ(11.0, o.getAverageTime("Leyton", "Waterloo"));
    o.checkOut (10, "Waterloo", 38);
    EXPECT_EQ(12.0, o.getAverageTime("Leyton", "Waterloo"));
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/////CMakeLists.txt
cmake_minimum_required(VERSION 2.6)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

$ cmake .
$ make
$ ./runtests
```
