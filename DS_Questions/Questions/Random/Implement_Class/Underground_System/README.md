- [Underground System](#ques)
- Approach, HashMap
  - [Logic](#logic)
  - [Complexity](#comp)
  - [Code](#code)

<a name=ques></a>
### [Underground System](https://leetcode.com/problems/design-underground-system/)
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
- checkInData HashMap to be populated at checkIn() method.
```c
                //id    stationName,checkInTime
    unordered_map<int, pair<string,int>> checkInData;
    
| 1,<A,10> | 2,<B,20> | 3,<C,30> | 4,<D,40> |
```
- journeyData HashMap about journey to be populated at checkout()
```c
                //ss->es    TotalTime,NoOfTrips
    unordered_map<string, pair<double,double>> journeyData;
    
checkout (id=1, es=B, t=50) {
  //Find start station for id=1. ss=A. key becomes startStation->endStation = A->B
  
  if (key(ss->es) is not found journeyData HashMap) {
    //totalTime = t-checkInTime = 50-10 = 40
    //NoOfTrips = 1. if same Id have travelled once
    |A->B, <40, 1>|
  }
  else
    increment old totalTime by (t-startTime)
    increment NoOfTrips by 1.
  
}
```
- Using these 2 hashMaps we will find 
```c
```

#### Code
