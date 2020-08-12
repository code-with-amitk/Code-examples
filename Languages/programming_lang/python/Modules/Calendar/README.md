## Calendar module
- **What** output calendars and provides additional useful functions related to the calendar.

### 1. Print calendar for any year and month
```
import calendar
y = int(input("year:"))
m = int(input("month:"))
print(calendar.month(y,m))

$ python3 test.py
year:2017
month:2
   February 2017
Mo Tu We Th Fr Sa Su
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28
```
