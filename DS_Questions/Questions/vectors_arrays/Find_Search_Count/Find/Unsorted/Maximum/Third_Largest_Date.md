**Third Largest Date**

### Third Largest Date
- Input Dates are given as below. Program should return 3rd largest date(19-07-2014)
```c
7
14-04-2001
29-12-2061
21-10-2019
07-01-1973
19-07-2014
11-03-1992
21-10-2019
```

### Code
- Find epochtime using `struct tm` fill in ordered map and find, 3rd from left.
```cpp
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using vec = vector<int>;
struct Date
{
    int Day;
    int Year;
    int Month;
};

Date ThirdLatest(std::vector<Date> & dates) {
    struct tm t;
    map<time_t, int> m;
    for (int i=0;i<dates.size();++i) {
        t.tm_year = dates[i].Year-1900;
        t.tm_mon = dates[i].Month-1;
        t.tm_mday = dates[i].Day;
        t.tm_hour = 0;
        t.tm_min = 0;
        t.tm_sec = 0;
        t.tm_wday = 0;
        t.tm_yday = 0;
        t.tm_isdst = 0;
        time_t timeSinceEpoch = mktime(&t);
        m.insert({timeSinceEpoch, i});
        //cout << timeSinceEpoch <<"\n";
    }
    //Take 3rd from last
    int k=1;
    auto itr = m.rbegin();
    while(itr!=m.rend()){
        if (k == 3) 
            break;
        ++k;
        itr++;
    }

    time_t epoch_time = itr->first;
    int index = itr->second;
    cout << "test";
    Date d;
    d.Day=dates[index].Day;
    d.Month=dates[index].Month;
    d.Year=dates[index].Year;
    return d;
}

int main() {
    int numberOfEntries;
    //int res = scanf("%d\n", &numberOfEntries);
    std::vector<Date> dates;
    //for (int i = 0; i < numberOfEntries; ++i)
    {
        Date date;
        /*7
        14-04-2001
29-12-2061
21-10-2019
07-01-1973
19-07-2014
11-03-1992
21-10-2019*/
        //res = scanf("%d-%d-%d", &date.Day, &date.Month, &date.Year);
        date.Day=14;date.Month=04;date.Year=2001;
        dates.push_back(date);
        date.Day=29;date.Month=12;date.Year=2061;
        dates.push_back(date);
        date.Day=21;date.Month=10;date.Year=2019;
        dates.push_back(date);
        date.Day=07;date.Month=01;date.Year=1973;
        dates.push_back(date);
        date.Day=19;date.Month=07;date.Year=2014;
        dates.push_back(date);
        date.Day=11;date.Month=03;date.Year=1992;
        dates.push_back(date);
        date.Day=21;date.Month=10;date.Year=2019;
        dates.push_back(date);
    }    
    
    Date result = ThirdLatest(dates);
    printf("%02d-%02d-%d\n", result.Day, result.Month, result.Year);
    // int year = ThirdLatest(dates);
    // cout << "year=" << year;
    return 0;
}
```
